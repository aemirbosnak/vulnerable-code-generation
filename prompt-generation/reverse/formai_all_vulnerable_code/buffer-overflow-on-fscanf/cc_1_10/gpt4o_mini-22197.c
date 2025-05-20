//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_WORD_LENGTH 50
#define TEXT_LENGTH 1024
#define POSITIVE_WORDS_FILE "positive.txt"
#define NEGATIVE_WORDS_FILE "negative.txt"
#define NUM_THREADS 4

typedef struct {
    char *text;
    int start;
    int end;
    int sentiment_score;
} ThreadData;

char *positive_words[100];
char *negative_words[100];
int positive_count = 0;
int negative_count = 0;

void load_words(const char *filename, char *words[], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }
    while (fscanf(file, "%s", words[(*count)++]) != EOF);
    fclose(file);
}

// Function to analyze sentiment in a segment of text
void *analyze_sentiment(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    char *text_segment = strndup(data->text + data->start, data->end - data->start);
    
    char *word = strtok(text_segment, " ,.!?;\n");
    while (word != NULL) {
        for (int i = 0; i < positive_count; i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                data->sentiment_score++;
            }
        }
        for (int i = 0; i < negative_count; i++) {
            if (strcmp(word, negative_words[i]) == 0) {
                data->sentiment_score--;
            }
        }
        word = strtok(NULL, " ,.!?;\n");
    }
    
    free(text_segment);
    pthread_exit(NULL);
}

int main() {
    char text[TEXT_LENGTH];
    
    // Load positive and negative words
    load_words(POSITIVE_WORDS_FILE, positive_words, &positive_count);
    load_words(NEGATIVE_WORDS_FILE, negative_words, &negative_count);

    printf("Please enter the text for sentiment analysis:\n");
    fgets(text, TEXT_LENGTH, stdin);
    
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    int segment_size = strlen(text) / NUM_THREADS;

    // Create threads to analyze segments of text
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].text = text;
        thread_data[i].start = i * segment_size;
        thread_data[i].end = (i == NUM_THREADS - 1) ? strlen(text) : (i + 1) * segment_size;
        thread_data[i].sentiment_score = 0;
        pthread_create(&threads[i], NULL, analyze_sentiment, (void *)&thread_data[i]);
    }
    
    // Wait for threads to finish and aggregate results
    int total_sentiment_score = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        total_sentiment_score += thread_data[i].sentiment_score;
    }

    // Display the final sentiment score
    printf("Final Sentiment Score: %d\n", total_sentiment_score);
    if (total_sentiment_score > 0) {
        printf("The sentiment is positive.\n");
    } else if (total_sentiment_score < 0) {
        printf("The sentiment is negative.\n");
    } else {
        printf("The sentiment is neutral.\n");
    }

    return 0;
}
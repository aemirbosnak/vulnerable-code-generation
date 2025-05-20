//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10 // maximum number of threads
#define MAX_SENTIMENT 50 // maximum size of sentiment string
#define MAX_TEXT 500 // maximum size of text

// struct to store sentiment and its frequency
typedef struct {
    char sentiment[MAX_SENTIMENT];
    int frequency;
} Sentiment;

// global variables
Sentiment sentiment_data[MAX_SENTIMENT];
char text_data[MAX_TEXT];

// function to count the frequency of each sentiment
void *sentimentCounter(void *arg) {
    char *sentiment = (char *) arg;
    int frequency = 0;
    char *temp = strtok(text_data, " ");
    while (temp != NULL) {
        if (strcmp(temp, sentiment) == 0) {
            frequency++;
        }
        temp = strtok(NULL, " ");
    }
    for (int i = 0; i < MAX_SENTIMENT; i++) {
        if (strcmp(sentiment_data[i].sentiment, sentiment) == 0) {
            sentiment_data[i].frequency = frequency;
            pthread_exit(NULL);
        }
    }
}

int main() {
    int num_threads, sentiment_count = 0;
    char buffer[MAX_TEXT];
    printf("Enter the text to analyze: ");
    fgets(buffer, MAX_TEXT, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // remove newline character
    
    // tokenize the text and count the number of unique sentiments
    char *temp = strtok(buffer, " ");
    while (temp != NULL) {
        int found = 0;
        for (int i = 0; i < sentiment_count; i++) {
            if (strcmp(sentiment_data[i].sentiment, temp) == 0) {
                found = 1;
            }
        }
        if (!found) {
            strcpy(sentiment_data[sentiment_count].sentiment, temp);
            sentiment_data[sentiment_count].frequency = 0;
            sentiment_count++;
        }
        strcat(text_data, temp);
        strcat(text_data, " ");
        temp = strtok(NULL, " ");
    }
    
    printf("Enter the number of threads to use (maximum %d): ", MAX_THREADS);
    scanf("%d", &num_threads);
    if (num_threads > MAX_THREADS) {
        printf("Maximum number of threads exceeded. Defaulting to %d.\n", MAX_THREADS);
        num_threads = MAX_THREADS;
    }
    pthread_t threads[num_threads];
    
    // create and execute the threads
    for (int i = 0; i < sentiment_count; i++) {
        int rc = pthread_create(&threads[i], NULL, sentimentCounter, (void *) sentiment_data[i].sentiment);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(1);
        }
    }
    
    // wait for threads to finish and print results
    printf("\nSentiment analysis results:\n");
    for (int i = 0; i < sentiment_count; i++) {
        pthread_join(threads[i], NULL);
        printf("%s: %d\n", sentiment_data[i].sentiment, sentiment_data[i].frequency);
    }
    
    return 0;
}
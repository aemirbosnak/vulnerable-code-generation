//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define POSITIVE_WORDS_FILE "positive-words.txt"
#define NEGATIVE_WORDS_FILE "negative-words.txt"

// Function prototypes
void loadWords(const char *filename, char words[][MAX_WORD_LENGTH], int *word_count);
int analyzeSentiment(const char *text, char positive_words[][MAX_WORD_LENGTH], int pos_count,
                     char negative_words[][MAX_WORD_LENGTH], int neg_count);
void toLowerCase(char *str);
int isWordPresent(char word[], char words[][MAX_WORD_LENGTH], int count);

int main() {
    char positive_words[MAX_WORDS][MAX_WORD_LENGTH];
    char negative_words[MAX_WORDS][MAX_WORD_LENGTH];
    int pos_count = 0, neg_count = 0;

    // Load positive and negative words
    loadWords(POSITIVE_WORDS_FILE, positive_words, &pos_count);
    loadWords(NEGATIVE_WORDS_FILE, negative_words, &neg_count);

    char input_text[1000];
    printf("Enter your text for sentiment analysis:\n");
    fgets(input_text, sizeof(input_text), stdin);
    
    // Analyze sentiment of the input text
    int result = analyzeSentiment(input_text, positive_words, pos_count, negative_words, neg_count);

    // Display the result
    if (result > 0) {
        printf("The sentiment of the text is POSITIVE.\n");
    } else if (result < 0) {
        printf("The sentiment of the text is NEGATIVE.\n");
    } else {
        printf("The sentiment of the text is NEUTRAL.\n");
    }

    return 0;
}

void loadWords(const char *filename, char words[][MAX_WORD_LENGTH], int *word_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", words[*word_count]) != EOF) {
        (*word_count)++;
        if (*word_count >= MAX_WORDS) {
            fprintf(stderr, "Warning: Reached maximum word limit from %s\n", filename);
            break;
        }
    }
    
    fclose(file);
}

int analyzeSentiment(const char *text, char positive_words[][MAX_WORD_LENGTH], int pos_count,
                     char negative_words[][MAX_WORD_LENGTH], int neg_count) {
    int sentiment_score = 0;
    char word[MAX_WORD_LENGTH];
    char temp_text[1000];
    strcpy(temp_text, text);
    
    char *token = strtok(temp_text, " \n");
    while (token != NULL) {
        toLowerCase(token);
        if (isWordPresent(token, positive_words, pos_count)) {
            sentiment_score++;
        } else if (isWordPresent(token, negative_words, neg_count)) {
            sentiment_score--;
        }
        token = strtok(NULL, " \n");
    }

    return sentiment_score;
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int isWordPresent(char word[], char words[][MAX_WORD_LENGTH], int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(word, words[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}
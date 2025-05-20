//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

// Structure to hold the sentiment data
typedef struct {
    char word[MAX_WORD_LENGTH];
    int score; // positive score > 0, negative score < 0
} Sentiment;

// Function to read sentiment data from a file
int load_sentiment_data(const char *filename, Sentiment sentiments[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening sentiment file\n");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%s %d", sentiments[count].word, &sentiments[count].score) != EOF) {
        count++;
    }
    fclose(file);
    return count;
}

// Function to clean and lowercase a string
void clean_string(char *str) {
    char *original = str;
    char *cleaned = (char *)malloc(strlen(str) + 1);
    int j = 0;

    while (*original) {
        if (isalpha(*original) || *original == ' ') {
            cleaned[j++] = tolower(*original);
        }
        original++;
    }
    cleaned[j] = '\0';
    strcpy(str, cleaned);
    free(cleaned);
}

// Function to analyze a text and return its sentiment score
int analyze_sentiment(const char *text, Sentiment sentiments[], int sentiment_count) {
    char *words[MAX_WORDS];
    char text_copy[2048];
    strcpy(text_copy, text);
    
    clean_string(text_copy);

    // Tokenize the cleaned string into words
    char *token = strtok(text_copy, " ");
    int total_score = 0;

    while (token) {
        int found = 0;
        for (int i = 0; i < sentiment_count; i++) {
            if (strcmp(token, sentiments[i].word) == 0) {
                total_score += sentiments[i].score;
                found = 1;
                break;
            }
        }
        if (!found) {
            // If the word is not found in the sentiment list, we ignore it
            printf("Unknown word: %s\n", token);
        }
        token = strtok(NULL, " ");
    }
    
    return total_score;
}

int main() {
    Sentiment sentiments[MAX_WORDS];
    int sentiment_count = load_sentiment_data("sentiment.txt", sentiments);

    if (sentiment_count == 0) {
        return 1; // Exit if no sentiment data loaded
    }

    char text[2048];
    printf("Enter some text for sentiment analysis (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(text, sizeof(text), stdin);
        
        // Remove trailing new line character
        text[strcspn(text, "\n")] = 0;

        if (strcmp(text, "exit") == 0) {
            break; // Exit loop if user types 'exit'
        }

        int score = analyze_sentiment(text, sentiments, sentiment_count);

        if (score > 0) {
            printf("Sentiment Score: %d (Positive)\n", score);
        } else if (score < 0) {
            printf("Sentiment Score: %d (Negative)\n", score);
        } else {
            printf("Sentiment Score: %d (Neutral)\n", score);
        }
    }

    return 0;
}
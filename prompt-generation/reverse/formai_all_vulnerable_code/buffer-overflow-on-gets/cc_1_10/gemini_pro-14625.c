//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024
#define NUM_WORDS 100

// Function to split a string into words
char** split(char* str, int* num_words) {
    char** words = malloc(sizeof(char*) * NUM_WORDS);
    char* word = strtok(str, " ");
    int i = 0;
    while (word != NULL) {
        words[i] = malloc(strlen(word) + 1);
        strcpy(words[i], word);
        i++;
        word = strtok(NULL, " ");
    }
    *num_words = i;
    return words;
}

// Function to compare two strings
int cmp(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

// Function to summarize a text
char* summarize(char* text, int num_words) {
    // Split the text into words
    int num_words_in_text;
    char** words = split(text, &num_words_in_text);

    // Sort the words in alphabetical order
    qsort(words, num_words_in_text, sizeof(char*), cmp);

    // Get the top num_words words
    char* summary = malloc(MAX_LEN);
    int i = 0;
    int j = 0;
    while (i < num_words && j < num_words_in_text) {
        if (strcmp(words[i], words[j]) != 0) {
            strcat(summary, words[j]);
            strcat(summary, " ");
            i++;
        }
        j++;
    }

    // Free the memory allocated for the words
    for (i = 0; i < num_words_in_text; i++) {
        free(words[i]);
    }
    free(words);

    return summary;
}

int main() {
    // Get the text from the user
    char text[MAX_LEN];
    printf("Enter the text to be summarized: ");
    gets(text);

    // Get the number of words to include in the summary
    int num_words;
    printf("Enter the number of words to include in the summary: ");
    scanf("%d", &num_words);

    // Summarize the text
    char* summary = summarize(text, num_words);

    // Print the summary
    printf("Summary: %s\n", summary);

    // Free the memory allocated for the summary
    free(summary);

    return 0;
}
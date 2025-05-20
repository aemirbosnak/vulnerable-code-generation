//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct word_count {
    char* word; 
    int count;
} word_count;

int main() {
    char text[1000];
    int num_words = 0, i, j, k;
    
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    // Remove trailing newline from user input
    text[strlen(text) - 1] = '\0';

    // Convert all uppercase characters to lowercase
    for(int i = 0; text[i]; i++){
        text[i] = tolower(text[i]);
    }

    // Count number of words in text
    for (i = 0; i < strlen(text); i++) {
        if (isspace(text[i])) {
            num_words++;
        }
    }
    num_words++;

    // Create array to hold each word and its count
    word_count* wc = (word_count*) malloc(num_words * sizeof(word_count));
    if (wc == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Tokenize text and count frequency of each word
    char* token = strtok(text, " ");
    for (i = 0; i < num_words; i++) {
        wc[i].word = (char*) malloc(strlen(token) + 1);
        if (wc[i].word == NULL) {
            perror("Error allocating memory");
            exit(1);
        }
        strncpy(wc[i].word, token, strlen(token) + 1);
        wc[i].count = 1;
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(token, wc[j].word) == 0) {
                wc[i].count++;
                free(wc[j].word);
                wc[j].word = NULL;
            }
        }
        token = strtok(NULL, " ");
    }

    // Remove any NULL pointers from wc array
    for (i = 0, j = 0; i < num_words; i++) {
        if (wc[i].word != NULL) {
            wc[j].word = wc[i].word;
            wc[j].count = wc[i].count;
            j++;
        }
        else {
            free(wc[i].word);
            wc[i].word = NULL;
        }
    }
    num_words = j;

    // Print results
    printf("\nWord frequency count:\n\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", wc[i].word, wc[i].count);
    }

    // Free memory
    for (i = 0; i < num_words; i++) {
        free(wc[i].word);
        wc[i].word = NULL;
    }
    free(wc);

    return 0;
}
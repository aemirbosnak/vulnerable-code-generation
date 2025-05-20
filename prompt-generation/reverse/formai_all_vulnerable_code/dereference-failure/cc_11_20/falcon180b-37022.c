//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *english;
    char *alien;
} WordPair;

int main() {
    FILE *fp;
    char line[100];
    WordPair words[MAX_WORDS];
    int num_words = 0;
    int i;

    // Open the dictionary file
    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    // Read in the English words and their translations
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Too many words in dictionary.\n");
            return 2;
        }
        char *english_word = strtok(line, " ");
        char *alien_word = strtok(NULL, " ");
        if (english_word == NULL || alien_word == NULL) {
            printf("Error: Invalid line in dictionary file.\n");
            return 3;
        }
        strcpy(words[num_words].english, english_word);
        strcpy(words[num_words].alien, alien_word);
        num_words++;
    }

    // Close the dictionary file
    fclose(fp);

    // Get the user's input
    printf("Enter a sentence to translate:\n");
    fgets(line, sizeof(line), stdin);

    // Remove the newline character from the input
    line[strcspn(line, "\n")] = '\0';

    // Convert the input to lowercase
    for (i = 0; i < strlen(line); i++) {
        line[i] = tolower(line[i]);
    }

    // Split the input into words
    char *word = strtok(line, " ");
    while (word!= NULL) {
        // Look up the word in the dictionary
        int found = 0;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].english) == 0) {
                printf("%s ", words[i].alien);
                found = 1;
                break;
            }
        }
        // If the word is not found, print an error message
        if (!found) {
            printf("Error: Unknown word '%s'.\n", word);
        }
        // Move on to the next word
        word = strtok(NULL, " ");
    }

    // Print a newline character
    printf("\n");

    return 0;
}
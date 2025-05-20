//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    char input[MAX_WORD_LENGTH];
    char *token;
    FILE *file;
    WordCount words[MAX_WORDS];
    int numWords = 0;

    // Open file for reading
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read in file
    while (fscanf(file, "%s", input)!= EOF) {
        // Convert input to lowercase
        for (int i = 0; i < strlen(input); i++) {
            input[i] = tolower(input[i]);
        }

        // Remove punctuation
        input[strcspn(input, ".,?!;:\"'()[]{}<>")] = '\0';

        // Tokenize input
        token = strtok(input, " ");
        while (token!= NULL) {
            // Check if word already exists in array
            for (int i = 0; i < numWords; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            // Add new word to array
            if (numWords < MAX_WORDS) {
                strcpy(words[numWords].word, token);
                words[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL, " ");
        }
    }

    // Print word counts
    printf("Word\t\tCount\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t\t%d\n", words[i].word, words[i].count);
    }

    // Close file
    fclose(file);

    return 0;
}
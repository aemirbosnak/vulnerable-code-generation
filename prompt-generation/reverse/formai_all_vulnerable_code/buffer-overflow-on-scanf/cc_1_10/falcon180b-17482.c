//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    int numWords = 0;
    WordCount words[MAX_WORDS];

    printf("Enter the filename: ");
    scanf("%s", line);

    file = fopen(line, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read the file line by line
    while ((getline(&line, &len, file))!= -1) {
        // Convert the line to lowercase
        for (int i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }

        // Split the line into words
        char *word = strtok(line, " \t\n\r\f\v");
        while (word!= NULL) {
            numWords++;

            // Check if we have reached the maximum number of words
            if (numWords >= MAX_WORDS) {
                printf("Error: too many words in the file.\n");
                exit(1);
            }

            // Store the word and its count
            strcpy(words[numWords-1].word, word);
            words[numWords-1].count = 1;

            // Get the next word
            word = strtok(NULL, " \t\n\r\f\v");
        }
    }

    // Print the word counts
    printf("Word Count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
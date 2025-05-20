//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *word;
        char *saveptr;
        word = strtok_r(line, " \t\n\r\f\v", &saveptr);
        while (word!= NULL) {
            // Check if word is already in array
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            // Add new word to array
            if (i == numWords) {
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }
            word = strtok_r(NULL, " \t\n\r\f\v", &saveptr);
        }
    }

    fclose(file);

    // Sort array by word count
    for (i = 0; i < numWords - 1; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (words[j].count > words[i].count) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print word count
    printf("Word Count:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} WordCount;

int main() {
    FILE *file;
    char line[100];
    char word[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    // Open file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read file and count words
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(word, token);
            for (i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords >= MAX_WORDS) {
                    printf("Error: too many words\n");
                    exit(1);
                }
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL, " ");
        }
    }

    // Sort words by count
    for (i = 0; i < numWords - 1; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (words[j].count > words[i].count) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print results
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Close file
    fclose(file);

    return 0;
}
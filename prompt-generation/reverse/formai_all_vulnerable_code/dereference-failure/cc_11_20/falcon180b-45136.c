//Falcon-180B DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_WORDS 1000

typedef struct {
    char* word;
    int count;
} WordCount;

int main() {
    FILE* file;
    char buffer[MAX_BUFFER_SIZE];
    char* line = NULL;
    size_t len = 0;
    int lineCount = 0;
    int maxWordSize = 0;
    WordCount words[MAX_WORDS];
    int numWords = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while ((getline(&line, &len, file))!= -1) {
        lineCount++;

        // Remove trailing newline character
        if (line[len-1] == '\n') {
            line[len-1] = '\0';
            len--;
        }

        // Split line into words
        char* word = strtok(line, " \t\r\n\f\v");
        while (word!= NULL) {
            int wordSize = strlen(word);
            if (wordSize > maxWordSize) {
                maxWordSize = wordSize;
            }
            if (numWords >= MAX_WORDS) {
                printf("Error: too many words\n");
                exit(1);
            }
            words[numWords].word = malloc(wordSize + 1);
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
            word = strtok(NULL, " \t\r\n\f\v");
        }
    }

    fclose(file);

    // Sort words by count
    for (int i = 0; i < numWords-1; i++) {
        for (int j = i+1; j < numWords; j++) {
            if (words[j].count > words[i].count) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print word count
    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Print line count
    printf("\nLine count: %d\n", lineCount);

    // Print maximum word size
    printf("Maximum word size: %d\n", maxWordSize);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: minimalist
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_NAME_LENGTH 256
#define MAX_LINE_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *file;
    char fileName[MAX_FILE_NAME_LENGTH];
    char line[MAX_LINE_LENGTH];
    char *word;
    WordCount wordCounts[100];
    int numWords = 0;

    // Check if file name is provided as argument
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Get file name from command line argument
    strcpy(fileName, argv[1]);

    // Open file for reading
    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        return 1;
    }

    // Read file line by line and count words
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        word = strtok(line, " \t\n\r\f");
        while (word!= NULL) {
            // Convert word to lowercase and remove punctuation
            char *p = word;
            while (*p!= '\0') {
                if (!isalnum(*p)) {
                    *p = '\0';
                }
                p++;
            }
            // Check if word is already in wordCounts array
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(wordCounts[i].word, word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }
            // Add word to wordCounts array if not already present
            if (i == numWords) {
                strcpy(wordCounts[numWords].word, word);
                wordCounts[numWords].count = 1;
                numWords++;
            }
            word = strtok(NULL, " \t\n\r\f");
        }
    }

    // Close file
    fclose(file);

    // Print word counts
    printf("Word counts:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}
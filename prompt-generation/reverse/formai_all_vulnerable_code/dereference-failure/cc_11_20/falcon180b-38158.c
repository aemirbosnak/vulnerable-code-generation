//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

typedef struct {
    char *word;
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char line[MAX_LINE_SIZE];
    char word[MAX_WORD_SIZE];
    WordCount wordCounts[26]; // assuming only 26 unique words will be found in the input file
    int lineNumber = 1;

    if (argc!= 2) {
        printf("Error: Please provide a filename as an argument.\n");
        exit(1);
    }

    inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, inputFile)!= NULL) {
        char *wordStart = line;
        char *wordEnd;
        int wordLength = 0;

        // remove any leading/trailing spaces
        while (isspace(*wordStart)) {
            wordStart++;
        }
        while (isspace(*(wordEnd = wordStart + strlen(wordStart) - 1))) {
            wordEnd--;
        }
        *wordEnd = '\0';

        // find the next word
        while ((wordStart = strtok(wordEnd, " \t\r\n"))!= NULL) {
            // convert word to lowercase
            strcpy(word, wordStart);
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }

            // update word count
            int wordIndex = tolower(word[0]) - 'a';
            if (wordIndex >= 0 && wordIndex < 26) {
                wordCounts[wordIndex].count++;
            } else {
                printf("Error: Word '%s' is not a valid letter.\n", word);
            }
        }

        lineNumber++;
    }

    fclose(inputFile);

    // print word counts
    printf("Word counts:\n");
    for (int i = 0; i < 26; i++) {
        if (wordCounts[i].count > 0) {
            printf("%c: %d\n", 'a' + i, wordCounts[i].count);
        }
    }

    return 0;
}
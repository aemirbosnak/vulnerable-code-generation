//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_WORDS 100

typedef struct {
    char *word;
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINES];
    char word[MAX_WORDS];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    // Open the file
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    // Read the file and count the words
    while (fgets(line, MAX_LINES, fp)!= NULL) {
        numWords = 0;
        strcpy(word, "");
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                strcat(word, tolower(line[i]));
            } else {
                if (numWords < MAX_WORDS) {
                    strcpy(words[numWords].word, word);
                    words[numWords].count = 1;
                    numWords++;
                }
                strcpy(word, "");
            }
        }
        if (numWords < MAX_WORDS) {
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }
    }

    // Print the word counts
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Close the file
    fclose(fp);

    return 0;
}
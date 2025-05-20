//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void readFile(FILE* file, struct WordFrequency* words, int* numWords) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            int j = 1;
            while ((ch = fgetc(file))!= EOF && isalnum(ch)) {
                if (j >= MAX_WORD_LENGTH) {
                    printf("Error: Word is too long.\n");
                    exit(1);
                }
                words[i].word[j] = tolower(ch);
                j++;
            }
            words[i].word[j] = '\0';
            words[i].frequency = 1;
            i++;
        } else if (isspace(ch)) {
            continue;
        } else {
            printf("Error: Invalid character.\n");
            exit(1);
        }
    }
    *numWords = i;
}

void sortWords(struct WordFrequency* words, int numWords) {
    for (int i = 0; i < numWords - 1; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                struct WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void printWordFrequencies(struct WordFrequency* words, int numWords) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    int numWords = 0;
    struct WordFrequency words[MAX_WORDS];
    readFile(file, words, &numWords);

    sortWords(words, numWords);
    printWordFrequencies(words, numWords);

    fclose(file);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Educational ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void loadWords(char* filename, WordCount* words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int index = 0;
        while (index < MAX_WORDS && words[index].word[0]!= '\0') {
            index++;
        }
        if (index == MAX_WORDS) {
            printf("Error: too many words in file\n");
            exit(1);
        }
        strcpy(words[index].word, word);
        words[index].count = 0;
    }

    fclose(file);
}

void countWords(char* text, WordCount* words) {
    int length = strlen(text);
    char word[MAX_WORD_LENGTH];
    int index = 0;

    while (index < length) {
        if (isspace(text[index])) {
            if (index > 0 &&!isspace(text[index - 1])) {
                word[index - 1] = '\0';
                int wordIndex = 0;
                while (wordIndex < MAX_WORDS && words[wordIndex].word[0]!= '\0') {
                    if (strcmp(word, words[wordIndex].word) == 0) {
                        words[wordIndex].count++;
                        break;
                    }
                    wordIndex++;
                }
            }
            index++;
        } else {
            strncat(word, &text[index], 1);
            index++;
        }
    }
}

void printWords(WordCount* words) {
    int count = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].word[0]!= '\0') {
            printf("%s: %d\n", words[i].word, words[i].count);
            count++;
        }
    }
    if (count == 0) {
        printf("No words found\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <text>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    char* text = argv[2];

    WordCount words[MAX_WORDS];
    loadWords(filename, words);

    countWords(text, words);

    printWords(words);

    return 0;
}
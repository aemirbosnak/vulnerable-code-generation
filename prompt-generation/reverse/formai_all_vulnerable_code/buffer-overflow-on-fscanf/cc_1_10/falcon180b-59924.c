//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE *file, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in the file.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].count = 0;
        i++;
    }
}

void countWords(char *sentence, WordCount words[]) {
    char *token;
    int i, j;

    token = strtok(sentence, " ");

    while (token!= NULL) {
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("Error: Unknown word '%s'.\n", token);
            exit(1);
        }

        token = strtok(NULL, " ");
    }
}

void printWords(WordCount words[]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    WordCount words[MAX_WORDS];

    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Cannot open input file '%s'.\n", argv[1]);
        return 1;
    }

    readWords(file, words);
    fclose(file);

    countWords(argv[2], words);
    printWords(words);

    return 0;
}
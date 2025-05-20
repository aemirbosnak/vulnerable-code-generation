//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void readWords(char *filename, Word *words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (wordCount >= MAX_WORDS) {
            printf("Error: too many words in file\n");
            exit(1);
        }
        strcpy(words[wordCount].word, word);
        words[wordCount].count = 0;
        wordCount++;
    }

    fclose(file);
}

void spellCheck(char *filename, Word *words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // remove newline character

        int i;
        for (i = 0; i < wordCount; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == wordCount) {
            printf("Misspelled word: %s\n", word);
        }
    }

    fclose(file);
}

void printWords(Word *words) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <dictionary> <text_file>\n", argv[0]);
        exit(1);
    }

    Word words[MAX_WORDS];
    readWords(argv[1], words);

    spellCheck(argv[2], words);

    printWords(words);

    return 0;
}
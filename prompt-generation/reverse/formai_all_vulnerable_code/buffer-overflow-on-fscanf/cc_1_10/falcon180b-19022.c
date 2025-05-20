//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE *file, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) > 0) {
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }
            int index = hash(word);
            words[index].count++;
        }
    }
}

int hash(char *word) {
    int hashValue = 0;
    for (int i = 0; i < strlen(word); i++) {
        hashValue += (int)word[i];
    }
    return hashValue % MAX_WORDS;
}

void printWords(WordCount words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordCount words[MAX_WORDS];
    readWords(file, words);

    fclose(file);

    printf("Word Count:\n");
    printWords(words);

    return 0;
}
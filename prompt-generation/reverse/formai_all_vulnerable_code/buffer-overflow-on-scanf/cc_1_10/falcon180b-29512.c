//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_words(FILE *fp, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (strlen(word) > 0) {
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }
            int found = 0;
            for (int j = 0; j < MAX_WORDS; j++) {
                if (strcmp(words[j].word, word) == 0) {
                    words[j].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(words[MAX_WORDS - 1].word, word);
                words[MAX_WORDS - 1].count = 1;
            }
        }
    }
}

void print_word_counts(WordCount words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strlen(words[i].word) > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *fp;
    char filename[100];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    WordCount words[MAX_WORDS];
    read_words(fp, words);
    fclose(fp);
    printf("Word counts:\n");
    print_word_counts(words);
    return 0;
}
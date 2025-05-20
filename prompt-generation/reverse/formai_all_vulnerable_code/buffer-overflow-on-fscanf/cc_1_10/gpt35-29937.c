//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int num_words = 0;
    WordCount words[MAX_WORDS];

    while (fscanf(file, "%s", word) != EOF) {
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            WordCount wc;
            strcpy(wc.word, word);
            wc.count = 1;
            words[num_words] = wc;
            num_words++;
        }
    }
    fclose(file);

    printf("\nWord Frequency Count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%-15s %d\n", words[i].word, words[i].count);
    }

    return 0;
}
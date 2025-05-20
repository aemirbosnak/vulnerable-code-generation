//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

struct word {
    char word[WORD_LENGTH];
    int count;
};

int main() {
    FILE *fp;
    char filename[50];
    int num_words = 0;
    struct word words[MAX_WORDS];

    printf("Enter file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[1024];
    char *word;

    while (fgets(line, sizeof(line), fp)) {
        word = strtok(line, " ,.\n\t");
        while (word != NULL) {
            for (int i = 0; i < num_words; i++) {
                if (strcasecmp(words[i].word, word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (num_words < MAX_WORDS) {
                strcpy(words[num_words].word, word);
                words[num_words++].count = 1;
            } else {
                printf("Too many words in file.\n");
                exit(1);
            }
        }
        word = strtok(NULL, " ,.\n\t");
    }

    fclose(fp);

    printf("\nWord count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
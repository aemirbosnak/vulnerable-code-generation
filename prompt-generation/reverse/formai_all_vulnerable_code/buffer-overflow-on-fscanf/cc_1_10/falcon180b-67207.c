//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} word_pair;

void load_words(word_pair *word_list) {
    FILE *file = fopen("words.txt", "r");
    if (!file) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(file, "%s %s\n", word_list[num_words].word, word_list[num_words].translation)!= EOF) {
        num_words++;
    }

    fclose(file);
}

int main() {
    word_pair word_list[MAX_WORDS];
    load_words(word_list);

    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence: ");
    fgets(input, MAX_WORD_LENGTH, stdin);

    int num_words = 0;
    char *word_start = input;
    char *token = strtok(word_start, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, word_list[i].word) == 0) {
                printf("%s ", word_list[i].translation);
                break;
            }
        }
        if (i == num_words) {
            printf("%s ", token);
        }
        num_words++;
        token = strtok(NULL, " ");
    }

    printf("\n");
    return 0;
}
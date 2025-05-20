//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} word_t;

void load_words(word_t words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s", words[count].word, words[count].translation) == 2) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Too many words in file.\n");
            exit(1);
        }
    }

    fclose(file);
}

int main() {
    word_t words[MAX_WORDS];
    load_words(words);

    char input[MAX_WORD_LEN];
    printf("Enter a sentence:\n");
    fgets(input, MAX_WORD_LEN, stdin);

    char *token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].word) == 0) {
                printf("%s ", words[i].translation);
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}
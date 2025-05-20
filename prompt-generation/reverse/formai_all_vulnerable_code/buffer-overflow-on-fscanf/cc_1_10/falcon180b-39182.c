//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} Word;

void load_words(Word *words, int n) {
    FILE *file = fopen("words.txt", "r");

    if (file == NULL) {
        printf("Error: cannot open words.txt\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %s", words[i].word, words[i].translation) == 2 && i < n) {
        i++;
    }

    fclose(file);
}

int main() {
    char input[MAX_WORD_LENGTH];
    char output[MAX_WORD_LENGTH];

    int n = 0;
    Word words[MAX_WORDS];
    load_words(words, MAX_WORDS);

    while (1) {
        printf("Enter a word to translate: ");
        scanf("%s", input);

        int i;
        for (i = 0; i < n; i++) {
            if (strcmp(input, words[i].word) == 0) {
                strcpy(output, words[i].translation);
                break;
            }
        }

        if (i == n) {
            printf("No translation found for '%s'\n", input);
        } else {
            printf("Translation for '%s': '%s'\n", input, output);
        }
    }

    return 0;
}
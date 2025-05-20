//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    int translation;
} word_t;

void load_words(word_t *words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %d\n", words[count].word, &words[count].translation) == 2) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Error: too many words in file.\n");
            exit(1);
        }
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    word_t words[MAX_WORDS];
    load_words(words);

    printf("Alien Language Translator\n");

    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a word to translate: ");
        scanf("%s", input);

        int translation = 0;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(input, words[i].word) == 0) {
                translation = words[i].translation;
                break;
            }
        }

        if (translation == 0) {
            printf("Unknown word.\n");
        } else {
            printf("Translation: %d\n", translation);
        }
    }

    return 0;
}
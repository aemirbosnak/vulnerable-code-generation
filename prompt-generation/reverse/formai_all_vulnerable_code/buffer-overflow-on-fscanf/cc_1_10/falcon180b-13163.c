//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} word_t;

void load_words(word_t words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].cat) == 2 && count < MAX_WORDS) {
        count++;
    }

    fclose(file);
}

void translate_sentence(const char *sentence, word_t words[]) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].cat);
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("unknown word: %s\n", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    word_t words[MAX_WORDS];
    load_words(words);

    translate_sentence(argv[1], words);

    return 0;
}
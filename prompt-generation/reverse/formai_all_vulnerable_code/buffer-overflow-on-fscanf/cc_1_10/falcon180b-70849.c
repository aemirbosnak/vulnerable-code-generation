//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct word_t {
    char word[MAX_WORD_LENGTH];
    int count;
} word_t;

void load_words(char *filename, word_t *words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    int num_words = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        words[num_words].word[0] = toupper(word[0]);
        strcpy(words[num_words].word + 1, word + 1);
        words[num_words].count = 1;
        num_words++;
    }

    fclose(file);
}

void translate_sentence(char *sentence, word_t *words) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].word) == 0) {
                printf("%s ", words[i].word);
                words[i].count++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <words_file> <sentence>\n", argv[0]);
        return 1;
    }

    word_t words[MAX_WORDS];
    load_words(argv[1], words);

    char *sentence = argv[2];
    translate_sentence(sentence, words);

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}
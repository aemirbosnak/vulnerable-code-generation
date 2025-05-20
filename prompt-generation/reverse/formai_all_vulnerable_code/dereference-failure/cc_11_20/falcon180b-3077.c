//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct word_t {
    char *english;
    char *alien;
} word_t;

int main() {
    FILE *dict_file;
    char line[100];
    int num_words = 0;
    word_t *words = (word_t*)malloc(MAX_WORDS * sizeof(word_t));

    dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), dict_file)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary is too large.\n");
            exit(1);
        }

        char *english_word = strtok(line, ",");
        char *alien_word = strtok(NULL, ",");

        if (english_word == NULL || alien_word == NULL) {
            printf("Error: invalid line in dictionary file.\n");
            exit(1);
        }

        int english_len = strlen(english_word);
        int alien_len = strlen(alien_word);

        if (english_len > MAX_WORD_LENGTH || alien_len > MAX_WORD_LENGTH) {
            printf("Error: words are too long.\n");
            exit(1);
        }

        words[num_words].english = strdup(english_word);
        words[num_words].alien = strdup(alien_word);
        num_words++;
    }

    fclose(dict_file);

    char *input_line;
    while (fgets(input_line, sizeof(input_line), stdin)!= NULL) {
        char *token = strtok(input_line, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, words[i].english) == 0) {
                    printf("%s ", words[i].alien);
                    break;
                }
            }
            if (i == num_words) {
                printf("%s ", token);
            }
            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    for (int i = 0; i < num_words; i++) {
        free(words[i].english);
        free(words[i].alien);
    }
    free(words);

    return 0;
}
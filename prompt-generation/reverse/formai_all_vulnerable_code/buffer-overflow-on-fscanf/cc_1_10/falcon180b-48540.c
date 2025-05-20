//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct cat_word {
    char *english;
    char *cat;
    int count;
} cat_word_t;

void load_words(cat_word_t *words) {
    FILE *fp = fopen("cat_words.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open cat_words.txt\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(fp, "%s %s\n", words[num_words].english, words[num_words].cat) == 2) {
        num_words++;
        if (num_words >= MAX_WORDS) {
            printf("Error: Too many words in cat_words.txt\n");
            exit(1);
        }
    }

    fclose(fp);
}

int main() {
    cat_word_t words[MAX_WORDS];
    load_words(words);

    char input[MAX_WORD_LENGTH];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        int num_words = 0;
        char *token = strtok(input, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, words[i].english) == 0) {
                    printf("%s ", words[i].cat);
                    words[i].count++;
                    break;
                }
            }

            if (i == num_words) {
                printf("Error: Unknown word '%s'\n", token);
            }

            num_words++;
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many words in input\n");
                break;
            }

            token = strtok(NULL, " ");
        }

        printf("\n");
    }

    return 0;
}
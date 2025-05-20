//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

struct word {
    char english[MAX_WORD_LEN];
    char cat[MAX_WORD_LEN];
};

int main() {
    FILE *fp;
    char line[100];
    struct word words[MAX_WORDS];
    int num_words = 0;

    fp = fopen("english_to_cat.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Too many words in file.\n");
            exit(1);
        }

        char *token = strtok(line, " ");
        strcpy(words[num_words].english, token);

        token = strtok(NULL, " ");
        strcpy(words[num_words].cat, token);

        num_words++;
    }

    fclose(fp);

    char input[MAX_WORD_LEN];
    printf("Enter a sentence in English:\n");
    fgets(input, sizeof(input), stdin);

    char output[MAX_WORD_LEN * 2];
    output[0] = '\0';

    char *token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                strcat(output, words[i].cat);
                strcat(output, " ");
                break;
            }
        }

        if (i == num_words) {
            printf("Unknown word: %s\n", token);
        }

        token = strtok(NULL, " ");
    }

    printf("Translation: %s\n", output);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct {
    char english[MAX_WORD_LEN];
    char cat[MAX_WORD_LEN];
} Word;

int main() {
    char input[MAX_WORD_LEN];
    char output[MAX_WORD_LEN];
    FILE *fp;
    Word words[MAX_WORDS];
    int num_words = 0;

    fp = fopen("english_to_cat.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s", input, output)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Too many words in file.\n");
            exit(1);
        }
        strcpy(words[num_words].english, input);
        strcpy(words[num_words].cat, output);
        num_words++;
    }

    fclose(fp);

    printf("Enter an English sentence to translate into Cat:\n");
    fgets(input, MAX_WORD_LEN, stdin);
    input[strcspn(input, "\n")] = '\0';

    char *token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].cat);
                break;
            }
        }
        if (i == num_words) {
            printf("Unknown word: %s\n", token);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}
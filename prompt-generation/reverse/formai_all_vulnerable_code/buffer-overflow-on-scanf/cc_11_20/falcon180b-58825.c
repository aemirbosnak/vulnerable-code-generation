//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct word {
    char english[MAX_WORD_LEN];
    char alien[MAX_WORD_LEN];
} Word;

int main() {
    FILE *fp;
    char filename[50];
    char line[100];
    int i, j, num_words = 0;
    Word words[MAX_WORDS];

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'.\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in file '%s'.\n", filename);
            exit(1);
        }
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (strlen(token) > MAX_WORD_LEN) {
                printf("Error: word '%s' is too long in file '%s'.\n", token, filename);
                exit(1);
            }
            strcpy(words[num_words].english, token);
            strcpy(words[num_words].alien, "");
            num_words++;
            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(fp);

    printf("Enter the name of the output file: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file '%s'.\n", filename);
        exit(1);
    }

    for (i = 0; i < num_words; i++) {
        for (j = 0; j < MAX_WORD_LEN; j++) {
            if (words[i].alien[j] == '\0') {
                words[i].alien[j] = 'a';
                words[i].alien[j + 1] = '\0';
                break;
            }
        }
    }

    for (i = 0; i < num_words; i++) {
        fprintf(fp, "%s = %s\n", words[i].english, words[i].alien);
    }

    fclose(fp);

    printf("Translation complete.\n");

    return 0;
}
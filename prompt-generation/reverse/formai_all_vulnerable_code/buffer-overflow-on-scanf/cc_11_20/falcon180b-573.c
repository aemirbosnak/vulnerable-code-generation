//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: excited
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

struct word {
    char english[MAX_WORD_LEN];
    char alien[MAX_WORD_LEN];
};

int main() {
    FILE *fp;
    char filename[50];
    char line[100];
    int num_words = 0;
    struct word words[MAX_WORDS];

    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter the name of the file containing the words you want to translate: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *word = strtok(line, ",.?!;:-_\"'");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words in file.\n");
                exit(1);
            }
            strcpy(words[num_words].english, word);
            printf("Please enter the translation for %s: ", word);
            scanf("%s", words[num_words].alien);
            num_words++;
            word = strtok(NULL, ",.?!;:-_\"'");
        }
    }

    fclose(fp);

    printf("\nTranslating...\n");

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *word = strtok(line, ",.?!;:-_\"'");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].english) == 0) {
                    printf("%s ", words[i].alien);
                    break;
                }
            }
            if (i == num_words) {
                printf("%s ", word);
            }
            word = strtok(NULL, ",.?!;:-_\"'");
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}
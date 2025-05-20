//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
};

int main() {
    FILE *fp;
    char filename[50];
    char line[100];
    int num_words = 0;
    struct word *words = (struct word *)malloc(MAX_WORDS * sizeof(struct word));

    printf("Enter the name of the file containing the English words: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }
        if (strlen(line) > MAX_WORD_LENGTH) {
            printf("Word is too long.\n");
            continue;
        }
        strcpy(words[num_words].english, line);
        strcpy(words[num_words].alien, "");
        num_words++;
    }

    fclose(fp);

    printf("Enter the name of the output file: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (int i = 0; i < num_words; i++) {
        printf("Enter the alien translation for %s: ", words[i].english);
        scanf("%s", words[i].alien);
        fprintf(fp, "%s\t%s\n", words[i].english, words[i].alien);
    }

    fclose(fp);

    printf("Translation complete.\n");

    return 0;
}
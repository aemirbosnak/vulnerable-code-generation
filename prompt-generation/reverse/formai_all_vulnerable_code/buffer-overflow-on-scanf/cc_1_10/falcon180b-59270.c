//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
};

int main() {
    int num_words;
    char filename[50];
    FILE *fp;
    struct word words[MAX_WORDS];

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(fp, "%d", &num_words);

    for (int i = 0; i < num_words; i++) {
        fscanf(fp, "%s %s", words[i].english, words[i].cat);
    }

    fclose(fp);

    printf("Enter the name of the output file: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fp, "C Cat Language Translator\n");
    fprintf(fp, "==========================\n\n");

    for (int i = 0; i < num_words; i++) {
        fprintf(fp, "%s = %s\n", words[i].english, words[i].cat);
    }

    fclose(fp);

    printf("Translation completed successfully!\n");

    return 0;
}
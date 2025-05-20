//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} Word;

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read in words
    Word words[MAX_WORDS];
    int num_words = 0;
    while (fscanf(fp, "%s", words[num_words].word)!= EOF) {
        num_words++;
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words.\n");
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);

    // Translate words
    for (int i = 0; i < num_words; i++) {
        printf("Enter translation for %s: ", words[i].word);
        scanf("%s", words[i].translation);
    }

    // Write translations to file
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    for (int i = 0; i < num_words; i++) {
        fprintf(fp, "%s %s\n", words[i].word, words[i].translation);
    }
    fclose(fp);

    printf("Translations saved to %s.\n", filename);
    return 0;
}
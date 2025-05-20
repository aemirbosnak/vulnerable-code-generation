//Code Llama-13B DATASET v1.0 Category: Cat Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char *word;
    char *translation;
} Translation;

Translation *translations;
int num_translations;

void load_translations(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: unable to open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        char *word = strtok(line, " ");
        char *translation = strtok(NULL, "\n");
        translations[num_translations].word = word;
        translations[num_translations].translation = translation;
        num_translations++;
    }

    fclose(fp);
}

void translate(char *input) {
    for (int i = 0; i < num_translations; i++) {
        if (strcmp(input, translations[i].word) == 0) {
            printf("%s\n", translations[i].translation);
            return;
        }
    }

    printf("No translation found for %s\n", input);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    load_translations(argv[1]);

    char input[MAX_LINE_LEN];
    while (fgets(input, MAX_LINE_LEN, stdin) != NULL) {
        translate(input);
    }

    return 0;
}
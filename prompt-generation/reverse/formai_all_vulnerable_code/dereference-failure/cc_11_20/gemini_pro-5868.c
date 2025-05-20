//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 100

char *cat_language_table[] = {
    "meow", "purr", "hiss", "growl", "chirp",
    "mew", "squeak", "trill", "howl", "bark"
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    int num_lines = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        if (num_lines >= MAX_NUM_LINES) {
            fprintf(stderr, "Too many lines in input file\n");
            return EXIT_FAILURE;
        }

        char *translated_line = malloc(strlen(line) + 1);
        if (translated_line == NULL) {
            perror("malloc");
            return EXIT_FAILURE;
        }

        int i = 0;
        while (line[i] != '\0') {
            if (line[i] >= 'a' && line[i] <= 'z') {
                translated_line[i] = cat_language_table[line[i] - 'a'];
            } else if (line[i] >= 'A' && line[i] <= 'Z') {
                translated_line[i] = cat_language_table[line[i] - 'A'];
            } else {
                translated_line[i] = line[i];
            }

            i++;
        }

        translated_line[i] = '\0';

        printf("%s", translated_line);

        free(translated_line);

        num_lines++;
    }

    fclose(fp);

    return EXIT_SUCCESS;
}
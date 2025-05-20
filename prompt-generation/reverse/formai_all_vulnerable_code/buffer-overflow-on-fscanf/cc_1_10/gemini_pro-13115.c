//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024
#define MAX_WORD_LENGTH 128

int main(int argc, char *argv[]) {
    char *filename;
    FILE *file;
    char buffer[MAX_WORD_LENGTH];
    char *words[MAX_WORDS];
    int num_words = 0;
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    filename = argv[1];
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    while (fscanf(file, "%s", buffer) != EOF) {
        if (num_words >= MAX_WORDS) {
            fprintf(stderr, "Too many words in file.\n");
            return EXIT_FAILURE;
        }

        words[num_words] = (char *)malloc(strlen(buffer) + 1);
        if (words[num_words] == NULL) {
            perror("malloc");
            return EXIT_FAILURE;
        }

        strcpy(words[num_words], buffer);
        num_words++;
    }

    fclose(file);

    for (i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }

    for (i = 0; i < num_words; i++) {
        free(words[i]);
    }

    return EXIT_SUCCESS;
}
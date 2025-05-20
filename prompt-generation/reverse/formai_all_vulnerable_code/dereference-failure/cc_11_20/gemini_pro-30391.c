//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the file into a string.
    char *text = malloc(1000000);
    size_t len = fread(text, 1, 1000000, fp);
    fclose(fp);

    // Tokenize the string into words.
    char *words[100000];
    int num_words = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Create a frequency table of the words.
    int frequencies[100000];
    for (int i = 0; i < num_words; i++) {
        frequencies[i] = 0;
    }
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequencies[i]++;
            }
        }
    }

    // Sort the frequency table.
    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (frequencies[i] < frequencies[j]) {
                int temp = frequencies[i];
                frequencies[i] = frequencies[j];
                frequencies[j] = temp;

                char *temp_word = words[i];
                words[i] = words[j];
                words[j] = temp_word;
            }
        }
    }

    // Print the frequency table.
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], frequencies[i]);
    }

    // Free the allocated memory.
    free(text);
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }

    return EXIT_SUCCESS;
}
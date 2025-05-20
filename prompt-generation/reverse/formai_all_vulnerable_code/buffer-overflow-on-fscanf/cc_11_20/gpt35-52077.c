//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

int main(int argc, char *argv[]) {
    FILE *input_file;
    char buffer[MAX_WORD_LENGTH];
    char *words[MAX_WORDS];
    int count[MAX_WORDS] = {0};
    int num_words = 0;
    int i, j, k;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s file_name\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((input_file = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fscanf(input_file, "%s", buffer) != EOF) {
        for (i = 0, j = 0; buffer[i]; i++) {
            if (isalpha(buffer[i])) {
                buffer[j++] = tolower(buffer[i]);
            }
        }
        buffer[j] = '\0';

        for (k = 0; k < num_words; k++) {
            if (strcmp(words[k], buffer) == 0) {
                count[k]++;
                break;
            }
        }

        if (k == num_words) {
            if (num_words == MAX_WORDS) {
                fprintf(stderr, "Too many words in file.\n");
                exit(EXIT_FAILURE);
            }
            words[num_words++] = strdup(buffer);
            count[num_words-1]++;
        }
    }

    printf("Word Frequency Count\n");
    printf("---------------------\n");
    for (i = 0; i < num_words; i++) {
        printf("%-15s %3d\n", words[i], count[i]);
        free(words[i]);
    }

    fclose(input_file);
    exit(EXIT_SUCCESS);
}
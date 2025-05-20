//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define WORDS_TO_REMOVE_COUNT 3

char *words_to_remove[WORDS_TO_REMOVE_COUNT] = {"apple", "banana", "orange"};

void process_line(char line[], FILE *input_file, FILE *output_file) {
    char word[MAX_LINE_LENGTH];
    char *token;
    int i;

    fgets(line, MAX_LINE_LENGTH, input_file);

    token = strtok(line, " \t\n\r,");

    while (token != NULL) {
        for (i = 0; i < WORDS_TO_REMOVE_COUNT; i++) {
            if (strcmp(token, words_to_remove[i]) == 0) {
                int length = strlen(token);
                memmove(token, token + length, strlen(line) + 1 - (length + strlen(token)));
                line[strlen(line) - 1] = '\0';
                break;
            }
        }

        if (token[strlen(token) - 1] == '\n') {
            token[strlen(token) - 1] = '\0';
        }

        fprintf(output_file, "%s ", token);

        token = strtok(NULL, " \t\n\r,");
    }

    if (strlen(line) > 0 && line[strlen(line) - 1] != '\n') {
        fprintf(output_file, "%s\n", line);
    }
}

int main() {
    FILE *input_file;
    FILE *output_file;
    char input_filename[MAX_LINE_LENGTH];
    char output_filename[MAX_LINE_LENGTH];

    printf("Enter input file name: ");
    scanf("%s", input_filename);

    printf("Enter output file name: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");

    if (input_file == NULL) {
        perror("Error opening input file.");
        return EXIT_FAILURE;
    }

    output_file = fopen(output_filename, "w");

    if (output_file == NULL) {
        perror("Error opening output file.");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        process_line(line, input_file, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Processing completed.\n");

    return EXIT_SUCCESS;
}
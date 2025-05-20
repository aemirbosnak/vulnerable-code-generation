//MISTRAL-7B DATASET v1.0 Category: Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS_PER_LINE 100
#define MAX_LENGTH_OF_WORD 50

bool is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

int main() {
    FILE *file;
    char filename[100];
    char line[MAX_WORDS_PER_LINE][MAX_LENGTH_OF_WORD];
    int total_words = 0;
    int words_in_current_line = 0;

    printf("Enter the file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char word[MAX_LENGTH_OF_WORD];
    while (fgets(line[words_in_current_line], MAX_WORDS_PER_LINE * MAX_LENGTH_OF_WORD, file) != NULL) {
        char *token = strtok(line[words_in_current_line], " \t\n");
        while (token != NULL) {
            strcpy(word, token);
            if (strlen(word) > 0) {
                total_words++;
                words_in_current_line++;
                if (words_in_current_line >= MAX_WORDS_PER_LINE) {
                    printf("Line %d contains too many words. Increase MAX_WORDS_PER_LINE.\n", words_in_current_line);
                    break;
                }
            }
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(file);
    printf("Total number of words in the file: %d\n", total_words);

    return EXIT_SUCCESS;
}
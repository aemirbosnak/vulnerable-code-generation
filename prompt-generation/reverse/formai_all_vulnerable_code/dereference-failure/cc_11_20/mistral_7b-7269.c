//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char word[MAX_WORD_LENGTH];
    int count = 0;
    int case_sensitive = 1;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <file> <word> [--insensitive]\n", argv[0]);
        return 1;
    }

    strcpy(word, argv[2]);

    if (argc > 3 && strcmp(argv[3], "--insensitive") == 0) {
        case_sensitive = 0;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        char *token = strtok(buffer, " \t\n\r.,;:!?");

        while (token != NULL) {
            int i;
            int word_length = strlen(token);

            for (i = 0; i < word_length && isalpha(token[i]); i++) {
                if (case_sensitive && strncasecmp(token, word, word_length) == 0) {
                    count++;
                    break;
                }

                token[i] = tolower(token[i]);

                if (strncasecmp(token, word, word_length) == 0) {
                    count++;
                    break;
                }
            }

            token = strtok(NULL, " \t\n\r.,;:!?");
        }
    }

    fclose(file);

    printf("The word '%s' occurs %d times in the file '%s'.\n", word, count, argv[1]);

    return 0;
}
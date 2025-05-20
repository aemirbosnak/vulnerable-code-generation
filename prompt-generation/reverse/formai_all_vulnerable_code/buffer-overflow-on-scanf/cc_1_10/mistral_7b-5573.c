//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define WORD_LENGTH 25

int main() {
    FILE *file;
    char filename[50], line[MAX_LINE_LENGTH], word[WORD_LENGTH];
    int line_number = 1, mystery_count = 0;

    printf("What is the mystery that lies hidden in this text?\n");

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file. Exiting...\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \t\n\r.,;:!");

        while (token != NULL) {
            strcpy(word, token);
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }

            if (strcmp(word, "mystery") == 0) {
                mystery_count++;
                printf("The word 'mystery' was found on line %d.\n", line_number);
                break;
            }

            token = strtok(NULL, " \t\n\r.,;:!");
        }

        line_number++;
    }

    if (mystery_count == 0) {
        printf("What is the mystery that this text holds within its depths?\n");
        printf("Or is it that there is no mystery at all?\n");
    }

    fclose(file);
    return 0;
}
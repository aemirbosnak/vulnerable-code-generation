//FormAI DATASET v1.0 Category: Spell checking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

char *read_file(char *filename) {

    FILE *file = fopen(filename, "r");
    char *file_buffer = malloc(MAX_LENGTH * sizeof(char));
    char *line_buffer = malloc(MAX_LENGTH * sizeof(char));

    if (!file) {
        printf("Error opening file!");
        exit(1);
    }

    while (fgets(line_buffer, MAX_LENGTH, file) != NULL) {
        strcat(file_buffer, line_buffer);
    }

    fclose(file);
    free(line_buffer);

    return file_buffer;
}

void spell_check(char *file_buffer, char *word) {

    int occurences = 0;
    char *token = strtok(file_buffer, " \n\t\r\f");

    while (token != NULL) {

        if (strcmp(token, word) == 0) {
            occurences++;
        }

        token = strtok(NULL, " \n\t\r\f");
    }

    printf("The word \"%s\" was found %d times.\n", word, occurences);
}

int main()
{
    printf("---------------------------\n");
    printf("| C Spell Checking Example |\n");
    printf("---------------------------\n\n");

    printf("Enter the name of the file to spell check: ");
    char filename[MAX_LENGTH];
    scanf("%s", filename);

    printf("Enter the word to check: ");
    char word[MAX_LENGTH];
    scanf("%s", word);

    char *file_buffer = read_file(filename);

    spell_check(file_buffer, word);

    free(file_buffer);

    return 0;
}
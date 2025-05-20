//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_SIZE 1000000
#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[MAX_FILE_SIZE];
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    int char_count = 0;

    if (argc < 2) {
        printf("Error: Please specify a filename\n");
        return 1;
    }

    strcpy(filename, argv[1]);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char_count += strlen(line);

        char *token = strtok(line, ",.!?;:");

        while (token!= NULL) {
            strcpy(word, token);

            if (strlen(word) > 0) {
                word_count++;
            }

            char_count += strlen(word);

            token = strtok(NULL, ",.!?;:");
        }
    }

    printf("Total number of words: %d\n", word_count);
    printf("Total number of characters: %d\n", char_count);

    fclose(file);

    return 0;
}
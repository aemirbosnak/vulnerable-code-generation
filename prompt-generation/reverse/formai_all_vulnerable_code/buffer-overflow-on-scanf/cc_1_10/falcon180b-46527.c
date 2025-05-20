//Falcon-180B DATASET v1.0 Category: File handling ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    int character_count = 0;
    int word_count = 0;
    int sentence_count = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_number++;
        character_count += strlen(line);

        // Remove newline character
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        // Count words
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            word_count++;
            word = strtok(NULL, ",.?!;:");
        }

        // Count sentences
        if (line[len - 1] == '.') {
            sentence_count++;
        }
    }

    printf("Total lines: %d\n", line_number);
    printf("Total characters: %d\n", character_count);
    printf("Total words: %d\n", word_count);
    printf("Total sentences: %d\n", sentence_count);

    fclose(file);
    return 0;
}
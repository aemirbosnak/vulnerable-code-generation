//Falcon-180B DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

int main() {
    FILE *input_file, *output_file;
    char input_filename[MAX_LINE_SIZE], output_filename[MAX_LINE_SIZE];
    int line_count = 0, word_count = 0, char_count = 0;
    char line[MAX_LINE_SIZE];

    printf("Enter input file name: ");
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    printf("Enter output file name: ");
    scanf("%s", output_filename);

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        line_count++;
        char_count += strlen(line);
        word_count += count_words(line);

        fprintf(output_file, "Line %d:\n%s\n", line_count, line);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File processing completed.\n");
    printf("Total lines: %d\n", line_count);
    printf("Total words: %d\n", word_count);
    printf("Total characters: %d\n", char_count);

    return 0;
}

int count_words(char *line) {
    int count = 0;
    char *word = strtok(line, " ");

    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}
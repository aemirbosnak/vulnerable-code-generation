//Falcon-180B DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32

int main() {
    FILE *input_file, *output_file;
    char input_filename[MAX_LINE_LENGTH], output_filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int word_count = 0;

    printf("Enter input file name: ");
    scanf("%s", input_filename);

    printf("Enter output file name: ");
    scanf("%s", output_filename);

    // Open input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Open output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        exit(1);
    }

    // Read input file and count words
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char *token = strtok(line, " \t\r\n\f\v");
        while (token!= NULL) {
            strcpy(word, token);
            word[strcspn(word, "\t\r\n\f\v")] = '\0';
            if (strlen(word) > 0) {
                word_count++;
            }
            token = strtok(NULL, " \t\r\n\f\v");
        }
    }

    // Write word count to output file
    fprintf(output_file, "Word count: %d\n", word_count);

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Text processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

int is_word(char c) {
    return isalpha(c);
}

int main(int argc, char *argv[]) {
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    char input_filename[MAX_LINE_LENGTH];
    char output_filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int word_count = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    output_file = fopen(output_filename, "w");

    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char *p = line;
        char *word = strtok(p, " \t\n\r\f\v,.?!;:");

        while (word!= NULL) {
            if (is_word(*word)) {
                word_count++;
            }

            word = strtok(NULL, " \t\n\r\f\v,.?!;:");
        }
    }

    fprintf(output_file, "Total number of words in the file: %d\n", word_count);

    fclose(input_file);
    fclose(output_file);

    return 0;
}
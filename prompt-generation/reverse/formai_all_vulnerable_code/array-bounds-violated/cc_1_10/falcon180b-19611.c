//Falcon-180B DATASET v1.0 Category: Text processing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input_file[100];
    char output_file[100];
    char line[100];
    FILE *input_ptr, *output_ptr;
    int i, j;
    char *word;
    char *delimiter = " ";
    char *delimiter_list = ",.?!;:";
    char *delimiter_ptr;
    int delimiter_len;

    // Get input and output file names
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open input file
    input_ptr = fopen(input_file, "r");
    if (input_ptr == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    // Open output file
    output_ptr = fopen(output_file, "w");
    if (output_ptr == NULL) {
        printf("Error opening output file!\n");
        exit(1);
    }

    // Read input file line by line
    while (fgets(line, sizeof(line), input_ptr)!= NULL) {
        // Remove leading and trailing spaces
        i = 0;
        while (isspace(line[i])) {
            i++;
        }
        j = strlen(line) - 1;
        while (isspace(line[j])) {
            line[j] = '\0';
            j--;
        }

        // Tokenize line using delimiters
        delimiter_ptr = delimiter_list;
        delimiter_len = strlen(delimiter_list);
        word = strtok(line, delimiter_ptr);
        while (word!= NULL) {
            fprintf(output_ptr, "%s\n", word);
            word = strtok(NULL, delimiter_ptr);
        }
    }

    // Close input and output files
    fclose(input_ptr);
    fclose(output_ptr);

    return 0;
}
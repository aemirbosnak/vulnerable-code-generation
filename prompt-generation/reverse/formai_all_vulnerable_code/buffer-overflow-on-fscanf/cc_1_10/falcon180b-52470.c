//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[MAX_LINE_SIZE] = "", output_filename[MAX_LINE_SIZE] = "";
    int hex_value = 0, decimal_value = 0;
    char hex_string[MAX_LINE_SIZE] = "", decimal_string[MAX_LINE_SIZE] = "";
    int i, j, k;

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fscanf(input_file, "%s", hex_string)!= EOF) {
        for (i = 0; i < strlen(hex_string); i++) {
            if (!isxdigit(hex_string[i])) {
                printf("Error: Invalid hexadecimal character '%c' at position %d.\n", hex_string[i], i + 1);
                exit(1);
            }
        }

        hex_value = strtol(hex_string, NULL, 16);
        sprintf(decimal_string, "%d", hex_value);

        fprintf(output_file, "%s = %s\n", hex_string, decimal_string);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Conversion completed successfully.\n");

    return 0;
}
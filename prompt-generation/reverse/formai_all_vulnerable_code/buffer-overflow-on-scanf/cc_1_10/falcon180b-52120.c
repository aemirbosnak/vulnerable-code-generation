//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUMBER_LENGTH 32

int main() {
    char input_file_name[MAX_LINE_LENGTH];
    char output_file_name[MAX_LINE_LENGTH];
    FILE *input_file;
    FILE *output_file;

    printf("Enter input file name: ");
    scanf("%s", input_file_name);

    printf("Enter output file name: ");
    scanf("%s", output_file_name);

    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char *number_start = line;
        while (*number_start!= '\0' &&!isdigit(*number_start)) {
            number_start++;
        }

        if (*number_start == '\0') {
            fprintf(output_file, "No number found in line.\n");
        } else {
            char number[MAX_NUMBER_LENGTH];
            int number_length = 0;

            while (*number_start!= '\0' && isdigit(*number_start)) {
                number[number_length++] = *number_start;
                number_start++;
            }

            number[number_length] = '\0';

            int decimal_value = atoi(number);
            char binary_value[33];

            sprintf(binary_value, "%032b", decimal_value);

            fprintf(output_file, "Binary value: %s\n", binary_value);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
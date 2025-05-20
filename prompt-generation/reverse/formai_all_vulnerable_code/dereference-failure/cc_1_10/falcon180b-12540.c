//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_INPUT_LENGTH 100
#define MAX_OUTPUT_LENGTH (MAX_INPUT_LENGTH * 8 + 1)

void convert_binary(char* input, char* output) {
    int i, j;
    char binary_table[] = "0123456789ABCDEF";
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isdigit(input[i])) {
            output[j++] = binary_table[input[i] - '0'];
        } else if (isupper(input[i])) {
            output[j++] = binary_table[input[i] - 'A'] + 10;
        } else if (islower(input[i])) {
            output[j++] = binary_table[input[i] - 'a'] + 10;
        } else {
            printf("Invalid input: '%c'\n", input[i]);
            exit(1);
        }
    }
    output[j] = '\0';
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s [input_file] [output_file]\n", argv[0]);
        exit(1);
    }

    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", argv[1]);
        exit(1);
    }

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", argv[2]);
        exit(1);
    }

    char input_buffer[MAX_INPUT_LENGTH];
    char output_buffer[MAX_OUTPUT_LENGTH];

    while (fgets(input_buffer, MAX_INPUT_LENGTH, input_file)!= NULL) {
        convert_binary(input_buffer, output_buffer);
        fprintf(output_file, "%s\n", output_buffer);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
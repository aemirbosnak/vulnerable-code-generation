//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LENGTH 32

int main() {
    FILE *input_file;
    char input_line[MAX_LINE_LENGTH];
    char hex_num[MAX_NUM_LENGTH];
    char ascii_str[MAX_NUM_LENGTH];
    int hex_val;
    int ascii_val;
    int i;

    // Open input file
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read input file line by line
    while (fgets(input_line, MAX_LINE_LENGTH, input_file)!= NULL) {
        // Convert input line to uppercase
        for (i = 0; input_line[i]!= '\0'; i++) {
            input_line[i] = toupper(input_line[i]);
        }

        // Extract hex number from input line
        sscanf(input_line, "0x%s", hex_num);

        // Convert hex number to decimal
        hex_val = strtol(hex_num, NULL, 16);

        // Convert decimal to ASCII character
        ascii_val = hex_val;
        if (ascii_val < 32 || ascii_val > 126) {
            ascii_val = '.';
        }

        // Convert ASCII character to string
        sprintf(ascii_str, "%c", ascii_val);

        // Print results
        printf("Hex: %s\nDecimal: %d\nASCII: %s\n\n", hex_num, hex_val, ascii_str);
    }

    // Close input file
    fclose(input_file);

    return 0;
}
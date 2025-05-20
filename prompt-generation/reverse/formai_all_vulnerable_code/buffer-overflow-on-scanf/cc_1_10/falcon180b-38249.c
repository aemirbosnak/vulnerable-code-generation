//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7
#define HEX_DIGITS "0123456789ABCDEF"
#define BIN_DIGITS "010"
#define DEC_DIGITS "0123456789"

int main() {
    char input_code[MAX_CODE_LENGTH + 1], output_code[MAX_CODE_LENGTH + 1];
    int input_code_length, output_code_length, i, j;
    char *input_ptr, *output_ptr;

    // Prompt the user to enter a color code
    printf("Enter a color code (up to %d characters): ", MAX_CODE_LENGTH);
    scanf("%s", input_code);
    input_code_length = strlen(input_code);

    // Check if the input code is valid
    if (input_code_length!= 3 && input_code_length!= 6) {
        printf("Invalid input code length.\n");
        return 1;
    }

    for (i = 0; i < input_code_length; i++) {
        if (!isxdigit(input_code[i])) {
            printf("Invalid character in input code.\n");
            return 1;
        }
    }

    // Determine the type of input code
    if (input_code_length == 3) {
        output_code_length = 6;
        strcpy(output_code, "#");
    } else {
        output_code_length = 3;
        strcpy(output_code, "");
    }

    // Convert the input code to the output code
    input_ptr = input_code;
    output_ptr = output_code;
    if (input_code_length == 3) {
        for (i = 0; i < 3; i++) {
            *output_ptr++ = *input_ptr++;
        }
        for (i = 0; i < 3; i++) {
            *output_ptr++ = *input_ptr;
        }
    } else {
        for (i = 0; i < 6; i++) {
            *output_ptr++ = *input_ptr;
        }
    }

    // Print the output code
    printf("Output code: %s\n", output_code);

    return 0;
}
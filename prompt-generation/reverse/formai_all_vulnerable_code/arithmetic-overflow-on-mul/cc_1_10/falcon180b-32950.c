//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define MAX_OUTPUT_LENGTH (MAX_INPUT_LENGTH * 8)

void print_binary(char* binary, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", binary[i]);
    }
    printf("\n");
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char binary[MAX_OUTPUT_LENGTH];
    int input_length;

    printf("Enter a binary number: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input_length = strlen(input);

    if (input_length == 0) {
        printf("Error: Empty input.\n");
        return 1;
    }

    int decimal = 0;
    for (int i = 0; i < input_length; i++) {
        char c = tolower(input[i]);
        if (c == '0') {
            decimal = decimal * 2 + 0;
        } else if (c == '1') {
            decimal = decimal * 2 + 1;
        } else {
            printf("Error: Invalid input.\n");
            return 1;
        }
    }

    int binary_length = 0;
    while (decimal > 0) {
        binary[binary_length++] = tolower(decimal % 2 + '0');
        decimal /= 2;
    }

    printf("Binary number: ");
    print_binary(binary, binary_length);

    return 0;
}
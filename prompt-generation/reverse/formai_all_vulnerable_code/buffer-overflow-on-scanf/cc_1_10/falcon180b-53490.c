//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void binary_converter(char* input_string) {
    int length = strlen(input_string);
    int binary_number = 0;
    int base = 1;

    for(int i = length - 1; i >= 0; i--) {
        char current_char = input_string[i];

        if(isdigit(current_char)) {
            int decimal_value = current_char - '0';
            binary_number += decimal_value * base;
        } else {
            switch(current_char) {
                case 'A':
                    binary_number += 10;
                    break;
                case 'B':
                    binary_number += 11;
                    break;
                case 'C':
                    binary_number += 12;
                    break;
                case 'D':
                    binary_number += 13;
                    break;
                case 'E':
                    binary_number += 14;
                    break;
                case 'F':
                    binary_number += 15;
                    break;
            }
        }

        base *= 16;
    }

    printf("Binary equivalent: %d\n", binary_number);
}

int main() {
    char input_string[50];

    printf("Enter a hexadecimal number: ");
    scanf("%s", input_string);

    binary_converter(input_string);

    return 0;
}
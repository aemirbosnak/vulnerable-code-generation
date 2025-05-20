//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

char* binary_to_string(int binary) {
    char* str = (char*) malloc(MAX_LENGTH * sizeof(char));
    int i = 0;
    while (binary > 0) {
        if (binary % 2 == 1) {
            str[i] = '1';
        } else {
            str[i] = '0';
        }
        i++;
        binary /= 2;
    }
    str[i] = '\0';
    return str;
}

int string_to_binary(char* str) {
    int binary = 0;
    int i = 0;
    while (str[i]!= '\0') {
        if (str[i] == '1') {
            binary += 1;
        }
        i++;
    }
    return binary;
}

int main() {
    char* input_str;
    int input_binary;
    char* output_str;
    int output_binary;

    printf("Enter a binary number: ");
    scanf("%s", input_str);
    input_binary = string_to_binary(input_str);

    printf("Enter a decimal number: ");
    scanf("%d", &output_binary);
    output_str = binary_to_string(output_binary);

    printf("Binary equivalent: %s\n", output_str);

    free(input_str);
    free(output_str);

    return 0;
}
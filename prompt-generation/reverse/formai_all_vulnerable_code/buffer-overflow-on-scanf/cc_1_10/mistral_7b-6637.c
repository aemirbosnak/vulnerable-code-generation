//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void binary_string_to_int(char* binary_string, int* number) {
    *number = 0;
    int len = strlen(binary_string);
    for (int i = len - 1; i >= 0; i--) {
        if (binary_string[i] == '1') {
            *number += pow(2, len - i - 1);
        }
    }
}

void int_to_binary_string(int number, char* binary_string) {
    int len = 0;
    char temp[32] = {0};

    while (number > 0) {
        temp[len++] = number % 2 + '0';
        number /= 2;
    }

    if (len == 0) {
        strcpy(binary_string, "0");
        return;
    }

    strncpy(binary_string, &temp[len - 1], len);
}

int main() {
    char binary_string[33] = {0};
    int number = 0;

    printf("Surprise! I'll convert your number to binary for you.\n");
    printf("Enter a number: ");
    scanf("%d", &number);

    int_to_binary_string(number, binary_string);
    printf("The binary representation of %d is: %s\n", number, binary_string);

    printf("\nNow, let me surprise you again! I'll convert your binary number to decimal.\n");
    printf("Enter a binary number: ");
    scanf("%s", binary_string);

    binary_string_to_int(binary_string, &number);
    printf("The decimal representation of %s is: %d\n", binary_string, number);

    return 0;
}
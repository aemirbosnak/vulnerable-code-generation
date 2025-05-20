//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main(int argc, char *argv[]) {
    char input[MAX_SIZE];
    char buffer[MAX_SIZE];
    int i, j, len, bin_len, is_valid = 1;
    long int decimal = 0;

    printf("Welcome to the Exciting Binary Converter!\n");

    printf("Please enter a decimal number (up to %d digits): ", MAX_SIZE - 1);
    fgets(input, MAX_SIZE, stdin);
    len = strlen(input);

    // Remove leading/trailing spaces and newline character
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }

    for (i = 0; i < len; i++) {
        if (!isdigit(input[i])) {
            printf("Invalid input! Please enter a valid decimal number.\n");
            is_valid = 0;
            break;
        }
    }

    if (is_valid) {
        decimal = strtol(input, NULL, 10);

        // Convert decimal to binary
        bin_len = 0;
        do {
            buffer[bin_len++] = (decimal % 2) + '0';
            decimal /= 2;
        } while (decimal > 0);

        // Reverse the binary string
        for (i = 0, j = bin_len - 1; i < j; i++, j--) {
            char temp = buffer[i];
            buffer[i] = buffer[j];
            buffer[j] = temp;
        }

        printf("The binary representation of %ld is: %s\n", decimal, buffer);
    }

    return 0;
}
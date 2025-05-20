//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_SIZE 1000

int main() {
    char input[MAX_NUM_SIZE];
    int i = 0;
    int num_size = 0;
    int bin_size = 0;
    int j = 0;
    int num_sign = 0;
    int is_valid = 0;
    int bin_num = 0;

    printf("Enter a number: ");
    fgets(input, MAX_NUM_SIZE, stdin);

    // Check if input is a valid number
    for (i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            printf("Invalid input!\n");
            return 0;
        }
    }

    // Get the size of the input number
    num_size = strlen(input);

    // Convert input number to binary
    for (i = 0; i < num_size; i++) {
        if (input[i] == '-') {
            num_sign = 1;
        } else {
            bin_num = bin_num * 10 + input[i] - '0';
        }
    }

    // Add leading zeros to binary number
    while (bin_num % 2 == 0) {
        bin_num = bin_num / 2;
        bin_size++;
    }

    // Output the binary number
    printf("Binary number: ");
    for (i = bin_size - 1; i >= 0; i--) {
        printf("%d", bin_num % 2);
        bin_num = bin_num / 2;
    }

    return 0;
}
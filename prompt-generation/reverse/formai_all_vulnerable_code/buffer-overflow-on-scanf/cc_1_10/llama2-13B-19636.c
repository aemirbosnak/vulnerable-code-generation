//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define BINARY_PREFIX "0b"

// Function to convert a number to binary string
void convert_to_binary(int num, char* str) {
    int i, j = 0;

    do {
        str[j++] = (num % 2) ? '1' : '0';
        num /= 2;
    } while (num > 0);

    str[j] = '\0';
}

// Function to convert a binary string to a number
int convert_from_binary(char* str) {
    int num = 0, i = 0;

    while (str[i] != '\0') {
        if (str[i] == '1') {
            num *= 2;
            num += (int)pow(2, i);
        }
        i++;
    }

    return num;
}

int main() {
    char bin[MAX_LENGTH], dec[MAX_LENGTH];
    int num, i, j;

    // Get a number from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Convert the number to binary
    convert_to_binary(num, bin);

    // Print the binary representation
    printf("Binary representation of %d: %s\n", num, bin);

    // Get a binary string from the user
    printf("Enter a binary string: ");
    fgets(bin, MAX_LENGTH, stdin);

    // Convert the binary string to a number
    convert_from_binary(bin);

    // Print the resulting number
    printf("Decimal representation of %s: %d\n", bin, num);

    return 0;
}
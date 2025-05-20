//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_SIZE 1000

// Function to reverse a string
void reverse(char* str, int len) {
    int i = 0;
    int j = len - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to convert decimal to binary
void dec_to_bin(int num, char* bin) {
    int i = 0;

    while (num > 0) {
        bin[i] = num % 2 + '0';
        num /= 2;
        i++;
    }

    reverse(bin, i);
}

int main() {
    int num;
    char bin[MAX_NUM_SIZE];

    // Prompt user for decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    // Convert decimal to binary
    dec_to_bin(num, bin);

    // Output binary number
    printf("The binary equivalent is: %s\n", bin);

    return 0;
}
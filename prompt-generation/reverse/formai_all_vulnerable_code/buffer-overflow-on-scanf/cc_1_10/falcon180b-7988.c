//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_DIGITS 1000
#define MAX_NUM_SIZE (MAX_NUM_DIGITS + 1)

// function to convert decimal to binary
void decimal_to_binary(int decimal, char *binary) {
    int i = 0, j = 0;
    char temp[MAX_NUM_SIZE];

    // initialize binary with leading zeros
    for (i = 0; i < MAX_NUM_SIZE - strlen(binary); i++) {
        strcat(binary, "0");
    }

    // convert decimal to binary
    while (decimal > 0) {
        temp[j] = decimal % 2 + '0';
        decimal /= 2;
        j++;
    }

    // reverse the binary string
    for (i = 0, j = strlen(temp) - 1; i < j; i++, j--) {
        char c = temp[i];
        temp[i] = temp[j];
        temp[j] = c;
    }

    // copy the binary string to the output buffer
    strcpy(binary, temp);
}

int main() {
    int decimal, i;
    char binary[MAX_NUM_SIZE];

    // prompt the user to enter a decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // convert decimal to binary
    decimal_to_binary(decimal, binary);

    // print the binary number
    printf("Binary equivalent: %s\n", binary);

    return 0;
}
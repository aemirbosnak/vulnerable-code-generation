//FormAI DATASET v1.0 Category: Binary Converter ; Style: puzzling
#include <stdio.h>

int main() {
    // banner message
    printf("Welcome to the mysterious Binary Converter!\n");
    printf("Your input shall invoke the unknown powers of the program...\n\n");

    // initialize variables
    int decimal;
    char binary[32] = {0};
    int index = 0;

    // prompt user for input
    printf("Enter a decimal number: ");

    // accept input
    scanf("%d", &decimal);

    // make sure input is valid
    if (decimal < 0) {
        printf("Negative numbers are not supported!\n");

        // exit program
        return 1;
    }

    // convert decimal to binary
    while (decimal > 0) {
        binary[index] = decimal % 2 + '0';
        decimal /= 2;
        index++;
    }

    // reverse binary string
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - 1 - i];
        binary[index - 1 - i] = temp;
    }

    // display binary output
    printf("The binary equivalent is: %s\n", binary);

    // secret message
    printf("\nCongratulations! You have discovered the mysteries of the Binary Converter.\n");
    printf("Keep this knowledge safe...\n");

    // exit program
    return 0;
}
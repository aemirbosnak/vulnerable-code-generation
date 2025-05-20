//FormAI DATASET v1.0 Category: Binary Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// This program is a binary converter with a Cyberpunk theme
// The user can enter a binary number and the program will convert it to decimal

// Function to convert binary to decimal
int binaryToDecimal(long int binaryNum) {

    int decimalNum = 0, power = 1;

    while (binaryNum != 0) {
        int remainder = binaryNum % 10;
        decimalNum += remainder * power;
        power *= 2;
        binaryNum /= 10;
    }

    return decimalNum;
}

int main() {

    printf("\n");
    printf("*****************************************************************\n");
    printf("*                                                               *\n");
    printf("*                      BINARY CONVERTER                          *\n");
    printf("*                                                               *\n");
    printf("*            Enter a binary number to convert to decimal         *\n");
    printf("*                                                               *\n");
    printf("*****************************************************************\n");
    printf("\n");

    // Get user input
    char binaryInput[20];
    printf("Enter a binary number: ");
    scanf("%s", binaryInput);

    // Validate input
    for (int i = 0; i < strlen(binaryInput); i++) {
        if (binaryInput[i] < '0' || binaryInput[i] > '1') {
            printf("\nYou must enter a binary number!\n");
            exit(1);
        }
    }

    // Convert binary to decimal
    int decimalNum = binaryToDecimal(atoi(binaryInput));

    printf("\nThe decimal equivalent of %s is %d.\n", binaryInput, decimalNum);

    return 0;
}
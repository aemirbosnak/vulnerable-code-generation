//FormAI DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decToBin(int n)
{
    // Initialize binary array
    int binary[1000];

    // Counter for binary array
    int i = 0;
    while (n > 0) {
        // Store remainder in binary array
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Print binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);
}

// Function to convert binary to decimal
int binToDec(char binary[])
{
    int decimal = 0;
    int len = strlen(binary);

    // Compute decimal by iterating through binary string
    for (int i = len - 1; i >= 0; i--) {
        int power = len - i - 1;
        decimal += (binary[i] - '0') * (1 << power);
    }

    return decimal;
}

int main()
{
    char input[100];
    int choice;

    printf("Welcome to the Medieval Binary Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("Choice: ");

    // Get user input for choice
    fgets(input, 100, stdin);
    sscanf(input, "%d", &choice);

    // Run selected function based on user input
    if (choice == 1) {
        int decimal;
        printf("\nEnter a decimal number: ");
        fgets(input, 100, stdin);
        sscanf(input, "%d", &decimal);

        printf("\nBinary: ");
        decToBin(decimal);
        printf("\n");
    } else if (choice == 2) {
        char binary[100];
        printf("\nEnter a binary number: ");
        fgets(input, 100, stdin);
        sscanf(input, "%s", binary);

        printf("\nDecimal: %d\n", binToDec(binary));
    } else {
        printf("\nInvalid choice. Please try again.\n");
    }

    return 0;
}
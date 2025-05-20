//Code Llama-13B DATASET v1.0 Category: Binary Converter ; Style: automated
// Binary Converter Program
#include <stdio.h>

// Function to convert binary to decimal
int binToDec(int n)
{
    int dec = 0, i = 0;
    while (n > 0)
    {
        dec += (n % 10) * pow(2, i);
        n /= 10;
        i++;
    }
    return dec;
}

// Function to convert decimal to binary
int decToBin(int n)
{
    int rem, bin = 0;
    while (n > 0)
    {
        rem = n % 2;
        bin = bin * 10 + rem;
        n /= 2;
    }
    return bin;
}

// Main function
int main()
{
    // Declare variables
    int num, choice;

    // Ask user for choice
    printf("Enter 1 to convert binary to decimal and 2 to convert decimal to binary: ");
    scanf("%d", &choice);

    // Check user choice
    if (choice == 1)
    {
        // Ask user for binary number
        printf("Enter a binary number: ");
        scanf("%d", &num);

        // Convert binary to decimal
        int dec = binToDec(num);

        // Print result
        printf("The decimal equivalent of %d is %d\n", num, dec);
    }
    else if (choice == 2)
    {
        // Ask user for decimal number
        printf("Enter a decimal number: ");
        scanf("%d", &num);

        // Convert decimal to binary
        int bin = decToBin(num);

        // Print result
        printf("The binary equivalent of %d is %d\n", num, bin);
    }
    else
    {
        // Print error message
        printf("Invalid choice\n");
    }

    return 0;
}
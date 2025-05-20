//FormAI DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>

// Define a function that converts decimal to binary
int decimalToBinary(int decimal)
{
    int binary = 0, base = 1;

    while (decimal > 0)
    {
        binary += (decimal % 2) * base;
        decimal /= 2;
        base *= 10;
    }

    return binary;
}

// Define a function that converts binary to decimal
int binaryToDecimal(int binary)
{
    int decimal = 0, base = 1;

    while (binary > 0)
    {
        decimal += (binary % 10) * base;
        binary /= 10;
        base *= 2;
    }

    return decimal;
}

// Define the main function
int main()
{
    int option, input, output;

    printf("Welcome to the Binary Converter!\n\n");

    while (1)
    {
        printf("Please select an option:\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &input);
                output = decimalToBinary(input);
                printf("Binary: %d\n\n", output);
                break;

            case 2:
                printf("Enter a binary number: ");
                scanf("%d", &input);
                output = binaryToDecimal(input);
                printf("Decimal: %d\n\n", output);
                break;

            case 3:
                printf("Thank you for using the Binary Converter!\n");
                return 0;

            default:
                printf("Invalid option, please try again.\n\n");
                break;
        }
    }
}
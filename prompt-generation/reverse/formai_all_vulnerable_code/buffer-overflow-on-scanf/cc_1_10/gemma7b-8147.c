//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int decimal, binary;
    char choice;

    printf("Welcome, traveler! You have stumbled upon a humble binary converter.\n");
    printf("Would you like to convert from decimal to binary (D) or from binary to decimal (B)? (D/B): ");
    scanf(" %c", &choice);

    switch (choice)
    {
        case 'D':
            printf("Please enter the decimal number: ");
            scanf(" %d", &decimal);

            binary = decimal;
            while (binary)
            {
                int digit = binary % 2;
                binary /= 2;
                printf("%d ", digit);
            }
            printf("\nYour binary number is: ");
            break;

        case 'B':
            printf("Please enter the binary number: ");
            scanf(" %d", &binary);

            decimal = binary;
            int count = 0;
            while (decimal)
            {
                int digit = decimal % 2;
                decimal /= 2;
                count++;
            }
            printf("\nThe decimal equivalent of your binary number is: ");
            printf("%d", decimal);
            break;

        default:
            printf("Invalid input, traveler. Please try again.\n");
            break;
    }

    return 0;
}
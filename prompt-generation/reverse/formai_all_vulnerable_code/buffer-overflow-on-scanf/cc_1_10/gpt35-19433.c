//FormAI DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal)
{
    int binary[32];
    int i = 0;
    while(decimal > 0)
    {
        binary[i] = decimal % 2;
        decimal = decimal/2;
        i++;
    }
    printf("Binary equivalent is: ");
    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
}

// Function to convert binary to decimal
void binaryToDecimal(int binary)
{
    int decimal = 0;
    int i = 0;
    while(binary > 0)
    {
        int rem = binary % 10;
        decimal = decimal + (rem * pow(2, i));
        binary = binary/10;
        i++;
    }
    printf("Decimal equivalent is: %d", decimal);
}

int main()
{
    int choice;
    int num;
    printf("Welcome to the Binary Converter!\n");
    do
    {
        printf("\nSelect an option:\n");
        printf("1. Decimal to binary\n");
        printf("2. Binary to decimal\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &num);
                decimalToBinary(num);
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%d", &num);
                binaryToDecimal(num);
                break;
            case 3:
                printf("Thank you for using the Binary Converter!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }while(choice != 3);
    return 0;
}
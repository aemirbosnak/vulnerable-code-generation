//FormAI DATASET v1.0 Category: Binary Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// function to convert decimal to binary
void decimalToBinary(int dec)
{
    int binary[32], index = 0;
    
    // loop to convert decimal to binary
    while (dec > 0)
    {
        binary[index++] = dec % 2; // store the remainder
        dec = dec / 2; // update decimal value
    }
    
    // loop to print the binary representation
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
}

// function to convert binary to decimal
void binaryToDecimal(long long bin)
{
    int decimal = 0, base = 1;
    
    // loop to convert binary to decimal
    while (bin > 0)
    {
        int lastDigit = bin % 10; // get the last digit
        bin = bin / 10; // update binary value
        
        // calculate decimal value
        decimal += lastDigit * base;
        base = base * 2;
    }
    
    printf("%d", decimal); // print the decimal representation
}

int main()
{
    int choice, dec;
    long long bin;
    
    // main menu
    printf("Welcome to Binary Converter!\n");
    printf("Choose an option:\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Exit\n");
    
    // loop to handle user input
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                printf("Enter decimal number: ");
                scanf("%d", &dec);
                printf("Binary representation: ");
                decimalToBinary(dec);
                printf("\n");
                break;
            case 2:
                printf("Enter binary number: ");
                scanf("%lld", &bin);
                printf("Decimal representation: ");
                binaryToDecimal(bin);
                printf("\n");
                break;
            case 3:
                printf("Thank you for using Binary Converter.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
        
    } while (choice != 3);
    
    return 0;
}
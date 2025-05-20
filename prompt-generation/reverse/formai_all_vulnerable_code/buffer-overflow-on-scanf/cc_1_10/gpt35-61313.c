//FormAI DATASET v1.0 Category: Binary Converter ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
long long decimalToBinary(int decimalNumber){
    long long binaryNumber = 0;
    int remainder, i = 1;

    while(decimalNumber != 0){
        remainder = decimalNumber % 2;
        decimalNumber /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }

    return binaryNumber;
}

// Function to convert binary to decimal
int binaryToDecimal(long long binaryNumber){
    int decimalNumber = 0, i = 0, remainder;

    while(binaryNumber != 0){
        remainder = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }

    return decimalNumber;
}

// Main function
int main(){
    int choice, decimalNumber;
    long long binaryNumber;
    
    printf("\n\n~~~ Welcome to the Binary Converter ~~~\n\n");
    
    // Displaying the menu
    printf("Menu:\n");
    printf("1. Convert decimal to binary\n");
    printf("2. Convert binary to decimal\n");
    printf("3. Exit\n");
    
    // Loop to keep the program running until the user exits
    do{
        printf("\nEnter your choice (1/2/3): ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("\nEnter the decimal number: ");
                scanf("%d", &decimalNumber);
                binaryNumber = decimalToBinary(decimalNumber);
                printf("\nBinary equivalent of %d is %lld\n", decimalNumber, binaryNumber);
                break;
            case 2:
                printf("\nEnter the binary number: ");
                scanf("%lld", &binaryNumber);
                decimalNumber = binaryToDecimal(binaryNumber);
                printf("\nDecimal equivalent of %lld is %d\n", binaryNumber, decimalNumber);
                break;
            case 3:
                printf("\nThank you for using Binary Converter!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter 1, 2, or 3.\n");
                break;
        }
        
    }while(choice != 3);
    
    return 0;
}
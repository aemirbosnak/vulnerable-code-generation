//FormAI DATASET v1.0 Category: Binary Converter ; Style: high level of detail
// C Binary Converter
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int decimalToBinary(int decimal){
    if(decimal == 0){
        return 0;
    }
    else{
        return (decimal % 2 + 10 * decimalToBinary(decimal / 2));
    }
}

int binaryToDecimal(long long binary){
    int decimal = 0, i = 0, remainder;
    while (binary != 0){
        remainder = binary % 10;
        binary /= 10;
        decimal += remainder * pow(2, i);
        ++i;
    }
    return decimal;
}

int main(){
    int choice;
    system("cls"); //clears the console screen
    
    // display the menu
    printf("\n\n======= Binary Converter =======\n");
    printf("1 - Decimal to Binary\n");
    printf("2 - Binary to Decimal\n");
    printf("3 - Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            {
                int decimal;
                printf("\nEnter decimal number to convert to binary: ");
                scanf("%d", &decimal);
                printf("Binary equivalent of %d is %d\n", decimal, decimalToBinary(decimal));
                break;
            }
        case 2:
            {
                long long binary;
                printf("\nEnter binary number to convert to decimal: ");
                scanf("%lld", &binary);
                printf("Decimal equivalent of %lld is %d\n", binary, binaryToDecimal(binary));
                break;
            }
        case 3:
            {
                printf("\nThanks for using the binary converter!\n");
                return 0;
            }
        default:
            {
                printf("\nInvalid choice. Please try again!\n");
                break;
            }
    }
    main(); //recursive call to display the menu again
    return 0;
}
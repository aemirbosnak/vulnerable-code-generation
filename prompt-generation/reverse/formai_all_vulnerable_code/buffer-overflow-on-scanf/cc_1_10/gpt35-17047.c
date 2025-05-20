//FormAI DATASET v1.0 Category: Binary Converter ; Style: invasive
#include<stdio.h>
#include<string.h>
#include<math.h>

int decimalToBinary(int decimal){
    int binary = 0, rem, base = 1;

    while(decimal > 0){
        rem = decimal % 2;
        binary = binary + (rem * base);
        decimal /= 2;
        base *= 10;
    }

    return binary;
}

int binaryToDecimal(long long binary){
    int decimal = 0, i = 0, rem;

    while(binary != 0){
        rem = binary % 10;
        binary /= 10;
        decimal += rem * pow(2, i);
        ++i;
    }

    return decimal;
}

int main(){

    int choice;
    long long binaryNumber;
    int decimalNumber;

    printf("Welcome to the Binary Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert decimal to binary\n");
    printf("2. Convert binary to decimal\n");

    scanf("%d", &choice);

    switch(choice){

        case 1:
            printf("Enter decimal number: ");
            scanf("%d", &decimalNumber);
            printf("Binary conversion of %d is %d", decimalNumber, decimalToBinary(decimalNumber));
            break;

        case 2:
            printf("Enter binary number: ");
            scanf("%lld", &binaryNumber);
            printf("Decimal conversion of %lld is %d", binaryNumber, binaryToDecimal(binaryNumber));
            break;

        default:
            printf("Invalid choice. Please try again.");
            break;

    }

    return 0;

}
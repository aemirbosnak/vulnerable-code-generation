//FormAI DATASET v1.0 Category: Binary Converter ; Style: portable
#include <stdio.h>
#include <stdbool.h>

bool isBinary(unsigned long long n){
    while(n){
        if(n%10 > 1){
            return false;
        }
        n /= 10;
    }
    return true;
}

long long binaryToDecimal(unsigned long long n) {
    long long decimalNumber = 0, i = 0, remainder;
    while (n != 0) {
        remainder = n % 10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        i++;
    }
    return decimalNumber;
}

unsigned long long decimalToBinary(long long n){
    unsigned long long binaryNumber = 0;
    int remainder, i = 1;
    while(n){
        remainder = n % 2;
        n /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }
    return binaryNumber;
}

int main(){
    int choice;
    unsigned long long n;
    printf("Enter the number you want to convert: ");
    scanf("%lld",&n);
    printf("\n");
    printf("What do you want to do:\n");
    printf("1. Convert Binary to Decimal.\n");
    printf("2. Convert Decimal to Binary.\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    if(choice == 1){
        if(!isBinary(n)){
            printf("Invalid binary number!");
            return 0;
        }
        printf("The decimal number is: %lld", binaryToDecimal(n));
    } else if(choice == 2){
        printf("The binary number is: %lld", decimalToBinary(n));
    } else {
        printf("Invalid input!");
        return 0;
    }
    return 0;
}
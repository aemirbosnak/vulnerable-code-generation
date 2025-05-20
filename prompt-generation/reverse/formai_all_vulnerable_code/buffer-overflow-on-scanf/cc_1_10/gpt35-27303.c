//FormAI DATASET v1.0 Category: Binary Converter ; Style: statistical
#include<stdio.h> 
#include<math.h> 

// Function to convert binary to decimal 
int binaryToDecimal(long long n) 
{ 
    int decimalNumber = 0, i = 0, remainder; 
    while (n!=0) 
    { 
        remainder = n%10; 
        n /= 10; 
        decimalNumber += remainder*pow(2,i); 
        ++i; 
    } 
    return decimalNumber; 
} 

// Function to convert decimal to binary 
long long decimalToBinary(int n) 
{ 
    long long binaryNumber = 0; 
    int remainder, i = 1, step = 1; 
    while (n!=0) 
    { 
        remainder = n%2; 
        n /= 2; 
        binaryNumber += remainder*i; 
        i *= 10; 
    } 
    return binaryNumber; 
} 

// Main function for testing 
int main() 
{ 
    int choice, decimalNumber; 
    long long binaryNumber; 
    printf("Please choose an option:\n"); 
    printf("1. Convert binary to decimal\n"); 
    printf("2. Convert decimal to binary\n"); 
    scanf("%d", &choice); 
    switch(choice) 
    { 
        case 1: 
            printf("Enter a binary number: "); 
            scanf("%lld", &binaryNumber); 
            printf("%lld in binary = %d in decimal", binaryNumber, binaryToDecimal(binaryNumber)); 
            break; 
        case 2: 
            printf("Enter a decimal number: "); 
            scanf("%d", &decimalNumber); 
            printf("%d in decimal = %lld in binary", decimalNumber, decimalToBinary(decimalNumber)); 
            break; 
        default: 
            printf("Invalid choice"); 
    } 
    return 0; 
}
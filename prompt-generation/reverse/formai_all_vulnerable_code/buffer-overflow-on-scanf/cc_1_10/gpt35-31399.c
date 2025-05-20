//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>

// Function to convert decimal to binary
void decToBinary(int num, int bits, int binary[]){
    int i;
    for (i = bits - 1; i >= 0; i--){
        binary[i] = num % 2;
        num = num/2;
    }
}

// Function to print the binary array
void printBinary(int binary[], int bits){
    int i;
    for (i = 0; i < bits; i++)
        printf("%d", binary[i]);
}

int main()
{
    int num1, num2, bitCount, i;
    
    printf("Enter two decimal numbers: ");
    scanf("%d %d", &num1, &num2);
    
    //Count number of bits required to represent the bigger number
    if (num1 > num2) bitCount = sizeof(num1) * 8;
    else bitCount = sizeof(num2) * 8;
    
    int binary1[bitCount], binary2[bitCount], binary3[bitCount];
    decToBinary(num1, bitCount, binary1);
    decToBinary(num2, bitCount, binary2);
    
    printf("\nNumber 1 in binary: ");
    printBinary(binary1, bitCount);
    
    printf("\nNumber 2 in binary: ");
    printBinary(binary2, bitCount);
    
    // Bitwise AND operation
    for(i=0;i<bitCount;i++){
        binary3[i]=binary1[i]&binary2[i];
    }
    printf("\nBitwise AND result: ");
    printBinary(binary3, bitCount);
    
    // Bitwise OR operation
    for(i=0;i<bitCount;i++){
        binary3[i]=binary1[i]|binary2[i];
    }
    printf("\nBitwise OR result: ");
    printBinary(binary3, bitCount);
    
    // Bitwise XOR operation
    for(i=0;i<bitCount;i++){
        binary3[i]=binary1[i]^binary2[i];
    }
    printf("\nBitwise XOR result: ");
    printBinary(binary3, bitCount);
    
    // Bitwise NOT operation
    printf("\nBitwise NOT of Number 1: ");
    for(i=0;i<bitCount;i++){
        binary3[i]=!binary1[i];
    }
    printBinary(binary3, bitCount);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert decimal to binary
char* decimalToBinary(int decimal){
    int i, j;
    char* binary = (char*) malloc( sizeof(char) * 8 );

    // convert decimal to binary
    for(i=7; i>=0; i--){
        j = decimal >> i;
        binary[7-i] = (j & 1) ? '1' : '0';
    }
    return binary;
}

// function to convert binary to decimal
int binaryToDecimal(char* binary){
    int decimal, i;

    // convert binary to decimal
    decimal = 0;
    for(i=0; i<8; i++){
        if(binary[i] == '1')
            decimal += 1 << (7-i);
    }
    return decimal;
}

int main(){
    // initialize variables
    int decimal;
    char binary[9];
    memset(binary, 0, sizeof(binary));

    // get input from user
    printf("Enter an integer (0-255) to convert to binary: ");
    scanf("%d", &decimal);

    // convert decimal to binary and print result
    printf("\nDecimal %d is equivalent to binary %s\n", decimal, decimalToBinary(decimal));

    // get input from user
    printf("\nEnter a binary number (8 bits) to convert to decimal: ");
    scanf("%s", binary);

    // convert binary to decimal and print result
    printf("\nBinary %s is equivalent to decimal %d\n", binary, binaryToDecimal(binary));

    return 0;
}
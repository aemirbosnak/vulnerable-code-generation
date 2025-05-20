//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void decToBinary(int n, char *binaryRep) {
    // This function converts a decimal number to binary
    int index = 0;
    if (n == 0) {
        binaryRep[index++] = '0'; 
    } else {
        while(n > 0) {
            binaryRep[index++] = (n % 2) + '0'; // Get remainder as char
            n /= 2; // Shift right by 1 (divide by 2)
        }
    }
    
    binaryRep[index] = '\0'; // Null-terminate string
    // Reverse the string to get the correct binary representation
    for(int i = 0; i < index / 2; i++) {
        char temp = binaryRep[i];
        binaryRep[i] = binaryRep[index - i - 1];
        binaryRep[index - i - 1] = temp;
    }
}

void displayBinary(char *binaryRep) {
    // Shockingly, this function will display the binary representation
    printf("Oh my goodness! The binary representation is: %s\n", binaryRep);
}

void getDecimalNumber(int *num) {
    printf("Enter a decimal number to convert (positive integer): ");
    scanf("%d", num);

    if (*num < 0) {
        printf("Whoa! That's not a valid number! Let's stick to positive integers.\n");
        exit(1);
    }
}

int main() {
    int decimalNumber;
    char binaryRepresentation[65]; // 64 bits + 1 for null terminator
    memset(binaryRepresentation, 0, sizeof(binaryRepresentation)); // Initialize

    // Where the magic begins
    printf("Be prepared! You are about to witness the conversion from Decimal to Binary!\n");
    
    getDecimalNumber(&decimalNumber);
    
    // This could be a crazy ride!
    printf("Hold on! Converting %d to binary...\n", decimalNumber);
    
    decToBinary(decimalNumber, binaryRepresentation);
    
    // Let's shock the world with this binary output
    displayBinary(binaryRepresentation);
    
    printf("Conversion complete! Wasn't that something?!!\n");
    printf("Thank you for witnessing this binary transformation!\n");
    
    return 0;
}
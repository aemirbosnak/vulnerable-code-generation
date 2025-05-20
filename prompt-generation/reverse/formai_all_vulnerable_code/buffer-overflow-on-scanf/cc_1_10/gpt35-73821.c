//FormAI DATASET v1.0 Category: Binary Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the binary number
#define MAX_SIZE 1000

// Many different shape-shifting forms
typedef struct {
    int id;
    char symbol;
} Transformation;

Transformation transformations[] = {
    {0, 'A'},
    {1, 'B'},
    {2, 'C'},
    {3, 'D'},
    {4, 'E'},
    {5, 'F'},
    {6, 'G'},
    {7, 'H'},
    {8, 'I'},
    {9, 'J'},
    {10, 'K'},
    {11, 'L'},
    {12, 'M'},
    {13, 'N'},
    {14, 'O'},
    {15, 'P'}
};

// Function to transform decimal to binary using shift shape-shifting
void decimalToBinaryShift(int decimalNumber) {
    int binaryNumber[MAX_SIZE], i = 0;
    while (decimalNumber > 0) {
        binaryNumber[i] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        i++;
    }
    printf("Binary Number (Shift Shape-Shifting): ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNumber[j]);
        if (j % 4 == 0) {
            printf(" ");
        }
    }
}

// Function to transform decimal to binary using letter shape-shifting
void decimalToBinaryLetter(int decimalNumber) {
    char binaryNumber[MAX_SIZE], binaryNumberWithLetters[MAX_SIZE];
    int i = 0;
    while (decimalNumber > 0) {
        binaryNumber[i] = decimalNumber % 2 + '0';
        decimalNumber = decimalNumber / 2;
        i++;
    }
    int j = 0;
    // Loop through each binary digit
    for (int k = i - 1; k >= 0; k--) {
        binaryNumberWithLetters[j] = transformations[binaryNumber[k] - '0'].symbol;
        j++;
    }
    printf("\nBinary Number (Letter Shape-Shifting): ");
    for (int k = j - 1; k >= 0; k--) {
        printf("%c", binaryNumberWithLetters[k]);
    }
}

// Main function to convert decimal to binary
int main() {
    int decimalNumber;
    printf("Enter Decimal Number: ");
    scanf("%d", &decimalNumber);
    decimalToBinaryShift(decimalNumber);
    decimalToBinaryLetter(decimalNumber);
    printf("\n");
    return 0;
}
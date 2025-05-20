//FormAI DATASET v1.0 Category: Binary Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binToDec(char[]); // Function to convert binary to decimal
void decToBin(int); // Function to convert decimal to binary

int main() {
    char binary[32];
    int decimal;

    printf("Please enter a binary number to convert to decimal: ");
    scanf("%s", binary);

    decimal = binToDec(binary);
    printf("The decimal equivalent of %s is: %d\n", binary, decimal);

    printf("\nNow, let's convert a decimal number to binary!\n");
    printf("Please enter a decimal number: ");
    scanf("%d", &decimal);

    decToBin(decimal);

    return 0;
}

// Function to convert binary to decimal
int binToDec(char binary[]) {
    int decimal = 0;
    int i, j, len;

    len = strlen(binary);

    for(i = 0, j = len-1; i < len; i++, j--) {
        if(binary[i] == '1') {
            decimal += (int)pow(2, j);
        }
    }

    return decimal;
}

// Function to convert decimal to binary
void decToBin(int decimal) {
    int binary[32];
    int i = 0, j;

    while(decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    printf("The binary equivalent is: ");

    for(j = i-1; j >= 0; j--) {
        printf("%d", binary[j]);
    }

    printf("\n");
}
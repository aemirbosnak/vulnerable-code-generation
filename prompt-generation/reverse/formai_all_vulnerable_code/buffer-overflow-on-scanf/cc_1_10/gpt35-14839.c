//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: mind-bending
#include <stdio.h>

// Function that returns the binary representation of a decimal number
int* decimalToBinary(int decimal, int* binary) {
    int i = 0;
    while(decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }
    return binary;
}

// Function that converts the binary representation to a hexadecimal string
char* binaryToHex(int* binary, char* hex) {
    int i, j, decimal;
    for(i = 0; i < 16; i += 4) {
        decimal = 0;
        for(j = i; j < i + 4; j++) {
            decimal += binary[j] * (1 << (j - i));
        }
        hex[i / 4] = decimal < 10 ? decimal + '0' : decimal - 10 + 'A';
    }
    hex[4] = '\0';
    return hex;
}

int main() {
    // Take decimal input from user
    int decimal;
    printf("Enter a decimal number between 0 and 65535: ");
    scanf("%d", &decimal);
    
    // Check if input is valid
    if(decimal < 0 || decimal > 65535) {
        printf("Invalid input!");
        return 0;
    }
    
    // Convert decimal to binary
    int binary[16] = {0};
    decimalToBinary(decimal, binary);
    
    // Convert binary to hexadecimal string
    char hex[5] = {0};
    binaryToHex(binary, hex);
    
    // Print the result
    printf("The hexadecimal representation of %d is %s", decimal, hex);
    
    return 0;
}
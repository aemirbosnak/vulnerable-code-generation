//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hexToDec(char *hex);  // Function to convert hex to decimal
void decToHex(int dec);    // Function to convert decimal to hex

int main() {

    char hexNum[100];   // String to store hex number
    
    printf("Enter a hexadecimal number: ");
    scanf("%s", hexNum);
    
    hexToDec(hexNum);   // Call function to convert hex to decimal
    
    int decNum;
    printf("\nEnter a decimal number: ");
    scanf("%d", &decNum);
    
    decToHex(decNum);   // Call function to convert decimal to hex
    
    return 0;
}

void hexToDec(char *hex) {
    
    int length = strlen(hex);   // Get length of hex string
    int dec = 0;                // Variable to store decimal equivalent
    
    for(int i = 0; i < length; i++) {
        int digit;
        if(hex[i] >= 48 && hex[i] <= 57) {
            digit = hex[i] - 48;
        } else if(hex[i] >= 65 && hex[i] <= 70) {
            digit = hex[i] - 55;
        } else if(hex[i] >= 97 && hex[i] <= 102) {
            digit = hex[i] - 87;
        }
        dec += digit * pow(16, length - i - 1);  // Convert each digit to decimal and add up
    }
    
    printf("Decimal equivalent of %s is %d\n", hex, dec);
}

void decToHex(int dec) {
    
    char hex[100];    // String to store hex number
    int i = 0;        // Index for hex string
    
    while(dec > 0) {
        int remainder = dec % 16;
        if(remainder < 10) {
            hex[i] = remainder + 48;     // Convert remainder to hex character
        } else {
            hex[i] = remainder + 55;
        }
        dec /= 16;   // Divide decimal by 16 to get next digit
        i++;
    }
    
    printf("Hexadecimal equivalent of %d is ", dec);
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);     // Print hex number digit by digit in reverse order
    }
    printf("\n");
}
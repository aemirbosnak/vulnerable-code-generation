//FormAI DATASET v1.0 Category: Binary Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// function to convert binary to decimal
int binaryToDecimal(char *binaryString, int length) {
    int decimal = 0;
    int power = 0;
    for(int i = length-1; i >= 0; i--) {
        if(binaryString[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

// function to convert decimal to binary
void decimalToBinary(int decimal, char* binaryString) {
    int index = 0;
    while(decimal > 0) {
        int remainder = decimal % 2;
        binaryString[index++] = (remainder == 0) ? '0' : '1';
        decimal /= 2;
    }
    // reverse the binaryString
    for(int i = 0, j = strlen(binaryString)-1; i < j; i++, j--) {
        char temp = binaryString[i];
        binaryString[i] = binaryString[j];
        binaryString[j] = temp;
    }
}

int main() {
    // input decimal or binary
    int choice;
    printf("Enter 1 to convert Binary to Decimal\n");
    printf("Enter 2 to convert Decimal to Binary\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: {
            // input binary string
            char binaryString[64];
            printf("Enter binary string: ");
            scanf("%s", binaryString);
            int length = strlen(binaryString);
            // check if input string is valid binary string
            for(int i = 0; i < length; i++) {
                if(binaryString[i] != '0' && binaryString[i] != '1') {
                    printf("Invalid binary string\n");
                    return 1;
                }
            }
            // convert binary to decimal
            int decimal = binaryToDecimal(binaryString, length);
            printf("Decimal equivalent: %d\n", decimal);
            break;
        }
        case 2: {
            // input decimal number
            int decimal;
            printf("Enter decimal number: ");
            scanf("%d", &decimal);
            // convert decimal to binary
            char binaryString[64];
            memset(binaryString, 0, sizeof(binaryString));
            decimalToBinary(decimal, binaryString);
            printf("Binary equivalent: %s\n", binaryString);
            break;
        }
        default: {
            printf("Invalid choice\n");
            return 1;
        }
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define max length of hexadecimal and binary numbers
#define MAX_HEX_LENGTH 10
#define MAX_BINARY_LENGTH 32

// Function to convert hexadecimal string to binary string
char* hexToBin(char* hexString) {
    int i = 0;
    int len = strlen(hexString);
    char* binString = malloc(MAX_BINARY_LENGTH * sizeof(char));
    for(i = 0; i < len; i++) {
        switch(hexString[i]) {
            case '0': strcat(binString, "0000"); break;
            case '1': strcat(binString, "0001"); break;
            case '2': strcat(binString, "0010"); break;
            case '3': strcat(binString, "0011"); break;
            case '4': strcat(binString, "0100"); break;
            case '5': strcat(binString, "0101"); break;
            case '6': strcat(binString, "0110"); break;
            case '7': strcat(binString, "0111"); break;
            case '8': strcat(binString, "1000"); break;
            case '9': strcat(binString, "1001"); break;
            case 'A': strcat(binString, "1010"); break;
            case 'B': strcat(binString, "1011"); break;
            case 'C': strcat(binString, "1100"); break;
            case 'D': strcat(binString, "1101"); break;
            case 'E': strcat(binString, "1110"); break;
            case 'F': strcat(binString, "1111"); break;
            default:  strcat(binString, ""); break;
        }
    }
    return binString;
}

// Function to convert binary string to hexadecimal string
char* binToHex(char* binString) {
    int i = 0;
    int j = 0;
    int len = strlen(binString);
    int hexLength = len / 4;
    char* hexString = malloc(MAX_HEX_LENGTH * sizeof(char));
    for(i = 0; i < hexLength; i++) {
        int value = 0;
        for(j = 0; j < 4; j++) {
            if(binString[i*4+j] == '1') {
                value += (1 << (3-j));
            }
        }
        switch(value) {
            case 0:  strcat(hexString, "0"); break;
            case 1:  strcat(hexString, "1"); break;
            case 2:  strcat(hexString, "2"); break;
            case 3:  strcat(hexString, "3"); break;
            case 4:  strcat(hexString, "4"); break;
            case 5:  strcat(hexString, "5"); break;
            case 6:  strcat(hexString, "6"); break;
            case 7:  strcat(hexString, "7"); break;
            case 8:  strcat(hexString, "8"); break;
            case 9:  strcat(hexString, "9"); break;
            case 10: strcat(hexString, "A"); break;
            case 11: strcat(hexString, "B"); break;
            case 12: strcat(hexString, "C"); break;
            case 13: strcat(hexString, "D"); break;
            case 14: strcat(hexString, "E"); break;
            case 15: strcat(hexString, "F"); break;
            default: strcat(hexString, ""); break;
        }
    }
    return hexString;
}

// Main function to convert hexadecimal to binary and vice versa
int main() {
    printf("Welcome to the C Hexadecimal Converter!\n");
    printf("Enter '1' to convert hexadecimal to binary or '2' to convert binary to hexadecimal: ");
    int choice = 0;
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter a hexadecimal number: ");
        char* hexInput = malloc(MAX_HEX_LENGTH * sizeof(char));
        scanf("%s", hexInput);
        char* binOutput = hexToBin(hexInput);
        printf("The binary representation of %s is %s\n", hexInput, binOutput);
        free(hexInput);
        free(binOutput);
    }
    else if(choice == 2) {
        printf("Enter a binary number: ");
        char* binInput = malloc(MAX_BINARY_LENGTH * sizeof(char));
        scanf("%s", binInput);
        char* hexOutput = binToHex(binInput);
        printf("The hexadecimal representation of %s is %s\n", binInput, hexOutput);
        free(binInput);
        free(hexOutput);
    }
    else {
        printf("Invalid choice. Please try again.\n");
    }

    printf("Thank you for using the C Hexadecimal Converter!\n");
    return 0;
}
//FormAI DATASET v1.0 Category: QR code reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if the given string is a valid QR code
bool isValidQRCode(char *str) {
    // Check for required prefix and suffix
    if (str[0] != 'Q' || str[1] != 'R' || str[2] != ':' || str[strlen(str)-1] != '!') {
        return false; // Invalid QR code
    }
    
    // Check for valid data
    int i = 3;
    while (i < strlen(str)-1) {
        if (str[i] == '0' || str[i] == '1') {
            i++;
        } else {
            return false; // Invalid QR code
        }
    }
    
    return true; // Valid QR code
}

// Function to convert QR code data into binary
int convertToBinary(char *str, int length, char *binary) {
    // Loop through data and convert each bit to binary
    int index = 0;
    for (int i=3; i<length-1; i++) {
        if (str[i] == '0') {
            binary[index] = '0';
            binary[index+1] = '0';
        } else {
            binary[index] = '1';
            binary[index+1] = '0';
        }
        index += 2;
    }
    
    // Return length of binary data
    return length - 4;
}

// Function to process QR code data
void processQRCode(char *str) {
    // Convert data to binary
    int length = strlen(str);
    char binary[length*2];
    int binaryLength = convertToBinary(str, length, binary);
    
    // Print binary data
    printf("Binary data:\n");
    for (int i=0; i<binaryLength*2; i++) {
        printf("%c", binary[i]);
    }
    printf("\n");
    
    // Print ASCII data
    printf("ASCII data:\n");
    for (int i=0; i<binaryLength; i++) {
        int asciiCode = 0;
        for (int j=0; j<8; j++) {
            asciiCode += (binary[i*8+j]-'0') * (1<<7-j);
        }
        printf("%c", asciiCode);
    }
    printf("\n");
}

int main() {
    // Get input from user
    printf("Enter QR code: ");
    char str[100];
    fgets(str, 100, stdin);
    
    // Remove newline character from input
    if (str[strlen(str)-1] == '\n') {
        str[strlen(str)-1] = '\0';
    }
    
    // Check if input is valid QR code
    if (!isValidQRCode(str)) {
        printf("Invalid QR code\n");
        exit(0);
    }
    
    // Process QR code data
    processQRCode(str);
    
    return 0;
}
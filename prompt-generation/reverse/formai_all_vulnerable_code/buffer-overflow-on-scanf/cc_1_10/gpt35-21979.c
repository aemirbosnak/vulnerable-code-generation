//FormAI DATASET v1.0 Category: QR code reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_CODE_LENGTH 1000

bool isQRCodeValid(char *qrCode) {
    // Check if the string contains only valid characters
    int i;
    for(i = 0; qrCode[i] != '\0'; i++) {
        if(qrCode[i] != '1' && qrCode[i] != '0') {
            return false;
        }
    }
    
    // Check if the length of the string is valid
    if(i != 256 && i != 512 && i != 768 && i != 1000) {
        return false;
    }
    
    return true;
}

int readQRCode() {
    char qrCode[MAX_QR_CODE_LENGTH];
    printf("Scan QR code: ");
    fgets(qrCode, MAX_QR_CODE_LENGTH, stdin);
    qrCode[strcspn(qrCode, "\n")] = '\0'; // Remove trailing newline character
    
    if(!isQRCodeValid(qrCode)) {
        printf("Invalid QR code\n");
        return -1;
    }
    
    int codeValue = 0;
    int i, j;
    for(i = 0; qrCode[i] != '\0'; i += 8) {
        // Convert 8 characters at a time to binary and then to decimal
        char binary[9];
        strncpy(binary, qrCode + i, 8);
        binary[8] = '\0';
        int decimal = strtol(binary, NULL, 2);
        
        // Combine the decimal values to get the code value
        for(j = 0; j < 8; j++) {
            codeValue += (decimal >> j & 1) << i + j;
        }
    }
    
    return codeValue;
}

int main() {
    printf("Welcome to the QR code reader!\n");
    
    while(true) {
        int codeValue = readQRCode();
        
        if(codeValue != -1) {
            printf("QR code value: %d\n", codeValue);
        }
        
        // Ask the user if they want to scan another QR code
        printf("Do you want to scan another QR code? (y/n): ");
        char answer;
        scanf("%c", &answer);
        getchar(); // Remove trailing newline character
        
        if(answer == 'n') {
            break;
        }
    }
    
    return 0;
}
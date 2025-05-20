//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_QRCODE_SIZE 100

// Function to check if a string is a valid QR code
int isValidQRCode(char* str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            count++;
        }
    }
    return count >= 3;
}

// Function to read a QR code
int readQRCode(char* str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            count++;
        }
    }
    if (count < 3) {
        printf("Invalid QR code. ");
        return 0;
    }
    printf("QR code read successfully. ");
    return 1;
}

// Function to print a QR code
void printQRCode(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        printf("%c ", str[i]);
    }
}

int main() {
    char qrcode[MAX_QRCODE_SIZE];
    printf("Enter a QR code: ");
    scanf("%s", qrcode);
    if (isValidQRCode(qrcode)) {
        readQRCode(qrcode);
        printQRCode(qrcode);
    }
    return 0;
}
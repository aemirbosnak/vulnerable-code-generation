//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to check if a character is a valid QR code character
bool isQRChar(char c) {
    return isalnum(c) || c == '/' || c == '+' || c == '%';
}

// Function to parse a QR code string and return the decoded data
char* decodeQR(char* qrStr) {
    int len = strlen(qrStr);
    char* data = malloc(len * 3 + 1);
    int idx = 0;
    for (int i = 0; i < len; i++) {
        if (qrStr[i] == '/') {
            data[idx++] = '0';
        } else if (qrStr[i] == '+') {
            data[idx++] = '1';
        } else if (qrStr[i] == '%') {
            data[idx++] = '2';
        } else {
            data[idx++] = qrStr[i];
        }
    }
    data[idx] = '\0';
    return data;
}

// Function to print a QR code in a medieval style
void printQR(char* qrStr) {
    printf("+---+");
    for (int i = 0; i < strlen(qrStr); i++) {
        if (qrStr[i] == '/') {
            printf("|   |");
        } else if (qrStr[i] == '+') {
            printf("|  |");
        } else if (qrStr[i] == '%') {
            printf("| _|");
        } else {
            printf("|%c|", qrStr[i]);
        }
    }
    printf("+---+\n");
}

// Main function to read a QR code from the user and print the decoded data
int main() {
    char qrStr[1000];
    printf("Enter a QR code: ");
    scanf("%s", qrStr);
    if (isQRChar(qrStr[0]) && strlen(qrStr) >= 10) {
        char* data = decodeQR(qrStr);
        printf("Decoded data: %s\n", data);
        free(data);
    } else {
        printf("Invalid QR code.\n");
    }
    return 0;
}
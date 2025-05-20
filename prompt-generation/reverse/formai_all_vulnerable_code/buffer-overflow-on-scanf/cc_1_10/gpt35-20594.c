//FormAI DATASET v1.0 Category: QR code reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum length of a QR code
#define MAX_QR_CODE_LENGTH 100

// Function to check if a string contains only digits
bool isNumber(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

// Function to read a QR code from user input
char* readQRCode() {
    char *qrCode = calloc(MAX_QR_CODE_LENGTH, sizeof(char));
    printf("Enter the QR code: ");
    scanf("%s", qrCode);
    return qrCode;
}

// Function to decode a QR code and extract the data
void decodeQRCode(char *qrCode) {
    char *token;
    char *delim = ",";
    char *data[3];
    int count = 0;
    
    // Parse the QR code and extract the data
    token = strtok(qrCode, delim);
    while (token != NULL) {
        data[count++] = token;
        token = strtok(NULL, delim);
    }
    
    // Check if the data is valid (has three fields, all numeric)
    if (count == 3 && isNumber(data[0]) && isNumber(data[1]) && isNumber(data[2])) {
        printf("QR code decoded successfully!\n");
        printf("Data: ID %s, Quantity %s, Price %s\n", data[0], data[1], data[2]);
    } else {
        printf("QR code is invalid or corrupted.\n");
    }
}

int main() {
    char *qrCode = readQRCode();
    decodeQRCode(qrCode);
    free(qrCode);
    return 0;
}
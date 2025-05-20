//FormAI DATASET v1.0 Category: QR code reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Functions for parsing and checking validity of QR code */

/* Check if given QR code is valid */
bool isValidQR(char qrCode[]) {
    int qrLength = strlen(qrCode);
    if (qrLength != 25) {
        return false;
    }
    for (int i = 0; i < qrLength; i++) {
        if ((qrCode[i] < '0' || qrCode[i] > '9') && (qrCode[i] < 'A' || qrCode[i] > 'Z')) {
            return false;
        }
    }
    return true;
}

/* Parse the QR code and get the name of the product */
void parseQR(char qrCode[], char *productName) {
    /* Assuming the name of the product is between the first and last '-' in the QR code */
    int firstIndex = -1, lastIndex = -1;
    int qrLength = strlen(qrCode);
    for (int i = 0; i < qrLength; i++) {
        if (qrCode[i] == '-') {
            if (firstIndex == -1) {
                firstIndex = i;
            } else {
                lastIndex = i;
            }
        }
    }
    if (firstIndex != -1 && lastIndex != -1) {
        memcpy(productName, qrCode + firstIndex + 1, lastIndex - firstIndex - 1);
    }
}

/* Main function for scanning QR code */
void scanQRCode() {
    char qrCode[25];
    char productName[20];
    printf("Please scan the QR code:\n");
    scanf("%s", qrCode);
    while (!isValidQR(qrCode)) {
        printf("Invalid QR code. Please try again.\n");
        scanf("%s", qrCode);
    }
    parseQR(qrCode, productName);
    printf("Scanned product: %s\n", productName);
}

/* Driver function to test QR code scanner */
int main() {
    printf("Welcome to QR code scanner!\n");
    while (true) {
        scanQRCode();
        char choice;
        printf("\nDo you want to scan another QR code? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }
    printf("Thank you for using QR code scanner!\n");
    return 0;
}
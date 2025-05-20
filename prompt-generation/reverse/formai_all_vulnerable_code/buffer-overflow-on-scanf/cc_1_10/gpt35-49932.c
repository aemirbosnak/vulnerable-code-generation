//FormAI DATASET v1.0 Category: QR code reader ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_QR_CODE_SIZE 500

// QR Code Data Structure
typedef struct {
    int size;
    char data[MAX_QR_CODE_SIZE];
} QRCode;

// Function to get QR code from input
QRCode getQRCode() {
    QRCode qrCode;
    printf("Enter QR Code: ");
    scanf("%s", qrCode.data);
    qrCode.size = strlen(qrCode.data);
    return qrCode;
}

// Function to check if QR code is valid
bool isValidQRCode(QRCode qrCode) {
    // Check if size is valid
    if (qrCode.size != 25) {
        return false;
    }

    // Check if data starts with "https://"
    char prefix[] = "https://";
    if (strncmp(qrCode.data, prefix, strlen(prefix)) != 0) {
        return false;
    }
    
    // Check if data ends with ".com"
    char suffix[] = ".com";
    if (strncmp(qrCode.data + qrCode.size - strlen(suffix), suffix, strlen(suffix)) != 0) {
        return false;
    }

    return true;
}

// Main function
int main() {
    QRCode qrCode = getQRCode();

    if (isValidQRCode(qrCode)) {
        printf("QR Code is valid!\n");

        // Extract domain from data
        char domain[MAX_QR_CODE_SIZE];
        int domainStart = strlen("https://");
        int domainEnd = qrCode.size - strlen(".com");
        strncpy(domain, qrCode.data + domainStart, domainEnd - domainStart);
        domain[domainEnd - domainStart] = '\0';

        printf("Domain: %s\n", domain);
    } else {
        printf("Invalid QR Code!\n");
    }

    return 0;
}
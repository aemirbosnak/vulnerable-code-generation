//FormAI DATASET v1.0 Category: QR code reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct qrCode {
    char versionInfo[10];
    char dataBytes[256];
    int dataLength;
    char errorCorrectionCode[60];
    bool hasAlphanumericData;
} QRCode;

void readQRCode(QRCode *qr) {
    // Read in version info
    printf("Enter version info: ");
    fgets(qr->versionInfo, 10, stdin);
    qr->versionInfo[strcspn(qr->versionInfo, "\n")] = 0;
    
    // Read in data bytes
    printf("Enter data bytes: ");
    fgets(qr->dataBytes, 256, stdin);
    qr->dataBytes[strcspn(qr->dataBytes, "\n")] = 0;
    qr->dataLength = strlen(qr->dataBytes);
    
    // Read in error correction code
    printf("Enter error correction code: ");
    fgets(qr->errorCorrectionCode, 60, stdin);
    qr->errorCorrectionCode[strcspn(qr->errorCorrectionCode, "\n")] = 0;
    
    // Check if data contains alphanumeric characters
    char *p = qr->dataBytes;
    while (*p) {
        if ((*p >= '0' && *p <= '9') || (*p >= 'A' && *p <= 'Z') || (*p == ' ') || (*p == '$') || (*p == '%') || (*p == '*') || (*p == '+') || (*p == '-') || (*p == '.') || (*p == '/') || (*p == ':')) {
            qr->hasAlphanumericData = true;
            break;
        }
        p++;
    }
}

void printQRCode(QRCode qr) {
    printf("\nVersion info: %s\n", qr.versionInfo);
    printf("Data bytes: %s\n", qr.dataBytes);
    printf("Error correction code: %s\n", qr.errorCorrectionCode);
    
    if (qr.hasAlphanumericData) {
        printf("This QR code has alphanumeric data!\n");
    } else {
        printf("This QR code does not have alphanumeric data.\n");
    }
}

int main() {
    printf("Welcome to the Shape Shifting QR code reader program!\n");
    
    int shapeShift = 1;
    while (shapeShift) {
        printf("\nWhat shape would you like the QR code to shift into?\n");
        printf("1. Circle\n");
        printf("2. Square\n");
        printf("3. Triangle\n");
        printf("4. Quit\n");
        
        scanf("%d", &shapeShift);
        getchar(); // Clear input buffer
        
        QRCode qr;
        readQRCode(&qr);
        
        printf("\nReading QR code...\n");
        printf("Shape-shifting QR code into ");
        switch (shapeShift) {
            case 1:
                printf("a circle...");
                break;
            case 2:
                printf("a square...");
                break;
            case 3:
                printf("a triangle...");
                break;
            case 4:
                printf("quitting the program...");
                exit(EXIT_SUCCESS);
            default:
                printf("an invalid shape. Please try again.\n");
                continue;
        }
        printf("\n\n");
        printQRCode(qr);
    }
    
    return 0;
}
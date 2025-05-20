//FormAI DATASET v1.0 Category: QR code generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// QR Code structure
typedef struct qrcode {
    int size;
    char data[1000];
} QRCode;

// Function to create QR code
QRCode createQRCode(char* data) {
    QRCode code;
    code.size = strlen(data);
    strcpy(code.data, data);
    return code;
}

// Function to print QR code in binary format
void printQRCode(QRCode code) {
    printf("\nPrinting QR code in binary format:\n");
    for(int i=0; i<code.size; i++) {
        printf("%c", code.data[i]);
    }
    printf("\n");
}

// Function to print QR code in retro style
void printQRCodeRetro(QRCode code) {
    printf("\nPrinting QR code in retro style:\n");
    for(int i=0; i<code.size; i++) {
        if(code.data[i] == '0') {
            printf("░░");
        }
        else {
            printf("▓▓");
        }
    }
    printf("\n");
}

// Main function to generate and print QR code
int main() {
    char data[100];
    printf("Enter data to generate QR code:\n");
    scanf("%s", data);
    QRCode code = createQRCode(data);
    printQRCode(code);
    printQRCodeRetro(code);
    return 0;
}
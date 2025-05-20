//FormAI DATASET v1.0 Category: QR code generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the capacity of the QR code
#define MAX_CAPACITY 100

// Define the structure for storing QR code information
struct QR_Code {
    char data[MAX_CAPACITY];
    int size;
};

// Define the function for generating QR code
struct QR_Code generateQRCode(char *data) {
    struct QR_Code qr;
    qr.size = strlen(data);
    if (qr.size > MAX_CAPACITY) {
        printf("Error: data too long for QR code\n");
        exit(1);
    }
    strcpy(qr.data, data);
    return qr;
}

// Define the function for printing QR code
void printQRCode(struct QR_Code qr) {
    printf("\n");
    for (int i = 0; i < qr.size + 4; i++) {
        printf("*");
    }
    printf("\n* ");
    for (int i = 0; i < qr.size; i++) {
        printf("%c ", qr.data[i]);
    }
    printf("*\n");
    for (int i = 0; i < qr.size + 4; i++) {
        printf("*");
    }
    printf("\n");
}

// Define the main function
int main() {
    char data[MAX_CAPACITY];
    printf("Enter data to generate QR code: ");
    scanf("%[^\n]", data);
    struct QR_Code qr = generateQRCode(data);
    printQRCode(qr);
    return 0;
}
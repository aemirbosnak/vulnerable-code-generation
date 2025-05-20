//FormAI DATASET v1.0 Category: QR code reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 512

typedef struct {
    char type[3];
    char data[MAX_LENGTH];
    int data_length;
} QRCode;

void readQRCode(QRCode* qr_code) {
    printf("Enter QR Code: ");
    scanf("%s", qr_code->data);
    qr_code->data_length = strlen(qr_code->data);
    memcpy(qr_code->type, qr_code->data, 2);
    qr_code->type[2] = '\0';
}

void printQRCode(QRCode qr_code) {
    printf("Type: %s\nData: %s\n", qr_code.type, qr_code.data);
}

int main() {
    QRCode qr_code;

    // Read QR Code
    readQRCode(&qr_code);

    // Check if QR Code is valid
    if (strcmp(qr_code.type, "C:") == 0) {
        // Decode QR Code Data
        char decoded_data[MAX_LENGTH];
        int i = 0, j = 0;
        while (i < qr_code.data_length) {
            int count = qr_code.data[i] - '0';
            i++;
            for (int k = 0; k < count; k++) {
                decoded_data[j] = qr_code.data[i];
                j++;
            }
            i++;
        }
        decoded_data[j] = '\0';

        // Print Decoded QR Code Data
        printf("Decoded Data: %s\n", decoded_data);
    } else {
        printf("Invalid QR Code Type!\n");
    }

    return 0;
}
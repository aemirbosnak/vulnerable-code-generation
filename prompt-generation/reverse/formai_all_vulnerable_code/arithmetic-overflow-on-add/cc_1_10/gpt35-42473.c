//FormAI DATASET v1.0 Category: QR code generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

// Function to print the generated QR code
void printQRCode(QRcode *qrcode) {
    printf("QR Code: \n");
    for(int i=0; i<qrcode->width+4; i++) {
        printf("\u2588");
    }
    printf("\n");

    for(int i=0; i<qrcode->width; i++) {
        printf("\u2588\u2588");
        for(int j=0; j<qrcode->width; j++) {
            if(qrcode->data[i*qrcode->width+j]&1) {
                printf("  ");
            }
            else {
                printf("\u2588\u2588");
            }
        }
        printf("\u2588\u2588\n");
    }

    for(int i=0; i<qrcode->width+4; i++) {
        printf("\u2588");
    }
    printf("\n");
}

// Main function
int main() {
    char str[100];
    printf("Welcome to the QR code generator! \n");
    printf("Enter the data to be encoded in the QR code: ");

    // Reading input from the user
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;

    // Generating the QR code
    QRcode *qrcode;
    qrcode = QRcode_encodeString(str, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Printing the QR code
    printQRCode(qrcode);

    // Releasing the memory allocated for the QR code
    QRcode_free(qrcode);

    printf("Thanks for using the QR code generator. \n");
    return 0;
}
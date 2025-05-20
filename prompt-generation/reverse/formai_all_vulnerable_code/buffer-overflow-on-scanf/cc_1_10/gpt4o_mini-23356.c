//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void displayQrCode(const QRcode *qrcode) {
    int size = qrcode->width;
    unsigned char *data = qrcode->data;

    // Print the QR code to the console in ASCII format
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (data[y * size + x] & 0x01) {
                printf("██"); // Black block
            } else {
                printf("  "); // White block
            }
        }
        printf("\n");
    }
}

void generateQrCode(const char *input) {
    QRcode *qrcode = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode) {
        displayQrCode(qrcode);
        QRcode_free(qrcode);
    } else {
        fprintf(stderr, "Failed to generate QR Code\n");
    }
}

void showMenu() {
    printf("===================================\n");
    printf("         QR Code Generator         \n");
    printf("===================================\n");
    printf("1. Generate QR Code\n");
    printf("2. Exit\n");
    printf("===================================\n");
}

int main() {
    int choice;
    char input[256];
    
    while(1) {
        showMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input!\n");
            while(getchar() != '\n'); // clear input buffer
            continue;
        }
        
        switch(choice) {
            case 1:
                printf("Enter the text or URL to encode: ");
                scanf(" %[^\n]", input); // Read input with spaces
                generateQrCode(input);
                break;
                
            case 2:
                printf("Exiting...\n");
                exit(0);
                break;
                
            default:
                fprintf(stderr, "Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}
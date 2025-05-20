//FormAI DATASET v1.0 Category: QR code reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct qr_code {
    char data[256];
    int size;
} QRCode;

void read_qr_code(QRCode *code) {
    printf("Please scan the QR code: ");
    scanf("%s", code->data);
    code->size = strlen(code->data);
    printf("QR code read successfully!\n");
}

void print_qr_code(QRCode code) {
   printf("\nQR Code: %s\n", code.data);
}

void decode_qr_code(QRCode code) {
    // Perform decoding logic here
    printf("Decoding QR code...\n");
    printf("QR code decoded successfully!\n\n");
}

int main() {
    bool running = true;
    char input;
    QRCode code;

    while (running) {
        printf("Press 'r' to read a new QR code, 'p' to print the current QR code, 'd' to decode the QR code, or 'q' to quit: ");
        scanf(" %c", &input);

        switch (input) {
            case 'r':
                read_qr_code(&code);
                break;
            case 'p':
                print_qr_code(code);
                break;
            case 'd':
                decode_qr_code(code);
                break;
            case 'q':
                running = false;
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }

    return 0;
}
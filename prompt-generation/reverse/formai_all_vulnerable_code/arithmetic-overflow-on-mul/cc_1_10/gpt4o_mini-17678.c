//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generate_qr(const char *text) {
    QRcode *qrcode;
    unsigned char *qbuf;
    int width, size, i, j;

    printf("\nGenerating QR Code for the text: \"%s\"\n", text);
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    if (qrcode == NULL) {
        fprintf(stderr, "QR Code generation failed!\n");
        return;
    }

    size = qrcode->width + 2;
    width = size * size;

    qbuf = (unsigned char *)malloc(width);
    if (qbuf == NULL) {
        fprintf(stderr, "Memory allocation failed for QR code!\n");
        QRcode_free(qrcode);
        return;
    }
    
    // Create QR code visualization
    printf("Here's your QR Code:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (qrcode->data[i * qrcode->width + j] & 1) {
                printf("██"); // Black module
            } else {
                printf("  "); // White module
            }
        }
        printf("\n");
    }

    QRcode_free(qrcode);
    free(qbuf);
}

int main() {
    char input[256];

    printf("Welcome to the QR Code Generator! 🎉\n");
    printf("Please enter the text that you want to convert into a QR code:\n");

    // Get user input
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input!\n");
        exit(EXIT_FAILURE);
    }

    // Remove newline from string if present
    input[strcspn(input, "\n")] = 0;

    // Generate QR code
    generate_qr(input);

    printf("Thank you for using the QR Code Generator! Have a great day! 🎈\n");

    return 0;
}
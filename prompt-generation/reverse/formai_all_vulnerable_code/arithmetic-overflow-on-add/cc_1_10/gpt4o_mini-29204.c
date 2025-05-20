//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void print_qr(const QRcode *qrcode) {
    int size = qrcode->width;
    // Artistic border and filling style
    printf("\n");
    for (int y = 0; y < size + 2; y++) {
        for (int x = 0; x < size + 2; x++) {
            if (x == 0 || x == size + 1 || y == 0 || y == size + 1) {
                // Draw border
                printf("#");
            } else {
                // Inside the border
                if (qrcode->data[(y - 1) * size + (x - 1)] & 1) {
                    printf("##"); // Filled block
                } else {
                    printf("  "); // Empty space
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

void banner() {
    printf("===================================\n");
    printf("        QR Code Generator          \n");
    printf("        By Artful Coder            \n");
    printf("===================================\n");
}

int main() {
    char input[256];
    banner();

    // Get user input for the QR Code
    printf("Enter the text to encode in QR Code: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    // Generate QR code
    QRcode *qrcode = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    if (qrcode) {
        // Print the QR Code in artistic style
        print_qr(qrcode);
        QRcode_free(qrcode);
    } else {
        fprintf(stderr, "Error generating QR Code.\n");
        return 1;
    }

    printf("Scan the QR code above with your reader!\n");
    return 0;
}
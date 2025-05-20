//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generate_qr_code(const char *data) {
    QRcode *qrcode;
    unsigned char *output;
    int i, j;

    // Generate QR code
    qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Error generating QR code\n");
        return;
    }

    // Create a smaller matrix for display
    output = (unsigned char *)malloc((qrcode->width + 1) * (qrcode->width + 1));
    if (!output) {
        QRcode_free(qrcode);
        fprintf(stderr, "Memory allocation error\n");
        return;
    }

    // Fill the output for visualization
    for (i = 0; i < qrcode->width; i++) {
        for (j = 0; j < qrcode->width; j++) {
            output[i * (qrcode->width + 1) + j] = (qrcode->data[i * qrcode->width + j] & 1) ? 1 : 0;
        }
        output[i * (qrcode->width + 1) + qrcode->width] = 0;  // New line
    }

    // Display the QR code in a simple text format
    printf("QR Code for: %s\n", data);
    for (i = 0; i < qrcode->width; i++) {
        for (j = 0; j < qrcode->width; j++) {
            if (output[i * (qrcode->width + 1) + j]) {
                printf("██");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    // Clean up memory
    free(output);
    QRcode_free(qrcode);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text_to_encode>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Generate QR Code
    generate_qr_code(argv[1]);

    return EXIT_SUCCESS;
}
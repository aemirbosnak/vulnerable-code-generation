//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <qrencode.h>

#define ERROR_CORRECTION_LEVEL QR_ECLEVEL_L // Set error correction level
#define SIZE 10 // Size of the QR code modules
#define MARGIN 4 // Margin around the QR code

// Function to generate and save QR code to a file
void generateQRCode(const char *text) {
    QRcode *qr;
    FILE *fp;

    // Generate QR code from text
    qr = QRcode_encodeString(text, 0, ERROR_CORRECTION_LEVEL, QR_MODE_8, 1);

    if (!qr) {
        fprintf(stderr, "Failed to generate QR Code!\n");
        exit(EXIT_FAILURE);
    }

    // Create a file to save the QR code as a PPM image
    fp = fopen("qrcode.ppm", "wb");
    if (!fp) {
        fprintf(stderr, "Failed to open file for saving QR Code!\n");
        QRcode_free(qr);
        exit(EXIT_FAILURE);
    }

    // Write PPM header
    fprintf(fp, "P3\n%d %d\n255\n", qr->width + MARGIN * 2, qr->width + MARGIN * 2);

    // Write QR code data to file
    for (int y = -MARGIN; y < qr->width + MARGIN; y++) {
        for (int x = -MARGIN; x < qr->width + MARGIN; x++) {
            if (x < 0 || x >= qr->width || y < 0 || y >= qr->width || (qr->data[y * qr->width + x] & 1) == 0) {
                // Outside QR code or a white module
                fprintf(fp, "255 255 255 "); // White
            } else {
                // Inside QR code (black module)
                fprintf(fp, "0 0 0 "); // Black
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    QRcode_free(qr);
    printf("QR Code generated and saved as 'qrcode.ppm'!\n");
}

// Main function
int main() {
    char input[256];

    printf("Welcome to the SHOCKING QR Code Generator!\n");
    printf("Enter the text you want to encode in the QR code (up to 255 characters):\n");

    // Getting user input
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Failed to read input!\n");
        exit(EXIT_FAILURE);
    }

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Surprise! Check for empty input
    if (strlen(input) == 0) {
        fprintf(stderr, "Unexpected! You entered nothing. What a SHOCK!\n");
        exit(EXIT_FAILURE);
    }

    // Generate QR code
    generateQRCode(input);

    // Surprise message!
    printf("YOUR QR CODE HAS BEEN SUCCESSFULLY GENERATED! Go check 'qrcode.ppm' now!\n");
    
    return 0;
}
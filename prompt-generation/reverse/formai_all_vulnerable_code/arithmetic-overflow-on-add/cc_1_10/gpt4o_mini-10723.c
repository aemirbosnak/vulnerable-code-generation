//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// QR Code generation library
#include <qrencode.h>

// Function to generate QR Code
void generate_qr_code(const char *text, const char *filename) {
    QRcode *qrcode;
    
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    if (qrcode) {
        FILE *fp = fopen(filename, "wb");
        if (!fp) {
            fprintf(stderr, "Could not open file for writing: %s\n", filename);
            return;
        }
        
        // Create a simple PGM image format
        fprintf(fp, "P2\n");
        fprintf(fp, "%d %d\n", qrcode->width, qrcode->width);
        fprintf(fp, "255\n");
        
        for (int j = 0; j < qrcode->width; j++) {
            for (int i = 0; i < qrcode->width; i++) {
                int offset = i + j * qrcode->width;
                fputc((qrcode->data[offset] & 1) ? '0' : ' ', fp);
                fputc(' ', fp);
            }
            fputc('\n', fp);
        }
        
        fclose(fp);
        QRcode_free(qrcode);
        printf("QR Code generated and saved to %s\n", filename);
    } else {
        fprintf(stderr, "Could not generate QR code for input: %s\n", text);
    }
}

// Main function
int main() {
    char input[256];
    char filename[256];
    
    printf("Welcome to the Retro QR Code Generator!\n");
    printf("=========================================\n");
    
    // User input for QR code data
    printf("Enter the text to encode in the QR code: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

    // User input for output filename
    printf("Enter the filename to save the QR code (without extension): ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove trailing newline

    // Append .pgm to the filename
    strcat(filename, ".pgm");

    // Generate the QR code
    generate_qr_code(input, filename);
    
    printf("Thank you for using the Retro QR Code Generator!\n");
    printf("=========================================\n");
    return 0;
}
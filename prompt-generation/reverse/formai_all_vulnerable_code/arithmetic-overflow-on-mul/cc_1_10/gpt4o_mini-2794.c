//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void save_png(const char *filename, QRcode *qrcode) {
    int width = qrcode->width;
    unsigned char *png = (unsigned char *)malloc(width * width);
    FILE *fp = fopen(filename, "wb");

    if (!fp) {
        fprintf(stderr, "Could not open file for writing: %s\n", filename);
        free(png);
        return;
    }

    // Generate the PNG pixel data (black and white)
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < width; x++) {
            png[y * width + x] = (qrcode->data[y * width + x] & 1) ? 0 : 255;
        }
    }

    // Write a simple PNG header (this can be expanded for complete PNG generation)
    fwrite("\x89PNG\r\n\x1A\n", 1, 8, fp);
    // Insert other necessary PNG writing code here...

    // Cleanup
    fclose(fp);
    free(png);
}

void generate_qr_code(const char *text, const char *output_filename) {
    QRcode *qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode) {
        save_png(output_filename, qrcode);
        QRcode_free(qrcode);
        printf("QR Code generated and saved as %s\n", output_filename);
    } else {
        fprintf(stderr, "Failed to generate QR Code\n");
    }
}

int main() {
    char input_text[256]; 
    char output_filename[256];

    printf("Welcome to the QR Code Generator!\n");
    printf("Please enter the text (or URL) you want to encode: ");
    fgets(input_text, sizeof(input_text), stdin);
    input_text[strcspn(input_text, "\n")] = 0; // Remove newline character

    printf("Enter the desired output filename (e.g., output.png): ");
    fgets(output_filename, sizeof(output_filename), stdin);
    output_filename[strcspn(output_filename, "\n")] = 0; // Remove newline character

    generate_qr_code(input_text, output_filename);

    return 0;
}
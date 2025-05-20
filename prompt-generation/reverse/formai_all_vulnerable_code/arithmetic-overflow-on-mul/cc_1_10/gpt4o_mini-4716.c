//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generate_png(const char *filename, QRcode *qrcode) {
    if (!filename || !qrcode) {
        fprintf(stderr, "Invalid filename or QRcode pointer.\n");
        return;
    }

    int width = qrcode->width;
    int size = (width + 2) * 3; // png size: (width + border) * scale
    unsigned char *png = malloc(size * size);
    memset(png, 255, size * size); // Initialize with white

    // Draw QR code
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < width; x++) {
            if (qrcode->data[y * width + x] & 1) {
                // Set pixel to black
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        png[(y * 3 + i + 1) * size + (x * 3 + j + 1)] = 0;
                    }
                }
            }
        }
    }

    // Create a PNG file
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Could not open file for writing\n");
        free(png);
        return;
    }

    // Write PNG header
    fprintf(fp, "\x89PNG\r\n\x1A\n");

    // Write IHDR chunk
    fprintf(fp, "IHDR");
    fwrite(png, 1, 8, fp); // Placeholder for IHDR data - to be updated later

    // Write IDAT chunk with actual QR image (not fully PNG-compliant)
    // Here you should actually implement PNG compression
    fprintf(fp, "IDAT");
    fwrite(png + (size - 8) * 3, 1, 8, fp); // Placeholder

    // Write IEND chunk
    fprintf(fp, "IEND");

    fclose(fp);
    free(png);
    printf("PNG generated: %s\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <text to encode> <output filename>\n", argv[0]);
        return 1;
    }

    const char *text = argv[1];
    const char *output_filename = argv[2];

    // Generate QR code
    QRcode *qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Could not generate QR code.\n");
        return 1;
    }

    // Generate PNG file
    generate_png(output_filename, qrcode);

    // Cleanup QR code
    QRcode_free(qrcode);
    
    printf("QR code generation complete.\n");
    return 0;
}
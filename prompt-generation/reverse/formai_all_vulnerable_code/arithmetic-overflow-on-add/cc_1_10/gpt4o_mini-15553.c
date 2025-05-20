//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generate_qr_code(const char *text, const char *filename) {
    QRcode *qrcode;

    // Generate QR code from input text
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Error generating QR Code. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    // Open file to write the QR code image
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Could not open %s for writing.\n", filename);
        QRcode_free(qrcode);
        exit(EXIT_FAILURE);
    }

    // Generate PNG format output
    unsigned char *png_data;
    int png_size = 0;

    png_data = (unsigned char *)malloc((qrcode->width + 1) * (qrcode->width + 1) * 4);
    if(png_data == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        fclose(fp);
        QRcode_free(qrcode);
        exit(EXIT_FAILURE);
    }

    // Convert QR code data to a pixel array (RGBA format)
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            int offset = (y * (qrcode->width + 1) + x) * 4;
            if (qrcode->data[y * qrcode->width + x] & 0x01) {
                png_data[offset] = 0; // R
                png_data[offset + 1] = 0; // G
                png_data[offset + 2] = 0; // B
                png_data[offset + 3] = 255; // A (Opaque)
            } else {
                png_data[offset] = 255; // R
                png_data[offset + 1] = 255; // G
                png_data[offset + 2] = 255; // B
                png_data[offset + 3] = 255; // A (Transparent)
            }
        }
    }

    // Write PNG header
    fwrite(png_data, 1, (qrcode->width) * (qrcode->width) * 4, fp);
    
    // Write QR code dimensions
    fwrite(&qrcode->width, sizeof(int), 1, fp);
    
    // Clean up and close the file
    free(png_data);
    fclose(fp);
    QRcode_free(qrcode);

    printf("QR code generated successfully and saved as %s\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <text to encode> <output filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *text = argv[1];
    const char *filename = argv[2];

    generate_qr_code(text, filename);
    return EXIT_SUCCESS;
}
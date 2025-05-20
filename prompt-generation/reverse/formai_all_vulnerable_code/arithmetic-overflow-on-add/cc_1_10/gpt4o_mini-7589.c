//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void generate_qr_code(const char *input, const char *filename) {
    QRcode *qrcode;
    FILE *fp;
    int size, margin;
    
    // Generate the QR code
    qrcode = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Failed to generate QR Code\n");
        return;
    }

    // Set the size and margin
    size = qrcode->width;
    margin = 4;

    // Create a BMP file
    fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Failed to open file %s for writing\n", filename);
        QRcode_free(qrcode);
        return;
    }
    
    // BMP file header
    unsigned char bmpfileheader[14] = {
        'B', 'M',               // Signature
        0, 0, 0, 0,            // File size (filled later)
        0, 0,                  // Reserved
        0, 0,                  // Reserved
        54, 0, 0, 0           // Offset to start of pixel data
    };
    
    unsigned char bmpinfoheader[40] = {
        40, 0, 0, 0,           // Header size
        0, 0, 0, 0,           // Image width (filled later)
        0, 0, 0, 0,           // Image height (filled later)
        1, 0,                  // Number of color planes
        24, 0,                 // Bits per pixel
        0, 0, 0, 0,           // Compression (0 = none)
        0, 0, 0, 0,           // Image size (0 = no compression)
        0, 0, 0, 0,           // Horizontal resolution (pixels/meter)
        0, 0, 0, 0,           // Vertical resolution (pixels/meter)
        0, 0, 0, 0,           // Number of colors in the palette
        0, 0, 0, 0            // Number of important colors (0 = all)
    };

    // Calculate and fill the size of the BMP file
    int bmp_size = 54 + (size + margin * 2) * (size + margin * 2) * 3;
    bmpfileheader[2] = (unsigned char)(bmp_size);
    bmpfileheader[3] = (unsigned char)(bmp_size >> 8);
    bmpfileheader[4] = (unsigned char)(bmp_size >> 16);
    bmpfileheader[5] = (unsigned char)(bmp_size >> 24);

    bmpinfoheader[18] = (unsigned char)(size + margin * 2);
    bmpinfoheader[19] = (unsigned char)(size + margin * 2 >> 8);
    bmpinfoheader[22] = (unsigned char)(size + margin * 2);
    bmpinfoheader[23] = (unsigned char)(size + margin * 2 >> 8);

    // Write headers to file
    fwrite(bmpfileheader, sizeof(bmpfileheader), 1, fp);
    fwrite(bmpinfoheader, sizeof(bmpinfoheader), 1, fp);

    // Prepare pixel data
    unsigned char *pixels = (unsigned char *)malloc((size + margin * 2) * (size + margin * 2) * 3);
    if (!pixels) {
        fprintf(stderr, "Failed to allocate memory for pixel data\n");
        fclose(fp);
        QRcode_free(qrcode);
        return;
    }

    // Fill pixel array
    for (int y = 0; y < size + margin * 2; ++y) {
        for (int x = 0; x < size + margin * 2; ++x) {
            if (x >= margin && x < size + margin && y >= margin && y < size + margin) {
                int module = (qrcode->data[(y - margin) * qrcode->width + (x - margin)] & 0x1);
                pixels[(y * (size + margin * 2) + x) * 3 + 0] = (module ? 0 : 255); // R
                pixels[(y * (size + margin * 2) + x) * 3 + 1] = (module ? 0 : 255); // G
                pixels[(y * (size + margin * 2) + x) * 3 + 2] = (module ? 0 : 255); // B
            } else {
                pixels[(y * (size + margin * 2) + x) * 3 + 0] = 255; // R
                pixels[(y * (size + margin * 2) + x) * 3 + 1] = 255; // G
                pixels[(y * (size + margin * 2) + x) * 3 + 2] = 255; // B
            }
        }
    }

    // Write pixel data to file
    fwrite(pixels, (size + margin * 2) * (size + margin * 2) * 3, 1, fp);

    // Clean up
    free(pixels);
    fclose(fp);
    QRcode_free(qrcode);
    
    printf("QR code saved to %s\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input string> <output filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    generate_qr_code(argv[1], argv[2]);
    return EXIT_SUCCESS;
}
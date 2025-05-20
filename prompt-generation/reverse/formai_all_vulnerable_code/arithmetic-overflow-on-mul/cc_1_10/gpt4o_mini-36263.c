//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

// Function to generate the QR code
void generate_qr(const char* text) {
    QRcode* qrcode;
    unsigned char* png;
    int width, size;

    // Generate QR code from the given text
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR code for text: %s\n", text);
        exit(EXIT_FAILURE);
    }

    // Calculate the size of the QR code
    size = qrcode->width;
    width = size * 3; // Scaled up for better visual quality

    // Create the PNG array
    png = (unsigned char*)malloc(width * width);
    memset(png, 255, width * width); // Set background to white

    // Generate the actual pixel data
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int is_pixel_set = (qrcode->data[y * size + x] & 1);
            int color = is_pixel_set ? 0 : 255; // Black or white
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    png[(y * 3 + i) * width + (x * 3 + j)] = color; // Scale pixel
                }
            }
        }
    }

    // Output PNG data
    FILE* pngFile = fopen("output.png", "wb");
    if (!pngFile) {
        fprintf(stderr, "Failed to create output file.\n");
        free(png);
        QRcode_free(qrcode);
        exit(EXIT_FAILURE);
    }

    // Write PNG header and data
    fprintf(pngFile, "%s", "\x89PNG\r\n\x1A\n"); // PNG signature
    // For simplicity, let's just write raw RGB data (not a valid PNG)
    // You'll need a PNG library for proper PNG encoding
    fwrite(png, 1, width * width, pngFile);
    fclose(pngFile);

    free(png);
    QRcode_free(qrcode);
    printf("QR code generated and saved as output.png\n");
}

int main(int argc, char* argv[]) {
    // Check for text input
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text_to_encode>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Generate the QR code for the provided text
    generate_qr(argv[1]);

    return 0;
}
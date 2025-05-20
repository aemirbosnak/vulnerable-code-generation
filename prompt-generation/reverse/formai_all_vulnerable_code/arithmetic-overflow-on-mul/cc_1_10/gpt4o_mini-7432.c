//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generateQR(const char *text, const char *filename) {
    QRcode *qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Failed to generate QR code.\n");
        exit(1);
    }

    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Could not open file for writing: %s\n", filename);
        QRcode_free(qrcode);
        exit(1);
    }

    int size = qrcode->width;
    unsigned char *image = (unsigned char *)malloc(size * size * 3);
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int offset = (y * size + x) * 3;
            if (qrcode->data[y * size + x] & 1) {
                image[offset] = 0;     // Black
                image[offset + 1] = 0;
                image[offset + 2] = 0;
            } else {
                image[offset] = 255;   // White
                image[offset + 1] = 255;
                image[offset + 2] = 255;
            }
        }
    }

    // Writing the PPM image header
    fprintf(fp, "P6\n%d %d\n255\n", size, size);
    fwrite(image, 3, size * size, fp);

    fclose(fp);
    QRcode_free(qrcode);
    free(image);

    printf("QR Code generated and saved to %s\n", filename);
    printf("Scan the QR code to discover its secrets!\n");
}

int main() {
    char text[256];
    char filename[300];

    printf("Greetings, curious traveler! What secret code shall we embed in our mystical QR artifact?\n");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove new line character from input

    printf("And where shall we craft this QR code? Perhaps a name for our scroll? (e.g., myqrcode.ppm)\n");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove new line character from input

    generateQR(text, filename);

    return 0;
}
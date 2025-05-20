//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

void save_png(const char* filename, unsigned char* data, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Failed to open file for writing");
        return;
    }
    int size = width * height;
    fwrite(data, sizeof(unsigned char), size, fp);
    fclose(fp);
}

unsigned char* create_qr_code(const char* text, int* width, int* height) {
    QRcode *qrcode;
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Failed to generate QR Code\n");
        exit(EXIT_FAILURE);
    }

    *width = qrcode->width;
    *height = qrcode->width;

    unsigned char *png = malloc(*width * *height);
    if (!png) {
        fprintf(stderr, "Memory allocation failed\n");
        QRcode_free(qrcode);
        exit(EXIT_FAILURE);
    }

    for (int y = 0; y < *height; y++) {
        for (int x = 0; x < *width; x++) {
            png[y * *width + x] = (qrcode->data[y * qrcode->width + x] & 1) ? 0 : 255;
        }
    }

    QRcode_free(qrcode);
    return png;
}

int main() {
    char input[256];
    printf("Enter text to encode in QR Code: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;  // Remove trailing newline character

    int width, height;
    unsigned char* qr_code = create_qr_code(input, &width, &height);

    char filename[300];
    sprintf(filename, "qr_code_%d_%d.png", width, height);
    save_png(filename, qr_code, width, height);

    printf("QR Code generated successfully!\nSaved as: %s\n", filename);
    
    free(qr_code);
    return 0;
}
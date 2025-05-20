//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generate_qr_code(const char *data, const char *filename) {
    QRcode *qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR Code\n");
        return;
    }

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open output file\n");
        QRcode_free(qrcode);
        return;
    }

    unsigned char *image = (unsigned char *)malloc((qrcode->width + 2) * (qrcode->width + 2));
    int i, j;
    
    // Creating a border
    for (i = 0; i < qrcode->width + 2; i++) {
        for (j = 0; j < qrcode->width + 2; j++) {
            if (i == 0 || i == qrcode->width + 1 || j == 0 || j == qrcode->width + 1) {
                image[i * (qrcode->width + 2) + j] = 0; // border
            } else {
                image[i * (qrcode->width + 2) + j] = (qrcode->data[(i - 1) * qrcode->width + (j - 1)] & 1) ? 255 : 0;
            }
        }
    }

    // Writing the PGM file header
    fprintf(fp, "P5\n%d %d\n255\n", qrcode->width + 2, qrcode->width + 2);
    fwrite(image, 1, (qrcode->width + 2) * (qrcode->width + 2), fp);

    fclose(fp);
    free(image);
    QRcode_free(qrcode);

    printf("QR Code generated and saved to %s\n", filename);
}

int main() {
    char input[256];
    char filename[256];

    printf("Enter the data to encode as QR Code: ");
    fgets(input, sizeof(input), stdin);

    size_t len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';  // Remove trailing newline
    }

    printf("Enter filename to save QR Code (e.g., output.pgm): ");
    fgets(filename, sizeof(filename), stdin);

    len = strlen(filename);
    if (filename[len - 1] == '\n') {
        filename[len - 1] = '\0';  // Remove trailing newline 
    }

    generate_qr_code(input, filename);

    return 0;
}
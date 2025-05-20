//FormAI DATASET v1.0 Category: QR code generator ; Style: secure
// QR Code Generator Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define BUFFER_SIZE 4096

int main(int argc, char* argv[]) {
    
    // Parse command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [text]\n", argv[0]);
        return 1;
    }
    const char* text = argv[1];
    const int length = strlen(text);

    // Allocate buffer for QR code image
    unsigned char* buffer = (unsigned char*) malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory\n");
        return 1;
    }

    // Generate QR code
    QRcode* qr = QRcode_encodeString(text, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
    if (qr == NULL) {
        fprintf(stderr, "Error: Failed to generate QR code\n");
        free(buffer);
        return 1;
    }

    // Render QR code to buffer
    const int size = qr->width > 0 ? qr->width : 1;
    const int scale = 4;
    for (int y = 0; y < size * scale; y++) {
        for (int x = 0; x < size * scale; x++) {
            const int index = (y / scale) * size + (x / scale);
            const unsigned char module = qr->data[index] & 1;
            buffer[y * size * scale + x] = module ? 255 : 0;
        }
    }

    // Write buffer to PNG file
    char filename[length + 5];
    strncpy(filename, text, length);
    strcat(filename, ".png");
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file\n");
        QRcode_free(qr);
        free(buffer);
        return 1;
    }
    fwrite(buffer, 1, size * scale * size * scale, file);
    fclose(file);

    // Free memory
    QRcode_free(qr);
    free(buffer);

    printf("QR code created: %s\n", filename);
    return 0;
}
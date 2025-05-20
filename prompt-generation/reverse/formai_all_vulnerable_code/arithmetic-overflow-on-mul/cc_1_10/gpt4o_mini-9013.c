//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void save_image(const char *filename, QRcode *qrcode) {
    int size = qrcode->width;
    int width = size * 10;
    int height = size * 10;
    unsigned char *image = malloc(width * height * 3);
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int qr_x = x / 10;
            int qr_y = y / 10;
            int color = qrcode->data[qr_y * size + qr_x] & 1;
            image[(y * width + x) * 3 + 0] = color ? 0 : 255; // R
            image[(y * width + x) * 3 + 1] = color ? 0 : 255; // G
            image[(y * width + x) * 3 + 2] = color ? 0 : 255; // B
        }
    }
    
    FILE *file = fopen(filename, "wb");
    if (file) {
        fprintf(file, "P6\n%d %d\n255\n", width, height);
        fwrite(image, 3, width * height, file);
        fclose(file);
    } else {
        fprintf(stderr, "Could not save image: %s\n", filename);
    }
    free(image);
}

int main() {
    char input[256];
    
    printf("Welcome to QR Code Generator!\n");
    printf("Enter the text or URL you want to encode: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from string
    input[strcspn(input, "\n")] = 0;

    // Generate QR code
    QRcode *qrcode = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    
    if (qrcode) {
        printf("QR Code generated successfully!\n");
        
        char *filename = "qrcode.ppm";
        save_image(filename, qrcode);
        
        printf("QR Code saved as %s\n", filename);
        
        // Free QR Code
        QRcode_free(qrcode);
    } else {
        printf("Failed to generate QR Code!\n");
    }
    
    return 0;
}
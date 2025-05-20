//FormAI DATASET v1.0 Category: QR code generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <data> <filename>\n", argv[0]);
        printf("Example: %s \"Hello, World!\" qr_code.png\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    QRcode *qrcode = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
    
    if (qrcode == NULL) {
        printf("Error: Failed to generate QR code.\n");
        return EXIT_FAILURE;
    }
    
    int size = qrcode->width > 1024 ? 1024 : qrcode->width;
    
    unsigned char *image_buffer = (unsigned char *) malloc(size * size * 3);
    
    if (image_buffer == NULL) {
        printf("Error: Failed to allocate memory for image buffer.\n");
        return EXIT_FAILURE;
    }
    
    memset(image_buffer, 255, size * size * 3);
    
    unsigned char *p = image_buffer;
    
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            if (qrcode->data[y * qrcode->width + x] & 1) {
                memset(p, 0, 3);
            }
            p += 3;
        }
        p += (size - qrcode->width) * 3;
    }
    
    QRcode_free(qrcode);
    
    FILE *fp = fopen(argv[2], "wb");
    
    if (fp != NULL) {
        fwrite(image_buffer, 1, size * size * 3, fp);
        fclose(fp);
    } else {
        printf("Error: Failed to open file '%s' for writing.\n", argv[2]);
        return EXIT_FAILURE;
    }
    
    printf("QR code successfully generated in file '%s'.\n", argv[2]);
    
    free(image_buffer);
    
    return EXIT_SUCCESS;
}
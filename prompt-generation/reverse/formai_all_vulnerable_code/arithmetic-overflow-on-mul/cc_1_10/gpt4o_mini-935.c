//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void save_png(const char *filename, QRcode *qrcode) {
    int width = qrcode->width;
    int size = 10; // size of each module
    int img_width = width * size;
    int img_height = img_width;

    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        return;
    }

    // Write the PNG header
    fprintf(fp, "\x89PNG\r\n\x1A\n");
    // The rest of the PNG format and chunks will be implemented below...

    // Simplified representation: Create a minimal PNG header
    fprintf(fp, "IHDR\x00\x00\x00\x0A\x00\x00\x00\x0A\x08\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00");
    fprintf(fp, "IDAT");
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char color = (qrcode->data[y * width + x] & 1) ? 0 : 255; // black or white
            fwrite(&color, 1, 1, fp);
            fwrite(&color, 1, 1, fp);
            fwrite(&color, 1, 1, fp); // RGB triplet
        }
    }
    fprintf(fp, "IEND");
    fclose(fp);
}

void generate_qr_code(const char *text) {
    QRcode *qrcode;

    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode) {
        char filename[100];
        snprintf(filename, sizeof(filename), "%s.png", text);
        save_png(filename, qrcode);
        QRcode_free(qrcode);
        printf("QR code saved to %s\n", filename);
    } else {
        fprintf(stderr, "Failed to generate QR code for: %s\n", text);
    }
}

void display_instructions() {
    printf("QR Code Generator\n");
    printf("------------------\n");
    printf("Enter the text to convert into a QR code.\n");
    printf("Type 'exit' to quit the program.\n");
    printf("\n");
}

int main() {
    char input[256];

    display_instructions();

    while (1) {
        printf("Enter text: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // end on error
        }

        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            break;
        }

        generate_qr_code(input);
    }

    return 0;
}
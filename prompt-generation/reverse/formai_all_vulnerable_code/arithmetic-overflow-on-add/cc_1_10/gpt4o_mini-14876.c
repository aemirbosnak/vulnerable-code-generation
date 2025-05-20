//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generate_qr_code(const char *text, const char *filename) {
    QRcode *qrcode;
    unsigned char *qrcode_data;
    int pixel_size = 10;
    
    // Generate QR code
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR code\n");
        return;
    }

    // Create a PPM (portable pixmap) file to save the QR code
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s for writing\n", filename);
        QRcode_free(qrcode);
        return;
    }

    // Write the PPM header
    fprintf(fp, "P3\n%d %d\n255\n", qrcode->width, qrcode->width);

    // Write pixel data
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            int pixel_value = qrcode->data[y * qrcode->width + x] & 1;
            if (pixel_value) {
                fwrite("0 0 0 ", sizeof(char), 7, fp); // black pixel
            } else {
                fwrite("255 255 255 ", sizeof(char), 13, fp); // white pixel
            }
        }
        fwrite("\n", sizeof(char), 1, fp);
    }

    // Cleanup
    fclose(fp);
    QRcode_free(qrcode);
    printf("QR code generated successfully! Saved to %s\n", filename);
}

int main() {
    char input_text[256];
    char output_file[256];

    printf("Welcome to the QR Code Generator!\n");
    printf("Please enter the text or URL you want to encode in a QR code:\n");
    fgets(input_text, sizeof(input_text), stdin);
    
    // Remove newline character added by fgets
    input_text[strcspn(input_text, "\n")] = 0;

    printf("Awesome! You entered: %s\n", input_text);
    printf("Now, please enter the desired output filename (without extension):\n");
    fgets(output_file, sizeof(output_file), stdin);
    
    // Remove newline character from filename
    output_file[strcspn(output_file, "\n")] = 0;
    strcat(output_file, ".ppm"); // append .ppm extension

    // Generate the QR Code
    generate_qr_code(input_text, output_file);

    return 0;
}
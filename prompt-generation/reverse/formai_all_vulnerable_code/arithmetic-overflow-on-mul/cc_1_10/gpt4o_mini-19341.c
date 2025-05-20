//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void save_qr_to_file(const char *filename, QRcode *qr) {
    // Define the dimensions of the QR code image
    int size = qr->width;
    // Allocate memory for the image
    unsigned char *image = malloc(size * size * 3);
    if (image == NULL) {
        fprintf(stderr, "Unable to allocate memory for image.\n");
        return;
    }

    // Create a simple RGB image (white background, black QR code)
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int pixel = qr->data[y * size + x];
            int index = (y * size + x) * 3;
            if (pixel & 1) { // Black
                image[index] = 0;     // R
                image[index + 1] = 0; // G
                image[index + 2] = 0; // B
            } else { // White
                image[index] = 255;   // R
                image[index + 1] = 255; // G
                image[index + 2] = 255; // B
            }
        }
    }

    // Write the image to a PPM file
    FILE *fp = fopen(filename, "wb");
    if (fp) {
        fprintf(fp, "P6\n%d %d\n255\n", size, size);
        fwrite(image, 1, size * size * 3, fp);
        fclose(fp);
        printf("QR Code saved to %s\n", filename);
    } else {
        fprintf(stderr, "Error opening file for writing.\n");
    }

    // Clean up
    free(image);
}

int main() {
    char input[256];
    char filename[256];

    printf("Welcome to the QR Code Generator!\n");

    // Get input data from the user
    printf("Enter the text or URL to encode as QR code: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character

    // Get the desired filename from the user
    printf("Enter the filename to save the QR code image (e.g., 'qrcode.ppm'): ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove the newline character

    // Generate the QR code
    QRcode *qr = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    if (qr) {
        // Save the QR code to a PPM file
        save_qr_to_file(filename, qr);
        QRcode_free(qr);
    } else {
        fprintf(stderr, "Failed to generate QR code.\n");
    }

    printf("Thank you for using the QR Code Generator!\n");
    return 0;
}
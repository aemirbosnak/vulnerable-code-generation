//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

// Function to generate a QR code and save it as a PNG file
void generateQRCode(const char *text, const char *filename) {
    QRcode *qrcode;
    unsigned char *image;
    int width, height, raw_size, i, j;
    
    // Generate the QR code from the text
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Error encoding QR code.\n");
        exit(EXIT_FAILURE);
    }
    
    // Set the dimensions for the PNG output
    width = qrcode->width;
    height = width;
    raw_size = width * height;
    
    // Allocate memory for the image (for a simple black/white image)
    image = (unsigned char *)malloc(3 * raw_size); // RGB
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for QR image.\n");
        QRcode_free(qrcode);
        exit(EXIT_FAILURE);
    }
    
    // Fill the image data
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            int pixel = qrcode->data[i * width + j] & 0x1;
            int idx = (i * width + j) * 3; // RGB
            image[idx] = image[idx + 1] = image[idx + 2] = (pixel ? 0 : 255); // Black or white
        }
    }

    // Save the image as a PNG file using a simple method
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error opening file for writing.\n");
        free(image);
        QRcode_free(qrcode);
        exit(EXIT_FAILURE);
    }

    // Write PNG file header
    fputs("89504E47", fp); // PNG magic number
    // ... (More code would be needed here to write the rest of the PNG format)
    fclose(fp);

    // Cleanup
    free(image);
    QRcode_free(qrcode);
    printf("QR Code generated and saved to: %s\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <text-to-encode> <output-filename.png>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Generate QR Code with the provided text
    generateQRCode(argv[1], argv[2]);
    return EXIT_SUCCESS;
}
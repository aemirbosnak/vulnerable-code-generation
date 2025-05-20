//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generate_qr_code(const char *data, const char *filename) {
    QRcode *qr;
    unsigned char *image;
    int width, height, i, j, byte_index;

    // Generate QR code
    qr = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qr) {
        fprintf(stderr, "Failed to generate QR code for the data: %s\n", data);
        exit(EXIT_FAILURE);
    }

    // Set parameters for image creation
    width = qr->width;
    height = qr->width;
    image = (unsigned char *)malloc(width * height * 3); // RGB
    memset(image, 255, width * height * 3); // Fill with white background

    // Create the QR code image
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            if (qr->data[j * width + i] & 1) { // If the bit is set
                byte_index = (j * width + i) * 3;
                image[byte_index] = 0;     // R
                image[byte_index + 1] = 0; // G
                image[byte_index + 2] = 0; // B
            }
        }
    }

    // Write to BMP file
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        QRcode_free(qr);
        free(image);
        exit(EXIT_FAILURE);
    }

    // BMP header
    unsigned char bmpfileheader[14] = {
        'B', 'M', // Bitmap id
        0, 0, 0, 0, // File size (we'll fill this in later)
        0, 0, // Reserved1
        0, 0, // Reserved2
        54, 0, 0, 0 // Offset to start of pixel data
    };
    unsigned char bmpinfoheader[40] = {
        40, 0, 0, 0, // Info header size
        0, 0, 0, 0, // Width (we'll fill this in later)
        0, 0, 0, 0, // Height (we'll fill this in later)
        1, 0, // Color planes
        24, 0, // Bits per pixel
        0, 0, 0, 0, // Compression
        0, 0, 0, 0, // Image size (0 for uncompressed)
        0, 0, 0, 0, // Pixels per meter (we'll fill this in later)
        0, 0, 0, 0, // Colors in palette
        0, 0, 0, 0  // Important color count
    };

    // Set image dimensions in the BMP header
    int filesize = 54 + 3 * width * height;
    bmpfileheader[2] = (unsigned char)(filesize);
    bmpfileheader[3] = (unsigned char)(filesize >> 8);
    bmpfileheader[4] = (unsigned char)(filesize >> 16);
    bmpfileheader[5] = (unsigned char)(filesize >> 24);

    bmpinfoheader[18] = (unsigned char)(width);
    bmpinfoheader[19] = (unsigned char)(width >> 8);
    bmpinfoheader[20] = (unsigned char)(width >> 16);
    bmpinfoheader[21] = (unsigned char)(width >> 24);

    bmpinfoheader[22] = (unsigned char)(height);
    bmpinfoheader[23] = (unsigned char)(height >> 8);
    bmpinfoheader[24] = (unsigned char)(height >> 16);
    bmpinfoheader[25] = (unsigned char)(height >> 24);

    // Write headers to file
    fwrite(bmpfileheader, 1, 14, fp);
    fwrite(bmpinfoheader, 1, 40, fp);

    // Write pixel data
    for (i = height - 1; i >= 0; i--) {
        fwrite(image + i * width * 3, 3, width, fp);
        // Padding for 4-byte alignment
        unsigned char padding[3] = {0, 0, 0};
        fwrite(padding, 1, (4 - (width * 3) % 4) % 4, fp);
    }

    // Clean up
    fclose(fp);
    QRcode_free(qr);
    free(image);
    printf("QR Code generated successfully and saved to %s\n", filename);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <data> <output_filename.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    generate_qr_code(argv[1], argv[2]);
    return EXIT_SUCCESS;
}
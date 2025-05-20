//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void print_usage(const char *progname) {
    printf("Welcome to the QR Code Generator!\n");
    printf("Usage: %s <your QR code text>\n", progname);
    printf("Example: %s 'Hello, World!'\n", progname);
    printf("Let's get coding and make some QR magic happen!\n");
}

int save_png(const char *filename, QRcode *qrcode) {
    int size = qrcode->width;
    unsigned char *image = malloc(size * size);
    
    if (image == NULL) {
        fprintf(stderr, "Memory allocation failed for image\n");
        return -1;
    }
    
    // Create a simple black and white image
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            image[y * size + x] = (qrcode->data[y * size + x] & 1) ? 0 : 255; // Black or white
        }
    }
    
    // Writing the PNG file
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Could not open file %s for writing\n", filename);
        free(image);
        return -1;
    }
    
    // Writing a basic PNG header
    fprintf(fp, "\x89PNG\r\n\x1A\n"); // PNG signature
    fwrite("\0\0\0\0IHDR", 1, 8, fp);
    fwrite("\0\0\0\0", 1, 4, fp); // width and height to be filled later
    fwrite("\8\0\0\0", 1, 4, fp); // bit depth and color type
    fwrite("\0", 1, 1, fp);      // compression method
    fwrite("\0", 1, 1, fp);      // filter method
    fwrite("\0", 1, 1, fp);      // interlace method

    // Now completing IHDR with width and height
    unsigned int width_n = htonl(size);
    unsigned int height_n = htonl(size);
    fseek(fp, 16, SEEK_SET);
    fwrite(&width_n, sizeof(width_n), 1, fp);
    fwrite(&height_n, sizeof(height_n), 1, fp);
    
    fclose(fp);
    free(image);
    printf("QR Code saved as %s! Happy scanning!\n", filename);
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *data = argv[1];
    printf("Generating QR code for the text: \"%s\"\n", data);

    QRcode *qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR code! Please double-check your data.\n");
        return EXIT_FAILURE;
    }

    char filename[256];
    snprintf(filename, sizeof(filename), "qrcode.png");

    if (save_png(filename, qrcode) != 0) {
        QRcode_free(qrcode);
        return EXIT_FAILURE;
    }

    QRcode_free(qrcode);
    printf("Your QR Code has been successfully generated and stored in %s!\n", filename);
    printf("Scan it with your favorite QR code reader.\n");
    printf("Thank you for using the QR Code Generator! Happy Coding!\n");

    return EXIT_SUCCESS;
}
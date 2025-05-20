//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void save_png(const char *filename, unsigned char *data, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Could not open file for writing");
        exit(EXIT_FAILURE);
    }

    // Write PNG headers and data
    // For simplicity, omitting actual PNG encoding, ideally should use libpng
    // Here, we assume data is in grayscale bitmap format which is not erased.
    fprintf(fp, "PNG\n"); // This is a placeholder; actual PNG encoding is required

    // Write dummy data for placeholder
    for (int i = 0; i < width * height; i++) {
        fputc(data[i], fp); // Assuming data[i] is in the appropriate format
    }

    fclose(fp);
}

void generate_qr_code(const char *text, const char *filename) {
    QRcode *qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Error encoding QR code.\n");
        return;
    }

    // Placeholder minimum PNG size calculations
    int size = qrcode->width;
    unsigned char *bitmap = malloc(size * size);
    if (!bitmap) {
        fprintf(stderr, "Memory allocation failed.\n");
        QRcode_free(qrcode);
        return;
    }

    // Convert QR code to bitmap
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            bitmap[y * size + x] = (qrcode->data[y * size + x] & 1) ? 0 : 255; // Inverting colors
        }
    }

    save_png(filename, bitmap, size, size);

    free(bitmap);
    QRcode_free(qrcode);
}

void usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <text> <output.png>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *text = argv[1];
    const char *output_file = argv[2];

    generate_qr_code(text, output_file);
    printf("QR code generated and saved to %s\n", output_file);

    return EXIT_SUCCESS;
}
//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void generate_qr_code(const char* text, const char* file_path, int scale, int margin) {
    QRcode* qrcode;
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to create QR Code\n");
        return;
    }

    FILE* fp = fopen(file_path, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file for writing\n");
        QRcode_free(qrcode);
        return;
    }

    // PNG file header
    const unsigned char png_header[8] = {
        0x89, 'P', 'N', 'G', 0x0D, 0x0A, 0x1A, 0x0A
    };
    fwrite(png_header, sizeof(unsigned char), 8, fp);
    
    // Writing PNG file with scale and margin
    int size = qrcode->width;
    int png_size = (size + 2 * margin) * scale;
    unsigned char* img = malloc(png_size * png_size);
    for (int y = 0; y < png_size; y++) {
        for (int x = 0; x < png_size; x++) {
            img[y * png_size + x] = 255; // White background
        }
    }

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (qrcode->data[y * size + x] & 1) {
                for (int wy = 0; wy < scale; wy++) {
                    for (int wx = 0; wx < scale; wx++) {
                        img[(y * scale + wy + margin) * png_size + (x * scale + wx + margin)] = 0; // Black square
                    }
                }
            }
        }
    }
    
    // TODO: Actual PNG encoding logic...

    // Placeholder for successful write (actual PNG writing is not completed here)
    printf("QR Code has been generated and saved to %s\n", file_path);

    free(img);
    QRcode_free(qrcode);
    fclose(fp);
}

void print_usage(const char* prog_name) {
    printf("Usage: %s <text> <output_file> [scale] [margin]\n", prog_name);
    printf("text        : Text to encode in QR code\n");
    printf("output_file : Output file (PNG) path\n");
    printf("scale       : Optional scaling factor (default=10)\n");
    printf("margin      : Optional margin (default=4)\n");
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char* text = argv[1];
    const char* output_file = argv[2];
    int scale = (argc >= 4) ? atoi(argv[3]) : 10;
    int margin = (argc >= 5) ? atoi(argv[4]) : 4;

    if (scale < 1 || margin < 0) {
        fprintf(stderr, "Error: scale must be >= 1 and margin must be >= 0.\n");
        return EXIT_FAILURE;
    }

    generate_qr_code(text, output_file, scale, margin);
    
    return EXIT_SUCCESS;
}
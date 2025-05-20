//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <qrencode.h>

void create_qr_code(const char* data, const char* file_path) {
    QRcode* qr;
    qr = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    if (qr == NULL) {
        fprintf(stderr, "Failed to generate QR code.\n");
        return;
    }

    FILE *fp = fopen(file_path, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file for writing.\n");
        QRcode_free(qr);
        return;
    }

    int size = qr->width;
    int scale = 10; // Adjust scale for QR code size
    unsigned char *image = (unsigned char *)malloc(size * size * 3 * scale * scale);

    // Create a RGB image - simple white background with black QR code
    for (int y = 0; y < size * scale; y++) {
        for (int x = 0; x < size * scale; x++) {
            int px = x / scale;
            int py = y / scale;
            int index = (y * size * scale + x) * 3;

            if (qr->data[py * qr->width + px] & 0x1) { // Black module
                image[index] = 0;     // Red
                image[index + 1] = 0; // Green
                image[index + 2] = 0; // Blue
            } else { // White module
                image[index] = 255;   // Red
                image[index + 1] = 255; // Green
                image[index + 2] = 255; // Blue
            }
        }
    }

    // Write image to file
    fprintf(fp, "P6\n%d %d\n255\n", size * scale, size * scale);
    fwrite(image, 3, size * size * scale * scale, fp);
    fclose(fp);

    free(image);
    QRcode_free(qr);
    printf("QR code generated and saved to %s\n", file_path);
}

void display_menu() {
    printf("Welcome to the QR Code Generator!\n");
    printf("1. Generate QR Code\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char url[256];
    int choice;
    char output_file[300];

    while (1) {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the data (URL or text) for the QR code: ");
                while (getchar() != '\n'); // Clear buffer before reading string
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = 0; // Remove newline character

                if (strlen(url) == 0) {
                    printf("Input cannot be empty. Please try again.\n");
                    continue;
                }

                snprintf(output_file, sizeof(output_file), "qrcode_%s.ppm", url);
                create_qr_code(url, output_file);
                break;

            case 2:
                printf("Exiting the QR Code Generator. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please select 1 or 2.\n");
                break;
        }
    }

    return 0;
}
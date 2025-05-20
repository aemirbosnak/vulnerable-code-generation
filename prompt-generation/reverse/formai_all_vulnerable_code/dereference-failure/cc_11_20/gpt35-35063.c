//FormAI DATASET v1.0 Category: QR code reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: QRreader <filename>\n");
        return -1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", argv[1]);
        return -1;
    }

    // Determine the file size
    fseek(fp, 0, SEEK_END);
    long f_size = ftell(fp);
    rewind(fp);

    // Allocate memory for file contents
    char* f_contents = (char*)malloc(sizeof(char) * f_size);
    if (f_contents == NULL) {
        printf("Error: Not enough memory to read file %s\n", argv[1]);
        return -1;
    }

    // Read file contents into memory
    size_t result = fread(f_contents, 1, f_size, fp);
    if (result != f_size) {
        printf("Error: Failed to read file %s\n", argv[1]);
        return -1;
    }

    // Generate QR code from file contents
    QRcode* qr = QRcode_encodeString(f_contents, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
    if (qr == NULL) {
        printf("Error: Failed to generate QR code from file contents\n");
        return -1;
    }

    // Print QR code to console
    int width = qr->width, i, j;
    for (i = 0; i < width + 4; i++) {
        printf("-");
    }
    printf("\n");
    for (i = 0; i < width; i++) {
        printf("| ");
        for (j = 0; j < width; j++) {
            if (qr->data[i * width + j] & 1) {
                printf("##");
            } else {
                printf("  ");
            }
        }
        printf(" |\n");
    }
    for (i = 0; i < width + 4; i++) {
        printf("-");
    }

    // Cleanup
    QRcode_free(qr);
    free(f_contents);
    fclose(fp);

    return 0;
}
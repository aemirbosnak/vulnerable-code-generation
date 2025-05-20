//FormAI DATASET v1.0 Category: QR code reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void print_qr(QRcode *code) {
    // Print the QR code to the console
    int width = code->width;

    // Print top border
    for (int i = 0; i < width + 4; i++) {
        printf("#");
    }
    printf("\n");

    // Print side borders and QR code
    for (int i = 0; i < width; i++) {
        printf("#  ");
        for (int j = 0; j < width; j++) {
            if (code->data[i*width + j] & 1) {
                printf("  ");
            } else {
                printf("\u2588\u2588");
            }
        }
        printf("  #\n");
    }

    // Print bottom border
    for (int i = 0; i < width + 4; i++) {
        printf("#");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    // Check for argument
    if (argc < 2) {
        printf("Error: Please provide a file name.\n");
        return -1;
    }

    // Read in file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to read file %s.\n", argv[1]);
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);
    char *file_contents = (char*)malloc(file_size + 1);
    fread(file_contents, file_size, 1, fp);
    fclose(fp);
    file_contents[file_size] = '\0';

    // Generate QR code
    QRcode *code = QRcode_encodeString(file_contents, 0, QR_ECLEVEL_M, QR_MODE_8, 1);
    free(file_contents);

    // Print QR code
    print_qr(code);

    // Free QR code
    QRcode_free(code);

    return 0;
}
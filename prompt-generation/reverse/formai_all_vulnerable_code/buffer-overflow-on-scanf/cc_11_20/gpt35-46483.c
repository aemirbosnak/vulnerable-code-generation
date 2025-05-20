//FormAI DATASET v1.0 Category: QR code generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[])
{
    // set default values for QR code image size and error correction level
    int qr_size = 5;
    QRecLevel qr_level = QR_ECLEVEL_L;

    // parse command line options to modify QR code image size and error correction level
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-s") == 0) {
            qr_size = atoi(argv[i+1]);
        }

        if (strcmp(argv[i], "-l") == 0) {
            char *level = argv[i+1];
            if (strcmp(level, "L") == 0) {
                qr_level = QR_ECLEVEL_L;
            } else if (strcmp(level, "M") == 0) {
                qr_level = QR_ECLEVEL_M;
            } else if (strcmp(level, "Q") == 0) {
                qr_level = QR_ECLEVEL_Q;
            } else if (strcmp(level, "H") == 0) {
                qr_level = QR_ECLEVEL_H;
            } else {
                printf("Invalid error correction level specified. Defaulting to L.\n");
            }
        }
    }

    // prompt user for input data
    char input[100];
    printf("Enter data to generate QR code: ");
    scanf("%s", input);

    // generate QR code using qrencode library
    QRcode *qr = QRcode_encodeString(input, 0, qr_level, QR_MODE_8, 1);

    // print QR code to console using ASCII art
    for (int row = 0; row < qr->width; row++) {
        for (int col = 0; col < qr->width; col++) {
            int module = *(qr->data + row*qr->width + col);
            printf(module ? "##" : "  ");
        }
        printf("\n");
    }

    // free memory used by qrencode library
    QRcode_free(qr);

    return 0;
}
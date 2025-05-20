//FormAI DATASET v1.0 Category: QR code generator ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<qrencode.h>

int main(int argc, char **argv) {
    QRcode *qrcode;
    FILE *fp;
    char *text = "Hello, World!";
    int size = 10;
    int margin = 4;
    int version = 2;
    int level = QR_ECLEVEL_Q;
    int casesensitive = 1;

    if (argc > 1) {
        size = atoi(argv[1]);
    }
    if (argc > 2) {
        margin = atoi(argv[2]);
    }
    if (argc > 3) {
        version = atoi(argv[3]);
    }
    if (argc > 4) {
        if (argv[4][0] == 'L') {
            level = QR_ECLEVEL_L;
        } else if (argv[4][0] == 'M') {
            level = QR_ECLEVEL_M;
        } else if (argv[4][0] == 'Q') {
            level = QR_ECLEVEL_Q;
        } else if (argv[4][0] == 'H') {
            level = QR_ECLEVEL_H;
        }
    }
    if (argc > 5) {
        text = argv[5];
    }

    qrcode = QRcode_encodeString(text, 0, level, version, casesensitive);
    if (qrcode == NULL) {
        fprintf(stderr, "QRcode_encodeString failed\n");
        return -1;
    }
    fp = fopen("qrcode.png", "wb");
    if (fp == NULL) {
        perror("fopen");
        QRcode_free(qrcode);
        return -1;
    }
    // Below code writes the QR code data as PNG image to file
    fwrite(qrcode->data, qrcode->width * qrcode->width, 1, fp);
    fclose(fp);
    QRcode_free(qrcode);
    return 0;
}
//FormAI DATASET v1.0 Category: QR code generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char **argv) {
    QRcode *qr;
    char *data;
    int version, width, margin;
    FILE *fp;
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <data>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    data = argv[1];
    version = 0;
    width = 3;
    margin = 4;
    
    qr = QRcode_encodeString(data, version, QR_ECLEVEL_Q, QR_MODE_8, 1);
    if (qr == NULL) {
        fprintf(stderr, "QRencode failed\n");
        return EXIT_FAILURE;
    }
    
    fp = fopen("qrcode.pbm", "wb");
    if (fp == NULL) {
        fprintf(stderr, "Can't create output file\n");
        return EXIT_FAILURE;
    }
    
    fprintf(fp, "P1\n%d %d\n", qr->width + margin*2, qr->width + margin*2);
    for (int i = -margin; i < qr->width+margin; i++) {
        for (int j = -margin; j < qr->width+margin; j++) {
            int x = j + margin;
            int y = i + margin;
            if (i < 0 || j < 0 || i >= qr->width || j >= qr->width) {
                fprintf(fp, "0 ");
            } else {
                fprintf(fp, "%d ", qr->data[i*qr->width+j]&1);
            }
        }
        fprintf(fp, "\n");
    }
    
    fclose(fp);
    QRcode_free(qr);
    printf("QR code generated successfully!\n");
    return EXIT_SUCCESS;
}
//FormAI DATASET v1.0 Category: QR code generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h> // for QRcode

int main(void) {
    char *input_string;
    QRcode *qr_code;
    int version = 6, width = 3;
    int input_len, qr_size, margin;
    FILE *fp;
    unsigned char *row, *p;

    printf("Welcome to the C QR code generator!\n");
    printf("Please enter the string you want to convert to QR code: \n");

    // Get user input string
    scanf("%[^\n]", input_string);

    // Get length of input string
    input_len = strlen(input_string);

    // Create QR code from input string
    qr_code = QRcode_encodeString(input_string, version, QR_ECLEVEL_M, QR_MODE_8, 1);

    // Get size of QR code
    qr_size = qr_code->width;

    // Print QR code to console
    margin = width;
    row = (unsigned char *) malloc((qr_size + margin * 2) * width);
    memset(row, 0xff, (qr_size + margin * 2) * width);

    for (int i = 0; i < margin; i++) {
        fwrite(row, 1, (qr_size + margin * 2) * width, stdout);
        printf("\n");
    }
    for (int i = 0; i < qr_size; i++) {
        p = qr_code->data + i * qr_size;
        memset(row, 0xff, margin * width);
        for (int j = 0; j < qr_size; j++) {
            for (int k = 0; k < width; k++) {
                fwrite(p, 1, 1, stdout);
                fwrite(p, 1, 1, stdout);
                p++;
            }
        }
        memset(row, 0xff, margin * width);
        fwrite(row, 1, margin * width, stdout);
        printf("\n");
    }
    for (int i = 0; i < margin; i++) {
        fwrite(row, 1, (qr_size + margin * 2) * width, stdout);
        printf("\n");
    }

    // Save QR code to file
    fp = fopen("qr_code.png", "wb");
    fwrite(qr_code->data, qr_size, qr_size, fp);
    fclose(fp);

    printf("Your QR code has been saved to qr_code.png!\n");

    // Free allocated memory
    QRcode_free(qr_code);
    free(row);
    free(input_string);

    return 0;
}
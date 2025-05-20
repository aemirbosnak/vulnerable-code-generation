//FormAI DATASET v1.0 Category: QR code generator ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<qrencode.h>

int main() {

    // Defining the variables
    QRcode *qrcode;
    unsigned char *string;
    char input[1000];
    FILE *output;
    int i, j, length;

    // Asking for the text input from user
    printf("Enter the text: ");
    scanf("%[^\n]", input);

    // Get the length of the string
    length = strlen(input);

    // Generating QR Code
    qrcode = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Display the QR Code
    for(i=0; i<qrcode->width+4; i++) {
        printf("x");
    }
    printf("\n");

    for(i=0; i<qrcode->width; i++) {
        printf("x  ");
        for(j=0; j<qrcode->width; j++) {
            if(qrcode->data[i*qrcode->width+j]&1) {
                printf("  ");
            } else {
                printf("x ");
            }
        }
        printf("  x\n");
    }

    for(i=0; i<qrcode->width+4; i++) {
        printf("x");
    }
    printf("\n");

    // Save the QR code as PNG file
    output = fopen("qrcode.png", "wb");
    if(output == NULL) {
        printf("Error: Could not create QR code file.\n");
        return 0;
    } else {
        QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
        fwrite(qrcode->data, qrcode->width*qrcode->width, 1, output);
        fclose(output);
        printf("QR Code saved as qrcode.png file.\n");
    }

    // Freeing up the memory allocated
    QRcode_free(qrcode);

    return 0;
}
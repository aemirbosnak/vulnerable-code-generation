//FormAI DATASET v1.0 Category: QR code generator ; Style: authentic
#include <stdio.h>
#include <qrencode.h>

int main()
{
    // Get the text to encode
    char text[100];
    printf("Enter the text to encode: ");
    scanf("%s", text);

    // Set up the QR code options
    QRcode *qrcode;
    QRecLevel level = QR_ECLEVEL_L;
    int size = 5;
    int margin = 2;

    // Generate the QR code
    qrcode = QRcode_encodeString(text, 0, level, QR_MODE_8, 1);
    if (qrcode == NULL) {
        printf("Error: Unable to generate QR code\n");
        return 1;
    }

    // Print the QR code
    printf("\nQR Code:\n");
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            if (qrcode->data[y * qrcode->width + x] & 1) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }

    // Save the QR code as a PNG file
    char filename[100];
    printf("\nEnter the filename to save the QR code (without extension): ");
    scanf("%s", filename);

    FILE *fp = fopen(strcat(filename, ".png"), "wb");
    if (fp == NULL) {
        printf("Error: Unable to save QR code as PNG file\n");
        return 1;
    }

    int code = fwrite(qrcode->data, 1, qrcode->width * qrcode->width, fp);
    fclose(fp);

    // Check if saved successfully
    if (code != qrcode->width * qrcode->width) {
        printf("Error: Unable to save QR code as PNG file\n");
        return 1;
    }

    // Free the QR code memory
    QRcode_free(qrcode);

    printf("\nQR code has been saved as %s.png\n", filename);
    return 0;
}
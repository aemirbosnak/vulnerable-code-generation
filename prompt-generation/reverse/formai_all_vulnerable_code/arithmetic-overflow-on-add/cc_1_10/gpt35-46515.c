//FormAI DATASET v1.0 Category: QR code generator ; Style: introspective
#include <stdio.h>
#include <qrencode.h>

int main()
{
    // Input string to be converted
    char inputString[256];
    printf("Enter a string to convert into QR code: ");
    scanf("%s", inputString);

    // Specify the error correction level
    QRecLevel ecLevel = QR_ECLEVEL_H;

    // Specify the QR code version (1 - 40)
    int version = 5;

    // Create a new QR code object
    QRcode *qrCode = QRcode_encodeString(inputString, 0, ecLevel, QR_MODE_8, 1);
    if(qrCode == NULL)
    {
        fprintf(stderr, "Failed to encode QR code!\n");
        return -1;
    }

    // Print the QR code in console
    printf("\nQR code of entered string:\n\n");
    for(int i = 0; i < qrCode->width + 4; i++) printf("██");
    printf("██\n");
    for(int i = 0; i < qrCode->width; i++)
    {
        printf("██");
        for(int j = 0; j < qrCode->width; j++)
        {
            if((qrCode->data[i * qrCode->width + j] & 1) == 1)
            {
                printf("  ");
            }
            else
            {
                printf("██");
            }
        }
        printf("██\n");
    }
    for(int i = 0; i < qrCode->width + 4; i++) printf("██");
    printf("██\n\n");

    // Free memory allocated for QR code object
    QRcode_free(qrCode);

    return 0;
}
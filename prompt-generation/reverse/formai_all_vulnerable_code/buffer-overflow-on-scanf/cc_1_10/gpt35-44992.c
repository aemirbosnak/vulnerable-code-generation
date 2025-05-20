//FormAI DATASET v1.0 Category: QR code generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main()
{
    char data[100];
    int pixel_size, version, err = -1;
    QRcode *qr;

    printf("Enter the data to be encoded: ");
    fgets(data, sizeof(data), stdin);

    data[strcspn(data, "\n")] = '\0'; //remove newline character

    printf("Enter pixel size of QR code (between 1-10): ");
    scanf("%d", &pixel_size);

    printf("Enter QR code version (between 1-40): ");
    scanf("%d", &version);

    printf("Generating QR code...\n\n");

    qr = QRcode_encodeString(data, version, QR_ECLEVEL_L, QR_MODE_8, 1);

    printf("QR code data:\n%s\n", data);
    printf("Pixel size: %d\n", pixel_size);
    printf("Version: %d\n\n", version);

    int width = qr->width;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int index = j * width + i;
            if (qr->data[index] & 0x01)
            {
                for (int k = 0; k < pixel_size; k++)
                {
                    printf("**");
                }
            }
            else
            {
                for (int k = 0; k < pixel_size; k++)
                {
                    printf("  ");
                }
            }
        }
        printf("\n");
    }

    QRcode_free(qr);

    return 0;
}
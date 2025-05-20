//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define BLACK "█"
#define WHITE "  "

int generateQRCode(char data[], int size) {
    int version = 1;
    int errorCorrectionLevel = 0;
    int maskPattern = 0;
    int numDataCodewords = (size - 21) * 8;
    int numRSBlocks = (numDataCodewords + 7) / 8;
    int numErrorCorrectionCodewords = (numRSBlocks - 1) * 10 + 7;
    int totalCodewords = numDataCodewords + numErrorCorrectionCodewords;
    int i, j, k, count, value, pattern;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if ((i == 0 || i == size - 1) && (j == 0 || j == size - 1)) {
                pattern = 1;
            } else if ((i == 0 || i == size - 1) && (j!= 0 && j!= size - 1)) {
                pattern = 2;
            } else if ((i!= 0 && i!= size - 1) && (j == 0 || j == size - 1)) {
                pattern = 4;
            } else {
                pattern = 8;
            }

            value = (data[k] >> (7 - j)) & 1;

            if (value == 1) {
                if (pattern == 1 || pattern == 2 || pattern == 4) {
                    printf(BLACK);
                } else {
                    printf(WHITE);
                }
            } else {
                if (pattern == 1 || pattern == 2 || pattern == 8) {
                    printf(WHITE);
                } else {
                    printf(BLACK);
                }
            }

            count++;

            if (count == 8) {
                count = 0;
                k++;
            }
        }

        printf("\n");
    }

    return 0;
}

int main() {
    char data[MAX_SIZE];
    int size;

    printf("Enter the data to encode: ");
    scanf("%s", data);

    printf("Enter the size of the QR code: ");
    scanf("%d", &size);

    srand(time(0));
    int qrCodeSize = size + 2;

    printf("\n");

    for (int i = 0; i < qrCodeSize; i++) {
        printf(WHITE);
    }

    printf("\n");

    for (int i = 0; i < qrCodeSize; i++) {
        printf(BLACK);
    }

    printf("\n");

    generateQRCode(data, size);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define QR_MAX 177
#define QR_SIZE 21
#define QR_DATA (QR_MAX - 40)

/* QR code generator function */
void generate_qrcode(char *data, int size) {
    int i, j, pos = 0;
    char *qr_data = malloc(QR_DATA * sizeof(char));

    /* Add padding to data */
    for (i = 0; i < QR_DATA - strlen(data); i++) {
        strcat(data, "0");
    }

    /* Add error correction data */
    for (i = 0; i < QR_DATA; i += 2) {
        qr_data[i] = data[pos++];
    }

    /* Fill in QR code pattern */
    for (i = 0; i < QR_MAX; i++) {
        for (j = 0; j < QR_MAX; j++) {
            if (i >= QR_SIZE && j >= QR_SIZE) {
                if (qr_data[i - QR_SIZE] == '1') {
                    printf("  ");
                } else {
                    printf("██");
                }
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    free(qr_data);
}

int main() {
    char data[QR_DATA];
    int size;

    /* Get data and size from user input */
    printf("Enter data to encode in QR code: ");
    scanf("%s", data);
    printf("Enter QR code size (1-40): ");
    scanf("%d", &size);

    /* Generate QR code */
    generate_qrcode(data, size);

    return 0;
}
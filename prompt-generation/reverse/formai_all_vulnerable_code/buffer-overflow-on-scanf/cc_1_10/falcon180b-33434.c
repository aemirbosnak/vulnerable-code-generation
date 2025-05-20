//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define QR_MAX_SIZE 256
#define QR_MAX_DATA_SIZE (QR_MAX_SIZE - 17)

typedef struct {
    int size;
    int data_size;
    int *data;
} qr_t;

void qr_init(qr_t *qr, int size) {
    qr->size = size;
    qr->data_size = 0;
    qr->data = malloc(QR_MAX_DATA_SIZE * sizeof(int));
}

void qr_add_data(qr_t *qr, int data) {
    if (qr->data_size >= QR_MAX_DATA_SIZE) {
        printf("Error: data size exceeds limit\n");
        exit(1);
    }

    qr->data[qr->data_size++] = data;
}

void qr_generate(qr_t *qr) {
    int i, j, k, n, m, s;
    int *data = qr->data;
    int data_size = qr->data_size;
    int size = qr->size;
    int mask = 0x80;
    int bit = 0;
    int count = 0;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            bit = 0;
            for (k = 0; k < 8; k++) {
                n = (i + k - 1) / 3;
                m = (j + k - 1) / 3;
                s = (n / 6) + (m / 3);
                bit |= (data[s] >> (7 - k)) & 1;
            }

            for (k = 0; k < 8; k++) {
                if (bit & 1) {
                    printf("X");
                } else {
                    printf(" ");
                }
                bit >>= 1;
            }
        }
        printf("\n");
    }
}

int main() {
    qr_t qr;
    int i, data;
    char *input;

    printf("Enter data to encode: ");
    scanf("%s", input);

    qr_init(&qr, 21);

    for (i = 0; i < strlen(input); i++) {
        data = input[i] - '0';
        qr_add_data(&qr, data);
    }

    qr_generate(&qr);

    free(qr.data);
    return 0;
}
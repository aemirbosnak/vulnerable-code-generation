//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *generate_qr_code(int version, int level, char *data) {
    int size = (version - 1) * 4 + 17;
    int i, j, k, n, m, p, q;
    int bit_count = 0;
    int data_bits = strlen(data) * 8;
    int num_modules = size * size;
    int *bit_matrix = (int *) malloc(num_modules * sizeof(int));

    if (bit_matrix == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }

    for (i = 0; i < num_modules; i++) {
        bit_matrix[i] = 0;
    }

    for (i = 0; i < data_bits; i++) {
        if (data[i / 8] & (1 << (7 - i % 8))) {
            bit_matrix[bit_count / size] |= 1 << (bit_count % size);
        }
        bit_count++;
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (bit_matrix[i * size + j] == 0) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }

    free(bit_matrix);

    return 0;
}

int main() {
    int version, level;
    char *data;

    printf("Enter the version of the QR code (1-40): ");
    scanf("%d", &version);

    printf("Enter the error correction level (L/M/Q/H): ");
    scanf(" %c", &level);

    printf("Enter the data to be encoded: ");
    scanf("%s", data);

    generate_qr_code(version, level, data);

    return 0;
}
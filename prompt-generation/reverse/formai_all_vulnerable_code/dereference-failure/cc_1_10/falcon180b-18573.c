//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 177
#define MAX_MODULES 144
#define MAX_LENGTH 16

int get_bit(int value, int bit) {
    return (value >> bit) & 1;
}

int get_value(int x, int y, int module_size) {
    int value = 0;
    int bit = 0;
    for (int i = 0; i < module_size; i++) {
        if (get_bit(x, i + y * module_size)) {
            value += 1 << bit;
        }
        bit++;
    }
    return value;
}

void decode_qr(int **qr, int size, int *values) {
    int module_size = size / MAX_MODULES;
    int x, y;
    for (int i = 0; i < size; i++) {
        x = i % module_size;
        y = i / module_size;
        int value = get_value(x, y, module_size);
        values[i] = value;
    }
}

int main() {
    int size;
    printf("Enter QR code size: ");
    scanf("%d", &size);

    int **qr = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        qr[i] = (int *) malloc(size * sizeof(int));
    }

    int values[MAX_LENGTH];

    int x, y;
    printf("Enter QR code values:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &qr[i][j]);
        }
    }

    decode_qr(qr, size, values);

    printf("Decoded values:\n");
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (values[i]!= -1) {
            printf("%d ", values[i]);
        }
    }

    for (int i = 0; i < size; i++) {
        free(qr[i]);
    }
    free(qr);

    return 0;
}
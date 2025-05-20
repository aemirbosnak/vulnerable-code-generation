//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to generate QR code
void generate_qr_code(char* data, int size) {
    int i, j, k, count = 0, temp;
    int qr_size = size * size;
    int data_size = strlen(data);
    int* qr_data = (int*) malloc(qr_size * sizeof(int));

    // Calculate the size of the QR code
    for (i = 0; i < data_size; i++) {
        count++;
        if (data[i] == '\n') {
            count++;
        }
    }

    // Generate the QR code
    for (i = 0; i < qr_size; i++) {
        qr_data[i] = 0;
    }

    i = 0;
    j = 0;
    k = 0;
    while (i < qr_size) {
        if (k == 0) {
            temp = (i / 3) % 2;
            if (temp == 0) {
                j++;
            } else {
                j--;
            }
            k = 1;
        } else {
            k--;
        }

        if (j >= 0 && j < qr_size && qr_data[i] == 0) {
            qr_data[i] = 1;
        }

        i++;
    }

    // Print the QR code
    for (i = 0; i < qr_size; i++) {
        for (j = 0; j < qr_size; j++) {
            if (qr_data[i * qr_size + j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    free(qr_data);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <data> <size>\n", argv[0]);
        return 1;
    }

    char* data = argv[1];
    int size = atoi(argv[2]);

    if (size > MAX_SIZE || size < 1) {
        printf("Invalid size\n");
        return 1;
    }

    generate_qr_code(data, size);

    return 0;
}
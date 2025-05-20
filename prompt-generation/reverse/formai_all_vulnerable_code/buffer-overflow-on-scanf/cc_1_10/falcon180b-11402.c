//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLACK 0
#define WHITE 1

// Function to create QR code
void create_qr_code(int size, char* input_data) {
    int data_size = strlen(input_data);
    int qr_size = size * size;
    int qr_data_size = qr_size * qr_size;
    int i, j, k;
    int qr_data[qr_data_size];
    int data_index = 0;
    int qr_index = 0;

    // Initialize QR data
    for (i = 0; i < qr_size; i++) {
        for (j = 0; j < qr_size; j++) {
            qr_data[qr_index++] = WHITE;
        }
    }

    // Add data to QR code
    for (i = 0; i < qr_size; i++) {
        for (j = 0; j < qr_size; j++) {
            if (i < size && j < size) {
                if (input_data[data_index] == '0') {
                    qr_data[qr_index++] = BLACK;
                } else {
                    qr_data[qr_index++] = WHITE;
                }
            } else {
                qr_data[qr_index++] = WHITE;
            }
        }
    }

    // Print QR code
    for (i = 0; i < qr_size; i++) {
        for (j = 0; j < qr_size; j++) {
            if (qr_data[i*qr_size + j] == BLACK) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    int size = rand() % 10 + 1;
    char input_data[100];
    printf("Enter data to encode in QR code: ");
    scanf("%s", input_data);
    create_qr_code(size, input_data);
    return 0;
}
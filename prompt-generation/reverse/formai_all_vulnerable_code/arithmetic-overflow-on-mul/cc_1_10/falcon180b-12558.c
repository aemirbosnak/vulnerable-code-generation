//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate QR code
void generate_qrcode(char *input, int size) {
    int i, j, k, count = 0;
    int qr_size = size * size;
    int **qr_code = (int **)malloc(qr_size * sizeof(int *));
    for (i = 0; i < qr_size; i++) {
        qr_code[i] = (int *)malloc(qr_size * sizeof(int));
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (input[count] == '1') {
                qr_code[i][j] = 1;
            } else {
                qr_code[i][j] = 0;
            }
            count++;
        }
    }

    // Print QR code
    for (i = 0; i < qr_size; i++) {
        for (j = 0; j < qr_size; j++) {
            if (qr_code[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < qr_size; i++) {
        free(qr_code[i]);
    }
    free(qr_code);
}

int main() {
    char input[100];
    int size;

    // Get input from user
    printf("Enter input: ");
    scanf("%s", input);

    // Get QR code size from user
    printf("Enter QR code size: ");
    scanf("%d", &size);

    // Generate QR code
    generate_qrcode(input, size);

    return 0;
}
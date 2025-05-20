//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void qr_decoder(char *input) {
    int len = strlen(input);
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            count++;
        }
    }

    if (count % 2 == 0) {
        printf("Invalid QR code\n");
        return;
    }

    int num_rows = count / 2;
    int row_size = len / num_rows;

    int **matrix = (int **)malloc(num_rows * sizeof(int *));

    for (int i = 0; i < num_rows; i++) {
        matrix[i] = (int *)malloc(row_size * sizeof(int));
    }

    int row = 0, col = 0;

    for (int i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            matrix[row][col++] = input[i] - '0';

            if (col == row_size) {
                row++;
                col = 0;
            }
        }
    }

    int data_bits = 0;

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < row_size; j++) {
            if (matrix[i][j] == 1) {
                data_bits += 1;
            }
        }
    }

    printf("Data bits: %d\n", data_bits);

    free(matrix);
}

int main() {
    char input[1000];

    printf("Enter QR code: ");
    scanf("%s", input);

    qr_decoder(input);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to read QR code
void read_qr_code(int **qr_code, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &qr_code[i][j]);
        }
    }
}

// Function to display QR code
void display_qr_code(int **qr_code, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", qr_code[i][j]);
        }
        printf("\n");
    }
}

// Function to decode QR code
void decode_qr_code(int **qr_code, int rows, int cols) {
    int i, j;
    char *decoded_message = malloc(cols * sizeof(char));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (qr_code[i][j] == 1) {
                decoded_message[j] = '1';
            } else {
                decoded_message[j] = '0';
            }
        }
        printf("%s\n", decoded_message);
    }
    free(decoded_message);
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns of the QR code: ");
    scanf("%d %d", &rows, &cols);

    int **qr_code = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        qr_code[i] = malloc(cols * sizeof(int));
    }

    read_qr_code(qr_code, rows, cols);
    display_qr_code(qr_code, rows, cols);
    decode_qr_code(qr_code, rows, cols);

    return 0;
}
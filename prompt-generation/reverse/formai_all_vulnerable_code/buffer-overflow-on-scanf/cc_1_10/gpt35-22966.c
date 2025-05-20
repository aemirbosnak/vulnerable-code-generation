//FormAI DATASET v1.0 Category: QR code generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 21
#define MAX_COLS 21

void generateQR(int qr[MAX_ROWS][MAX_COLS], int n) {
    int row, col, i, j;
    int start_row = 0, start_col = 0;

    for (i = 0; i < n; i++) {
        // Fill top left corner
        for (row = start_row; row < MAX_ROWS && row < start_row + 5; row++) {
            for (col = start_col; col < MAX_COLS && col < start_col + 5; col++) {
                qr[row][col] = 1;
            }
        }
        // Fill top right corner
        start_col += 16;
        for (row = start_row; row < MAX_ROWS && row < start_row + 5; row++) {
            for (col = start_col; col < MAX_COLS && col < start_col + 5; col++) {
                qr[row][col] = 1;
            }
        }
        // Fill bottom left corner
        start_col = 0;
        start_row += 16;
        for (row = start_row; row < MAX_ROWS && row < start_row + 5; row++) {
            for (col = start_col; col < MAX_COLS && col < start_col + 5; col++) {
                qr[row][col] = 1;
            }
        }
    }
}

void printQR(int qr[MAX_ROWS][MAX_COLS], int n) {
    int row, col;

    for (row = 0; row < n*21; row++) {
        for (col = 0; col < n*21; col++) {
            if (qr[row][col]) {
                printf("██");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int qr[MAX_ROWS][MAX_COLS] = {0};
    int n;

    printf("Enter qr code size (1-20): ");
    scanf("%d", &n);
    if (n < 1 || n > 20) {
        printf("Invalid n!\n");
        return 0;
    }

    generateQR(qr, n);
    printQR(qr, n);

    return 0;
}
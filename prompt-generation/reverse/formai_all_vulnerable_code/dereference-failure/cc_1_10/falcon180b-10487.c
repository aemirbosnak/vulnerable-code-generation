//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_VALUE 10
#define MIN_VALUE 1

void generate_qr_code(int **code, int width, int height) {
    int i, j;
    int value = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                value = MAX_VALUE;
            } else {
                value = rand() % MAX_VALUE + MIN_VALUE;
            }
            code[i][j] = value;
        }
    }
}

void print_qr_code(int **code, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", code[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int width, height;
    printf("Enter the width of the QR code: ");
    scanf("%d", &width);
    printf("Enter the height of the QR code: ");
    scanf("%d", &height);

    int **code = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        code[i] = (int *)malloc(width * sizeof(int));
    }

    generate_qr_code(code, width, height);
    printf("\nQR Code:\n");
    print_qr_code(code, width, height);

    for (int i = 0; i < height; i++) {
        free(code[i]);
    }
    free(code);

    return 0;
}
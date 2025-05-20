//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WIDTH 10
#define HEIGHT 10
#define BLACK 'X'
#define WHITE''

char *generate_qrcode(char *input) {
    int len = strlen(input);
    int size = WIDTH * HEIGHT;
    char *qrcode = malloc(size * sizeof(char));

    int i, j, k, n, m, s, t;
    int c = 0;

    for (i = 0; i < len; i++) {
        c += input[i] - '0';
    }

    c = (c * 10) % 103;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            qrcode[c] = BLACK;
            c = (c + 1) % size;
        }
    }

    return qrcode;
}

int main() {
    srand(time(NULL));

    int width, height;
    printf("Enter the width of the QR code: ");
    scanf("%d", &width);
    printf("Enter the height of the QR code: ");
    scanf("%d", &height);

    char *qrcode = generate_qrcode("Surrealist QR Code Generator");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", qrcode[i * width + j]);
        }
        printf("\n");
    }

    return 0;
}
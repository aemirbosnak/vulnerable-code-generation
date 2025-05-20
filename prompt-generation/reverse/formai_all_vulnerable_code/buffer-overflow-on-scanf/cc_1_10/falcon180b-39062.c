//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char qr_code[MAX_SIZE];
    int qr_size;
    int i, j, k, l;
    int color;
    int x, y, z;
    int red, green, blue;
    char ch;
    int count = 0;

    // Get QR code from user
    printf("Enter QR code: ");
    scanf("%[^\n]", qr_code);

    // Calculate size of QR code
    for (i = 0; i < strlen(qr_code); i++) {
        if (qr_code[i] == '\n') {
            qr_size = i;
            break;
        }
    }

    // Initialize colors
    red = 0;
    green = 0;
    blue = 0;

    // Loop through QR code
    for (i = 0; i < qr_size; i++) {
        for (j = 0; j < qr_size; j++) {
            // Get color of pixel
            ch = qr_code[i * qr_size + j];
            if (ch == '0') {
                red = 0;
                green = 0;
                blue = 0;
            } else if (ch == '1') {
                red = 255;
                green = 255;
                blue = 255;
            } else {
                printf("Invalid QR code\n");
                exit(1);
            }

            // Print pixel
            printf("\e[48;2;%d;%d;%dm ", red, green, blue);
        }
        printf("\n");
    }

    return 0;
}
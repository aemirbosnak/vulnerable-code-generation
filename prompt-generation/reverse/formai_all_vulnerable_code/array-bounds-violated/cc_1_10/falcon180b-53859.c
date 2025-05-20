//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000000

void generate_qr_code(int size, int value) {
    int code[MAX_SIZE][MAX_SIZE];
    int i, j, k, count = 0;
    int x = 0, y = 0;
    int dir = 0; // 0: right, 1: down, 2: left, 3: up

    srand(time(0));
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            code[i][j] = rand() % 2;
        }
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (code[i][j] == 1) {
                count++;
            }
        }
    }

    if (count % 2 == 0) {
        code[0][0] = 1;
        code[0][size - 1] = 1;
        code[size - 1][0] = 1;
        code[size - 1][size - 1] = 1;
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (code[i][j] == 0) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

int main() {
    int size, value;

    printf("Enter the size of the QR code: ");
    scanf("%d", &size);

    printf("Enter the value of the QR code: ");
    scanf("%d", &value);

    generate_qr_code(size, value);

    return 0;
}
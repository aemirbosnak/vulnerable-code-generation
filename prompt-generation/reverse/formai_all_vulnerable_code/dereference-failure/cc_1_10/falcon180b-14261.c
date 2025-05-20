//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define BLACK 0
#define WHITE 1

// Function to print the QR code
void print_qr_code(int **code, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (code[i][j] == BLACK) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

// Function to generate a random QR code
void generate_qr_code(int **code, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            code[i][j] = (rand() % 2)? BLACK : WHITE;
        }
    }
}

// Function to save the QR code as a PNG image
void save_qr_code(int **code, int size, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    fprintf(fp, "P5\n%d %d\n255\n", size, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fprintf(fp, "%c", (code[i][j] == BLACK)? '0' : '1');
        }
    }

    fclose(fp);
}

int main() {
    srand(time(NULL));

    int size = MAX_SIZE;
    int **code = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        code[i] = malloc(size * sizeof(int));
    }

    generate_qr_code(code, size);
    print_qr_code(code, size);
    save_qr_code(code, size, "qrcode.png");

    for (int i = 0; i < size; i++) {
        free(code[i]);
    }
    free(code);

    return 0;
}
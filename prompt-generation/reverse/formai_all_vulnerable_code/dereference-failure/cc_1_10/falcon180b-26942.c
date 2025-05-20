//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1000 // maximum size of QR code
#define BLACK 0x000000 // color black
#define WHITE 0xFFFFFF // color white

struct pixel {
    int x;
    int y;
    int value;
};

int** create_matrix(int size) {
    int **matrix = malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix[i] = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = WHITE;
        }
    }
    return matrix;
}

void set_pixel(int** matrix, int x, int y, int value) {
    if (x >= 0 && x < MAX_SIZE && y >= 0 && y < MAX_SIZE) {
        matrix[x][y] = value;
    }
}

void draw_qr_code(int** matrix, char* data, int size) {
    int num_modules = (size - 1) * 4 + 17; // total number of modules
    int module_size = size * 4; // size of each module
    int position = (size - 1) * 4 + 1; // starting position of QR code
    int value = 0; // initial value of module

    for (int i = 0; i < num_modules; i++) {
        if (data[i] == '0') {
            value = WHITE;
        } else {
            value = BLACK;
        }
        for (int j = 0; j < module_size; j++) {
            set_pixel(matrix, position + j - 1, i, value);
        }
        value =!value; // toggle value for next module
    }
}

void save_image(int** matrix, char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: could not create file.\n");
        exit(1);
    }

    fprintf(file, "P6\n%d %d\n255\n", MAX_SIZE, MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
    }

    fclose(file);
}

int main() {
    srand(time(NULL)); // seed random number generator with current time

    int size = 10; // size of QR code
    char* data = "Hello, World!"; // data to encode in QR code

    int** matrix = create_matrix(size);
    draw_qr_code(matrix, data, size);
    save_image(matrix, "qrcode.png");

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
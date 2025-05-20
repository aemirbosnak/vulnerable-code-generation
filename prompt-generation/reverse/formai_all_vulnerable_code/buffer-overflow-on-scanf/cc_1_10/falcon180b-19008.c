//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define BLACK 0
#define WHITE 1

// Function to generate a random QR code
void generate_qr_code(int *qr_code, int size) {
    for (int i = 0; i < size; i++) {
        qr_code[i] = rand() % 2;
    }
}

// Function to print the QR code
void print_qr_code(int *qr_code, int size) {
    for (int i = 0; i < size; i++) {
        if (qr_code[i] == 0) {
            printf("  ");
        } else {
            printf("██");
        }
    }
    printf("\n");
}

// Function to save the QR code as an image file
void save_qr_code(int *qr_code, int size, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fputc(qr_code[i] + '0', fp);
    }

    fclose(fp);
}

// Main function
int main() {
    srand(time(NULL));

    int qr_code[WIDTH * HEIGHT];
    generate_qr_code(qr_code, WIDTH * HEIGHT);

    printf("QR Code:\n");
    print_qr_code(qr_code, WIDTH * HEIGHT);

    char filename[100];
    printf("Enter filename to save QR code: ");
    scanf("%s", filename);

    save_qr_code(qr_code, WIDTH * HEIGHT, filename);

    printf("QR code saved to file %s\n", filename);

    return 0;
}
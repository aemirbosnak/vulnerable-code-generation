//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

// Function to generate a QR code
void generate_qr_code(char* data, int size) {
    // Initialize the QR code with all 0s
    int qr_code[WIDTH][HEIGHT] = {0};

    // Add the data to the QR code
    for (int i = 0; i < size; i++) {
        qr_code[i/WIDTH][i%WIDTH] = data[i] - 48;
    }

    // Add the QR code to the file
    FILE* file = fopen("qr_code.txt", "w");
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            fprintf(file, "%d", qr_code[i][j]);
        }
    }
    fclose(file);
}

// Function to read the QR code from the file
void read_qr_code() {
    FILE* file = fopen("qr_code.txt", "r");
    int qr_code[WIDTH][HEIGHT];
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            fscanf(file, "%d", &qr_code[i][j]);
        }
    }
    fclose(file);

    // Display the QR code
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d ", qr_code[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Generate a random string to use as the QR code data
    char data[10];
    for (int i = 0; i < 10; i++) {
        data[i] = rand() % 10 + 48;
    }

    // Generate the QR code
    generate_qr_code(data, 10);

    // Read the QR code
    read_qr_code();

    return 0;
}
//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate QR code
void generate_qr(int data[], int size, char* filename) {
    // Initialize QR code matrix
    int** matrix = (int**)malloc(size*sizeof(int*));
    for(int i=0; i<size; i++) {
        matrix[i] = (int*)malloc(size*sizeof(int));
        for(int j=0; j<size; j++) {
            matrix[i][j] = 0;
        }
    }

    // Generate QR code matrix
    int pos = 0;
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-1; j++) {
            if((i+j)%2 == 0) {
                matrix[i][j] = data[pos++];
            }
        }
    }

    // Save QR code to file
    FILE* file = fopen(filename, "w");
    if(file == NULL) {
        printf("Error: Could not save QR code to file.\n");
        exit(1);
    }
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

// Function to generate random QR code data
void generate_random_data(int size, int data[]) {
    // Initialize random number generator
    srand(time(NULL));

    // Generate random data
    for(int i=0; i<size; i++) {
        data[i] = rand() % 10;
    }
}

int main() {
    // Get QR code size from user
    int size;
    printf("Enter QR code size: ");
    scanf("%d", &size);

    // Generate random data
    int data[size];
    generate_random_data(size, data);

    // Generate QR code
    char filename[20];
    sprintf(filename, "qrcode_%d.txt", size);
    generate_qr(data, size, filename);

    // Print success message
    printf("QR code generated successfully!\n");

    return 0;
}
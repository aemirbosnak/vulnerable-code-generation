//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to create QR code
void create_qrcode(char input[], int size) {
    // Initialize QR code with all white pixels
    char qrcode[MAX_SIZE] = {0};
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            qrcode[i * size + j] = 0;
        }
    }

    // Set input data in QR code
    int input_size = strlen(input);
    int pos = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i + j) % 2 == 0) {
                qrcode[(i * size) + j] = input[pos];
                pos++;
            }
        }
    }

    // Print QR code
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (qrcode[(i * size) + j] == 0) {
                printf("  ");
            } else {
                printf("##");
            }
        }
        printf("\n");
    }
}

int main() {
    char input[100];
    printf("Enter input data: ");
    scanf("%s", input);

    // Check input size
    int input_size = strlen(input);
    if (input_size > 100) {
        printf("Input data too large!\n");
        return 0;
    }

    // Set QR code size
    int size = input_size + 10;

    // Create QR code
    create_qrcode(input, size);

    return 0;
}
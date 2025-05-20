//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10 // Width of the QR code
#define HEIGHT 10 // Height of the QR code
#define BLACK 'X' // Character to represent a black module
#define WHITE 'O' // Character to represent a white module

void generateQRCode(char data[], int size) {
    int i, j, k, bitCount, value, mask;
    int qrCode[WIDTH][HEIGHT];

    // Initialize the QR code with white modules
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            qrCode[i][j] = WHITE;
        }
    }

    // Calculate the number of bits in the input data
    bitCount = size * 8;

    // Add the error correction bits
    bitCount += (bitCount / 8);

    // Add the version bits
    bitCount += 10;

    // Add the format bits
    bitCount += 2;

    // Initialize the position of the first module
    i = 0;
    j = 0;

    // Encode the input data into the QR code
    for (k = 0; k < bitCount; k++) {
        value = (data[k / 8] >> (7 - (k % 8))) & 1;
        mask = 1 << (k % 8);

        // Set the color of the module
        if (value == 0) {
            qrCode[i][j] = BLACK;
        } else {
            qrCode[i][j] = WHITE;
        }

        // Move to the next module
        if (++j == WIDTH) {
            j = 0;
            i++;
        }
    }

    // Print the QR code
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", qrCode[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char data[100];
    int size;

    // Get the input data from the user
    printf("Enter the data to be encoded in the QR code: ");
    scanf("%s", data);

    // Get the size of the input data
    size = strlen(data);

    // Generate the QR code
    generateQRCode(data, size);

    return 0;
}
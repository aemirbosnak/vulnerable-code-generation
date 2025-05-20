//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate QR code
void generate_qr_code(int size, char *data) {
    int i, j;
    int num_modules = size * size;
    int module_value;

    // Initialize the QR code matrix
    int qr_code[num_modules];
    for (i = 0; i < num_modules; i++) {
        qr_code[i] = 0;
    }

    // Add data to the QR code matrix
    for (i = 0; i < strlen(data); i++) {
        module_value = data[i] - '0';
        for (j = 0; j < 8; j++) {
            if (module_value % 2 == 1) {
                qr_code[(i * 8) + j] = 1;
            }
            module_value /= 2;
        }
    }

    // Print the QR code matrix
    for (i = 0; i < num_modules; i++) {
        if (qr_code[i] == 1) {
            printf("#");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

// Function to generate random data for the QR code
char *generate_random_data(int length) {
    char *data = (char *)malloc(length + 1);
    int i;
    for (i = 0; i < length; i++) {
        data[i] = '0' + rand() % 10;
    }
    data[length] = '\0';
    return data;
}

int main() {
    int size;
    char *data;

    // Get the size of the QR code from the user
    printf("Enter the size of the QR code: ");
    scanf("%d", &size);

    // Generate random data for the QR code
    data = generate_random_data(size * size);

    // Generate the QR code
    generate_qr_code(size, data);

    // Free memory
    free(data);

    return 0;
}
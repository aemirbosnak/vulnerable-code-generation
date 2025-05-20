//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_MAX_SIZE 4096

// Function to generate QR code
void generate_qr_code(char* data, int size, char* output) {
    int i, j, k;
    int len = strlen(data);
    int qr_size = size;
    int qr_data_size = (qr_size - 21) * 4 + 1;
    int qr_data_pos = 0;

    // Initialize QR code
    memset(output, 0, qr_size * qr_size);

    // Add position markers
    for (i = 0; i < qr_size; i++) {
        output[i] = (i == 0 || i == qr_size - 1)? 1 : 0;
    }

    // Add data
    for (i = 0; i < len; i++) {
        int bit_pos = qr_data_pos * 8;
        int byte_pos = i / 8;
        int bit_shift = i % 8;

        if (data[i] == '1') {
            output[byte_pos + bit_pos / 8] |= (1 << (7 - bit_shift));
        }
    }

    // Fill QR code
    for (i = 0; i < qr_size; i++) {
        for (j = 0; j < qr_size; j++) {
            if (output[i * qr_size + j] == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    char data[QR_MAX_SIZE];
    char output[QR_MAX_SIZE];

    printf("Enter data to generate QR code: ");
    scanf("%s", data);

    printf("Enter QR code size: ");
    int size;
    scanf("%d", &size);

    generate_qr_code(data, size, output);

    printf("\nQR code:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", output[i * size + j]);
        }
        printf("\n");
    }

    return 0;
}
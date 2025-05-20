//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a QR code
void generate_qr_code(char *data, int size) {
    int len = strlen(data);
    int qr_size = size * size;
    int qr_data_size = qr_size - 21;
    int qr_data_pos = 0;
    int qr_data[qr_size];
    int qr_pos = 0;

    // Add position marker
    qr_data[qr_pos++] = 0;

    // Add data
    for (int i = 0; i < len; i++) {
        char c = toupper(data[i]);
        int value = c - 'A';
        if (value < 0 || value > 25) {
            value = 0;
        }
        qr_data[qr_pos++] = value;
    }

    // Add position marker
    qr_data[qr_pos++] = 0;

    // Add padding
    while (qr_pos < qr_size) {
        qr_data[qr_pos++] = 0;
    }

    // Add data to QR code
    for (int y = 0; y < qr_size; y++) {
        for (int x = 0; x < qr_size; x++) {
            int bit = (qr_data[(y * qr_size) + x] & 1) == 1? 1 : 0;
            printf("%d", bit);
        }
        printf("\n");
    }
}

int main() {
    char data[100];
    printf("Enter data to generate QR code: ");
    scanf("%s", data);
    int size = 10;
    generate_qr_code(data, size);
    return 0;
}
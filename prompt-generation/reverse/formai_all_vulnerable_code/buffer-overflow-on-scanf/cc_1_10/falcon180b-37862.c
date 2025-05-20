//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000
#define MAX_DATA 500

// Function to generate QR code
void generate_qrcode(char *data, int length) {
    int i, j, k, count = 0;
    char qrcode[MAX_LENGTH];

    // Set initial values for QR code
    for (i = 0; i < length; i++) {
        qrcode[i] = '0';
    }

    // Fill QR code with data
    for (i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            if (data[i] == '1' && qrcode[j] == '0') {
                qrcode[j] = '1';
                count++;
            }
        }
    }

    // Print QR code
    for (i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            printf("%c", qrcode[j]);
        }
        printf("\n");
    }

    printf("Number of 1's: %d\n", count);
}

int main() {
    char data[MAX_DATA];
    int length;

    printf("Enter data to be encoded: ");
    scanf("%s", data);

    length = strlen(data);

    generate_qrcode(data, length);

    return 0;
}
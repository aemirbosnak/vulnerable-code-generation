//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to decode the QR code
void decode_qrcode(char *qrcode) {
    int len = strlen(qrcode);
    int i = 0;
    int j = 0;
    int count = 0;
    char data[100];

    // Check for valid QR code
    if (len < 1 || len > 100) {
        printf("Invalid QR code length!\n");
        return;
    }

    // Decode the QR code
    while (i < len) {
        if (qrcode[i] == '1') {
            count++;
        } else if (qrcode[i] == '0') {
            count = 0;
        } else {
            printf("Invalid QR code!\n");
            return;
        }
        i++;
        if (count == 8) {
            data[j] = count;
            count = 0;
            j++;
        }
    }

    // Print the decoded data
    printf("Decoded data: ");
    for (int k = 0; k < j; k++) {
        printf("%d", data[k]);
    }
    printf("\n");
}

int main() {
    char qrcode[100];

    // Get the QR code from the user
    printf("Enter the QR code: ");
    scanf("%s", qrcode);

    // Decode the QR code
    decode_qrcode(qrcode);

    return 0;
}
//FormAI DATASET v1.0 Category: QR code reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define QR_CODE_SIZE 21

bool check_qr_code(char* qr_code) {
    // QR code should be exactly QR_CODE_SIZE characters long
    if (strlen(qr_code) != QR_CODE_SIZE) {
        return false;
    }

    // QR code should start with "QR:"
    if (strncmp(qr_code, "QR:", 3) != 0) {
        return false;
    }

    // QR code should end with "."
    if (qr_code[QR_CODE_SIZE - 1] != '.') {
        return false;
    }

    // QR code should have only alphanumeric characters
    for (int i = 0; i < QR_CODE_SIZE - 1; i++) {
        if (!((qr_code[i] >= '0' && qr_code[i] <= '9') ||
              (qr_code[i] >= 'A' && qr_code[i] <= 'Z') ||
              (qr_code[i] >= 'a' && qr_code[i] <= 'z'))) {
            return false;
        }
    }

    // QR code is valid
    return true;
}

int main() {
    printf("Enter QR code: ");

    char qr_code[QR_CODE_SIZE];
    scanf("%s", qr_code);

    if (check_qr_code(qr_code)) {
        printf("Valid QR code!\n");

        // Extract data from QR code
        char data[QR_CODE_SIZE - 5];
        strncpy(data, qr_code + 3, QR_CODE_SIZE - 5);
        data[QR_CODE_SIZE - 5] = '\0';

        // Print extracted data
        printf("Data: %s\n", data);
    } else {
        printf("Invalid QR code!\n");
    }

    return 0;
}
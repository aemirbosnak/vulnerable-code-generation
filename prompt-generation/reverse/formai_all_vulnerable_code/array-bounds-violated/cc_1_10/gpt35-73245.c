//FormAI DATASET v1.0 Category: QR code reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_SIZE 1000

int main() {
    printf("Welcome to the Paranoid QR Code Reader!\n");
    printf("Please enter QR code to read:\n");

    char qr_code[MAX_QR_SIZE];
    int code_len = 0;
    bool is_scanned = false;
    bool is_valid = true;

    while (!is_scanned) {
        fgets(qr_code, MAX_QR_SIZE, stdin);
        code_len = strlen(qr_code);
        
        // Remove any trailing newline character
        if (qr_code[code_len-1] == '\n') {
            qr_code[code_len-1] = '\0';
            code_len--;
        }

        // Validate QR code format
        if (code_len < 3 || qr_code[0] != 'C' || qr_code[1] != '-') {
            is_valid = false;
        } else {
            for (int i = 2; i < code_len; i++) {
                if (!isdigit(qr_code[i])) {
                    is_valid = false;
                    break;
                }
            }
        }

        if (is_valid) {
            printf("Scanning QR code...\n");
            
            // Generate random key for decryption
            srand(time(NULL));
            int key = rand() % 1000 + 1;
            
            // Decrypt QR code
            for (int i = 2; i < code_len; i++) {
                qr_code[i] -= key;
            }
            
            printf("Decrypted QR code: %s\n", qr_code);
            is_scanned = true;

        } else {
            printf("Invalid QR code format, please try again:\n");
            is_valid = true;
        }
    }

    return 0;
}
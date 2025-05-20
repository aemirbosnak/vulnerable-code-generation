//FormAI DATASET v1.0 Category: QR code reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_CODE_LENGTH 100
#define MAX_NUM_CODES 10

typedef struct QRCode {
    char code[MAX_CODE_LENGTH];
    bool is_valid;
} QRCode;

int main() {
    char input[MAX_CODE_LENGTH];
    int num_codes = 0;
    QRCode codes[MAX_NUM_CODES];

    printf("Welcome to the Post-Apocalyptic QR Code Reader\n");

    while(1) {
        printf("Please scan a QR code (or type 'quit' to exit):\n");
        scanf("%s", input);

        if(strcmp(input, "quit") == 0) {
            break;
        }

        // Check if code already exists
        bool code_exists = false;
        for(int i = 0; i < num_codes; i++) {
            if(strcmp(input, codes[i].code) == 0) {
                printf("ERROR: Code already scanned!\n");
                code_exists = true;
                break;
            }
        }

        if(code_exists) {
            continue;
        }

        // Add new code
        if(num_codes >= MAX_NUM_CODES) {
            printf("ERROR: Maximum number of codes scanned!\n");
            continue;
        }

        QRCode new_code;
        strcpy(new_code.code, input);

        // Check if code is valid
        if(strlen(input) < 10 || strlen(input) > 25) {
            printf("ERROR: Invalid code length!\n");
            new_code.is_valid = false;
        } else {
            // Some code validation logic
            new_code.is_valid = true;
        }

        codes[num_codes] = new_code;
        num_codes++;

        printf("QR code scanned: %s\n", new_code.code);
        printf("Code is %svalid\n", new_code.is_valid ? "" : "not ");
    }

    printf("Goodbye!\n");
    return 0;
}
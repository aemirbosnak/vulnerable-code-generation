//FormAI DATASET v1.0 Category: QR code reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/* Function to check if a string is a valid QR code */
bool is_valid_qr_code(char* str) {
    int len = strlen(str);
    if (len != 21) {
        return false;
    }
    if (strncmp(str, "QR|", 3) != 0) {
        return false;
    }
    for (int i = 3; i < len; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

/* Function to parse a QR code and extract the data */
void parse_qr_code(char* str, int* data) {
    for (int i = 3; i < 21; i++) {
        char digit = str[i];
        int value = digit - '0';
        *data = (*data * 10) + value;
    }
}

int main() {
    char qr_code[22];
    bool valid = false;
    int data = 0;

    printf("Scan the QR code:\n");
    scanf("%s", qr_code);

    valid = is_valid_qr_code(qr_code);
    if (!valid) {
        printf("Invalid QR code\n");
        exit(EXIT_FAILURE);
    }

    parse_qr_code(qr_code, &data);
    printf("QR code data: %d\n", data);

    return 0;
}
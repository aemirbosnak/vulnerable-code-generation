//FormAI DATASET v1.0 Category: QR code reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QR_CODE_LENGTH 1000

typedef struct QRCode {
    char data[MAX_QR_CODE_LENGTH];
} QRCode;

// Function to check if the given character is a valid hexadecimal character
bool is_hex(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
}

// Function to validate the given QR code string
bool validate_qr_code(char* qr_code) {
    int length = strlen(qr_code);
    if (length % 2 != 0 || length > MAX_QR_CODE_LENGTH) {
        return false;
    }
    for (int i = 0; qr_code[i] != '\0'; i++) {
        if (!is_hex(qr_code[i])) {
            return false;
        }
    }
    return true;
}

// Function to read a QR code from the user
QRCode read_qr_code() {
    QRCode qr_code;
    char input[MAX_QR_CODE_LENGTH];
    printf("Enter the QR code:\n");
    fgets(input, MAX_QR_CODE_LENGTH, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    if (!validate_qr_code(input)) {
        printf("Invalid QR code!\n");
        exit(EXIT_FAILURE);
    }
    memcpy(qr_code.data, input, strlen(input) + 1);
    return qr_code;
}

// Function to convert a hexadecimal character to its decimal equivalent
int hex_to_decimal(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    }
    else if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    }
    else if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    }
    return -1;
}

// Function to decode the QR code and print the result
void decode_qr_code(QRCode qr_code) {
    int length = strlen(qr_code.data);
    char decoded_data[MAX_QR_CODE_LENGTH / 2];
    for (int i = 0; i < length; i += 2) {
        int d1 = hex_to_decimal(qr_code.data[i]);
        int d2 = hex_to_decimal(qr_code.data[i + 1]);
        decoded_data[i / 2] = (d1 << 4) + d2;
    }
    printf("Decoded data: %s\n", decoded_data);
}

int main() {
    QRCode qr_code = read_qr_code();
    decode_qr_code(qr_code);
    return 0;
}
//FormAI DATASET v1.0 Category: QR code reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CODE_LENGTH 127
#define MAX_QR_VERSION 40

typedef struct qr_code {
    int version;
    int data_capacity;
    char error_correction_level;
    char encoded_data[MAX_CODE_LENGTH];
} QRCode;

bool is_numeric(char c) {
    return (c >= '0' && c <= '9');
}

bool is_alphanumeric(char c) {
    return ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c == ' ') || (c == '$') ||
            (c == '%') || (c == '*') ||
            (c == '+') || (c == '-') ||
            (c == '.') || (c == '/') ||
            (c == ':'));
}

void decode_qr_code(QRCode *code) {
    int alphabet_mode_indicator = 0;
    int length_indicator = 0;
    int character_count = 0;
    int i, j;

    // Determine the mode and character count indicator based on the QR version
    switch (code->version) {
        case 1 ... 9:
            alphabet_mode_indicator = 0x01;
            length_indicator = 10;
            break;
        case 10 ... 26:
            alphabet_mode_indicator = 0x02;
            length_indicator = 12;
            break;
        case 27 ... 40:
            alphabet_mode_indicator = 0x04;
            length_indicator = 14;
            break;
    }

    // Extract the character count
    for (i = 0; i < length_indicator; i++) {
        if (is_numeric(code->encoded_data[i])) {
            character_count = character_count * 10 + (code->encoded_data[i] - '0');
        }
    }

    // Decode the data based on the mode and character count
    switch (alphabet_mode_indicator) {
        case 0x01:
            for (i = 0; i < character_count; i++) {
                int value = 0;
                for (j = 0; j < 3; j++) {
                    if (is_numeric(code->encoded_data[length_indicator + (i * 3) + j])) {
                        value = value * 10 + (code->encoded_data[length_indicator + (i * 3) + j] - '0');
                    }
                }
                code->encoded_data[i] = (char)(value + '0');
            }
            code->encoded_data[character_count] = '\0';
            break;
        case 0x02:
            for (i = 0; i < character_count; i++) {
                int value = 0;
                for (j = 0; j < 2; j++) {
                    if (is_alphanumeric(code->encoded_data[length_indicator + (i * 2) + j])) {
                        if (is_numeric(code->encoded_data[length_indicator + (i * 2) + j])) {
                            value = value * 10 + (code->encoded_data[length_indicator + (i * 2) + j] - '0');
                        } else {
                            value = value * 45 + (code->encoded_data[length_indicator + (i * 2) + j] - (code->encoded_data[length_indicator + (i * 2) + j] < 'A' ? '%' : '&'));
                        }
                    }
                }
                code->encoded_data[i] = (char)((value < 256) ? value : 0);
            }
            code->encoded_data[character_count] = '\0';
            break;
        case 0x04:
            for (i = 0; i < character_count; i++) {
                int value = 0;
                for (j = 0; j < 2; j++) {
                    if (is_alphanumeric(code->encoded_data[length_indicator + (i * 2) + j])) {
                        if (is_numeric(code->encoded_data[length_indicator + (i * 2) + j])) {
                            value = value * 10 + (code->encoded_data[length_indicator + (i * 2) + j] - '0');
                        } else {
                            value = value * 45 + (code->encoded_data[length_indicator + (i * 2) + j] - (code->encoded_data[length_indicator + (i * 2) + j] < 'A' ? '%' : '&'));
                        }
                    }
                }
                code->encoded_data[i] = (char)((value < 256) ? value : 0);
            }
            code->encoded_data[character_count] = '\0';
            break;
    }
}

int main() {
    QRCode code;
    printf("Enter the QR code to decode: ");
    scanf("%s", &code.encoded_data);
    code.version = code.encoded_data[0] - '0';
    code.error_correction_level = code.encoded_data[1];
    code.data_capacity = (8 * MAX_CODE_LENGTH) - ((16 + 4 + 1 + (16 * code.version)) * 8);
    decode_qr_code(&code);
    printf("Decoded data: %s\n", code.encoded_data);
    return 0;
}
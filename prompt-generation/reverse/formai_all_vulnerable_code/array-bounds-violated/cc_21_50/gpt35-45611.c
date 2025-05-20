//FormAI DATASET v1.0 Category: QR code reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_CODE_LENGTH 200

bool is_qr_code(const char *str) {
    int len = strlen(str);
    if (len < 21 || (len - 21) % 2 != 0 || str[0] != 'Q' || str[1] != 'R' || str[2] != ':' || str[20] != ':')
        return false;
    int bit_length = (len - 21) / 2;
    unsigned char *bits = (unsigned char *)calloc(bit_length, sizeof(unsigned char));
    if (!bits) return false;
    for (int i = 0; i < bit_length; ++i) {
        if (str[21 + i * 2] < '0' || str[21 + i * 2] > '1' ||
                str[21 + i * 2 + 1] < '0' || str[21 + i * 2 + 1] > '1') {
            free(bits);
            return false;
        }
        bits[i] = (str[21 + i * 2] == '1' ? 1 : 0) * 2 + (str[21 + i * 2 + 1] == '1' ? 1 : 0);
    }
    for (int i = 0; i < bit_length; ++i) {
        if (bits[i] == 0) {
            if (i + 9 < bit_length && bits[i + 1] == 0 && bits[i + 2] == 0 && bits[i + 3] == 0 && bits[i + 4] == 0 && bits[i + 5] == 0 && bits[i + 6] == 0 && bits[i + 7] == 0 && bits[i + 8] == 0 && bits[i + 9] == 0) {
                i += 10;
            } else {
                free(bits);
                return false;
            }
        } else if (bits[i] == 1) {
            if (i + 4 < bit_length && bits[i + 1] == 1 && bits[i + 2] == 0 && bits[i + 3] == 1 && bits[i + 4] == 0) {
                i += 5;
            } else {
                free(bits);
                return false;
            }
        } else if (bits[i] == 2) {
            if (i + 4 < bit_length && bits[i + 1] == 0 && bits[i + 2] == 1 && bits[i + 3] == 1 && bits[i + 4] == 0) {
                i += 5;
            } else {
                free(bits);
                return false;
            }
        } else if (bits[i] == 3) {
            if (i + 4 < bit_length && bits[i + 1] == 0 && bits[i + 2] == 1 && bits[i + 3] == 0 && bits[i + 4] == 0) {
                i += 5;
            } else {
                free(bits);
                return false;
            }
        }
    }
    free(bits);
    return true;
}

int main() {
    char qr_code[MAX_QR_CODE_LENGTH];
    printf("Please input your QR code:\n");
    while (fgets(qr_code, MAX_QR_CODE_LENGTH, stdin)) {
        // Remove trailing newline character
        int len = strlen(qr_code);
        if (qr_code[len - 1] == '\n') qr_code[len - 1] = '\0';
        if (is_qr_code(qr_code)) {
            printf("Great job! Your QR code is valid!\n");
        } else {
            printf("Oops, your QR code is not valid. Please try again:\n");
        }
    }
    return 0;
}
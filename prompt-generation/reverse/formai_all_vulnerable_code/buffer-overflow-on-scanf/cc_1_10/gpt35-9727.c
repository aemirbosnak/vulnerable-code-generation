//FormAI DATASET v1.0 Category: QR code reader ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QR_SIZE 33

bool is_valid_qr(char* qr_code) {
    if (strlen(qr_code) != MAX_QR_SIZE) {
        return false;
    }
    for (int i = 0; i < MAX_QR_SIZE; i++) {
        if (qr_code[i] != '0' && qr_code[i] != '1') {
            return false;
        }
    }
    return true;
}

char* read_qr_code() {
    char* qr_code = (char*) malloc(MAX_QR_SIZE * sizeof(char));
    printf("Please enter the QR code (max %d characters):\n", MAX_QR_SIZE);
    scanf("%s", qr_code);
    if (is_valid_qr(qr_code)) {
        return qr_code;
    } else {
        free(qr_code);
        printf("Invalid QR code. Please try again.\n");
        return read_qr_code();
    }
}

int calculate_checksum(char* qr_code) {
    int checksum = 0;
    for (int i = 0; i < MAX_QR_SIZE - 4; i += 4) {
        checksum ^= (qr_code[i] << 3) + (qr_code[i+1] << 2) + (qr_code[i+2] << 1) + qr_code[i+3];
    }
    return checksum;
}

int main() {
    printf("Welcome to the QR code reader!\n");
    printf("--------------------------------\n");
    char* qr_code = read_qr_code();
    printf("The entered QR code is: %s\n", qr_code);
    int checksum = calculate_checksum(qr_code);
    if (checksum == (qr_code[MAX_QR_SIZE-4] << 3) + (qr_code[MAX_QR_SIZE-3] << 2) + (qr_code[MAX_QR_SIZE-2] << 1) + qr_code[MAX_QR_SIZE-1]) {
        printf("The QR code is valid!\n");
    } else {
        printf("The QR code is invalid.\n");
    }
    free(qr_code);
    return 0;
}
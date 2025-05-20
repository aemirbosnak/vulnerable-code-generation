//FormAI DATASET v1.0 Category: QR code reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STR_LEN 1024

// Utility function to calculate the length of a string
int str_len(char *str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

// Utility function to reverse a string
void str_reverse(char *str) {
    int len = str_len(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Utility function to convert an integer to a string
void int_to_str(int n, char *str) {
    bool negative = false;
    if (n < 0) {
        negative = true;
        n = -n;
    }
    int index = 0;
    do {
        str[index++] = n % 10 + '0';
        n /= 10;
    } while (n > 0);
    if (negative) {
        str[index++] = '-';
    }
    str[index] = '\0';
    str_reverse(str);
}

// Utility function to read a QR code from the console input
bool read_qr_code(char *qr_code) {
    char input_buffer[MAX_STR_LEN];
    printf("Please scan the QR code: ");
    if (fgets(input_buffer, MAX_STR_LEN, stdin) == NULL) {
        return false;
    }
    int input_len = str_len(input_buffer);
    if (input_buffer[input_len - 1] == '\n') {
        input_buffer[input_len - 1] = '\0';
    }
    strcpy(qr_code, input_buffer);
    return true;
}

// Main function to read and process QR codes
int main() {
    char qr_code[MAX_STR_LEN];
    while (true) {
        if (!read_qr_code(qr_code)) {
            break;
        }
        printf("QR code read: %s\n", qr_code);
    }
    return 0;
}
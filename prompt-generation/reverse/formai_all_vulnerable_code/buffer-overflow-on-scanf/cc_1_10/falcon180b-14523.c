//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a valid QR code
int is_valid_qr_code(char *str) {
    int len = strlen(str);
    int i, j;
    int count = 0;
    for (i = 0; i < len; i++) {
        if (isdigit(str[i])) {
            count++;
        }
    }
    if (count % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print the QR code
void print_qr_code(char *str) {
    int len = strlen(str);
    int i, j;
    for (i = 0; i < len; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

// Function to read the QR code
void read_qr_code(char *str) {
    int len = strlen(str);
    int i, j;
    for (i = 0; i < len; i++) {
        if (isdigit(str[i])) {
            printf("%d", str[i] - '0');
        } else {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}

int main() {
    char qr_code[100];
    printf("Enter the QR code to be scanned: ");
    scanf("%s", qr_code);
    if (is_valid_qr_code(qr_code)) {
        printf("Valid QR code!\n");
        print_qr_code(qr_code);
        read_qr_code(qr_code);
    } else {
        printf("Invalid QR code.\n");
    }
    return 0;
}
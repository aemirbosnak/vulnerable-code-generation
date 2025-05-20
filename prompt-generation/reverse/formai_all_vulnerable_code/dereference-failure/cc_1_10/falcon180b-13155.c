//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_QR_CODE_SIZE 100

// Function to read QR code and convert it into a string
char* read_qr_code(int* size) {
    char qr_code[MAX_LENGTH];
    char ch;
    int i = 0;

    // Read QR code
    printf("Enter QR code: ");
    while ((ch = getchar())!= '\n') {
        if (isdigit(ch)) {
            qr_code[i++] = ch;
        } else {
            printf("Invalid QR code!\n");
            exit(0);
        }
    }
    qr_code[i] = '\0';

    // Convert QR code into a string
    *size = strlen(qr_code);
    char* result = malloc(sizeof(char) * (*size + 1));
    strcpy(result, qr_code);

    return result;
}

// Function to print QR code in a Sherlock Holmes style
void print_qr_code(char* qr_code) {
    int i, j, k = 0;
    int size = strlen(qr_code);

    // Print QR code
    for (i = 0; i < size; i++) {
        if (isdigit(qr_code[i])) {
            printf("%c", qr_code[i]);
        } else {
            printf(" ");
        }
    }
    printf("\n");

    // Print Sherlock Holmes style message
    printf("Elementary, my dear Watson!\n");
    printf("The QR code has been deciphered.\n");
    printf("The message is: %s\n", qr_code);
}

int main() {
    int size;
    char* qr_code = read_qr_code(&size);
    print_qr_code(qr_code);

    return 0;
}
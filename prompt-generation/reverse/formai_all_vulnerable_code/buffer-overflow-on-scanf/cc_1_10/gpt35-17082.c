//FormAI DATASET v1.0 Category: QR code reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define QR_CODE_SIZE 25

// Function to check if a string is a valid QR code
bool is_valid_qr_code(char* input) {
    if (strlen(input) != QR_CODE_SIZE) { // QR code should be of size 25
        return false;
    }
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        if (input[i] != '0' && input[i] != '1') { // QR code can only have 0's and 1's
            return false;
        }
    }
    return true;
}

// Function to convert a string of 0's and 1's to an integer array
// Assumes that the input string is a valid QR code
int* parse_qr_code(char* input) {
    int* code = malloc(QR_CODE_SIZE * sizeof(int));
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        code[i] = input[i] - '0';
    }
    return code;
}

// Function to print the QR code in a square matrix format
void print_qr_code(int* code) {
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        printf("%d ", code[i]);
        if ((i + 1) % 5 == 0) { // print newline after every 5th element
            printf("\n");
        }
    }
}

int main() {
    char input[QR_CODE_SIZE + 1]; // add extra byte for null terminator
    printf("Welcome to the QR code reader!\n");
    while (true) {
        printf("Please enter a QR code (a string of 0's and 1's, 25 characters long):\n");
        scanf("%s", input);
        if (is_valid_qr_code(input)) {
            int* code = parse_qr_code(input);
            printf("QR code detected:\n");
            print_qr_code(code);
            free(code); // deallocate code from memory
            break;
        }
        printf("The input is not a valid QR code. Please try again.\n");
    }
    printf("Thank you for using the QR code reader!\n");
    return 0;
}
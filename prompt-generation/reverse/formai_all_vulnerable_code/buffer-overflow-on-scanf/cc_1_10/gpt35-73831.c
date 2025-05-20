//FormAI DATASET v1.0 Category: QR code reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the QR code
#define MAX_QR_SIZE 100

// Define the pattern of the QR code
typedef struct qr_pattern {
    unsigned short code; // The code represented by the pattern
    bool is_valid; // Whether the pattern is valid (for error correction)
} qr_pattern;

// Define the QR code
typedef struct qr_code {
    qr_pattern patterns[MAX_QR_SIZE][MAX_QR_SIZE]; // The patterns that make up the code
    unsigned short size; // The size of the code (in patterns)
} qr_code;

// Define the function to read the QR code from input
qr_code read_qr_code() {
    qr_code code;
    // Read the size of the code
    scanf("%hu", &code.size);
    // Read the code patterns
    for (unsigned short i = 0; i < code.size; i++) {
        for (unsigned short j = 0; j < code.size; j++) {
            scanf("%hx", &code.patterns[i][j].code);
            code.patterns[i][j].is_valid = true; // Assume all patterns are valid initially
        }
    }
    return code;
}

// Define the function to print the QR code to output
void print_qr_code(qr_code code) {
    // Print the size of the code
    printf("%hu\n", code.size);
    // Print the code patterns
    for (unsigned short i = 0; i < code.size; i++) {
        for (unsigned short j = 0; j < code.size; j++) {
            printf("%04hx ", code.patterns[i][j].code); // Pad the output with leading zeroes
        }
        printf("\n"); // Separate rows with a newline
    }
}

// Define the function to check if the QR code is valid
bool is_qr_code_valid(qr_code code) {
    // Check each row and column for validity
    for (unsigned short i = 0; i < code.size; i++) {
        unsigned short row_code = 0;
        unsigned short col_code = 0;
        for (unsigned short j = 0; j < code.size; j++) {
            row_code ^= code.patterns[i][j].code; // XOR the row
            col_code ^= code.patterns[j][i].code; // XOR the column
        }
        if (row_code != 0 || col_code != 0) { // If any row or column has an invalid pattern, the code is invalid
            return false;
        }
    }
    return true;
}

int main() {
    // Read the QR code from input
    qr_code code = read_qr_code();

    // Check if the code is valid
    if (!is_qr_code_valid(code)) {
        printf("Error: Invalid QR code.\n"); // Print an error message and exit if the code is invalid
        return 1;
    }

    // Print the QR code to output
    print_qr_code(code);

    return 0;
}
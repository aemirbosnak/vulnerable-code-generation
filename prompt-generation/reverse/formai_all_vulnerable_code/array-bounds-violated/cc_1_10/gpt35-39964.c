//FormAI DATASET v1.0 Category: QR code reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 1024 // Maximum input length for QR code string.

// QR code structure.
struct QRCode {
    char version; // Version number.
    char encoding; // Encoding type.
    char data[MAX_INPUT_LENGTH]; // Data string.
};

// Function to parse QR code string and return a struct.
struct QRCode parseQRCode(char str[]) {
    struct QRCode code;
    code.version = str[0];
    code.encoding = str[1];
    strcpy(code.data, &str[2]);
    return code;
}

// Function to print QR code information.
void printQRCode(struct QRCode code) {
    printf("QR Code Information:\n");
    printf("Version: %c\n", code.version);
    printf("Encoding Type: %c\n", code.encoding);
    printf("Data: %s\n", code.data);
}

int main() {
    char input[MAX_INPUT_LENGTH]; // Input string for QR code.

    // Get input from user.
    printf("Enter QR Code String: ");
    fgets(input, sizeof(input), stdin);

    // Remove new line character from input if present.
    int len = strlen(input);
    if (input[len-1] == '\n') {
        input[len-1] = '\0';
    }

    // Check if input is valid QR code string.
    // Valid QR code string format: vXy,z
    // Where X is version number, y is encoding type and z is input data.
    bool isValid = false;
    int i;
    for (i = 0; i < len; i++) {
        if (input[i] == 'v' && (i+2) < len && input[i+2] == 'y' && (i+4) < len) {
            isValid = true;
            break;
        }
    }

    // If input is not valid, print error message and exit.
    if (!isValid) {
        printf("Invalid QR code string format. Please try again.\n");
        exit(1);
    }

    // Parse QR code string and print information.
    struct QRCode code = parseQRCode(&input[i]);
    printQRCode(code);

    return 0;
}
//FormAI DATASET v1.0 Category: QR code generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define QR_SIZE 21
#define MAX_INPUT_LENGTH 50

char *generate_qr_code(char *input);

int main(void) {
    char input[MAX_INPUT_LENGTH];

    printf("Enter text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove trailing newline character
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    char *qr_code = generate_qr_code(input);
    printf("QR Code: %s\n", qr_code);

    free(qr_code);

    return 0;
}

char *generate_qr_code(char *input) {
    char *qr_code = (char *) malloc(QR_SIZE * sizeof(char));
    memset(qr_code, ' ', QR_SIZE);

    // Generate QR code blocks
    int index = 0;
    for (int i = 0; i < QR_SIZE; i += 2) {
        if (input[index] == '\0') {
            break;
        }

        if (input[index] >= 'A' && input[index] <= 'Z') {
            qr_code[i] = '#';
            qr_code[i+1] = ' ';
        } else if (input[index] >= 'a' && input[index] <= 'z') {
            qr_code[i] = ' ';
            qr_code[i+1] = '#';
        }

        index++;
    }

    return qr_code;
}
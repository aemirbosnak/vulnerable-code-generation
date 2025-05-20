//FormAI DATASET v1.0 Category: QR code reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 100

void displayQRCode(char **code, int length) {
    // Display the QR Code in retro style
    printf("+");
    for (int i = 0; i < length; i++) {
        printf("--");
    }
    printf("+\n");
    for (int i = 0; i < length; i++) {
        printf("|");
        for (int j = 0; j < length; j++) {
            if (code[i][j] == '1') {
                printf("**");
            } else {
                printf("  ");
            }
        }
        printf("|\n");
    }
    printf("+");
    for (int i = 0; i < length; i++) {
        printf("--");
    }
    printf("+\n");
}

int main() {
    char qrCode[MAX_CODE_LENGTH];
    printf("Enter a QR code (a string of 0s and 1s): ");
    scanf("%s", qrCode);

    int codeLength = strlen(qrCode);
    if (codeLength > MAX_CODE_LENGTH) {
        printf("The code is too long. Maximum length is %d\n", MAX_CODE_LENGTH);
        return 1;
    }

    char **code = (char**)malloc(codeLength * sizeof(char*));
    for (int i = 0; i < codeLength; i++) {
        code[i] = (char*)malloc(codeLength * sizeof(char));
    }

    for (int i = 0; i < codeLength; i++) {
        for (int j = 0; j < codeLength; j++) {
            int index = i * codeLength + j;
            if (index >= strlen(qrCode)) {
                code[i][j] = '0';
            } else {
                code[i][j] = qrCode[index];
            }
        }
    }

    printf("QR code scanned successfully!\n");
    displayQRCode(code, codeLength);

    for (int i = 0; i < codeLength; i++) {
        free(code[i]);
    }
    free(code);

    return 0;
}
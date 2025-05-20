//FormAI DATASET v1.0 Category: QR code generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QR_SIZE 100

typedef struct {
    int size;
    char data[MAX_QR_SIZE][MAX_QR_SIZE];
} QR_Code;

QR_Code generateQR(char *input) {
    QR_Code qr;
    int len = strlen(input);
    int i, j;

    // Initialize QR code data with spaces
    for (i = 0; i < MAX_QR_SIZE; i++) {
        for (j = 0; j < MAX_QR_SIZE; j++) {
            qr.data[i][j] = ' ';
        }
    }

    // Encode input string in QR code using binary digits
    for (i = 0; i < len; i++) {
        int ascii = (int) input[i];
        for (j = 0; j < 8; j++) {
            int bit = (ascii >> (7 - j)) & 1;
            qr.data[i/2][j+(i%2)*8] = bit ? 'X' : ' ';
        }
    }

    // Add quiet zone
    qr.size = len/2 + 4;
    for (i = 0; i < qr.size; i++) {
        for (j = 0; j < qr.size; j++) {
            qr.data[i][j] = ' ';
        }
    }

    // Add finder patterns
    for (i = 0; i < 7; i++) {
        qr.data[0][i] = 'X';
        qr.data[0][qr.size-1-i] = 'X';
        qr.data[qr.size-1][i] = 'X';
        qr.data[i][0] = 'X';
        qr.data[qr.size-1-i][0] = 'X';
        qr.data[i][qr.size-1] = 'X';
        qr.data[qr.size-1-i][qr.size-1] = 'X';
    }

    // Add alignment pattern
    int a = qr.size/2 - 2;
    for (i = a; i < qr.size-1; i += 2) {
        for (j = a; j < qr.size-1; j += 2) {
            qr.data[i][j] = 'X';
        }
    }

    // Add timing patterns
    for (i = 1; i < qr.size-1; i++) {
        qr.data[i][6] = i % 2 ? ' ' : 'X';
        qr.data[6][i] = i % 2 ? ' ' : 'X';
    }

    // Add version information (not implemented)

    return qr;
}

void printQR(QR_Code qr) {
    int i, j;
    for (i = 0; i < qr.size; i++) {
        for (j = 0; j < qr.size; j++) {
            printf("%c ", qr.data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char input[50];
    printf("Enter the string to encode: ");
    scanf("%s", input);
    QR_Code qr = generateQR(input);
    printQR(qr);
    return 0;
}
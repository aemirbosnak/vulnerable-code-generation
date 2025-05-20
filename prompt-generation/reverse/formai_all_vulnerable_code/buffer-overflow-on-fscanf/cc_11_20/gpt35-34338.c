//FormAI DATASET v1.0 Category: QR code reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_SIZE 100

typedef struct {
    unsigned char data[MAX_QR_SIZE][MAX_QR_SIZE];
    int size;
} QRCode;

// Function to input QRCode data from file
void inputQR(QRCode *qrcode) {

    FILE *file = fopen("qrcode_data.txt", "r");

    // Get size of the QRCode
    fscanf(file, "%d", &(qrcode->size));

    // Get data of the QRCode
    for(int i = 0; i < qrcode->size; i++) {
        for(int j = 0; j < qrcode->size; j++) {
            fscanf(file, "%c", &(qrcode->data[i][j]));
            if(qrcode->data[i][j] == '\n') {
                j--;
            }
        }
    }

    fclose(file);
}

// Function to print QRCode data
void printQR(QRCode *qrcode) {
    for(int i = 0; i < qrcode->size; i++) {
        for(int j = 0; j < qrcode->size; j++) {
            printf("%c", qrcode->data[i][j]);
        }
        printf("\n");
    }
}

// Function to check if QRCode is valid
bool isValid(QRCode *qrcode) {

    // Check if QRCode size is odd and less than or equal to MAX_QR_SIZE
    if(qrcode->size % 2 == 0 || qrcode->size > MAX_QR_SIZE) {
        return false;
    }

    // Check if patterns based on position in QRCode are correct
    for(int i = 0; i < qrcode->size; i++) {
        for(int j = 0; j < qrcode->size; j++) {
            if((i < 7 && j < 7) || (i < 7 && j > qrcode->size-8) || (i > qrcode->size-8 && j < 7)) {
                // Check for timing pattern
                if((i % 2 == 0 && j % 2 == 0 && qrcode->data[i][j] != ' ' && qrcode->data[i][j] != '|') ||
                   (i % 2 == 0 && j % 2 == 1 && qrcode->data[i][j] != '|' && qrcode->data[i][j] != ' ') ||
                   (i % 2 == 1 && j % 2 == 0 && qrcode->data[i][j] != '_' && qrcode->data[i][j] != ' ') ||
                   (i % 2 == 1 && j % 2 == 1 && qrcode->data[i][j] != ' ' && qrcode->data[i][j] != '_')) {
                    return false;
                }

            } else if(i == 6 || i == qrcode->size-7 || j == 6 || j == qrcode->size-7) {
                // Check for position detection pattern
                if(!(i % 2 == 0 && j % 2 == 0 && qrcode->data[i][j] == ' ') &&
                   !(i % 2 == 0 && j % 2 == 1 && qrcode->data[i][j] == '|') &&
                   !(i % 2 == 1 && j % 2 == 0 && qrcode->data[i][j] == '_')) {
                    return false;
                }

            } else if((i < 9 && j > qrcode->size-9) || (i > qrcode->size-9 && j < 9)) {
                // Check for alignment pattern
                if(!(i % 2 == 0 && j % 2 == 0 && qrcode->data[i][j] == ' ') &&
                   !(i % 2 == 0 && j % 2 == 1 && qrcode->data[i][j] == '|') &&
                   !(i % 2 == 1 && j % 2 == 0 && qrcode->data[i][j] == '_')) {
                    return false;
                }

            } else if((i == 4 && (j > 7 && j < qrcode->size-8)) ||
                      (i == qrcode->size-5 && (j > 7 && j < qrcode->size-8)) ||
                      (j == 4 && (i > 7 && i < qrcode->size-8)) ||
                      (j == qrcode->size-5 && (i > 7 && i < qrcode->size-8))) {
                // Check for dark module pattern
                if(qrcode->data[i][j] != 'x') {
                    return false;
                }

            } else {
                // Check for data bits
                if(qrcode->data[i][j] != '0' && qrcode->data[i][j] != '1') {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {

    printf("Welcome to the QRCode Reader!\n");

    QRCode qrcode;

    inputQR(&qrcode);
    printf("QRCode read from file:\n");
    printQR(&qrcode);

    if(isValid(&qrcode)) {
        printf("QRCode is valid.\n");
    } else {
        printf("QRCode is not valid.\n");
    }

    return 0;
}
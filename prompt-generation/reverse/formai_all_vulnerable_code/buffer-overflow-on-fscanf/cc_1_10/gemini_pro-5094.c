//GEMINI-pro DATASET v1.0 Category: QR code reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int width;
    int height;
    char data[MAX_SIZE];
} QRCode;

bool readQRCode(QRCode *qrCode, char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return false;
    }

    fscanf(file, "%d %d ", &qrCode->width, &qrCode->height);

    char line[MAX_SIZE];
    int i = 0;
    while (fgets(line, MAX_SIZE, file)) {
        strcpy(qrCode->data + i * qrCode->width, line);
        i++;
    }

    fclose(file);

    return true;
}

void printQRCode(QRCode *qrCode) {
    for (int i = 0; i < qrCode->height; i++) {
        for (int j = 0; j < qrCode->width; j++) {
            printf("%c", qrCode->data[i * qrCode->width + j]);
        }
        printf("\n");
    }
}

int main() {
    QRCode qrCode;

    if (!readQRCode(&qrCode, "qrCode.txt")) {
        printf("Error reading QR code from file.\n");
        return EXIT_FAILURE;
    }

    printQRCode(&qrCode);

    return EXIT_SUCCESS;
}
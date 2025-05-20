//GEMINI-pro DATASET v1.0 Category: QR code reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int width;
    int height;
    char data[MAX_SIZE];
} QRCode;

QRCode* readQRCode(FILE *fp) {
    QRCode *qrCode = malloc(sizeof(QRCode));
    if (!qrCode) {
        return NULL;
    }
    fscanf(fp, "%d %d\n", &qrCode->width, &qrCode->height);
    if (fscanf(fp, "%[^\n]\n", qrCode->data) == EOF) {
        free(qrCode);
        return NULL;
    }
    return qrCode;
}

void printQRCode(QRCode *qrCode) {
    for (int i = 0; i < qrCode->height; i++) {
        for (int j = 0; j < qrCode->width; j++) {
            printf("%c", qrCode->data[i * qrCode->width + j]);
        }
        printf("\n");
    }
}

bool isPalindrome(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}

char* decodeQRCode(QRCode *qrCode) {
    char *decodedString = malloc(MAX_SIZE);
    int index = 0;
    for (int i = 0; i < qrCode->height; i++) {
        for (int j = 0; j < qrCode->width; j++) {
            if (qrCode->data[i * qrCode->width + j] == '1') {
                char str[MAX_SIZE];
                int strIndex = 0;
                while (i < qrCode->height && j < qrCode->width && qrCode->data[i * qrCode->width + j] == '1') {
                    str[strIndex++] = qrCode->data[i * qrCode->width + j];
                    i++;
                    j++;
                }
                str[strIndex] = '\0';
                if (isPalindrome(str)) {
                    strcat(decodedString, str);
                    index += strIndex;
                }
            }
        }
    }
    decodedString[index] = '\0';
    return decodedString;
}

int main() {
    FILE *fp = fopen("qrcode.txt", "r");
    if (!fp) {
        printf("Error opening file\n");
        return 1;
    }
    QRCode *qrCode = readQRCode(fp);
    if (!qrCode) {
        printf("Error reading QR code\n");
        return 1;
    }
    printQRCode(qrCode);
    char *decodedString = decodeQRCode(qrCode);
    printf("Decoded string: %s\n", decodedString);
    free(qrCode);
    free(decodedString);
    fclose(fp);
    return 0;
}
//FormAI DATASET v1.0 Category: QR code reader ; Style: Romeo and Juliet
// <<Two QR Codes, Both Alike in Dignity>> 
// A Romeo and Juliet Style QR Code Reader

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QR_CODE_SIZE 1024

void printQRCode(char qrCode[MAX_QR_CODE_SIZE][MAX_QR_CODE_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", qrCode[i][j]);
        }
        printf("\n"); 
    }
}

int readQRCode(char qrCode[MAX_QR_CODE_SIZE][MAX_QR_CODE_SIZE], char fileName[]) {
    FILE *fp;
    fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", fileName);
        return -1;
    }

    int n = 0;
    char ch = fgetc(fp);
    while (ch != EOF) {
        for (int i = 0; i < n; i++) {
            if (ch == '\n') {
                break;
            }
            qrCode[n][i] = ch;
            ch = fgetc(fp);
        }

        if (ch == '\n') {
            n++;
        }

        ch = fgetc(fp);
    }

    fclose(fp);
    return n;
}

int main() {
    char qrCode1[MAX_QR_CODE_SIZE][MAX_QR_CODE_SIZE];
    char qrCode2[MAX_QR_CODE_SIZE][MAX_QR_CODE_SIZE];
    char fileName1[] = "qr_code1.txt";
    char fileName2[] = "qr_code2.txt";

    printf("<<Two QR Codes, Both Alike in Dignity>>\n");
    printf("Enter QR code 1 file name: ");
    scanf("%s", fileName1);

    int n1 = readQRCode(qrCode1, fileName1);
    if (n1 == -1) {
        printf("Error: Could not read QR code 1 file\n");
        return -1;
    }

    printf("\nEnter QR code 2 file name: ");
    scanf("%s", fileName2);

    int n2 = readQRCode(qrCode2, fileName2);
    if (n2 == -1) {
        printf("Error: Could not read QR code 2 file\n");
        return -1;
    }

    printf("\nFirst QR code read:\n");
    printQRCode(qrCode1, n1);
    printf("\nSecond QR code read:\n");
    printQRCode(qrCode2, n2);

    return 0;
}
//FormAI DATASET v1.0 Category: QR code reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 200

typedef struct {
    bool data[MAX_LENGTH];
    int version;
    int mode;
    int count;
    int size;
} QRCode;

void printQR(QRCode* qr) {
    printf("QR Code:\n");
    printf("Version: %d\n", qr->version);
    printf("Mode: %d\n", qr->mode);
    printf("Count: %d\n", qr->count);
    printf("Size: %d\n", qr->size);
    printf("Data: ");
    for (int i = 0; i < qr->size; i++) {
        printf("%d", qr->data[i]);
    }
    printf("\n");
}

bool isValidFormat(char* input) {
    int length = strlen(input);
    if (length != 152 || strncmp(input, "000", 3) != 0) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (input[i] != '0' && input[i] != '1') {
            return false;
        }
    }
    return true;
}

QRCode* decodeQR(char* input) {
    QRCode* qr = (QRCode*) malloc(sizeof(QRCode));
    memset(qr, 0, sizeof(QRCode));
    char versionData[7];
    for (int i = 0, j = 0; i < 3; i++, j+=2) {
        versionData[i] = input[j+3];
        versionData[i+3] = input[j+144];
    }
    qr->version = atoi(versionData);
    qr->mode = (int)(input[39] - '0');
    qr->count = (int)(input[40] - '0');
    qr->size = qr->version * 4 + 17;
    qr->count = (qr->size - 21) / (4*qr->count+17);
    for (int i = 0, j = 0; i < qr->size; i++) {
        if (i == 0 || i == qr->size - 7) {
            continue;
        }
        if (j == 8) {
            j = 0;
        }
        if (i < 6) {
            qr->data[i] = 0;
        } else if (i == 6) {
            qr->data[i] = 1;
        } else if (i == 7) {
            qr->data[i] = 0;
        } else if (i < 14) {
            qr->data[i] = 1;
        } else if (i == 14) {
            qr->data[i] = 0;
        } else if (i == 15) {
            qr->data[i] = 1;
        } else {
            qr->data[i] = (input[3*(qr->count*j+i-15)+45] == '1');
            j++;
        }
    }
    return qr;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter valid C QR code:\n");
    scanf("%s", input);
    if (!isValidFormat(input)) {
        printf("Invalid QR code format.\n");
        return 0;
    }
    QRCode* qr = decodeQR(input);
    printQR(qr);
    free(qr);
    return 0;
}
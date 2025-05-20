//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODEWORDS 1000
#define MAX_MODULES 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    int value;
    Point position;
} CodeWord;

typedef struct {
    CodeWord *codewords;
    int numCodewords;
} QRCode;

void initQRCode(QRCode *qrcode) {
    qrcode->codewords = (CodeWord *)malloc(MAX_CODEWORDS * sizeof(CodeWord));
    qrcode->numCodewords = 0;
}

void freeQRCode(QRCode *qrcode) {
    free(qrcode->codewords);
}

void addCodeWord(QRCode *qrcode, int value, Point position) {
    if (qrcode->numCodewords >= MAX_CODEWORDS) {
        printf("Error: Maximum number of codewords reached.\n");
        return;
    }

    CodeWord *codeword = &qrcode->codewords[qrcode->numCodewords];
    codeword->value = value;
    codeword->position = position;

    qrcode->numCodewords++;
}

void printQRCode(QRCode *qrcode) {
    for (int i = 0; i < qrcode->numCodewords; i++) {
        CodeWord *codeword = &qrcode->codewords[i];
        printf("%d (%d,%d)\n", codeword->value, codeword->position.x, codeword->position.y);
    }
}

int main() {
    QRCode qrcode;
    initQRCode(&qrcode);

    int numModules;
    scanf("%d", &numModules);

    for (int i = 0; i < numModules; i++) {
        int value;
        Point position;
        scanf("%d %d %d", &value, &position.x, &position.y);

        addCodeWord(&qrcode, value, position);
    }

    printQRCode(&qrcode);

    freeQRCode(&qrcode);

    return 0;
}
//FormAI DATASET v1.0 Category: QR code reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 21 // 21x21 QR code
#define HEIGHT 21

void readQRCode(int qrCode[HEIGHT][WIDTH]){
    printf("Enter the QR code:\n");
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            scanf("%d", &qrCode[i][j]);
        }
    }
}

int calculateVersion(int qrCode[HEIGHT][WIDTH]){
    int version = 0;
    int numBits = 0;
    for(int i=0; i<6; i++){
        numBits += (qrCode[8][i] * pow(2, 5 - i));
    }
    version = (numBits - 7) / 4 + 1;
    return version;
}

int calculateMaskPattern(int qrCode[HEIGHT][WIDTH]){
    int maskPattern = 0;
    int b1 = qrCode[8][13];
    int b2 = qrCode[8][14];
    int b3 = qrCode[8][15];
    int b4 = qrCode[8][16];
    maskPattern = b1 * pow(2, 3) + b2 * pow(2, 2) + b3 * pow(2, 1) + b4 * pow(2, 0);
    return maskPattern;
}

void applyMaskPattern(int qrCode[HEIGHT][WIDTH], int maskPattern){
    switch(maskPattern){
        case 0: // Mask pattern 000
            for(int i=0; i<HEIGHT; i++){
                for(int j=0; j<WIDTH; j++){
                    qrCode[i][j] = (qrCode[i][j] + i + j) % 2;
                }
            }
            break;
        case 1: // Mask pattern 001
            for(int i=0; i<HEIGHT; i++){
                for(int j=0; j<WIDTH; j++){
                    if(i % 2 == 0){
                        qrCode[i][j] = (qrCode[i][j] + 1) % 2;
                    }
                }
            }
            break;
        case 2: // Mask pattern 010
            for(int i=0; i<HEIGHT; i++){
                for(int j=0; j<WIDTH; j++){
                    if(j % 3 == 0){
                        qrCode[i][j] = (qrCode[i][j] + 1) % 2;
                    }
                }
            }
            break;
        case 3: // Mask pattern 011
            for(int i=0; i<HEIGHT; i++){
                for(int j=0; j<WIDTH; j++){
                    if((i + j) % 3 == 0){
                        qrCode[i][j] = (qrCode[i][j] + 1) % 2;
                    }
                }
            }
            break;
        case 4: // Mask pattern 100
            for(int i=0; i<HEIGHT; i++){
                for(int j=0; j<WIDTH; j++){
                    if((i / 2 + j / 3) % 2 == 0){
                        qrCode[i][j] = (qrCode[i][j] + 1) % 2;
                    }
                }
            }
            break;
        case 5: // Mask pattern 101
            for(int i=0; i<HEIGHT; i++){
                for(int j=0; j<WIDTH; j++){
                    if(i * j % 2 + i * j % 3 == 0){
                        qrCode[i][j] = (qrCode[i][j] + 1) % 2;
                    }
                }
            }
            break;
        case 6: // Mask pattern 110
            for(int i=0; i<HEIGHT; i++){
                for(int j=0; j<WIDTH; j++){
                    if((i * j % 2 + i * j % 3) % 2 == 0){
                        qrCode[i][j] = (qrCode[i][j] + 1) % 2;
                    }
                }
            }
            break;
        case 7: // Mask pattern 111
            for(int i=0; i<HEIGHT; i++){
                for(int j=0; j<WIDTH; j++){
                    if((i + j) % 2 + (i * j) % 3 == 0){
                        qrCode[i][j] = (qrCode[i][j] + 1) % 2;
                    }
                }
            }
            break;
    }
}

void printQRCode(int qrCode[HEIGHT][WIDTH]){
    printf("QR code:\n");
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            printf("%d ", qrCode[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int qrCode[HEIGHT][WIDTH];
    readQRCode(qrCode);
    int version = calculateVersion(qrCode);
    printf("QR code version: %d\n", version);
    int maskPattern = calculateMaskPattern(qrCode);
    printf("Mask pattern: %d\n", maskPattern);
    applyMaskPattern(qrCode, maskPattern);
    printQRCode(qrCode);
    return 0;
}
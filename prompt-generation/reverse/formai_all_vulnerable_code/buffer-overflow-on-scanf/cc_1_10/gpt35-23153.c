//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: mathematical
#include <stdio.h>
#include <math.h>

int hexToDec(char hexNum[]) {
    int len = strlen(hexNum);
    int base = 1;
    int decNum = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (hexNum[i] >= '0' && hexNum[i] <= '9') {
            decNum += (hexNum[i] - 48) * base;
            base *= 16;
        } else if (hexNum[i] >= 'a' && hexNum[i] <= 'f') {
            decNum += (hexNum[i] - 87) * base;
            base *= 16;
        } else if (hexNum[i] >= 'A' && hexNum[i] <= 'F') {
            decNum += (hexNum[i] - 55) * base;
            base *= 16;
        }
    }
    return decNum;
}

void decToOct(int decNum) {
    int octArr[1000], i;
    for (i = 0; decNum > 0; i++) {
        octArr[i] = decNum % 8;
        decNum /= 8;
    }
    printf("Octal Number: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octArr[j]);
    }
}

void decToBin(int decNum) {
    int binArr[1000], i;
    for (i = 0; decNum > 0; i++) {
        binArr[i] = decNum % 2;
        decNum /= 2;
    }
    printf("Binary Number: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binArr[j]);
    }
}

void decToHex(int decNum) {
    char hexArr[1000];
    int i = 0, hexRem;
    while (decNum > 0) {
        hexRem = decNum % 16;
        if (hexRem < 10) {
            hexArr[i] = hexRem + 48;
        } else {
            hexArr[i] = hexRem + 55;
        }
        decNum /= 16;
        i++;
    }
    printf("Hexadecimal Number: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexArr[j]);
    }
}

int main() {
    char hexNum[20];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hexNum);

    int decNum = hexToDec(hexNum);
    printf("Decimal Number: %d\n", decNum);

    decToOct(decNum);
    printf("\n");

    decToBin(decNum);
    printf("\n");

    decToHex(decNum);
    printf("\n");

    return 0;
}
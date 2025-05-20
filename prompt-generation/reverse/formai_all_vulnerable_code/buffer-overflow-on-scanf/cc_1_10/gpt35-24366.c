//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void hexToDec();
void decToHex();

int main() {
    int menuSelection;

    printf("Please choose an option:\n");
    printf("1- Convert from Hexadecimal to Decimal\n");
    printf("2- Convert from Decimal to Hexadecimal\n");

    scanf("%d", &menuSelection);

    switch(menuSelection) {
        case 1:
            hexToDec();
            break;
        case 2:
            decToHex();
            break;
        default:
            printf("Invalid selection. Please choose either 1 or 2.\n");
    }

    return 0;
}

void hexToDec() {
    char hexNum[20];
    long long decNum = 0;

    printf("Please enter a hexadecimal number: ");
    scanf("%s", hexNum);

    for(int i = 0; hexNum[i] != '\0'; i++) {
        if(hexNum[i] >= '0' && hexNum[i] <= '9') {
            decNum = decNum * 16 + (hexNum[i] - '0');
        }
        else if(hexNum[i] >= 'a' && hexNum[i] <= 'f') {
            decNum = decNum * 16 + (hexNum[i] - 'a' + 10);
        }
        else if(hexNum[i] >= 'A' && hexNum[i] <= 'F') {
            decNum = decNum * 16 + (hexNum[i] - 'A' + 10);
        }
        else {
            printf("Invalid hexadecimal digit %c", hexNum[i]);
            exit(0);
        }
    }

    printf("The decimal equivalent of %s is %lld.\n", hexNum, decNum);    
}

void decToHex() {
    long long decNum;
    char hexNum[20];
    int i = 0, remainder;

    printf("Please enter a decimal number: ");
    scanf("%lld", &decNum);

    while(decNum != 0) {
        remainder = decNum % 16;
        if(remainder < 10) {
            hexNum[i] = remainder + 48;
        }
        else {
            hexNum[i] = remainder + 55;
        }
        i++;
        decNum /= 16;
    }

    printf("The hexadecimal equivalent is ");

    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hexNum[j]);
    }

    printf(".\n");
}
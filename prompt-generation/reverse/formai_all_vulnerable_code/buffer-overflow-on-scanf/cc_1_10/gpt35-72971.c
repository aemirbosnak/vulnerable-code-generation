//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: futuristic
#include <stdio.h>

void printHeader() {
    printf("##################### HEX CONVERTER 3000 #####################\n");
}

int convertToDecimal(char c) {
    switch(c) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'a': return 10;
        case 'b': return 11;
        case 'c': return 12;
        case 'd': return 13;
        case 'e': return 14;
        case 'f': return 15;
    }
    return -1;
}

char convertToHex(int val) {
    switch(val) {
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
        case 10: return 'a';
        case 11: return 'b';
        case 12: return 'c';
        case 13: return 'd';
        case 14: return 'e';
        case 15: return 'f';
    }
    return 'x';
}

int convertToDecimalFromHex(char *hexVal, int len) {
    int i, decVal = 0, baseVal = 16;
    for(i = 0; i < len; i++) {
        decVal += convertToDecimal(hexVal[i]) * baseVal;
        baseVal *= 16;
    }
    return decVal;
}

void convertToHexFromDecimal(int decVal) {
    if(decVal == 0) {
        printf("The Hexadecimal Value: 0");
        return;
    }
    int remainder, i, len = 0;
    char hexVal[50];
    while(decVal > 0) {
        remainder = decVal % 16;
        hexVal[len++] = convertToHex(remainder);
        decVal /= 16;
    }
    printf("The Hexadecimal Value: ");
    for(i = len - 1; i >= 0; i--)
        printf("%c", hexVal[i]);
}

int main() {
    int choice = 0;
    char hexVal[50] = "";
    int decVal = 0;
    while(1) {
        printHeader();
        printf("\n1. Hex to Decimal\n2. Decimal to Hex\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter the Hexadecimal Value: ");
                scanf("%s", hexVal);
                decVal = convertToDecimalFromHex(hexVal, strlen(hexVal));
                printf("\nThe Decimal Value: %d\n\n", decVal);
                break;
            case 2:
                printf("\nEnter the Decimal Value: ");
                scanf("%d", &decVal);
                convertToHexFromDecimal(decVal);
                printf("\n\n");
                break;
            case 3:
                printf("\nExiting the Hex Converter 3000\n\n");
                return 0;
            default:
                printf("\nInvalid Choice. Please try again.\n\n");
                break;
        }
    }
    return 0;
}
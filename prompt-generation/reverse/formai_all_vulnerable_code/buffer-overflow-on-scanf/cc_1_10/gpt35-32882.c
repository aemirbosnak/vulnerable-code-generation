//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hexToInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else {
        return -1;
    }
}

char intToHex(int n) {
    if (n >= 0 && n <= 9) {
        return n + '0';
    } else if (n >= 10 && n <= 15) {
        return n - 10 + 'a';
    } else {
        return '\0';
    }
}

void hexToBinary(char *hex, char *binary) {
    int i, j;
    for (i = 0, j = 0; hex[i] != '\0'; i++, j += 4) {
        int val = hexToInt(hex[i]);
        binary[j] = (val & 8) ? '1' : '0';
        binary[j + 1] = (val & 4) ? '1' : '0';
        binary[j + 2] = (val & 2) ? '1' : '0';
        binary[j + 3] = (val & 1) ? '1' : '0';
    }
    binary[j] = '\0';
}

void binaryToHex(char *binary, char *hex) {
    int i, j;
    for (i = 0, j = 0; binary[i] != '\0'; i += 4, j++) {
        int val = ((binary[i] & 1) << 3) |
                  ((binary[i + 1] & 1) << 2) |
                  ((binary[i + 2] & 1) << 1) |
                  (binary[i + 3] & 1);
        hex[j] = intToHex(val);
    }
    hex[j] = '\0';
}

int main() {
    char hexNum[100], binaryNum[401], menu, again;
    do {
        system("clear");
        printf("1. Convert Hexadecimal to Binary\n");
        printf("2. Convert Binary to Hexadecimal\n");
        printf("Choose one of the options: ");
        scanf(" %c", &menu);

        switch (menu) {
            case '1':
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNum);
                hexToBinary(hexNum, binaryNum);
                printf("The binary conversion of %s is %s\n", hexNum, binaryNum);
                break;
            case '2':
                printf("Enter a binary number: ");
                scanf("%s", binaryNum);
                binaryToHex(binaryNum, hexNum);
                printf("The hexadecimal conversion of %s is %s\n", binaryNum, hexNum);
                break;
            default:
                printf("Invalid Choice. Please try again\n\n");
                break;
        }
        printf("Do you want to run the program again (Y/N)? ");
        scanf(" %c", &again);
    } while (again == 'Y' || again == 'y');
    return 0;
}
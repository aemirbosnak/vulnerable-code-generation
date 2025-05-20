//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    char hexNum[20];
    int i, r, len = 0, dec = 0, place = 1;

    printf("Enter a surreal hexadecimal number: ");
    scanf("%s", hexNum);

    for (i = 0; hexNum[i] != '\0'; i++) {
        len++;
    }
    len--;

    for (i = len; i >= 0; i--) {
        switch (hexNum[i]) {
            case '0':
                r = 0;
                break;
            case '1':
                r = 1;
                break;
            case '2':
                r = 2;
                break;
            case '3':
                r = 3;
                break;
            case '4':
                r = 4;
                break;
            case '5':
                r = 5;
                break;
            case '6':
                r = 6;
                break;
            case '7':
                r = 7;
                break;
            case '8':
                r = 8;
                break;
            case '9':
                r = 9;
                break;
            case 'a':
            case 'A':
                r = 10;
                break;
            case 'b':
            case 'B':
                r = 11;
                break;
            case 'c':
            case 'C':
                r = 12;
                break;
            case 'd':
            case 'D':
                r = 13;
                break;
            case 'e':
            case 'E':
                r = 14;
                break;
            case 'f':
            case 'F':
                r = 15;
                break;
            case '@':
                r = rand() % 16;
                break;
            default:
                r = -1;
                break;
        }

        if (r == -1) {
            printf("Error: Invalid character in surreal hexadecimal number.\n");
            return -1;
        }

        dec += r * place;
        place *= 16;
    }

    printf("The decimal equivalent of the surreal hexadecimal number '%s' is %d.\n", hexNum, dec);

    return 0;
}
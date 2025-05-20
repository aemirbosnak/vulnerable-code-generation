//Code Llama-13B DATASET v1.0 Category: Hexadecimal Converter ; Style: Ada Lovelace
#include <stdio.h>

int main() {
    char hex[256];
    int i, j, k;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    for (i = 0, j = 0; hex[i] != '\0'; i += 2, j++) {
        switch (hex[i]) {
            case '0':
                printf("0000");
                break;
            case '1':
                printf("0001");
                break;
            case '2':
                printf("0010");
                break;
            case '3':
                printf("0011");
                break;
            case '4':
                printf("0100");
                break;
            case '5':
                printf("0101");
                break;
            case '6':
                printf("0110");
                break;
            case '7':
                printf("0111");
                break;
            case '8':
                printf("1000");
                break;
            case '9':
                printf("1001");
                break;
            case 'a':
            case 'A':
                printf("1010");
                break;
            case 'b':
            case 'B':
                printf("1011");
                break;
            case 'c':
            case 'C':
                printf("1100");
                break;
            case 'd':
            case 'D':
                printf("1101");
                break;
            case 'e':
            case 'E':
                printf("1110");
                break;
            case 'f':
            case 'F':
                printf("1111");
                break;
            default:
                printf("Invalid input");
                return 1;
        }
    }

    printf("\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the Hexadecimal Converter!\n\n");

    char hexstring[15];
    printf("Please enter a hexadecimal number: ");
    scanf("%s", hexstring);
    printf("\n");

    int i;
    unsigned long decimal = 0, place = 1, val;

    for(i = strlen(hexstring)-1; i >= 0; i--) {

        switch(hexstring[i]) {

            case '0':
                val = 0;
                break;

            case '1':
                val = 1;
                break;

            case '2':
                val = 2;
                break;

            case '3':
                val = 3;
                break;

            case '4':
                val = 4;
                break;

            case '5':
                val = 5;
                break;

            case '6':
                val = 6;
                break;

            case '7':
                val = 7;
                break;

            case '8':
                val = 8;
                break;

            case '9':
                val = 9;
                break;

            case 'A':
            case 'a':
                val = 10;
                break;

            case 'B':
            case 'b':
                val = 11;
                break;

            case 'C':
            case 'c':
                val = 12;
                break;

            case 'D':
            case 'd':
                val = 13;
                break;

            case 'E':
            case 'e':
                val = 14;
                break;

            case 'F':
            case 'f':
                val = 15;
                break;

            default:
                printf("Invalid hexadecimal number!\n");
                return 0;

        }

        decimal += val * place;
        place *= 16;

    }

    printf("The decimal equivalent of %s is %ld.\n", hexstring, decimal);

    printf("\nThanks for using the Hexadecimal Converter!");

    return 0;

}
//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Linus Torvalds
#include <stdio.h>

void hextobin(char* hex, char* bin){
    int i = 0;
    while (hex[i]){
        switch(hex[i]){
            case '0': strcat(bin, "0000"); break;
            case '1': strcat(bin, "0001"); break;
            case '2': strcat(bin, "0010"); break;
            case '3': strcat(bin, "0011"); break;
            case '4': strcat(bin, "0100"); break;
            case '5': strcat(bin, "0101"); break;
            case '6': strcat(bin, "0110"); break;
            case '7': strcat(bin, "0111"); break;
            case '8': strcat(bin, "1000"); break;
            case '9': strcat(bin, "1001"); break;
            case 'A': strcat(bin, "1010"); break;
            case 'B': strcat(bin, "1011"); break;
            case 'C': strcat(bin, "1100"); break;
            case 'D': strcat(bin, "1101"); break;
            case 'E': strcat(bin, "1110"); break;
            case 'F': strcat(bin, "1111"); break;
            default: printf("\nInvalid hexadecimal digit %c ", hex[i]); break;
        }
        i++;
    }
}

void bintohex(char* bin, char* hex){
    int i = 0;
    while (bin[i]){
        int nibble = 0;
        if(bin[i]=='1') nibble = 8;
        if(bin[i+1]=='1') nibble += 4;
        if(bin[i+2]=='1') nibble += 2;
        if(bin[i+3]=='1') nibble += 1;
        i += 4;
        switch(nibble){
            case 0: strcat(hex, "0"); break;
            case 1: strcat(hex, "1"); break;
            case 2: strcat(hex, "2"); break;
            case 3: strcat(hex, "3"); break;
            case 4: strcat(hex, "4"); break;
            case 5: strcat(hex, "5"); break;
            case 6: strcat(hex, "6"); break;
            case 7: strcat(hex, "7"); break;
            case 8: strcat(hex, "8"); break;
            case 9: strcat(hex, "9"); break;
            case 10: strcat(hex, "A"); break;
            case 11: strcat(hex, "B"); break;
            case 12: strcat(hex, "C"); break;
            case 13: strcat(hex, "D"); break;
            case 14: strcat(hex, "E"); break;
            case 15: strcat(hex, "F"); break;
        }
    }
}

int main(){
    char hex[17], bin[65];
    printf("Enter hexadecimal number: ");
    scanf("%s", hex);
    hex[16]='\0';
    bin[0]='\0';

    hextobin(hex, bin);
    printf("Binary representation: %s\n", bin);
    bin[0]='\0';

    bintohex(bin, hex);
    printf("Hexadecimal representation: %s\n", hex);

    return 0;
}
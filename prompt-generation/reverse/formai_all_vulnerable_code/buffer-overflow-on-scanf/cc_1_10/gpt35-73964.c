//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void decimalToHexadecimal(int decimal){
    int quotient, remainder;
    quotient = decimal/16;
    remainder = decimal%16;
    if(quotient != 0){
        decimalToHexadecimal(quotient);
    }
    if(remainder < 10){
        printf("%d", remainder);
    }
    else{
        printf("%c", 55+remainder);
    }
}

void hexadecimalToDecimal(char hexadecimal[]) {
    int decimal = 0, i;
    for (i=0; hexadecimal[i]!='\0'; i++) {
        if (hexadecimal[i]>='0' && hexadecimal[i]<='9') {
            decimal = decimal * 16 + hexadecimal[i] - '0';
        }
        else if (hexadecimal[i]>='a' && hexadecimal[i]<='f') {
            decimal = decimal*16 + hexadecimal[i] - 'a' + 10;
        }
        else if (hexadecimal[i]>='A' && hexadecimal[i]<='F') {
            decimal = decimal*16 + hexadecimal[i] - 'A' + 10;
        }
    }
    
    printf("Hexadecimal: 0x%s\nDecimal: %d\n", hexadecimal, decimal);
}

int main() {
    int choice, decimal;
    char hexadecimal[20];
    printf("Enter your choice:\n");
    printf("1. Decimal to Hexadecimal\n2. Hexadecimal to Decimal\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter decimal number: ");
            scanf("%d", &decimal);
            printf("Hexadecimal equivalent: ");
            decimalToHexadecimal(decimal);
            printf("\n");
            break;
        case 2:
            printf("Enter hexadecimal number: ");
            scanf("%s", hexadecimal);
            hexadecimalToDecimal(hexadecimal);
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}
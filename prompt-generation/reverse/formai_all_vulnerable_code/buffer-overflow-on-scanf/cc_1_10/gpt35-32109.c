//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: complex
#include <stdio.h>
#include <string.h>
#include <math.h>

int hexToDecimal(char hex[]){
    int i, len, decimal = 0;

    len = strlen(hex);
    for(i=0; hex[i]!='\0'; i++){
        if(hex[i]>='0' && hex[i]<='9')
            decimal += (hex[i]-'0')*pow(16, len-1);
        else if(hex[i]>='a' && hex[i]<='f')
            decimal += (hex[i]-'a'+10)*pow(16, len-1);
        else if(hex[i]>='A' && hex[i]<='F')
            decimal += (hex[i]-'A'+10)*pow(16, len-1);
        else{
            printf("\nInvalid Hexadecimal Number.\n");
            return -1;
        }
        len--;
    }

    return decimal;
}

void decimalToHex(int decimal){
    int quotient[100], i = 0, j;
    char hex[100];

    while(decimal > 0){
        quotient[i] = decimal % 16;
        i++;
        decimal /= 16;
    }

    for(j=0; j<i; j++){
        if(quotient[j]>=0 && quotient[j]<=9)
            hex[j] = quotient[j] + 48;
        else
            hex[j] = quotient[j] + 55;
    }

    printf("\nHexadecimal equivalent of %d is: ", decimal);
    for(j=i-1; j>=0; j--)
        printf("%c", hex[j]);

    return;

}

int main(){
    int decimal, choice;
    char hex[100];

    printf("Select the conversion mode:\n1. Hexadecimal to Decimal\n2. Decimal to Hexadecimal\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("\nEnter the hexadecimal number: ");
            scanf("%s", &hex);
            decimal = hexToDecimal(hex);
            if(decimal != -1)
                printf("\nDecimal equivalent of %s is: %d\n", hex, decimal);
            break;

        case 2:
            printf("\nEnter the decimal number: ");
            scanf("%d", &decimal);
            decimalToHex(decimal);
            break;

        default:
            printf("\nInvalid Choice.\n");
    }

    return 0;
}
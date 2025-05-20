//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hexconverter(char input[]);
void decimalconverter(char input[]);

int main(){
    printf("Welcome to the Hexadecimal Converter!\n");
    char input[20];
    int option;
    do{
        printf("Choose an option (1 or 2):\n1. Convert Hexadecimal to Decimal\n2. Convert Decimal to Hexadecimal\nOption: ");
        scanf("%d", &option);
    }while(option != 1 && option != 2);

    if(option == 1){
        printf("Enter the Hexadecimal number: ");
        scanf("%s", input);
        hexconverter(input);
    }
    else{
        printf("Enter the Decimal number: ");
        scanf("%s", input);
        decimalconverter(input);
    }
    return 0;
}

void hexconverter(char input[]){
    int i, j, len = strlen(input), decimal=0, mul=1;
    for(i=len-1; i>=0; i--){
        if(input[i]>='0' && input[i]<='9')
            decimal += (input[i]-'0')*mul;
        else if(input[i]>='A' && input[i]<='F')
            decimal += (input[i]-'A'+10)*mul;
        else if(input[i]>='a' && input[i]<='f')
            decimal += (input[i]-'a'+10)*mul;
        mul *= 16;
    }
    printf("The Decimal equivalent of %s is: %d\n", input, decimal);
}

void decimalconverter(char input[]){
    int decimal = atoi(input), i, j, rem, len = 0;
    char hex[20];
    while(decimal){
        rem = decimal%16;
        if(rem<10)
            hex[len++] = rem+'0';
        else
            hex[len++] = rem-10+'A';
        decimal /= 16;
    }
    if(len == 0)
        hex[len++] = '0';
    hex[len] = '\0';
    printf("The Hexadecimal equivalent of %s is: ", input);
    for(i=len-1; i>=0; i--)
        printf("%c", hex[i]);
    printf("\n");
}
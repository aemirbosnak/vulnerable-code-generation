//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include<stdio.h>

//function to convert decimal to hexadecimal
void dec_to_hex(int dec_num){
    int quotient, remainder, i = 1, j;
    char hex_num[100];

    //convert decimal to hexadecimal
    quotient = dec_num;
    while(quotient != 0){
        remainder = quotient % 16;
        if(remainder < 10)
            hex_num[i++] = 48 + remainder;
        else
            hex_num[i++] = 55 + remainder;
        quotient /= 16;
    }

    //print the hexadecimal number
    printf("\nHexadecimal Equivalent : ");
    for(j = i - 1; j > 0; j--)
        printf("%c", hex_num[j]);
}

//function to convert hexadecimal to decimal
void hex_to_dec(char hex_num[]){
    int i, decimal_num = 0;
    for(i = 0; hex_num[i] != '\0'; i++){
        if(hex_num[i] >= '0' && hex_num[i] <= '9')
            decimal_num = decimal_num * 16 + (hex_num[i] - '0');
        else if(hex_num[i] >= 'A' && hex_num[i] <= 'F')
            decimal_num = decimal_num * 16 + (hex_num[i] - 55);
    }

    //print the decimal number
    printf("\nDecimal Equivalent : %d", decimal_num);
}

int main(){
    int choice, dec_num;
    char hex_num[100];

    //menu for the user to select the conversion
    printf("Select conversion type:\n");
    printf("[1] Decimal to Hexadecimal\n");
    printf("[2] Hexadecimal to Decimal\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Enter decimal number: ");
            scanf("%d", &dec_num);
            dec_to_hex(dec_num);
            break;
        case 2:
            printf("Enter hexadecimal number: ");
            scanf("%s", &hex_num);
            hex_to_dec(hex_num);
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}
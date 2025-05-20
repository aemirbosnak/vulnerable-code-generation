//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimal_to_hex(int decimal_num){
    char hex_num[20];
    int rem, i = 0;

    while(decimal_num > 0){
        rem = decimal_num % 16;
        if(rem < 10){
            hex_num[i] = rem + 48;
        } else {
            hex_num[i] = rem + 55;
        }
        i++;
        decimal_num /= 16;
    }

    printf("\nHexadecimal representation: ");
    for(int j = i - 1; j >= 0; j--){
        printf("%c", hex_num[j]);
    }
}

void hex_to_decimal(char hex_num[]){
    int decimal_num = 0, base = 1, len = strlen(hex_num);
    for(int i = len - 1; i >= 0; i--){
        if(hex_num[i] >= '0' && hex_num[i] <= '9'){
            decimal_num += (hex_num[i] - 48) * base;
            base *= 16;
        } else if(hex_num[i] >= 'A' && hex_num[i] <= 'F'){
            decimal_num += (hex_num[i] - 55) * base;
            base *= 16;
        }
    }
    printf("\nDecimal representation: %d", decimal_num);
}

int main(){
    int choice, decimal_num;
    char hex_num[20];

    while(1){
        printf("\n***HEX TO DECIMAL AND DECIMAL TO HEX CONVERSION***\n");
        printf("\n1. Convert decimal to hexadecimal");
        printf("\n2. Convert hexadecimal to decimal");
        printf("\n3. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                printf("\nEnter a decimal number: ");
                scanf("%d", &decimal_num);
                decimal_to_hex(decimal_num);
                break;

            case 2:
                printf("\nEnter a hexadecimal number: ");
                scanf("%s", hex_num);
                hex_to_decimal(hex_num);
                break;

            case 3:
                printf("\nThanks for using the program. Exit!");
                exit(0);

            default:
                printf("\nInvalid Choice. Try again.");
        }
    }

    return 0;
}
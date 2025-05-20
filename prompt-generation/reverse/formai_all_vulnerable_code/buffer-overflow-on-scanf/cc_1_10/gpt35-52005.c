//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert decimal to hexadecimal */
void decimal_to_hexadecimal(int decimal_num){
    char hex_num[100];
    int count = 0;
    while(decimal_num != 0){
        int rem = decimal_num % 16;
        if(rem < 10){
            hex_num[count] = rem + 48;
            count++;
        }
        else{
            hex_num[count] = rem + 55;
            count++;
        }
        decimal_num /= 16;
    }
    printf("\nHexadecimal Number: ");
    for(int i = count - 1; i >= 0; i--){
        printf("%c", hex_num[i]);
    }
}

/* Function to convert hexadecimal to decimal */
void hexadecimal_to_decimal(char hex_num[]){
    int len = strlen(hex_num);
    int decimal_num = 0;
    int base = 1;
    for(int i = len - 1; i >= 0; i--){
        if(hex_num[i] >= '0' && hex_num[i] <= '9'){
            decimal_num += (hex_num[i] - 48) * base;
            base *= 16;
        }
        else if(hex_num[i] >= 'A' && hex_num[i] <= 'F'){
            decimal_num += (hex_num[i] - 55) * base;
            base *= 16;
        }
    }
    printf("\nDecimal Number: %d", decimal_num);
}

int main(){
    int choice, decimal_num;
    char hex_num[100];
    while(1){
        printf("\n1. Convert decimal to hexadecimal.");
        printf("\n2. Convert hexadecimal to decimal.");
        printf("\n3. Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter decimal number: ");
                scanf("%d", &decimal_num);
                decimal_to_hexadecimal(decimal_num);
                break;
            case 2:
                printf("\nEnter hexadecimal number: ");
                scanf("%s", hex_num);
                hexadecimal_to_decimal(hex_num);
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}
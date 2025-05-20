//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void decimal_to_hex(int decimal) {
   int remainder = 0, quotient = 0, i = 0;
   char hex_number[50];

   while(decimal > 0) {
       remainder = decimal % 16;
       quotient = decimal / 16;
       if(remainder < 10) {
           hex_number[i] = remainder + 48;
           i++;
       }
       else {
           hex_number[i] = remainder + 55;
           i++;
       }
       decimal = quotient;
   }

   printf("\nThe equivalent Hexadecimal number is: ");
   for(int j = i - 1; j >= 0; j--) printf("%c", hex_number[j]);
}

void hex_to_decimal(char *hex_number) {
    int length = strlen(hex_number), decimal = 0, base = 1;
    for(int i = length-1; i >= 0; i--) {
        if(isdigit(hex_number[i])) { 
            decimal += (hex_number[i] - 48) * base;
            base *= 16;
        }
        else if(hex_number[i] >= 'A' && hex_number[i] <= 'F') {
            decimal += (hex_number[i] - 55) * base;
            base *= 16;
        }
        else if(hex_number[i] >= 'a' && hex_number[i] <= 'f') {
            decimal += (hex_number[i] - 87) * base;
            base *= 16;
        }
        else {
            printf("\nInvalid Hexadecimal number.");
            return;
        }
    }
    printf("\nThe equivalent decimal number is: %d", decimal);
}

int main() {
    int choice, decimal;
    char hex_number[50];

    printf("\n1. Convert Decimal to Hexadecimal.");
    printf("\n2. Convert Hexadecimal to Decimal.");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter the decimal number: ");
            scanf("%d", &decimal);
            decimal_to_hex(decimal);
            break;
        case 2:
            printf("\nEnter the hexadecimal number: ");
            scanf("%s", hex_number);
            hex_to_decimal(hex_number);
            break;
        default:
            printf("\nInvalid choice.");
            break;
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void decimal_to_hexadecimal(int decimal_num) {
    char hexa_num[100];
    int i = 0;
    while(decimal_num != 0) {
        int temp = 0;
        temp = decimal_num % 16;
        if(temp < 10) {
            hexa_num[i] = temp + 48;
            i++;
        }
        else {
            hexa_num[i] = temp + 55;
            i++;
        }
        decimal_num = decimal_num / 16;
    }
    printf("Hexadecimal Value: ");
    for(int j = i - 1; j >= 0; j--)
        printf("%c", hexa_num[j]);
    printf("\n");
}

void hexadecimal_to_decimal(char* hexa_num) {
    int decimal_num = 0;
    for(int i = 0; hexa_num[i] != '\0'; i++) {
        if(hexa_num[i] >= '0' && hexa_num[i] <= '9') {
            decimal_num = decimal_num * 16 + (hexa_num[i] - '0');
        }
        else if(hexa_num[i] >= 'A' && hexa_num[i] <= 'F') {
            decimal_num = decimal_num * 16 + (hexa_num[i] - 55);
        }
        else if(hexa_num[i] >= 'a' && hexa_num[i] <= 'f') {
            decimal_num = decimal_num * 16 + (hexa_num[i] - 87);
        }
    }
    printf("\nDecimal Value : %d\n", decimal_num);
}

int main() {
    int choice, decimal_num;
    char hexa_num[100];
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter Decimal Number: ");
            scanf("%d", &decimal_num);
            decimal_to_hexadecimal(decimal_num);
            break;
        case 2:
            printf("Enter Hexadecimal Number: ");
            scanf("%s", hexa_num);
            hexadecimal_to_decimal(hexa_num);
            break;
        default:
            printf("Invalid Input");
    }
    return 0;
}
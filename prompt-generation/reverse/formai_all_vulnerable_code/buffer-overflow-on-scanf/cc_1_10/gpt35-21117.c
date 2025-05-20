//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert decimal to hexadecimal
void decimal_to_hexadecimal(int decimal_number) {
    char hexadecimal_number[100];
    int remainder, i = 0;
    while(decimal_number != 0) {
        remainder = decimal_number % 16;
        if(remainder < 10) {
            hexadecimal_number[i] = remainder + 48;
        } else {
            hexadecimal_number[i] = remainder + 55;
        }
        i++;
        decimal_number /= 16;
    }
    printf("Hexadecimal number is: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal_number[j]);
    }
}

// function to convert hexadecimal to decimal
void hexadecimal_to_decimal(char* hexadecimal_number) {
    int decimal_number = 0, size = strlen(hexadecimal_number);
    for(int i = 0; i < size; i++) {
        if(hexadecimal_number[i] >= '0' && hexadecimal_number[i] <= '9') {
            decimal_number = decimal_number * 16 + hexadecimal_number[i] - '0';
        } else if(hexadecimal_number[i] >= 'A' && hexadecimal_number[i] <= 'F') {
            decimal_number = decimal_number * 16 + hexadecimal_number[i] - 55;
        } else if(hexadecimal_number[i] >= 'a' && hexadecimal_number[i] <= 'f') {
            decimal_number = decimal_number * 16 + hexadecimal_number[i] - 87;
        }
    }
    printf("Decimal number is: %d", decimal_number);
}

int main() {
    char choice;
    printf("Choose an option:\n");
    printf("1. Decimal to Hexadecimal Conversion\n");
    printf("2. Hexadecimal to Decimal Conversion\n");
    scanf("%c", &choice);
    if(choice == '1') {
        int decimal_number;
        printf("Enter a decimal number: ");
        scanf("%d", &decimal_number);
        decimal_to_hexadecimal(decimal_number);
    } else if(choice == '2') {
        char hexadecimal_number[100];
        printf("Enter a hexadecimal number: ");
        scanf("%s", hexadecimal_number);
        hexadecimal_to_decimal(hexadecimal_number);
    } else {
        printf("Invalid choice");
    }
    return 0;
}
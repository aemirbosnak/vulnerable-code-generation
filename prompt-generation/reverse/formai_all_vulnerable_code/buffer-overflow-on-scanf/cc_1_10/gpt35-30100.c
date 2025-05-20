//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void decimal_to_hexadecimal(int decimal);
void hexadecimal_to_decimal(char* hexadecimal);

int main() {
    char option;
    int decimal;
    char hexadecimal[MAX_LENGTH];
    
    printf("Welcome to the Hexadecimal Converter!\n\n");
    
    do {
        printf("Please select an option:\n");
        printf("(A) Convert from decimal to hexadecimal\n");
        printf("(B) Convert from hexadecimal to decimal\n");
        printf("(Q) Quit the program\n");
        scanf(" %c", &option);

        switch (option) {
            case 'A':
            case 'a':
                printf("\nPlease enter a decimal number: ");
                scanf("%d", &decimal);
                decimal_to_hexadecimal(decimal);
                break;
                
            case 'B':
            case 'b':
                printf("\nPlease enter a hexadecimal number: ");
                scanf("%s", hexadecimal);
                hexadecimal_to_decimal(hexadecimal);
                break;
                
            case 'Q':
            case 'q':
                printf("\nGoodbye!\n");
                break;
                
            default:
                printf("\nInvalid option. Please try again.\n\n");
                break;
        }
    } while (option != 'Q' && option != 'q');
    
    return 0;
}

void decimal_to_hexadecimal(int decimal) {
    int quotient, remainder, i = 0;
    char hexadecimal[MAX_LENGTH];

    while (decimal > 0) {
        quotient = decimal / 16;
        remainder = decimal % 16;

        if (remainder < 10) {
            hexadecimal[i] = remainder + '0';
        } else {
            hexadecimal[i] = remainder + 55;
        }

        i++;
        decimal = quotient;
    }

    printf("\nThe hexadecimal representation is: ");

    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    
    printf("\n\n");
}

void hexadecimal_to_decimal(char* hexadecimal) {
    int decimal = 0, length = strlen(hexadecimal), base = 1;

    for (int i = length - 1; i >= 0; i--) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (hexadecimal[i] - '0') * base;
            base *= 16;
        } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            decimal += (hexadecimal[i] - 55) * base;
            base *= 16;
        } else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f'){
            decimal += (hexadecimal[i] - 87) * base;
            base *= 16;
        }
    }

    printf("\nThe decimal representation is: %d\n\n", decimal);
}
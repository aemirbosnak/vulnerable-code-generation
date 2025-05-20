//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binaryToHexadecimal(char[]);
int hexadecimalToDecimal(char);
void decimalToHexadecimal(int);
int isHexadecimal(char[]);
int isBinary(char[]);
int power(int, int);

int main() {
    char input[100];
    int option, decimal;

    printf("Welcome to the Hexadecimal Converter Program\n");
    
    while(1) {
        printf("Select an option:\n\n");
        printf("1. Binary to Hexadecimal\n");
        printf("2. Hexadecimal to Decimal\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter a binary number: ");
                scanf("%s", input);

                if(isBinary(input)) {
                    binaryToHexadecimal(input);
                } else {
                    printf("\nInvalid binary number.\n");
                }

                break;

            case 2:
                printf("\nEnter a hexadecimal number: ");
                scanf("%s", input);

                if(isHexadecimal(input)) {
                    decimal = 0;
                    for(int i = 0; input[i]!='\0'; i++) {
                        decimal = decimal*16 + hexadecimalToDecimal(input[i]);
                    }
                    printf("\nThe decimal equivalent is: %d\n", decimal);
                } else {
                    printf("\nInvalid hexadecimal number.\n");
                }

                break;

            case 3:
                printf("\nEnter a decimal number: ");
                scanf("%d", &decimal);

                printf("\nThe hexadecimal equivalent is: ");
                decimalToHexadecimal(decimal);
                printf("\n");

                break;

            case 4:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid option.\n");

        }
    }
}

void binaryToHexadecimal(char input[]) {
    int binary, length, decimal = 0, i = 0;
    char hexadecimal[20] = {'\0'};

    length = strlen(input);

    while(length--) {
        binary = input[length] - '0';
        decimal = decimal + binary*power(2, i++);
    }

    int index = 0;

    while(decimal !=0) {
        int rem = decimal%16;
        if(rem<10) {
            hexadecimal[index++] = rem + 48;
        } else {
            hexadecimal[index++] = rem + 55;
        }
        decimal = decimal/16;
    }

    printf("\nThe hexadecimal equivalent is: ");
    for(int i=index-1; i>=0; i--) {
        printf("%c", hexadecimal[i]);
    }
    printf("\n");
}

int hexadecimalToDecimal(char hex) {
    if(hex>='0' && hex<='9') {
        return hex - '0';
    } else if(hex>='A' && hex<='F') {
        return hex - 'A' + 10;
    } else if(hex>='a' && hex<='f') {
        return hex - 'a' + 10;
    } else {
        return -1;
    }
}

void decimalToHexadecimal(int decimal) {
    char hexadecimal[20];
    int index = 0;

    while(decimal != 0) {
        int rem = decimal%16;
        if(rem<10) {
            hexadecimal[index++] = rem + 48;
        } else {
            hexadecimal[index++] = rem + 55;
        }
        decimal = decimal/16;
    }

    for(int i=index-1; i>=0; i--) {
        printf("%c", hexadecimal[i]);
    }
}

int isHexadecimal(char input[]) {
    for(int i = 0; input[i]!='\0'; i++) {
        if((input[i]>='0' && input[i]<='9') || (input[i]>='A' && input[i]<='F') || (input[i]>='a' && input[i]<='f')) {
            continue;
        } else {
            return 0;
        }
    }

    return 1;
}

int isBinary(char input[]) {
    for(int i = 0; input[i]!='\0'; i++) {
        if(input[i] == '0' || input[i] == '1') {
            continue;
        } else {
            return 0;
        }
    }

    return 1;
}

int power(int base, int exponent) { // helper function to calculate power of 2
    int result = 1;

    for(int i = 0; i<exponent; i++) {
        result *= base;
    }

    return result;
}
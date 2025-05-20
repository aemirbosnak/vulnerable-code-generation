//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void binaryToDecimal(char binary[]);
void decimalToBinary(int decimal);
void displayResult(char binary[], int decimal);

int main() {
    char binary[MAX_LENGTH];
    int decimal;
    int choice;

    while(1) {
        printf("Enter 1 to convert decimal to binary\n");
        printf("Enter 2 to convert binary to decimal\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            decimalToBinary(decimal);
        }
        else if(choice == 2) {
            printf("Enter a binary number: ");
            scanf("%s", binary);
            binaryToDecimal(binary);
        }
        else if(choice == 3) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

void binaryToDecimal(char binary[]) {
    int decimal = 0, i = 0;
    while(binary[i]!= '\0') {
        if(binary[i] == '1') {
            decimal += pow(2, strlen(binary) - i - 1);
        }
        i++;
    }
    printf("The decimal equivalent is: %d\n", decimal);
}

void decimalToBinary(int decimal) {
    char binary[MAX_LENGTH];
    int i = 0;

    while(decimal > 0) {
        if(decimal % 2 == 0) {
            strcat(binary, "0");
        }
        else {
            strcat(binary, "1");
        }
        decimal /= 2;
        i++;
    }

    printf("The binary equivalent is: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", binary[j]);
    }
    printf("\n");
}

void displayResult(char binary[], int decimal) {
    printf("Result:\n");
    if(strcmp(binary, "0") == 0 || strcmp(binary, "1") == 0) {
        printf("Binary: %s\n", binary);
    }
    else {
        printf("Binary: ");
        for(int i = strlen(binary) - 1; i >= 0; i--) {
            printf("%c", binary[i]);
        }
        printf("\n");
    }
    printf("Decimal: %d\n", decimal);
}
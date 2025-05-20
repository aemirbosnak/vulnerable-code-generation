//FormAI DATASET v1.0 Category: Binary Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void binaryToDecimal(){
    char binary[1000];
    int decimal=0, len=0, i=0, j=0, bitValue=0;

    printf("\nEnter a binary number: ");
    scanf("%s", binary);

    len = strlen(binary);
    j = len - 1;

    for(i=0; i<len; i++){
        bitValue = binary[j]-'0';
        decimal += bitValue*pow(2, i);
        j--;
    }

    printf("Decimal value: %d\n\n", decimal);
}

void decimalToBinary(){
    int decimal=0, binary[1000], i=0, j=0;

    printf("\nEnter a decimal number: ");
    scanf("%d", &decimal);

    while(decimal != 0){
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    printf("Binary value: ");

    for(j=i-1; j>=0; j--){
        printf("%d", binary[j]);
    }

    printf("\n\n");
}

void menu(){
    int choice=0;

    while(choice != 3){
        printf("\n==================\n");
        printf("Binary Converter\n");
        printf("==================\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                binaryToDecimal();
                break;
            
            case 2:
                decimalToBinary();
                break;

            case 3:
                printf("Goodbye!\n\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }
}

int main(){
    menu();
    return 0;
}
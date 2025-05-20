//FormAI DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void BinaryToDecimal(){
    char binaryStr[100];
    int decimal = 0, length = 0, index = 0;
    printf("Enter a binary number: ");
    scanf("%s", binaryStr);
    length = strlen(binaryStr);
    for(int i = (length - 1); i >= 0; i--){
        if(binaryStr[i] == '1'){
            decimal += (int) pow(2, index);
        }
        index++;
    }
    printf("The decimal equivalent is: %d\n", decimal);
}

void DecimalToBinary(){
    int decimal, binaryArr[100], index = 0;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    while(decimal > 0){
        binaryArr[index] = decimal % 2;
        decimal = decimal / 2;
        index++;
    }
    printf("The binary equivalent is: ");
    for(int i = (index - 1); i >= 0; i--){
        printf("%d", binaryArr[i]);
    }
    printf("\n");
}

int main(){
    int choice;
    printf("1. Binary to Decimal Conversion\n");
    printf("2. Decimal to Binary Conversion\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if(choice == 1){
        BinaryToDecimal();
    } else if(choice == 2){
        DecimalToBinary();
    } else {
        printf("Invalid choice!\n");
        exit(0);
    }
    return 0;
}
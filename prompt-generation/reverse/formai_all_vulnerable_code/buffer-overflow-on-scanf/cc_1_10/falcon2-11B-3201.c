//Falcon2-11B DATASET v1.0 Category: Binary Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>

int convertBinaryToDecimal(char* binary){
    int decimal = 0;
    int index = 0;
    int length = strlen(binary);

    for(int i = 0; i < length; i++){
        if(binary[i] == '1'){
            decimal += pow(2, index);
        }
        index++;
    }

    return decimal;
}

char* convertDecimalToBinary(int decimal){
    char* binary = (char*)malloc(100 * sizeof(char));
    int length = 0;
    int index = 0;
    int power = 1;

    while(decimal > 0){
        binary[length] = '1';
        decimal -= power;
        power *= 2;
        length++;
    }

    for(int i = length - 1; i >= 0; i--){
        if(binary[i] == '1'){
            binary[i] = '0';
        }
        else{
            binary[i] = '1';
        }
    }

    return binary;
}

int main(){
    char* binary;
    int decimal;

    printf("Enter binary number: ");
    scanf("%s", &binary);

    printf("Enter decimal number: ");
    scanf("%d", &decimal);

    printf("Binary: %s\nDecimal: %d\n", binary, convertBinaryToDecimal(binary));
    printf("Decimal: %d\nBinary: %s\n", decimal, convertDecimalToBinary(decimal));

    return 0;
}
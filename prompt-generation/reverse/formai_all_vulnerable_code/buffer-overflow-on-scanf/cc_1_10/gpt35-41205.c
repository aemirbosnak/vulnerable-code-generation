//FormAI DATASET v1.0 Category: Binary Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert binary to decimal
int binaryToDecimal(char *binary){
    int decimal = 0, base = 1, length = strlen(binary);
    for(int i = length-1; i >= 0; i--){
        if(binary[i] == '1'){
            decimal += base;
        }
        base = base << 1;
    }
    return decimal;
}

// function to convert decimal to binary
char* decimalToBinary(int decimal){
    int remainder, length = 0;
    char *binary = NULL;
    while(decimal > 0){
        remainder = decimal % 2;
        length++;
        binary = (char*)realloc(binary, length * sizeof(char));
        binary[length-1] = remainder + '0';
        decimal = decimal / 2;
    }
    binary = (char*)realloc(binary, (length + 1) * sizeof(char));
    binary[length] = '\0';
    char temp;
    for(int i = 0; i < length/2; i++){
        temp = binary[i];
        binary[i] = binary[length-1-i];
        binary[length-1-i] = temp;
    }
    return binary;
}

int main(){
    char binary[100];
    printf("Enter a binary number: ");
    scanf("%s", binary);
    int decimal = binaryToDecimal(binary);
    printf("Decimal equivalent is: %d\n", decimal);
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    char *binary2 = decimalToBinary(number);
    printf("Binary equivalent is: %s\n", binary2);
    free(binary2);
    return 0;
}
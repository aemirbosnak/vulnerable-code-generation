//FormAI DATASET v1.0 Category: Binary Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* decimalToBinary(int n) {
    int binaryNum[32];
    int i = 0;
    char *binaryStr = (char*) malloc(sizeof(char) * 32);
    
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    
    for (int j = i - 1; j >= 0; j--) {
        sprintf(binaryStr, "%s%d", binaryStr, binaryNum[j]);
    }
    
    return binaryStr;
}

int binaryToDecimal(char* binary) {
    int decimal = 0;
    int len = strlen(binary);
    int power = len - 1;
    
    for (int i = 0; i < len; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power--;
    }
    
    return decimal;
}

int main() {
    printf("Enter a decimal number: ");
    int decimal;
    scanf("%d", &decimal);
    
    char *binary = decimalToBinary(decimal);
    printf("The binary equivalent of %d is %s\n", decimal, binary);
    
    printf("Enter a binary number: ");
    char binaryStr[32];
    scanf("%s", binaryStr);
    
    int decimalValue = binaryToDecimal(binaryStr);
    printf("The decimal equivalent of %s is %d\n", binaryStr, decimalValue);
    
    free(binary);
    return 0;
}
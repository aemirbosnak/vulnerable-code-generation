//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    char binary[MAX_SIZE];
    char hex[MAX_SIZE];
    int decimal;
    int i = 0;
    int j = 0;
    int k = 0;
    int len = 0;
    int flag = 0;

    printf("Enter a binary number: ");
    scanf("%s", binary);

    len = strlen(binary);

    if(len > 0 && binary[0] == '0') {
        flag = 1;
    }

    if(flag == 0) {
        printf("Invalid binary number\n");
        return 0;
    }

    for(i = 0; i < len; i++) {
        if(binary[i]!= '0' && binary[i]!= '1') {
            printf("Invalid binary number\n");
            return 0;
        }
    }

    decimal = 0;

    for(i = len - 1; i >= 0; i--) {
        if(binary[i] == '1') {
            decimal += pow(2, len - 1 - i);
        }
    }

    sprintf(hex, "%X", decimal);

    printf("Binary: %s\n", binary);
    printf("Decimal: %s\n", hex);

    return 0;
}
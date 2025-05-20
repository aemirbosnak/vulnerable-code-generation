//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void decimal_to_binary(int decimal_num) {
    if(decimal_num == 0) {
        printf("0");
        return;
    }
    int binary_num[32], i = 0;
    while(decimal_num > 0) {
        binary_num[i] = decimal_num % 2;
        decimal_num = decimal_num / 2;
        i++;
    }
    for(int j = i - 1; j >= 0; j--)
        printf("%d", binary_num[j]);
}

int binary_to_decimal(char binary_num[]) {
    int decimal_num = 0, len = strlen(binary_num) - 1, i, base = 1;
    for(i = len; i >= 0; i--) {
        if(binary_num[i] == '1')
            decimal_num += base;
        base = base * 2;
    }
    return decimal_num;
}

int main() {
    int choice;
    printf("Enter your choice:\n1. Convert decimal to binary\n2. Convert binary to decimal\n");
    scanf("%d", &choice);
    if(choice == 1) {
        int decimal_num;
        printf("Enter decimal number: ");
        scanf("%d", &decimal_num);
        printf("Binary conversion of %d is ", decimal_num);
        decimal_to_binary(decimal_num);
    }
    else if(choice == 2) {
        char binary_num[32];
        printf("Enter binary number: ");
        scanf("%s", binary_num);
        printf("Decimal conversion of %s is %d", binary_num, binary_to_decimal(binary_num));
    }
    else
        printf("Invalid input!");
    return 0;
}
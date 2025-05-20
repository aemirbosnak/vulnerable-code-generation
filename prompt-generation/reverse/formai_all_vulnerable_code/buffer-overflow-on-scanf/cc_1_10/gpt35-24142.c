//FormAI DATASET v1.0 Category: Binary Converter ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <math.h>

void decimal_to_binary(int num){
    int binary_num[1000], i = 0;
    while(num > 0){
        binary_num[i] = num % 2;
        num /= 2;
        i++;
    }
    printf("Binary Number: ");
    for(int j = i - 1;j >= 0;j--){
        printf("%d", binary_num[j]);
    }
    printf("\n");
}

void binary_to_decimal(int num){
    int decimal_num = 0, base = 1;
    while(num > 0){
        int last_digit = num % 10;
        num /= 10;
        decimal_num += last_digit * base;
        base *= 2;
    }
    printf("Decimal Number: %d\n", decimal_num);
}

int main(){
    int option;
    printf("Choose an option:\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");

    scanf("%d", &option);
    if(option == 1){
        int num;
        printf("Enter the decimal number: ");
        scanf("%d", &num);
        decimal_to_binary(num);
    }
    else if(option == 2){
        int num;
        printf("Enter the binary number: ");
        scanf("%d", &num);
        binary_to_decimal(num);
    }
    else{
        printf("Invalid option!");
    }
    return 0;
}
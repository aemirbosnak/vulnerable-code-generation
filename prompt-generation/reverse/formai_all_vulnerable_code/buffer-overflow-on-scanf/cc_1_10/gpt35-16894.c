//FormAI DATASET v1.0 Category: Binary Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void decimal_to_binary(int decimal_num) {
    if(decimal_num == 0) {
        return;
    }
    decimal_to_binary(decimal_num/2);
    printf("%d", decimal_num%2);
}

int binary_to_decimal(char binary_num[]) {
    int decimal_num = 0;
    int base = 1;
    int i = 0;
    int len = 0;
    while(binary_num[i] != '\0') {
        len++;
        i++;
    }
    for(i=len-1; i>=0; i--) {
        if(binary_num[i] == '1') {
            decimal_num += base;
        }
        base *= 2;
    }
    return decimal_num;
}

int main() {
    int menu_choice = -1;
    while(menu_choice != 0) {
        printf("Select an option:\n1. Decimal to Binary\n2. Binary to Decimal\n0. Exit\n");
        scanf("%d", &menu_choice);
        switch(menu_choice) {
            case 1:
                printf("Enter decimal number: ");
                int decimal = 0;
                scanf("%d", &decimal);
                decimal_to_binary(decimal);
                printf("\n");
                break;
            case 2:
                printf("Enter binary number: ");
                char binary[100];
                scanf("%s", binary);
                int decimal_result = binary_to_decimal(binary);
                printf("Decimal number is: %d\n", decimal_result);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}
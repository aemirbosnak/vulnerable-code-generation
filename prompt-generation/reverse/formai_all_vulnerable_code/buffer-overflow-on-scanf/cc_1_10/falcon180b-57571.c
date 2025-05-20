//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_SIZE 32

void print_binary(unsigned int num) {
    char binary_num[MAX_NUM_SIZE];
    int i = 0;
    while (num > 0) {
        binary_num[i++] = (num % 2) + '0';
        num /= 2;
    }
    printf("Binary: %s\n", binary_num);
}

void print_decimal(char binary_num[]) {
    int decimal_num = 0;
    int i = strlen(binary_num) - 1;
    while (i >= 0) {
        decimal_num += (binary_num[i] - '0') * pow(2, strlen(binary_num) - 1 - i);
        i--;
    }
    printf("Decimal: %d\n", decimal_num);
}

int main() {
    srand(time(NULL));
    int choice;
    do {
        printf("Enter 1 to convert decimal to binary\n");
        printf("Enter 2 to convert binary to decimal\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            int decimal_num;
            printf("Enter a decimal number: ");
            scanf("%d", &decimal_num);
            char binary_num[MAX_NUM_SIZE];
            sprintf(binary_num, "%b", decimal_num);
            print_binary(decimal_num);
            print_decimal(binary_num);
        } else if (choice == 2) {
            char binary_num[MAX_NUM_SIZE];
            printf("Enter a binary number: ");
            scanf("%s", binary_num);
            int decimal_num = atoi(binary_num);
            print_binary(decimal_num);
            print_decimal(binary_num);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);
    return 0;
}
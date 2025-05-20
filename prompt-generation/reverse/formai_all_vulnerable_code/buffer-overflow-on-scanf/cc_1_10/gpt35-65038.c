//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_header() {
    printf("+-----------------------+\n");
    printf("| C Binary Converter v1 |\n");
    printf("+-----------------------+\n");
}

int decimal_to_binary(int num) {
    int binary_num = 0;
    int remainder, base = 1;

    while (num > 0) {
        remainder = num % 2;
        binary_num += remainder * base;
        num /= 2;
        base *= 10;
    }

    return binary_num;
}

int binary_to_decimal(int binary_num) {
    int decimal_num = 0, base = 1;
    int temp = binary_num;

    while (temp > 0) {
        int last_digit = temp % 10;
        temp /= 10;

        decimal_num += last_digit * base;
        base *= 2;
    }

    return decimal_num;
}

void display_menu() {
    printf("What do you want to convert?\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Exit\n");
}

int get_choice() {
    int choice;

    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

void decimal_to_binary_converter() {
    printf("Enter a decimal number: ");
    int num;
    scanf("%d", &num);

    int binary_num = decimal_to_binary(num);

    printf("Binary equivalent of %d is %d\n", num, binary_num);
}

void binary_to_decimal_converter() {
    printf("Enter a binary number: ");

    char binary_string[100];
    scanf("%s", binary_string);

    int binary_num = atoi(binary_string);

    int decimal_num = binary_to_decimal(binary_num);

    printf("Decimal equivalent of %d is %d\n", binary_num, decimal_num);
}

void execute_choice(int choice) {
    switch(choice) {
        case 1:
            decimal_to_binary_converter();
            break;
        case 2:
            binary_to_decimal_converter();
            break;
        case 3:
            printf("Thank you for using C Binary Converter\n");
            exit(0);
        default:
            printf("Invalid choice\n");
    }
}

int main() {
    display_header();

    while (1) {
        display_menu();
        int choice = get_choice();
        execute_choice(choice);
    }

    return 0;
}
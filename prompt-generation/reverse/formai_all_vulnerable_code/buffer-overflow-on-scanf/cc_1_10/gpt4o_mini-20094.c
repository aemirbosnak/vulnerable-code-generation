//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: retro
#include <stdio.h>

void display_menu() {
    printf("\n--- Welcome to the Retro Bitwise Operations Program! ---\n");
    printf("1. Enter a Number\n");
    printf("2. Bitwise AND\n");
    printf("3. Bitwise OR\n");
    printf("4. Bitwise XOR\n");
    printf("5. Bitwise NOT\n");
    printf("6. Left Shift\n");
    printf("7. Right Shift\n");
    printf("8. Exit\n");
    printf("Please choose an option (1-8): ");
}

void enter_number(unsigned int *num) {
    printf("Enter a positive integer: ");
    scanf("%u", num);
}

void bitwise_and(unsigned int num) {
    unsigned int operand;
    printf("Enter another integer for AND operation: ");
    scanf("%u", &operand);
    printf("Result of %u AND %u = %u\n", num, operand, num & operand);
}

void bitwise_or(unsigned int num) {
    unsigned int operand;
    printf("Enter another integer for OR operation: ");
    scanf("%u", &operand);
    printf("Result of %u OR %u = %u\n", num, operand, num | operand);
}

void bitwise_xor(unsigned int num) {
    unsigned int operand;
    printf("Enter another integer for XOR operation: ");
    scanf("%u", &operand);
    printf("Result of %u XOR %u = %u\n", num, operand, num ^ operand);
}

void bitwise_not(unsigned int num) {
    printf("Result of NOT %u = %u\n", num, ~num);
}

void left_shift(unsigned int num) {
    int shift;
    printf("Enter number of positions to left shift: ");
    scanf("%d", &shift);
    printf("Result of %u << %d = %u\n", num, shift, num << shift);
}

void right_shift(unsigned int num) {
    int shift;
    printf("Enter number of positions to right shift: ");
    scanf("%d", &shift);
    printf("Result of %u >> %d = %u\n", num, shift, num >> shift);
}

int main() {
    unsigned int number = 0;
    int choice = 0;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enter_number(&number);
                break;
            case 2:
                bitwise_and(number);
                break;
            case 3:
                bitwise_or(number);
                break;
            case 4:
                bitwise_xor(number);
                break;
            case 5:
                bitwise_not(number);
                break;
            case 6:
                left_shift(number);
                break;
            case 7:
                right_shift(number);
                break;
            case 8:
                printf("Goodbye! Thanks for playing with bitwise operations!\n");
                return 0;
            default:
                printf("Invalid choice! Please choose a number between 1 and 8.\n");
        }
    }

    return 0;
}
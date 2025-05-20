//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: imaginative
#include <stdio.h>

#define TOGGLE_BITS 1
#define SHIFT_LEFT 2
#define SHIFT_RIGHT 3
#define AND_OPERATION 4
#define OR_OPERATION 5
#define XOR_OPERATION 6
#define NOT_OPERATION 7

void display_menu() {
    printf("\n====================================\n");
    printf("       Bitwise Operations Menu\n");
    printf("====================================\n");
    printf("1. Toggle Bits\n");
    printf("2. Shift Left\n");
    printf("3. Shift Right\n");
    printf("4. AND Operation\n");
    printf("5. OR Operation\n");
    printf("6. XOR Operation\n");
    printf("7. NOT Operation\n");
    printf("8. Exit\n");
    printf("====================================\n");
    printf("Select an operation (1-8): ");
}

unsigned int toggle_bits(unsigned int num) {
    return ~num;
}

unsigned int shift_left(unsigned int num, unsigned int positions) {
    return num << positions;
}

unsigned int shift_right(unsigned int num, unsigned int positions) {
    return num >> positions;
}

unsigned int and_operation(unsigned int num1, unsigned int num2) {
    return num1 & num2;
}

unsigned int or_operation(unsigned int num1, unsigned int num2) {
    return num1 | num2;
}

unsigned int xor_operation(unsigned int num1, unsigned int num2) {
    return num1 ^ num2;
}

unsigned int not_operation(unsigned int num) {
    return ~num;
}

unsigned int get_number_input(char *prompt) {
    unsigned int num;
    printf("%s", prompt);
    scanf("%u", &num);
    return num;
}

int main() {
    int choice;
    unsigned int num1, num2, positions;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case TOGGLE_BITS:
                num1 = get_number_input("Enter a number to toggle bits: ");
                printf("Original: %u, Toggled: %u\n", num1, toggle_bits(num1));
                break;

            case SHIFT_LEFT:
                num1 = get_number_input("Enter a number to shift left: ");
                positions = get_number_input("Enter number of positions to shift left: ");
                printf("Original: %u, Shifted Left: %u\n", num1, shift_left(num1, positions));
                break;

            case SHIFT_RIGHT:
                num1 = get_number_input("Enter a number to shift right: ");
                positions = get_number_input("Enter number of positions to shift right: ");
                printf("Original: %u, Shifted Right: %u\n", num1, shift_right(num1, positions));
                break;

            case AND_OPERATION:
                num1 = get_number_input("Enter first number for AND operation: ");
                num2 = get_number_input("Enter second number for AND operation: ");
                printf("Result of AND operation: %u\n", and_operation(num1, num2));
                break;

            case OR_OPERATION:
                num1 = get_number_input("Enter first number for OR operation: ");
                num2 = get_number_input("Enter second number for OR operation: ");
                printf("Result of OR operation: %u\n", or_operation(num1, num2));
                break;

            case XOR_OPERATION:
                num1 = get_number_input("Enter first number for XOR operation: ");
                num2 = get_number_input("Enter second number for XOR operation: ");
                printf("Result of XOR operation: %u\n", xor_operation(num1, num2));
                break;

            case NOT_OPERATION:
                num1 = get_number_input("Enter a number to perform NOT operation: ");
                printf("Original: %u, NOT Result: %u\n", num1, not_operation(num1));
                break;

            case 8:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please select again\n");
                break;
        }
    } while (choice != 8);

    return 0;
}
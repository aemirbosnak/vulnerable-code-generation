//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void display_menu();
void bitwise_operations(int a, int b);
void calculate_bitwise_and(int a, int b);
void calculate_bitwise_or(int a, int b);
void calculate_bitwise_xor(int a, int b);
void calculate_bitwise_not(int a);
void calculate_left_shift(int a, int shift);
void calculate_right_shift(int a, int shift);

int main() {
    int option;
    int a, b;

    printf("Welcome to the Bitwise Operations Program!\n");
    
    while (1) {
        display_menu();
        printf("Choose an option (0 to exit): ");
        scanf("%d", &option);

        if (option == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        printf("Enter the first integer (a): ");
        scanf("%d", &a);
        printf("Enter the second integer (b): ");
        scanf("%d", &b);

        bitwise_operations(a, b);
    }

    return 0;
}

void display_menu() {
    printf("\n------ Bitwise Operations Menu ------\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("------------------------------------\n");
}

void bitwise_operations(int a, int b) {
    while (1) {
        int operation;
        printf("\nSelect operation (1-6, 0 to return to main menu): ");
        scanf("%d", &operation);

        if (operation == 0) {
            break;
        }

        switch (operation) {
            case 1:
                calculate_bitwise_and(a, b);
                break;
            case 2:
                calculate_bitwise_or(a, b);
                break;
            case 3:
                calculate_bitwise_xor(a, b);
                break;
            case 4:
                calculate_bitwise_not(a);
                break;
            case 5:
                {
                    int shift;
                    printf("Enter number of positions to shift left: ");
                    scanf("%d", &shift);
                    calculate_left_shift(a, shift);
                }
                break;
            case 6:
                {
                    int shift;
                    printf("Enter number of positions to shift right: ");
                    scanf("%d", &shift);
                    calculate_right_shift(a, shift);
                }
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }
}

void calculate_bitwise_and(int a, int b) {
    int result = a & b;
    printf("Bitwise AND of %d and %d is: %d (0x%X)\n", a, b, result, result);
}

void calculate_bitwise_or(int a, int b) {
    int result = a | b;
    printf("Bitwise OR of %d and %d is: %d (0x%X)\n", a, b, result, result);
}

void calculate_bitwise_xor(int a, int b) {
    int result = a ^ b;
    printf("Bitwise XOR of %d and %d is: %d (0x%X)\n", a, b, result, result);
}

void calculate_bitwise_not(int a) {
    int result = ~a;
    printf("Bitwise NOT of %d is: %d (0x%X)\n", a, result, result);
}

void calculate_left_shift(int a, int shift) {
    int result = a << shift;
    printf("Left shift of %d by %d positions is: %d (0x%X)\n", a, shift, result, result);
}

void calculate_right_shift(int a, int shift) {
    int result = a >> shift;
    printf("Right shift of %d by %d positions is: %d (0x%X)\n", a, shift, result, result);
}
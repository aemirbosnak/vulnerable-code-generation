//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: dynamic
#include <stdio.h>

// Function declarations
void displayMenu();
int bitwiseAND(int a, int b);
int bitwiseOR(int a, int b);
int bitwiseXOR(int a, int b);
int bitwiseNOT(int a);
int leftShift(int a, int shift);
int rightShift(int a, int shift);

int main() {
    int choice, a, b, shift;
    
    while (1) {
        displayMenu();
        printf("Enter your choice (1-8, 0 to exit): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter two integers: ");
                scanf("%d %d", &a, &b);
                printf("Bitwise AND of %d and %d is: %d\n", a, b, bitwiseAND(a, b));
                break;
            case 2:
                printf("Enter two integers: ");
                scanf("%d %d", &a, &b);
                printf("Bitwise OR of %d and %d is: %d\n", a, b, bitwiseOR(a, b));
                break;
            case 3:
                printf("Enter two integers: ");
                scanf("%d %d", &a, &b);
                printf("Bitwise XOR of %d and %d is: %d\n", a, b, bitwiseXOR(a, b));
                break;
            case 4:
                printf("Enter an integer: ");
                scanf("%d", &a);
                printf("Bitwise NOT of %d is: %d\n", a, bitwiseNOT(a));
                break;
            case 5:
                printf("Enter an integer and number of positions to shift left: ");
                scanf("%d %d", &a, &shift);
                printf("%d left shifted by %d positions is: %d\n", a, shift, leftShift(a, shift));
                break;
            case 6:
                printf("Enter an integer and number of positions to shift right: ");
                scanf("%d %d", &a, &shift);
                printf("%d right shifted by %d positions is: %d\n", a, shift, rightShift(a, shift));
                break;
            case 7:
                printf("Enter two integers: ");
                scanf("%d %d", &a, &b);
                printf("Results of AND, OR, XOR between %d and %d are:\n", a, b);
                printf("AND: %d\nOR: %d\nXOR: %d\n", bitwiseAND(a, b), bitwiseOR(a, b), bitwiseXOR(a, b));
                break;
            case 8:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nBitwise Operations Menu:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("7. Display results of AND, OR, XOR\n");
    printf("8. Exit\n");
}

// Function implementations
int bitwiseAND(int a, int b) {
    return a & b;
}

int bitwiseOR(int a, int b) {
    return a | b;
}

int bitwiseXOR(int a, int b) {
    return a ^ b;
}

int bitwiseNOT(int a) {
    return ~a;
}

int leftShift(int a, int shift) {
    return a << shift;
}

int rightShift(int a, int shift) {
    return a >> shift;
}
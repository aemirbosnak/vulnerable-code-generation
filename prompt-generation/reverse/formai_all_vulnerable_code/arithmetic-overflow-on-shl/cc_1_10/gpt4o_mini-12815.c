//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
int bitwiseAND(int a, int b);
int bitwiseOR(int a, int b);
int bitwiseXOR(int a, int b);
int bitwiseNOT(int a);
int leftShift(int a, int n);
int rightShift(int a, int n);

int main() {
    int choice, a, b, n;
    
    printf("Welcome to the Bitwise Operations Program!\n");
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }
        
        if (choice == 6) {
            printf("Exiting the program...\n");
            break;
        }
        
        switch (choice) {
            case 1:
                printf("Enter two integers for AND operation: ");
                scanf("%d %d", &a, &b);
                printf("Result of %d & %d = %d\n", a, b, bitwiseAND(a, b));
                break;
            case 2:
                printf("Enter two integers for OR operation: ");
                scanf("%d %d", &a, &b);
                printf("Result of %d | %d = %d\n", a, b, bitwiseOR(a, b));
                break;
            case 3:
                printf("Enter two integers for XOR operation: ");
                scanf("%d %d", &a, &b);
                printf("Result of %d ^ %d = %d\n", a, b, bitwiseXOR(a, b));
                break;
            case 4:
                printf("Enter an integer for NOT operation: ");
                scanf("%d", &a);
                printf("Result of ~%d = %d\n", a, bitwiseNOT(a));
                break;
            case 5:
                printf("Enter an integer and the number of positions to shift left: ");
                scanf("%d %d", &a, &n);
                printf("Result of %d << %d = %d\n", a, n, leftShift(a, n));
                break;
            case 6:
                printf("Enter an integer and the number of positions to shift right: ");
                scanf("%d %d", &a, &n);
                printf("Result of %d >> %d = %d\n", a, n, rightShift(a, n));
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n--- Bitwise Operations Menu ---\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Bitwise Left Shift\n");
    printf("6. Bitwise Right Shift\n");
    printf("6. Exit\n");
}

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

int leftShift(int a, int n) {
    return a << n;
}

int rightShift(int a, int n) {
    return a >> n;
}
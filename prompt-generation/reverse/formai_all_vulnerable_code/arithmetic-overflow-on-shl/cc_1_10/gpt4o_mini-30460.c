//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: detailed
#include <stdio.h>

// Function prototypes
void displayMenu();
void performBitwiseOperations(int a, int b);

int main() {
    int a, b;

    // Taking two integers as input from the user
    printf("Enter first integer (a): ");
    scanf("%d", &a);
    printf("Enter second integer (b): ");
    scanf("%d", &b);

    // Performing bitwise operations
    performBitwiseOperations(a, b);

    return 0;
}

// Function to display menu options
void displayMenu() {
    printf("Choose a bitwise operation to perform:\n");
    printf("1. Bitwise AND (a & b)\n");
    printf("2. Bitwise OR (a | b)\n");
    printf("3. Bitwise XOR (a ^ b)\n");
    printf("4. Bitwise NOT (~a)\n");
    printf("5. Shift Left (a << 1)\n");
    printf("6. Shift Right (a >> 1)\n");
    printf("7. View both numbers in binary\n");
    printf("8. Exit\n");
}

// Function to perform various bitwise operations
void performBitwiseOperations(int a, int b) {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Result of %d & %d = %d\n", a, b, a & b);
                break;
            case 2:
                printf("Result of %d | %d = %d\n", a, b, a | b);
                break;
            case 3:
                printf("Result of %d ^ %d = %d\n", a, b, a ^ b);
                break;
            case 4:
                printf("Result of ~%d = %d\n", a, ~a);
                break;
            case 5:
                printf("Result of %d << 1 = %d\n", a, a << 1);
                break;
            case 6:
                printf("Result of %d >> 1 = %d\n", a, a >> 1);
                break;
            case 7:
                printf("Binary representation:\n");
                printf("a = %d: ", a);
                for (int i = sizeof(a) * 8 - 1; i >= 0; i--) {
                    printf("%d", (a >> i) & 1);
                }
                printf("\n");
                printf("b = %d: ", b);
                for (int i = sizeof(b) * 8 - 1; i >= 0; i--) {
                    printf("%d", (b >> i) & 1);
                }
                printf("\n");
                break;
            case 8:
                printf("Exiting the program.\n");
                return; // Exit the loop and the function
            default:
                printf("Invalid choice! Please choose between 1 and 8.\n");
        }
        printf("\n");
    }
}
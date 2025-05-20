//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include <stdio.h>

void displayMenu() {
    printf("Bitwise Operations Menu:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("7. Exit\n");
}

int main() {
    int choice;
    unsigned int num1, num2;
    unsigned int result;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1: // Bitwise AND
                printf("Enter two numbers (num1 num2): ");
                scanf("%u %u", &num1, &num2);
                result = num1 & num2;
                printf("Result of %u AND %u is: %u\n", num1, num2, result);
                break;

            case 2: // Bitwise OR
                printf("Enter two numbers (num1 num2): ");
                scanf("%u %u", &num1, &num2);
                result = num1 | num2;
                printf("Result of %u OR %u is: %u\n", num1, num2, result);
                break;

            case 3: // Bitwise XOR
                printf("Enter two numbers (num1 num2): ");
                scanf("%u %u", &num1, &num2);
                result = num1 ^ num2;
                printf("Result of %u XOR %u is: %u\n", num1, num2, result);
                break;

            case 4: // Bitwise NOT
                printf("Enter a number: ");
                scanf("%u", &num1);
                result = ~num1;
                printf("Result of NOT %u is: %u\n", num1, result);
                break;

            case 5: // Left Shift
                printf("Enter a number and number of positions to shift left (num positions): ");
                scanf("%u %u", &num1, &num2);
                result = num1 << num2;
                printf("Result of %u left shifted by %u is: %u\n", num1, num2, result);
                break;

            case 6: // Right Shift
                printf("Enter a number and number of positions to shift right (num positions): ");
                scanf("%u %u", &num1, &num2);
                result = num1 >> num2;
                printf("Result of %u right shifted by %u is: %u\n", num1, num2, result);
                break;

            default:
                printf("Invalid choice. Please select a valid operation.\n");
        }
        printf("\n"); // Add a newline for better readability between operations.
    }

    return 0;
}
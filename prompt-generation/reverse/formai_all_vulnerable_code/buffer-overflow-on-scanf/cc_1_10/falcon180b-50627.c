//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void bitwise_operations();

int main() {
    bitwise_operations();
    return 0;
}

// Function to perform bitwise operations
void bitwise_operations() {
    int num1, num2, result;
    char choice;

    // Loop until the user chooses to exit
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. AND operation\n");
        printf("2. OR operation\n");
        printf("3. XOR operation\n");
        printf("4. NOT operation\n");
        printf("5. Left shift operation\n");
        printf("6. Right shift operation\n");
        printf("7. Exit\n");
        scanf("%c", &choice);

        // Perform bitwise operation based on user's choice
        switch (choice) {
            case '1':
                printf("Enter two numbers:\n");
                scanf("%d %d", &num1, &num2);
                result = num1 & num2;
                printf("Result: %d\n", result);
                break;
            case '2':
                printf("Enter two numbers:\n");
                scanf("%d %d", &num1, &num2);
                result = num1 | num2;
                printf("Result: %d\n", result);
                break;
            case '3':
                printf("Enter two numbers:\n");
                scanf("%d %d", &num1, &num2);
                result = num1 ^ num2;
                printf("Result: %d\n", result);
                break;
            case '4':
                printf("Enter a number:\n");
                scanf("%d", &num1);
                result = ~num1;
                printf("Result: %d\n", result);
                break;
            case '5':
                printf("Enter a number and a position:\n");
                scanf("%d %d", &num1, &num2);
                result = num1 << num2;
                printf("Result: %d\n", result);
                break;
            case '6':
                printf("Enter a number and a position:\n");
                scanf("%d %d", &num1, &num2);
                result = num1 >> num2;
                printf("Result: %d\n", result);
                break;
            case '7':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
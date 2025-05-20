//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: minimalist
#include <stdio.h>

void print_menu() {
    printf("Select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exponentiation\n");
    printf("7. Exit\n");
}

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0; // Can use another form of error handling as suited
    }
    return a / b;
}

int modulus(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero in modulus!\n");
        return -1; // Use a suitable error indicator
    }
    return a % b;
}

float exponentiate(float base, int exp) {
    float result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main() {
    int choice;
    float num1, num2;
    int int_num1, int_num2;
    
    while(1) {
        print_menu();
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting the program.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                printf("Result: %.2f + %.2f = %.2f\n", num1, num2, add(num1, num2));
                break;
            
            case 2:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                printf("Result: %.2f - %.2f = %.2f\n", num1, num2, subtract(num1, num2));
                break;
            
            case 3:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                printf("Result: %.2f * %.2f = %.2f\n", num1, num2, multiply(num1, num2));
                break;
            
            case 4:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                printf("Result: %.2f / %.2f = %.2f\n", num1, num2, divide(num1, num2));
                break;

            case 5:
                printf("Enter two integers: ");
                scanf("%d %d", &int_num1, &int_num2);
                int mod_result = modulus(int_num1, int_num2);
                if (mod_result != -1) {
                    printf("Result: %d %% %d = %d\n", int_num1, int_num2, mod_result);
                }
                break;

            case 6:
                printf("Enter base and exponent: ");
                scanf("%f %d", &num1, &int_num2);
                printf("Result: %.2f ^ %d = %.2f\n", num1, int_num2, exponentiate(num1, int_num2));
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
        }
        printf("\n");
    }

    return 0;
}
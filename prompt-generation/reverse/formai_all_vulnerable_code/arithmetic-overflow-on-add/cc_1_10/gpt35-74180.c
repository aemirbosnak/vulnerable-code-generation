//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complete
#include <stdio.h>

int addition(int a, int b);
int subtraction(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);

int main() {
    int a, b, choice;
    
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    
    printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: printf("\nResult: %d", addition(a, b));
                break;
        case 2: printf("\nResult: %d", subtraction(a, b));
                break;
        case 3: printf("\nResult: %d", multiplication(a, b));
                break;
        case 4: if (b == 0) {
                    printf("\nCannot divide by zero!");
                } else {
                    printf("\nResult: %d", division(a, b));
                }
                break;
        default: printf("Invalid choice!");
    }
    
    return 0;
}

int addition(int a, int b) {
    return a + b;
}

int subtraction(int a, int b) {
    return a - b;
}

int multiplication(int a, int b) {
    return a * b;
}

int division(int a, int b) {
    return a / b;
}
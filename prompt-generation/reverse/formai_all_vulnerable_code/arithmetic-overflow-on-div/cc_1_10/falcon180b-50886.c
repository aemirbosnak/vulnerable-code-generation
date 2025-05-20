//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, c;
    int choice;

    printf("Welcome to the Arithmetic Calculator 3000!\n");
    printf("Please select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the first number: ");
            scanf("%d", &a);
            printf("Enter the second number: ");
            scanf("%d", &b);
            c = a + b;
            printf("The result is: %d\n", c);
            break;
        case 2:
            printf("Enter the first number: ");
            scanf("%d", &a);
            printf("Enter the second number: ");
            scanf("%d", &b);
            c = a - b;
            printf("The result is: %d\n", c);
            break;
        case 3:
            printf("Enter the first number: ");
            scanf("%d", &a);
            printf("Enter the second number: ");
            scanf("%d", &b);
            c = a * b;
            printf("The result is: %d\n", c);
            break;
        case 4:
            printf("Enter the first number: ");
            scanf("%d", &a);
            printf("Enter the second number: ");
            scanf("%d", &b);
            if(b == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                c = a / b;
                printf("The result is: %d\n", c);
            }
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
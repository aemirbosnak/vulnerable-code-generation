//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: recursive
#include<stdio.h>

// Function to perform addition using recursion
int add(int a, int b) {
    if(b == 0) {
        return a;
    }
    else {
        return a + add(a, b-1);
    }
}

// Function to perform subtraction using recursion
int subtract(int a, int b) {
    if(b == 0) {
        return a;
    }
    else {
        return a - subtract(a, b-1);
    }
}

// Function to perform multiplication using recursion
int multiply(int a, int b) {
    if(b == 0) {
        return 0;
    }
    else if(b == 1) {
        return a;
    }
    else {
        return a + multiply(a, b-1);
    }
}

// Function to perform division using recursion
int divide(int a, int b) {
    if(b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }
    else if(b == 1) {
        return a;
    }
    else {
        return a - divide(a, b-1);
    }
}

int main() {
    int choice, num1, num2;

    printf("Enter 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division.\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two numbers to add:\n");
            scanf("%d %d", &num1, &num2);
            printf("Result: %d\n", add(num1, num2));
            break;
        case 2:
            printf("Enter two numbers to subtract:\n");
            scanf("%d %d", &num1, &num2);
            printf("Result: %d\n", subtract(num1, num2));
            break;
        case 3:
            printf("Enter two numbers to multiply:\n");
            scanf("%d %d", &num1, &num2);
            printf("Result: %d\n", multiply(num1, num2));
            break;
        case 4:
            printf("Enter two numbers to divide:\n");
            scanf("%d %d", &num1, &num2);
            printf("Result: %d\n", divide(num1, num2));
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
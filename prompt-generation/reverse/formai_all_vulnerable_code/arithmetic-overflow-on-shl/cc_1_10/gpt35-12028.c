//FormAI DATASET v1.0 Category: Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int add(int num1, int num2) {
    if(num2 == 0) {
        return num1;
    } else {
        return add(num1 ^ num2, (num1 & num2) << 1);
    }
}

int subtract(int num1, int num2) {
    return add(num1, add(~num2, 1));
}

int multiply(int num1, int num2) {
    if(num2 == 0) {
        return 0;
    } else if(num2 > 0) {
        return add(num1, multiply(num1, subtract(num2, 1)));
    } else {
        return add(~add(num1, multiply(num1, add(~num2, 1))), 1);
    }
}

float divide(int num1, int num2) {
    return (float) num1 / num2;
}

int power(int base, int exponent) {
    if(exponent == 0) {
        return 1;
    } else {
        return multiply(base, power(base, subtract(exponent, 1)));
    }
}

int main() {
    int choice;
    do {
        printf("Choose an operation:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Power\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        if(choice >= 1 && choice <= 5) {
            int num1, num2;
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            switch(choice) {
                case 1:
                    printf("Result: %d\n", add(num1, num2));
                    break;
                case 2:
                    printf("Result: %d\n", subtract(num1, num2));
                    break;
                case 3:
                    printf("Result: %d\n", multiply(num1, num2));
                    break;
                case 4:
                    printf("Result: %f\n", divide(num1, num2));
                    break;
                case 5:
                    printf("Result: %d\n", power(num1, num2));
                    break;
            }
        } else if(choice == 6) {
            printf("Exiting Program...\n");
            exit(0);
        } else {
            printf("Invalid choice, please try again.\n");
        }
    } while(choice != 6);
    return 0;
}
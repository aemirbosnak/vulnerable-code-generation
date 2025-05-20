//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void showMenu();
void add(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);
void divide(int a, int b);
void modulus(int a, int b);
void power(int base, int exp);
void fibonacci(int n);

int main() {
    int choice;
    int number1, number2;
    int exp, n;

    printf("=== Welcome to the Magical Arithmetic Realm ===\n");
    printf("You are an apprentice wizard learning the secrets of arithmetic.\n");

    while(1){
        showMenu();
        printf("Select your spell (1-6) or 0 to Exit: ");
        scanf("%d", &choice);

        if(choice == 0) {
            printf("Farewell, young wizard! Until we meet again!\n");
            break;
        }

        switch(choice) {
            case 1:
                printf("Enter two numbers to cast the addition spell: ");
                scanf("%d %d", &number1, &number2);
                add(number1, number2);
                break;
            case 2:
                printf("Enter two numbers to cast the subtraction spell: ");
                scanf("%d %d", &number1, &number2);
                subtract(number1, number2);
                break;
            case 3:
                printf("Enter two numbers to invoke the multiplication incantation: ");
                scanf("%d %d", &number1, &number2);
                multiply(number1, number2);
                break;
            case 4:
                printf("Enter two numbers to summon the division spell: ");
                scanf("%d %d", &number1, &number2);
                divide(number1, number2);
                break;
            case 5:
                printf("Enter base and exponent for the power talisman: ");
                scanf("%d %d", &number1, &exp);
                power(number1, exp);
                break;
            case 6:
                printf("Enter a number to see Fibonacci series until that number: ");
                scanf("%d", &n);
                fibonacci(n);
                break;
            default:
                printf("Invalid choice! Please try again, brave apprentice.\n");
        }
    }
    return 0;
}

void showMenu() {
    printf("\n--- Arithmetic Menu ---\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("6. Fibonacci Series\n");
}

void add(int a, int b) {
    printf("The result of %d + %d is: %d\n", a, b, a + b);
}

void subtract(int a, int b) {
    printf("The result of %d - %d is: %d\n", a, b, a - b);
}

void multiply(int a, int b) {
    printf("The result of %d * %d is: %d\n", a, b, a * b);
}

void divide(int a, int b) {
    if (b == 0) {
        printf("Oh no! You cannot divide by zero, brave wizard!\n");
    } else {
        printf("The result of %d / %d is: %.2f\n", a, b, (float)a / b);
    }
}

void power(int base, int exp) {
    int result = 1;
    for(int i = 0; i < exp; i++) {
        result *= base;
    }
    printf("The result of %d^%d is: %d\n", base, exp, result);
}

void fibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;
    printf("Fibonacci Series: ");

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%d, ", t1);
            continue;
        }
        if (i == 2) {
            printf("%d, ", t2);
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;

        printf("%d, ", nextTerm);
    }
    printf("\n");
}
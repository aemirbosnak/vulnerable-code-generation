//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: Cryptic
#include <stdio.h>

#define MAX_NUM 20
#define MIN_NUM 1

void greet();
int random_number();
void arithmetic_operations(int num1, int num2);
void display_result(int res, char op);
void input_and_process();
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);

int main() {
    greet();
    input_and_process();
    return 0;
}

void greet() {
    printf("Welcome to the Magical Arithmetic Realm!\n");
    printf("You shall enter the numbers of your choice.\n");
    printf("Prepare for an adventure in calculations!\n\n");
}

int random_number() {
    return (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
}

void arithmetic_operations(int num1, int num2) {
    int sum = add(num1, num2);
    int diff = subtract(num1, num2);
    int prod = multiply(num1, num2);
    float quot = divide(num1, num2);

    display_result(sum, '+');
    display_result(diff, '-');
    display_result(prod, '*');
    
    if (num2 != 0) {
        display_result((int)quot, '/');
    } else {
        printf("Division by zero is a forbidden sorcery!\n");
    }
}

void display_result(int res, char op) {
    switch(op) {
        case '+': printf("The sum is: %d\n", res); break;
        case '-': printf("The difference is: %d\n", res); break;
        case '*': printf("The product is: %d\n", res); break;
        case '/': printf("The quotient is: %.2f\n", (float)res); break;
        default: printf("Unknown operation.\n"); break;
    }
}

void input_and_process() {
    int num1, num2;
    printf("Enter the first number (%d - %d): ", MIN_NUM, MAX_NUM);
    scanf("%d", &num1);
    printf("Enter the second number (%d - %d): ", MIN_NUM, MAX_NUM);
    scanf("%d", &num2);

    if (num1 < MIN_NUM || num1 > MAX_NUM || num2 < MIN_NUM || num2 > MAX_NUM) {
        printf("Numbers out of range! Choose wisely within the bound!\n");
        return;
    }

    printf("\nThe chosen numbers are: %d and %d\n", num1, num2);
    arithmetic_operations(num1, num2);
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / b;
}
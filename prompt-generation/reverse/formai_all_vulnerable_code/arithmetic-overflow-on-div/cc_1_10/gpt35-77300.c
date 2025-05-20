//FormAI DATASET v1.0 Category: Arithmetic ; Style: sophisticated
#include <stdio.h>

int add(int x, int y){
    return x + y;
}

int subtract(int x, int y){
    return x - y;
}

int multiply(int x, int y){
    return x * y;
}

int divide(int x, int y){
    if(y == 0){
        printf("Error! Division by zero.");
        return -1;
    }

    return x / y;
}

int main(){
    int num1, num2;
    char operator;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    int result;

    switch(operator){
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            printf("Error! Invalid operator.");
            return -1;
    }

    printf("The result is: %d", result);

    return 0;
}
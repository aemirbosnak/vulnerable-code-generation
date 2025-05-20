//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: light-weight
#include <stdio.h>

//Function to add two numbers
float add(float a, float b){
    return a + b;
}

//Function to subtract two numbers
float subtract(float a, float b){
    return a - b;
}

//Function to multiply two numbers
float multiply(float a, float b){
    return a * b;
}

//Function to divide two numbers
float divide(float a, float b){
    return a / b;
}

int main(){
    float num1, num2, result;
    char operator;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    switch(operator){
        case '+':
            result = add(num1, num2);
            printf("Result: %.2f\n", result);
            break;

        case '-':
            result = subtract(num1, num2);
            printf("Result: %.2f\n", result);
            break;

        case '*':
            result = multiply(num1, num2);
            printf("Result: %.2f\n", result);
            break;

        case '/':
            if(num2 == 0){
                printf("Cannot divide by zero!\n");
            }
            else{
                result = divide(num1, num2);
                printf("Result: %.2f\n", result);
            }
            break;

        default:
            printf("Invalid operator entered!\n");
            break;
    }

    return 0;
}
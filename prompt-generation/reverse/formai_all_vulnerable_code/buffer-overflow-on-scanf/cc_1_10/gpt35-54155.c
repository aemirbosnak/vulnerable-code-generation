//FormAI DATASET v1.0 Category: Text processing ; Style: mathematical
#include<stdio.h>
#include<string.h>

// Function to calculate the factorial of a number
int factorial(int num){
    if(num == 1 || num == 0)
        return 1;
    else
        return num * factorial(num - 1);
}

int main(){

    char equation[100];
    int i, j, k, len;
    int num1 = 0, num2 = 0, num3 = 0;
    int op1 = 0, op2 = 0;
    char operator1, operator2;

    // Ask user to enter the equation
    printf("Enter a mathematical equation: ");
    scanf("%s", equation);

    len = strlen(equation);

    // Splitting the equation in three parts
    for(i = 0; i < len; i++){
        if(equation[i] == '+' || equation[i] == '-'){
            operator1 = equation[i];
            for(j = 0; j < i; j++){
                num1 = num1 * 10 + (equation[j] - '0');
            }
            break;
        }
    }
    for(k = i + 1; k < len; k++){
        if(equation[k] == '+' || equation[k] == '-'){
            operator2 = equation[k];
            for(j = i + 1; j < k; j++){
                num2 = num2 * 10 + (equation[j] - '0');
            }
            break;
        }
    }
    for(j = k + 1; j < len; j++){
        num3 = num3 * 10 + (equation[j] - '0');
    }

    // Calculation of operators between the numbers
    switch(operator1){
        case '+': op1 = num1 + num2;
                  break;
        case '-': op1 = num1 - num2;
                  break;
    }

    switch(operator2){
        case '+': op2 = op1 + num3;
                  break;
        case '-': op2 = op1 - num3;
                  break;
    }

    // Calculation of factorial of the resulting number
    int result = factorial(op2);

    // Printing the result
    printf("Result: %d", result);

    return 0;
}
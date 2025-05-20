//FormAI DATASET v1.0 Category: Arithmetic ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

/*Function Prototypes*/
void clear_input_buffer();
bool is_valid_operator(char);
void print_results(int, int, char, int);

/*Main Function*/
int main()
{
    int num1, num2, result;
    char operator;

    printf("Welcome to the Simple Arithmetic Calculator\n");
    printf("Please enter the first number: ");
    scanf("%d", &num1);
    clear_input_buffer();

    printf("Please enter an operator (+, -, * or /): ");
    scanf("%c", &operator);
    clear_input_buffer();

    while(!is_valid_operator(operator))
    {
        printf("Invalid operator entered, please enter a valid operator (+, -, * or /): ");
        scanf("%c", &operator);
        clear_input_buffer();
    }

    printf("Please enter the second number: ");
    scanf("%d", &num2);
    clear_input_buffer();

    switch(operator)
    {
        case '+':
            result = num1 + num2;
            print_results(num1, num2, operator, result);
            break;
        case '-':
            result = num1 - num2;
            print_results(num1, num2, operator, result);
            break;
        case '*':
            result = num1 * num2;
            print_results(num1, num2, operator, result);
            break;
        case '/':
            if(num2 == 0)
            {
                printf("Division by zero is not allowed!\n");
                exit(0);
            }
            else
            {
                result = num1 / num2;
                print_results(num1, num2, operator, result);
                break;
            }
    }

    return 0;
}

/*Function Definitions*/
void clear_input_buffer()
{
    while(getchar() != '\n');
}

bool is_valid_operator(char op)
{
    if(op == '+' || op == '-' || op == '*' || op == '/')
        return true;
    else
        return false;
}

void print_results(int num1, int num2, char op, int result)
{
    printf("\n%d %c %d = %d\n", num1, op, num2, result);
}
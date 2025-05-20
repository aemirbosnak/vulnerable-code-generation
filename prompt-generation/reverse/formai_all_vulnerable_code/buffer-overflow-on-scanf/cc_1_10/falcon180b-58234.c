//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX_LENGTH 100

//Function to evaluate the expression
double evaluate(char* expression){
    double num1, num2, result = 0;
    char operation;
    int i = 0;
    while(expression[i]!= '\0'){
        if(isdigit(expression[i])){
            num1 = expression[i] - '0';
            while(isdigit(expression[++i])){
                num1 = num1 * 10 + (expression[i] - '0');
            }
            result += num1;
        }
        else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/'){
            operation = expression[i];
            i++;
        }
        else if(expression[i] == '('){
            i++;
            while(expression[i]!= ')'){
                i++;
            }
            i++;
        }
        else{
            printf("Invalid expression\n");
            exit(0);
        }
    }
    return result;
}

//Function to clear the buffer
void clearBuffer(char* buffer){
    int i = 0;
    while(buffer[i]!= '\0'){
        buffer[i] = '\0';
        i++;
    }
}

//Function to print the expression
void printExpression(char* expression){
    int i = 0;
    while(expression[i]!= '\0'){
        printf("%c", expression[i]);
        i++;
    }
}

int main(){
    char expression[MAX_LENGTH];
    char buffer[MAX_LENGTH];
    int i = 0;
    while(1){
        printf("Enter the expression: ");
        scanf("%[^\n]s", expression);
        if(strcmp(expression, "exit") == 0){
            exit(0);
        }
        clearBuffer(buffer);
        strcpy(buffer, expression);
        double result = evaluate(buffer);
        printf("Result: %lf\n", result);
        printExpression(buffer);
        printf("\n");
    }
}
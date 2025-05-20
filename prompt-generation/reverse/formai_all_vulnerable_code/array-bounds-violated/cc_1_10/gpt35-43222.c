//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: real-life
#include<stdio.h>
#include<math.h>

// Function to check if the given character is an operator or not
int is_operator(char op){
    if(op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        return 1;
    return 0;
}

// Function to return the precedence of given operator
int precedence(char op){
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    if(op == '^')
        return 3;
    return 0;
}

// Function to perform the calculation of given expression
double calculate(double num1, double num2, char op){
    switch(op){
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '^':
            return pow(num1, num2);
        default:
            printf("Invalid operator\n");
            return 0;
    }
}

int main(){
    char expression[1000];
    printf("Enter the expression: ");
    scanf("%[^\n]%*c", expression);
    
    int len = strlen(expression);
    char stack[len];
    int top = -1;
    double values[len];
    int val_top = -1;
    
    for(int i=0; i<len; i++){
        // If current character is a whitespace, move to next iteration
        if(expression[i] == ' ')
            continue;
        
        // If current character is a digit, extract the entire number and push it to values stack
        if(isdigit(expression[i])){
            double num = 0;
            int decimal = 0;
            while(i<len && (isdigit(expression[i]) || expression[i] == '.')){
                if(expression[i] == '.'){
                    decimal = 1;
                    i++;
                    continue;
                }
                num = num * 10 + (expression[i] - '0');
                if(decimal)
                    decimal *= 10;
                i++;
            }
            if(decimal)
                num /= decimal;
            values[++val_top] = num;
            i--;
        }
        
        // If current character is operator
        else if(is_operator(expression[i])){
            // If stack is empty or current operator has higher precedence than the operator at top of the stack
            if(top == -1 || precedence(expression[i]) > precedence(stack[top]))
                stack[++top] = expression[i];
            
            // If current operator has lower precedence than the operator at top of the stack,
            // then perform the calculation of top two values in values stack using the top operator in stack
            else{
                while(top != -1 && precedence(stack[top]) >= precedence(expression[i])){
                    double num2 = values[val_top--];
                    double num1 = values[val_top--];
                    char op = stack[top--];
                    double result = calculate(num1, num2, op);
                    values[++val_top] = result;
                }
                stack[++top] = expression[i];
            }
        }
        
        // If current character is open bracket, push it to stack
        else if(expression[i] == '('){
            stack[++top] = expression[i];
        }
        
        // If current character is closing bracket, pop operators from stack and perform the calculation
        // until open bracket is found. Also, push the result back to values stack
        else if(expression[i] == ')'){
            while(stack[top] != '('){
                double num2 = values[val_top--];
                double num1 = values[val_top--];
                char op = stack[top--];
                double result = calculate(num1, num2, op);
                values[++val_top] = result;
            }
            top--;
        }
        
        // If current character is anything else, print Invalid character and exit the program
        else{
            printf("Invalid character: %c\n", expression[i]);
            return 0;
        }
    }
    
    // If there are still some operators left in stack, perform the calculation
    while(top != -1){
        double num2 = values[val_top--];
        double num1 = values[val_top--];
        char op = stack[top--];
        double result = calculate(num1, num2, op);
        values[++val_top] = result;
    }
    
    // The final result will be in values stack at index 0
    printf("Result: %f\n", values[0]);
    
    return 0;
}
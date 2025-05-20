//FormAI DATASET v1.0 Category: Syntax parsing ; Style: complex
#include<stdio.h>

/*Structure to store the results of parsing*/
struct SyntaxTree{
    char operation; //operation symbol
    int operands[2]; //operands
};

/*Recursive function to convert infix expression to postfix expression*/
char* infixToPostfix(char* infix, char* postfix){
    char operators[5] = {'+', '-', '*', '/', '^'}; //valid operators
    int precedence[5] = {1, 1, 2, 2, 3}; //precedence of operators
    int stack[10], top = -1, i, j = 0;
    for(i = 0; infix[i] != '\0'; i++){
        if(infix[i] >= '0' && infix[i] <= '9'){ //if it is a digit
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '('){ //if it is opening parenthesis
            stack[++top] = infix[i];
        }
        else if(infix[i] == ')'){ //if it is closing parenthesis
            while(stack[top] != '('){
                postfix[j++] = stack[top--];
            }
            top--; //pop opening parenthesis
        }
        else if(infix[i] == ' '){ //if it is a space
            continue;
        }
        else{ //if it is an operator
            int p = 0;
            while(p < 5 && infix[i] != operators[p]){
                p++;
            }
            while(top >= 0 && stack[top] != '(' && precedence[p] <= precedence[stack[top]-1]){
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }
    while(top >= 0){
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    return postfix;
}

/*Recursive function to parse postfix expression*/
struct SyntaxTree parsePostfix(char* postfix, int i){
    char operators[5] = {'+', '-', '*', '/', '^'};
    int operands[2] = {0, 0}; //initialize the operands
    struct SyntaxTree node;
    if(postfix[i] == '\0'){ //if end of expression is reached
        node.operation = '\0';
        node.operands[0] = 0;
        node.operands[1] = 0;
        return node;
    }
    else if(postfix[i] >= '0' && postfix[i] <= '9'){ //if it is a digit
        node.operation = '\0';
        node.operands[0] = postfix[i] - '0';
        node.operands[1] = 0;
        return node;
    }
    else{ //if it is an operator
        int p = 0;
        while(p < 5 && postfix[i] != operators[p]){
            p++;
        }
        node.operation = operators[p];
        node.operands[0] = parsePostfix(postfix, i-2).operands[0];
        node.operands[1] = parsePostfix(postfix, i-2).operands[0];
        return node;
    }
}

int main(){
    char* infix = "2 + 3 * 4";
    char postfix[20];
    infixToPostfix(infix, postfix);
    struct SyntaxTree result = parsePostfix(postfix, strlen(postfix)-1);
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Syntax Tree: %c %d %d\n", result.operation, result.operands[0], result.operands[1]);
    return 0;
}
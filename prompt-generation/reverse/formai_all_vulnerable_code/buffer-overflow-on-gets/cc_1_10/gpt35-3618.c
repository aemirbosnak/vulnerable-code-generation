//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIZE 20
typedef enum {
    false, true
}boolean;

typedef struct{
    int top;
    double stk[MAX_SIZE];
}STACK;

void push(STACK* stack,double operand){
if(stack->top==MAX_SIZE-1){
        printf("Stack Overflow. Cannot push operand.\n");
    }
    else{
        stack->stk[++stack->top]=operand;
        printf("The operand %lf has been pushed.\n",operand);
    }
}

double pop(STACK* stack){
    if(stack->top==-1){
        printf("Stack Underflow. Cannot pop operand.\n");
        return -1.000000;
    }
    else{
        printf("The popped operand is %lf.\n",stack->stk[stack->top]);
        return stack->stk[stack->top--];
    }
}

double evaluatePostfix(char postfix[]){
    double operand1,operand2,result;
    int i=0;
    boolean isOperand;
    STACK* stack=(STACK*)malloc(sizeof(STACK));
    stack->top=-1;

    while(postfix[i]!='\0'){
        isOperand=true;
        if(postfix[i]==' ' || postfix[i]=='\t'){
        isOperand=false;
        }
        else if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='^'){
        operand2=pop(stack);
        operand1=pop(stack);
        switch(postfix[i]){
            case '+': result=operand1+operand2; break;
            case '-': result=operand1-operand2; break;
            case '*': result=operand1*operand2; break;
            case '/': result=operand1/operand2; break;
            case '^': result=pow(operand1,operand2); break;
            default: break;
        }
        push(stack,result);
        }
    else{
            double num=0;
            while(postfix[i]>='0'&&postfix[i]<='9'){
                num=num*10+(double)(postfix[i]-'0');
                ++i;
            }
            if(postfix[i]=='.'){
                ++i;
                double dec=1;
                while(postfix[i]>='0'&&postfix[i]<='9'){
                    dec=dec/10;
                    num=num+(double)(postfix[i]-'0')*dec;
                    ++i;
                }
            }
            push(stack,num);
        }
        ++i;
    }
    result=pop(stack);
    if(stack->top!=-1){
    printf("Error: Multiple operands left in stack.");
    }

    return result;
}

int main(){
    char postfix[MAX_SIZE];

    printf("Enter the Postfix Expression: ");
    gets(postfix);

    printf("\nThe result of evaluation of the postfix expression is %lf.",evaluatePostfix(postfix));

    return 0;
}
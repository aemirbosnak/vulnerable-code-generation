//FormAI DATASET v1.0 Category: Syntax parsing ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure holding information about a variable
struct variable{
    char name[50];
    int val;
};

int parseExp(char* exp);

int main(){

    char exp[100];
    printf("Enter C expression to parse: ");
    scanf("%[^\n]", exp);

    int res = parseExp(exp);

    printf("Result: %d\n", res);

    return 0;
}

int parseExp(char* exp){
    int val = 0;
    char op = '+';

    // Stack to keep track of signs
    char* stack = (char*) malloc(sizeof(char)*strlen(exp)+1);

    int top = -1;  // Stack pointer initialization

    // Array to maintain variables, maximum 100 variables
    struct variable varList[100];
    int varIndex = 0;

    // Traverse through the expression
    for(int i=0; i<strlen(exp); i++){
        if(exp[i] == '('){

            // Evaluate expression inside the bracket
            int j = i+1, bracketCount=1;
            char subExp[100];
            while(bracketCount != 0){
                subExp[j-i-1] = exp[j];
                if(exp[j] == '(')
                    bracketCount++;
                else if(exp[j] == ')')
                    bracketCount--;
                j++;
            }
            subExp[j-i-2] = '\0';
            int subVal = parseExp(subExp);

            // Update value of current expression according to previous operator
            if(op == '+')
                val += subVal;
            else if(op == '-')
                val -= subVal;
            else if(op == '*')
                val *= subVal;
            else if(op == '/')
                val /= subVal;

            i = j-1;

        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){

            // Push operator onto stack
            op = exp[i];
            *(stack + ++top) = op;

        }
        else if(isdigit(exp[i])){

            // Read digits of current number
            int j=i;
            char num[20];
            while(isdigit(exp[j])){
                num[j-i] = exp[j];
                j++;
            }
            num[j-i] = '\0';

            // Convert current number to int and update value of expression
            int numVal = atoi(num);
            if(op == '+')
                val += numVal;
            else if(op == '-')
                val -= numVal;
            else if(op == '*')
                val *= numVal;
            else if(op == '/')
                val /= numVal;

            i = j-1;

        }
        else if(isalpha(exp[i])){

            // Read variable name
            int j=i;
            char varName[50];
            while(isalpha(exp[j])){
                varName[j-i] = exp[j];
                j++;
            }
            varName[j-i] = '\0';

            // Check if variable is already in the list, if not add to list
            int varFound = 0;
            for(int k=0; k<varIndex; k++){
                if(strcmp(varList[k].name, varName) == 0){
                    if(op == '+')
                        val += varList[k].val;
                    else if(op == '-')
                        val -= varList[k].val;
                    else if(op == '*')
                        val *= varList[k].val;
                    else if(op == '/')
                        val /= varList[k].val;
                    varFound = 1;
                    break;
                }
            }
            if(!varFound){
                // Read value of variable and add to list
                printf("Enter value of variable %s: ", varName);
                int varVal;
                scanf("%d", &varVal);
                struct variable v;
                strcpy(v.name, varName);
                v.val = varVal;
                varList[varIndex++] = v;

                if(op == '+')
                    val += varVal;
                else if(op == '-')
                    val -= varVal;
                else if(op == '*')
                    val *= varVal;
                else if(op == '/')
                    val /= varVal;
            }

            i = j-1;

        }
    }

    // Pop operators from stack and apply to remaining value of expression
    while(top != -1){
        op = *(stack + top--);
        if(op == '+')
            val += parseExp(exp);
        else if(op == '-')
            val -= parseExp(exp);
        else if(op == '*')
            val *= parseExp(exp);
        else if(op == '/')
            val /= parseExp(exp);
    }

    return val;

}
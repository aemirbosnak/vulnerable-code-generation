//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM_SIZE 100
#define MAX_OPERATORS 10

char num1[MAX_NUM_SIZE];
char num2[MAX_NUM_SIZE];
char operator[MAX_OPERATORS];
char result[MAX_NUM_SIZE];
int operator_count = 0;

void push(char *stack, char c) {
    if(operator_count < MAX_OPERATORS-1) {
        strcat(stack, c);
        operator_count++;
    }
}

void pop(char *stack) {
    if(operator_count > 0) {
        operator_count--;
        strcpy(stack, "");
    }
}

void clear_stack(char *stack) {
    strcpy(stack, "");
    operator_count = 0;
}

void evaluate(char *stack) {
    if(operator_count == 1) {
        strcpy(result, stack);
    } else if(operator_count == 2) {
        int num1_val = atoi(num1);
        int num2_val = atoi(num2);
        int result_val;

        if(strcmp(operator, "+") == 0) {
            result_val = num1_val + num2_val;
        } else if(strcmp(operator, "-") == 0) {
            result_val = num1_val - num2_val;
        } else if(strcmp(operator, "*") == 0) {
            result_val = num1_val * num2_val;
        } else if(strcmp(operator, "/") == 0) {
            result_val = num1_val / num2_val;
        } else {
            printf("Invalid operator!\n");
            return;
        }

        sprintf(result, "%d", result_val);
    } else {
        printf("Invalid expression!\n");
    }
}

int main() {
    printf("Enter the first number: ");
    scanf("%s", num1);
    printf("Enter the second number: ");
    scanf("%s", num2);
    printf("Enter the operator (+, -, *, /): ");
    scanf("%s", operator);

    if(strcmp(operator, "+") == 0 || strcmp(operator, "-") == 0 || strcmp(operator, "*") == 0 || strcmp(operator, "/") == 0) {
        evaluate(operator);
        printf("Result: %s\n", result);
    } else {
        printf("Invalid operator!\n");
    }

    return 0;
}
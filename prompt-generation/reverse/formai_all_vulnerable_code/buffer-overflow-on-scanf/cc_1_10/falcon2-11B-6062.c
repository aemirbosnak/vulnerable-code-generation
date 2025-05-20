//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char operator;
    int value1;
    int value2;
    int operator_priority;
    int precedence;
} Operation;

typedef struct {
    Operation op1;
    Operation op2;
    Operation op3;
    Operation op4;
    Operation op5;
    Operation op6;
    Operation op7;
    Operation op8;
} Calculation;

Calculation calculate(char op1, char op2, char op3, char op4, char op5, char op6, char op7, char op8) {
    Calculation calculation;

    calculation.op1.operator = op1;
    calculation.op2.operator = op2;
    calculation.op3.operator = op3;
    calculation.op4.operator = op4;
    calculation.op5.operator = op5;
    calculation.op6.operator = op6;
    calculation.op7.operator = op7;
    calculation.op8.operator = op8;

    calculation.op1.value1 = 0;
    calculation.op2.value1 = 0;
    calculation.op3.value1 = 0;
    calculation.op4.value1 = 0;
    calculation.op5.value1 = 0;
    calculation.op6.value1 = 0;
    calculation.op7.value1 = 0;
    calculation.op8.value1 = 0;

    calculation.op1.value2 = 0;
    calculation.op2.value2 = 0;
    calculation.op3.value2 = 0;
    calculation.op4.value2 = 0;
    calculation.op5.value2 = 0;
    calculation.op6.value2 = 0;
    calculation.op7.value2 = 0;
    calculation.op8.value2 = 0;

    calculation.op1.operator_priority = 1;
    calculation.op2.operator_priority = 1;
    calculation.op3.operator_priority = 1;
    calculation.op4.operator_priority = 1;
    calculation.op5.operator_priority = 1;
    calculation.op6.operator_priority = 1;
    calculation.op7.operator_priority = 1;
    calculation.op8.operator_priority = 1;

    calculation.op1.precedence = 0;
    calculation.op2.precedence = 0;
    calculation.op3.precedence = 0;
    calculation.op4.precedence = 0;
    calculation.op5.precedence = 0;
    calculation.op6.precedence = 0;
    calculation.op7.precedence = 0;
    calculation.op8.precedence = 0;

    return calculation;
}

void display(Calculation calculation) {
    printf("Operator 1: %c, Operator 2: %c, Operator 3: %c, Operator 4: %c, Operator 5: %c, Operator 6: %c, Operator 7: %c, Operator 8: %c\n", calculation.op1.operator, calculation.op2.operator, calculation.op3.operator, calculation.op4.operator, calculation.op5.operator, calculation.op6.operator, calculation.op7.operator, calculation.op8.operator);
}

int main() {
    char op1, op2, op3, op4, op5, op6, op7, op8;

    printf("Enter first operator: ");
    scanf("%c", &op1);

    printf("Enter second operator: ");
    scanf("%c", &op2);

    printf("Enter third operator: ");
    scanf("%c", &op3);

    printf("Enter fourth operator: ");
    scanf("%c", &op4);

    printf("Enter fifth operator: ");
    scanf("%c", &op5);

    printf("Enter sixth operator: ");
    scanf("%c", &op6);

    printf("Enter seventh operator: ");
    scanf("%c", &op7);

    printf("Enter eighth operator: ");
    scanf("%c", &op8);

    Calculation calculation = calculate(op1, op2, op3, op4, op5, op6, op7, op8);

    display(calculation);

    return 0;
}
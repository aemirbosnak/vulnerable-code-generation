//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_INPUT_SIZE 100
#define MAX_OPERATIONS 50

int input_size = 0;
char input[MAX_INPUT_SIZE];
char *operations[MAX_OPERATIONS];
int num_operations = 0;

void push_operation(char *op) {
    if (num_operations >= MAX_OPERATIONS) {
        printf("Error: Too many operations.\n");
        exit(1);
    }
    operations[num_operations++] = op;
}

void perform_operation() {
    char *op = operations[--num_operations];
    char *result = malloc(MAX_INPUT_SIZE);
    int len = strlen(op);
    int i = 0;
    while (i < len &&!isdigit(op[i])) {
        i++;
    }
    int num1 = atoi(input);
    int num2 = atoi(op + i);
    switch (op[0]) {
        case '+':
            sprintf(result, "%d", num1 + num2);
            break;
        case '-':
            sprintf(result, "%d", num1 - num2);
            break;
        case '*':
            sprintf(result, "%d", num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero.\n");
                exit(1);
            }
            sprintf(result, "%d", num1 / num2);
            break;
        default:
            printf("Invalid operation.\n");
            exit(1);
    }
    strcpy(input, result);
    free(result);
}

int main() {
    printf("Enter an expression (e.g. \"3 + 4\"):\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input_size = strlen(input);
    if (input_size == 0 || input[input_size - 1]!= '\n') {
        printf("Error: Invalid input.\n");
        exit(1);
    }
    input[--input_size] = '\0';
    char *token = strtok(input, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            push_operation(token);
        } else {
            perform_operation();
        }
        token = strtok(NULL, " ");
    }
    if (num_operations > 0) {
        perform_operation();
    }
    printf("Result: %s\n", input);
    return 0;
}
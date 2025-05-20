//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum number of digits in a number
#define MAX_DIGITS 100

// Define the maximum number of operations in an expression
#define MAX_OPERATIONS 100

// Define the supported operations
#define ADD '+'
#define SUBTRACT '-'
#define MULTIPLY '*'
#define DIVIDE '/'
#define MODULUS '%'
#define POWER '^'

// Define the precedence of operations
#define PRECEDENCE_ADD_SUBTRACT 1
#define PRECEDENCE_MULTIPLY_DIVIDE 2
#define PRECEDENCE_MODULUS 3
#define PRECEDENCE_POWER 4

// Define the associativity of operations
#define ASSOCIATIVITY_LEFT 1
#define ASSOCIATIVITY_RIGHT 2

// Define the data structures for the stack and the queue
typedef struct stack_node {
    char data;
    struct stack_node *next;
} stack_node;

typedef struct queue_node {
    char data;
    struct queue_node *next;
} queue_node;

// Define the stack and queue functions
void push(stack_node **head, char data) {
    stack_node *new_node = malloc(sizeof(stack_node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

char pop(stack_node **head) {
    if (*head == NULL) {
        return '\0';
    }
    char data = (*head)->data;
    stack_node *next_node = (*head)->next;
    free(*head);
    *head = next_node;
    return data;
}

void enqueue(queue_node **head, queue_node **tail, char data) {
    queue_node *new_node = malloc(sizeof(queue_node));
    new_node->data = data;
    new_node->next = NULL;
    if (*tail == NULL) {
        *head = new_node;
    } else {
        (*tail)->next = new_node;
    }
    *tail = new_node;
}

char dequeue(queue_node **head, queue_node **tail) {
    if (*head == NULL) {
        return '\0';
    }
    char data = (*head)->data;
    queue_node *next_node = (*head)->next;
    free(*head);
    *head = next_node;
    if (*head == NULL) {
        *tail = NULL;
    }
    return data;
}

// Define the function to check if an operator is left-associative
int is_left_associative(char operator) {
    return operator == ADD || operator == SUBTRACT;
}

// Define the function to get the precedence of an operator
int get_precedence(char operator) {
    switch (operator) {
        case ADD:
        case SUBTRACT:
            return PRECEDENCE_ADD_SUBTRACT;
        case MULTIPLY:
        case DIVIDE:
            return PRECEDENCE_MULTIPLY_DIVIDE;
        case MODULUS:
            return PRECEDENCE_MODULUS;
        case POWER:
            return PRECEDENCE_POWER;
        default:
            return -1;
    }
}

// Define the function to evaluate an expression
double evaluate_expression(char *expression) {
    // Create the stack and queue
    stack_node *stack = NULL;
    queue_node *head = NULL;
    queue_node *tail = NULL;

    // Tokenize the expression
    char *token = strtok(expression, " ");
    while (token != NULL) {
        // Check if the token is an operand
        if (token[0] >= '0' && token[0] <= '9') {
            // Push the operand onto the stack
            push(&stack, token[0]);
        } else {
            // Check if the token is an operator
            if (token[0] == ADD || token[0] == SUBTRACT || token[0] == MULTIPLY || token[0] == DIVIDE || token[0] == MODULUS || token[0] == POWER) {
                // Get the precedence of the operator
                int precedence = get_precedence(token[0]);

                // While the stack is not empty and the precedence of the operator on the stack is greater than or equal to the precedence of the current operator, pop the operator from the stack and push it onto the queue
                while (stack != NULL && get_precedence(stack->data) >= precedence) {
                    enqueue(&head, &tail, pop(&stack));
                }

                // Push the current operator onto the stack
                push(&stack, token[0]);
            } else {
                // The token is not an operand or an operator, so it is an invalid expression
                return NAN;
            }
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // While the stack is not empty, pop the operator from the stack and push it onto the queue
    while (stack != NULL) {
        enqueue(&head, &tail, pop(&stack));
    }

    // Evaluate the queue
    double result = 0;
    while (head != NULL) {
        char operator = dequeue(&head, &tail);

        // Check if the operator is an operand
        if (operator >= '0' && operator <= '9') {
            // Push the operand onto the stack
            push(&stack, operator);
        } else {
            // Pop the two operands from the stack
            double operand1 = pop(&stack);
            double operand2 = pop(&stack);

            // Perform the operation
            switch (operator) {
                case ADD:
                    result = operand1 + operand2;
                    break;
                case SUBTRACT:
                    result = operand1 - operand2;
                    break;
                case MULTIPLY:
                    result = operand1 * operand2;
                    break;
                case DIVIDE:
                    result = operand1 / operand2;
                    break;
                case MODULUS:
                    result = fmod(operand1, operand2);
                    break;
                case POWER:
                    result = pow(operand1, operand2);
                    break;
            }

            // Push the result onto the stack
            push(&stack, result);
        }
    }

    // Pop the result from the stack
    return pop(&stack);
}

// Define the main function
int main() {
    // Get the expression from the user
    char expression[MAX_DIGITS + MAX_OPERATIONS + 1];
    printf("Enter the expression: ");
    scanf("%s", expression);

    // Evaluate the expression
    double result = evaluate_expression(expression);

    // Print the result
    printf("The result is: %f\n", result);

    return 0;
}
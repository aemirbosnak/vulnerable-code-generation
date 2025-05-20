//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

void introduce_calculator() {
    printf("Ah, welcome to my Scientific Calculator! Your humble assistant in solving mathematical riddles.\n");
    printf("Type in your equations, and let us unveil the mysteries of numbers together.\n");
    printf("Available operations: +, -, *, /, ^ (power), sin, cos, tan, log, sqrt\n");
    printf("Type 'exit' to conclude our mathematical adventure.\n\n");
}

void evaluate_expression(char *input) {
    double result = 0.0;
    char operation[MAX_INPUT_SIZE];
    double operand1, operand2;

    if (sscanf(input, "%lf %s %lf", &operand1, operation, &operand2) == 3) {
        if (strcmp(operation, "+") == 0) {
            result = operand1 + operand2;
        } else if (strcmp(operation, "-") == 0) {
            result = operand1 - operand2;
        } else if (strcmp(operation, "*") == 0) {
            result = operand1 * operand2;
        } else if (strcmp(operation, "/") == 0) {
            if (operand2 != 0) {
                result = operand1 / operand2;
            } else {
                printf("Ah, the age-old dilemma of division by zero! A most vexing situation.\n");
                return;
            }
        } else if (strcmp(operation, "^") == 0) {
            result = pow(operand1, operand2);
        } else {
            printf("Ah! I see there lies some confusion with your desired operation. Let us try again.\n");
            return;
        }
        printf("The result of your calculation is: %.2lf\n", result);
    } else {
        char func[MAX_INPUT_SIZE];
        if (sscanf(input, "%s %lf", func, &operand1) == 2) {
            if (strcmp(func, "sin") == 0) {
                result = sin(operand1);
            } else if (strcmp(func, "cos") == 0) {
                result = cos(operand1);
            } else if (strcmp(func, "tan") == 0) {
                result = tan(operand1);
            } else if (strcmp(func, "log") == 0) {
                if (operand1 > 0) {
                    result = log(operand1);
                } else {
                    printf("Logarithm of a non-positive number is illogical! Consider a different input.\n");
                    return;
                }
            } else if (strcmp(func, "sqrt") == 0) {
                if (operand1 >= 0) {
                    result = sqrt(operand1);
                } else {
                    printf("Ah, the square root of negativity! Alas, we shall not tread that path.\n");
                    return;
                }
            } else {
                printf("I cannot fathom that operation; perhaps it lies in the realm of the unknown.\n");
                return;
            }
            printf("The result of your function is: %.2lf\n", result);
        } else {
            printf("Ah, that input eludes my understanding. Pray, reformulate it!\n");
        }
    }
}

int main() {
    char input[MAX_INPUT_SIZE];

    introduce_calculator();

    while (1) {
        printf("Please enter your equation or type 'exit': ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            input[strcspn(input, "\n")] = 0;  // Remove the newline character
            if (strcmp(input, "exit") == 0) {
                printf("Ah, 'tis a most bittersweet farewell. Until we meet again!\n");
                break;
            } else {
                evaluate_expression(input);
            }
        } else {
            printf("A mishap has occurred, but fret not; we shall press onward!\n");
        }
    }
    
    return 0;
}
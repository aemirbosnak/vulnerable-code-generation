//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void calculate(char **buffer) {
    int i, length = 0, operator = -1, result = 0, number = 0;
    char operator_stack[MAX_BUFFER_SIZE];

    for (i = 0; buffer[i] != '\0'; i++) {
        if (isdigit(buffer[i])) {
            number = number * 10 + buffer[i] - '0';
            length++;
        } else if (operator == -1) {
            operator = buffer[i];
            operator_stack[length] = operator;
            length++;
            number = 0;
        } else if (operator != -1) {
            switch (operator) {
                case '+':
                    result = number + result;
                    break;
                case '-':
                    result = number - result;
                    break;
                case '*':
                    result = number * result;
                    break;
                case '/':
                    if (number == 0) {
                        printf("Cannot divide by zero\n");
                        return;
                    }
                    result = number / result;
                    break;
            }
            number = result;
            operator = -1;
        }
    }

    if (number) {
        printf("%d\n", number);
    } else {
        printf("No result\n");
    }
}

int main() {
    char buffer[MAX_BUFFER_SIZE];

    printf("Enter your calculator expression: ");
    gets(buffer);

    calculate(buffer);

    return 0;
}
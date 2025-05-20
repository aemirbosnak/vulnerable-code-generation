//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];

void clear_buffer() {
    int i = 0;
    for (i = 0; buffer[i] != '\0'; i++) {
        buffer[i] = '\0';
    }
}

int main() {
    char operator;
    char num1[MAX_BUFFER_SIZE];
    char num2[MAX_BUFFER_SIZE];

    clear_buffer();

    printf("Enter operator (+, -, *, /, %): ");
    scanf("%c", &operator);

    clear_buffer();

    printf("Enter first number: ");
    scanf("%s", num1);

    clear_buffer();

    printf("Enter second number: ");
    scanf("%s", num2);

    double result = 0.0;
    switch (operator) {
        case '+':
            result = atof(num1) + atof(num2);
            break;
        case '-':
            result = atof(num1) - atof(num2);
            break;
        case '*':
            result = atof(num1) * atof(num2);
            break;
        case '/':
            result = atof(num1) / atof(num2);
            break;
        default:
            printf("Invalid operator.\n");
            break;
    }

    if (result != 0.0) {
        printf("The result is: %.2lf\n", result);
    }

    return 0;
}
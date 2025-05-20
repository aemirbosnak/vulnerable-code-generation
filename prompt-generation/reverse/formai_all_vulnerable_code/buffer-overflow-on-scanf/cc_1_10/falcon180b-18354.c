//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>

typedef struct {
    double num1;
    double num2;
    char operation;
} input_t;

void *calculate(void *arg) {
    input_t *data = (input_t *) arg;
    double result;

    switch (data->operation) {
        case '+':
            result = data->num1 + data->num2;
            break;
        case '-':
            result = data->num1 - data->num2;
            break;
        case '*':
            result = data->num1 * data->num2;
            break;
        case '/':
            if (data->num2 == 0) {
                printf("Error: Division by zero\n");
                exit(1);
            }
            result = data->num1 / data->num2;
            break;
        case '^':
            result = pow(data->num1, data->num2);
            break;
        default:
            printf("Error: Invalid operation\n");
            exit(1);
    }

    printf("Result: %.2f\n", result);
    pthread_exit(0);
}

int main() {
    pthread_t thread_id;
    input_t data;
    char input[20];
    int i = 0;

    while (1) {
        printf("Enter the first number: ");
        scanf("%lf", &data.num1);

        printf("Enter the second number: ");
        scanf("%lf", &data.num2);

        printf("Enter the operation (+, -, *, /, ^): ");
        scanf(" %c", &data.operation);

        pthread_create(&thread_id, NULL, calculate, (void *) &data);
        pthread_join(thread_id, NULL);

        printf("\n");
        memset(&data, 0, sizeof(data));
        memset(input, 0, sizeof(input));
        i = 0;
    }

    return 0;
}
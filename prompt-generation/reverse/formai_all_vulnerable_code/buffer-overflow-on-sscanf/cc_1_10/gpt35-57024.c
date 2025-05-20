//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

double result = 0.0;
pthread_mutex_t lock;

void *calculate(void *args) {
    char *expression = (char *) args;
    double num1, num2;
    char op;

    sscanf(expression, "%lf %c %lf", &num1, &op, &num2);

    switch(op) {
        case '+': result = num1 + num2;
                  break;

        case '-': result = num1 - num2;
                  break;

        case '*': result = num1 * num2;
                  break;

        case '/': result = num1 / num2;
                  break;

        case '^': result = pow(num1, num2);
                  break;

        case '%': result = fmod(num1, num2);
                  break;

        default:  printf("Invalid operator\n");
                  break;
    }

    pthread_exit(NULL);
}

int main() {
    char expression[100];
    pthread_t tid;
    pthread_attr_t attr;

    pthread_mutex_init(&lock, NULL);
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    printf("Enter an arithmetic expression:");
    fgets(expression, sizeof(expression), stdin);

    pthread_mutex_lock(&lock);
    pthread_create(&tid, &attr, calculate, expression);
    pthread_join(tid, NULL);
    pthread_mutex_unlock(&lock);

    printf("Result of expression: %lf\n", result);

    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&lock);
    pthread_exit(NULL);

    return 0;
}
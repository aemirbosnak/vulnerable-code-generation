//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <math.h>

typedef struct {
    double value;
    char op;
} operation_t;

sem_t sem;
operation_t op;

void *thread_func(void *arg) {
    while (1) {
        sem_wait(&sem);
        switch (op.op) {
            case '+':
                op.value += atof(arg);
                break;
            case '-':
                op.value -= atof(arg);
                break;
            case '*':
                op.value *= atof(arg);
                break;
            case '/':
                op.value /= atof(arg);
                break;
            case '^':
                op.value = pow(op.value, atof(arg));
                break;
            case 's':
                op.value = sin(op.value);
                break;
            case 'c':
                op.value = cos(op.value);
                break;
            case 't':
                op.value = tan(op.value);
                break;
            case 'l':
                op.value = log(op.value);
                break;
            case 'e':
                op.value = exp(op.value);
                break;
            case 'q':
                exit(0);
                break;
        }
        sem_post(&sem);
    }
    return NULL;
}

int main() {
    sem_init(&sem, 0, 1);
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);

    while (1) {
        char input[100];
        printf("Enter operation (q to quit): ");
        scanf("%s", input);

        sem_wait(&sem);
        op.op = input[0];
        op.value = atof(input + 1);
        sem_post(&sem);
    }

    pthread_join(thread, NULL);
    sem_destroy(&sem);
    return 0;
}
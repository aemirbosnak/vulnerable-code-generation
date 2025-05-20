//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

typedef struct {
    double a;
    double b;
    int op;
    double result;
} calc_args;

void* calc_thread(void* arg) {
    calc_args* args = (calc_args*)arg;

    switch (args->op) {
        case '+':
            args->result = args->a + args->b;
            break;
        case '-':
            args->result = args->a - args->b;
            break;
        case '*':
            args->result = args->a * args->b;
            break;
        case '/':
            args->result = args->a / args->b;
            break;
        case '^':
            args->result = pow(args->a, args->b);
            break;
        case 's':
            args->result = sin(args->a);
            break;
        case 'c':
            args->result = cos(args->a);
            break;
        case 't':
            args->result = tan(args->a);
            break;
        case 'l':
            args->result = log(args->a);
            break;
    }

    return NULL;
}

int main() {
    pthread_t threads[10];
    calc_args args[10];
    int num_args = 0;

    while (1) {
        printf("Enter an expression (a op b): ");
        scanf("%lf %c %lf", &args[num_args].a, &args[num_args].op, &args[num_args].b);

        if (args[num_args].op == 'q') {
            break;
        }

        pthread_create(&threads[num_args], NULL, calc_thread, &args[num_args]);
        num_args++;
    }

    for (int i = 0; i < num_args; i++) {
        pthread_join(threads[i], NULL);
        printf("%lf %c %lf = %lf\n", args[i].a, args[i].op, args[i].b, args[i].result);
    }

    return 0;
}
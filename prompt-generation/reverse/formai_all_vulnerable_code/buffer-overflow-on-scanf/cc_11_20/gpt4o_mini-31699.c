//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define MAX_INPUT 100
#define MAX_THREADS 10

typedef struct {
    char operation;
    double num1;
    double num2;
    double result;
} Task;

void* calculate(void* arg) {
    Task* task = (Task*)arg;
    
    switch (task->operation) {
        case '+':
            task->result = task->num1 + task->num2;
            break;
        case '-':
            task->result = task->num1 - task->num2;
            break;
        case '*':
            task->result = task->num1 * task->num2;
            break;
        case '/':
            if (task->num2 != 0) {
                task->result = task->num1 / task->num2;
            } else {
                printf("Error: Division by zero\n");
                task->result = NAN; // Not a Number
            }
            break;
        case 's': // Square root
            if (task->num1 >= 0) {
                task->result = sqrt(task->num1);
            } else {
                printf("Error: Square root of negative number\n");
                task->result = NAN;
            }
            break;
        case '^': // Power
            task->result = pow(task->num1, task->num2);
            break;
        case '%': // Modulus
            if (task->num2 != 0) {
                task->result = fmod(task->num1, task->num2);
            } else {
                printf("Error: Modulus by zero\n");
                task->result = NAN;
            }
            break;
        case 'l': // Logarithm
            if (task->num1 > 0) {
                task->result = log(task->num1);
            } else {
                printf("Error: Logarithm of non-positive number\n");
                task->result = NAN;
            }
            break;
        default:
            printf("Error: Invalid operation\n");
            task->result = NAN;
            break;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    Task tasks[MAX_THREADS];
    int threadCount = 0;

    while (1) {
        if (threadCount >= MAX_THREADS) {
            printf("Maximum number of concurrent operations reached.\n");
            break;
        }

        char operation;
        double num1, num2;

        printf("Enter operation (+, -, *, /, s for sqrt, ^ for power, %, l for log) or q to quit: ");
        scanf(" %c", &operation);
        
        if (operation == 'q') {
            break;
        }

        if (operation == 's') {
            printf("Enter number: ");
            scanf("%lf", &num1);
            tasks[threadCount].operation = operation;
            tasks[threadCount].num1 = num1;
            tasks[threadCount].num2 = 0; // Not used for sqrt
        } else {
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            tasks[threadCount].operation = operation;
            tasks[threadCount].num1 = num1;
            tasks[threadCount].num2 = num2;
        }

        pthread_create(&threads[threadCount], NULL, calculate, (void*)&tasks[threadCount]);
        threadCount++;
    }

    for (int i = 0; i < threadCount; i++) {
        pthread_join(threads[i], NULL);
        if (!isnan(tasks[i].result)) {
            if (tasks[i].operation == 's') {
                printf("Square root of %.2lf is: %.2lf\n", tasks[i].num1, tasks[i].result);
            } else if (tasks[i].operation == 'l') {
                printf("Log of %.2lf is: %.2lf\n", tasks[i].num1, tasks[i].result);
            } else {
                printf("%.2lf %c %.2lf = %.2lf\n", tasks[i].num1, tasks[i].operation, tasks[i].num2, tasks[i].result);
            }
        }
    }

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define MAX_THREADS 10

typedef struct {
    char expression[MAX_INPUT_SIZE];
    double result;
    int thread_num;
} CalculatorTask;

void* calculate(void* arg) {
    CalculatorTask* task = (CalculatorTask*)arg;
    double value1, value2;
    char operator;
    
    sscanf(task->expression, "%lf %c %lf", &value1, &operator, &value2);
    
    switch (operator) {
        case '+':
            task->result = value1 + value2;
            break;
        case '-':
            task->result = value1 - value2;
            break;
        case '*':
            task->result = value1 * value2;
            break;
        case '/':
            if (value2 != 0) {
                task->result = value1 / value2;
            } else {
                snprintf(task->expression, sizeof(task->expression), "Error: Division by zero.");
            }
            break;
        case '^':
            task->result = pow(value1, value2);
            break;
        default:
            snprintf(task->expression, sizeof(task->expression), "Error: Unknown operator.");
            break;
    }
    
    return NULL;
}

void performCalculations(CalculatorTask tasks[], int task_count) {
    pthread_t threads[MAX_THREADS];
    
    for (int i = 0; i < task_count; i++) {
        printf("Starting calculation for thread %d: %s\n", i, tasks[i].expression);
        pthread_create(&threads[i], NULL, calculate, (void*)&tasks[i]);
    }
    
    for (int i = 0; i < task_count; i++) {
        pthread_join(threads[i], NULL);
        printf("Result for thread %d: %s = %.2f\n", i, tasks[i].expression, tasks[i].result);
    }
}

int main() {
    int task_count;
    CalculatorTask tasks[MAX_THREADS];

    printf("Enter the number of calculations to perform (max %d): ", MAX_THREADS);
    scanf("%d", &task_count);
    
    if (task_count > MAX_THREADS) {
        printf("Error: Too many tasks. Please limit to %d tasks.\n", MAX_THREADS);
        return 1;
    }
    
    for (int i = 0; i < task_count; i++) {
        printf("Enter expression for task %d (e.g., 2.0 + 3.0): ", i + 1);
        getchar();  // Consume newline
        fgets(tasks[i].expression, sizeof(tasks[i].expression), stdin);
        tasks[i].expression[strcspn(tasks[i].expression, "\n")] = 0;  // Remove newline character
        tasks[i].thread_num = i;
    }
    
    performCalculations(tasks, task_count);
    
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

#define MAX_LEN 100
#define MAX_COMMANDS 10

typedef struct {
    double result;
    int isReady;
    pthread_mutex_t lock;
} Calculator;

Calculator calc;

void *calculate(void *arg) {
    char *expression = (char *)arg;
    double result = 0.0;
    char command[MAX_LEN];
    
    // Extract command and value from input
    sscanf(expression, "%s", command);
    
    // Perform computations based on command
    if (strcmp(command, "add") == 0) {
        double a, b;
        sscanf(expression + strlen(command) + 1, "%lf %lf", &a, &b);
        result = a + b;

    } else if (strcmp(command, "sub") == 0) {
        double a, b;
        sscanf(expression + strlen(command) + 1, "%lf %lf", &a, &b);
        result = a - b;

    } else if (strcmp(command, "mul") == 0) {
        double a, b;
        sscanf(expression + strlen(command) + 1, "%lf %lf", &a, &b);
        result = a * b;

    } else if (strcmp(command, "div") == 0) {
        double a, b;
        sscanf(expression + strlen(command) + 1, "%lf %lf", &a, &b);
        if (b != 0) {
            result = a / b;
        } else {
            fprintf(stderr, "Error: Division by zero.\n");
            return NULL;
        }

    } else if (strcmp(command, "sin") == 0) {
        double angle;
        sscanf(expression + strlen(command) + 1, "%lf", &angle);
        result = sin(angle);

    } else if (strcmp(command, "cos") == 0) {
        double angle;
        sscanf(expression + strlen(command) + 1, "%lf", &angle);
        result = cos(angle);
        
    } else if (strcmp(command, "tan") == 0) {
        double angle;
        sscanf(expression + strlen(command) + 1, "%lf", &angle);
        result = tan(angle);
    
    } else {
        fprintf(stderr, "Error: Unknown command.\n");
        return NULL;
    }

    // Update calculator's result
    pthread_mutex_lock(&calc.lock);
    calc.result = result;
    calc.isReady = 1;
    pthread_mutex_unlock(&calc.lock);
    
    return NULL;
}

void displayResult() {
    pthread_mutex_lock(&calc.lock);
    if (calc.isReady) {
        printf("Result: %.2f\n", calc.result);
        calc.isReady = 0;  // Reset the ready flag
    }
    pthread_mutex_unlock(&calc.lock);
}

int main() {
    pthread_t thread;
    char input[MAX_LEN];
    
    // Initialize calculator structure
    calc.result = 0.0;
    calc.isReady = 0;
    pthread_mutex_init(&calc.lock, NULL);

    printf("Asynchronous Scientific Calculator\n");
    printf("Commands: add <a> <b>, sub <a> <b>, mul <a> <b>, div <a> <b>, sin <angle>, cos <angle>, tan <angle>\n");
    printf("Type 'exit' to quit.\n");
    
    while (1) {
        printf("Enter command: ");
        fgets(input, MAX_LEN, stdin);
        input[strcspn(input, "\n")] = 0;  // Remove newline character
        
        if (strcmp(input, "exit") == 0) {
            break;
        }

        if (pthread_create(&thread, NULL, calculate, (void *)strdup(input)) != 0) {
            fprintf(stderr, "Error creating thread: %s\n", strerror(errno));
            continue;
        }
        
        // Detached thread to let it run independently
        pthread_detach(thread);

        // Display result whenever it's ready
        while (1) {
            displayResult();
            usleep(100000); // Sleep for a short duration to prevent busy waiting
            if (calc.isReady) {
                break;
            }
        }
    }
    
    pthread_mutex_destroy(&calc.lock);
    return 0;
}
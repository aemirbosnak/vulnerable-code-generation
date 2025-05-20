//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

// Define the function to be executed by the thread
double calculate(double x, double y, char op) {
    double result;
    switch (op) {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        case '^':
            result = pow(x, y);
            break;
        case 's':
            result = sin(x);
            break;
        case 'c':
            result = cos(x);
            break;
        case 't':
            result = tan(x);
            break;
        default:
            result = 0;
            break;
    }
    return result;
}

// Define the thread function
void *thread_function(void *arg) {
    // Extract the arguments from the thread argument
    double *x = (double *)arg;
    double *y = x + 1;
    char *op = (char *)y + 1;

    // Calculate the result
    double result = calculate(*x, *y, *op);

    // Print the result
    printf("Result: %f\n", result);

    return NULL;
}

int main() {
    // Get the input from the user
    double x, y;
    char op;
    printf("Enter the first number: ");
    scanf("%lf", &x);
    printf("Enter the second number: ");
    scanf("%lf", &y);
    printf("Enter the operation (+, -, *, /, ^, s, c, t): ");
    scanf(" %c", &op);

    // Create a thread to perform the calculation
    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, &x);

    // Wait for the thread to complete
    pthread_join(thread, NULL);

    return 0;
}
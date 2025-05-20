//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double result; //Global variable to hold the result of the operation

//Function prototypes for the thread functions
void *addition(void *arg);
void *subtraction(void *arg);
void *multiplication(void *arg);
void *division(void *arg);

int main() {
    int choice;
    double num1, num2;

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    printf("\nChoose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    //Initialize threads and attributes
    pthread_t t_add, t_sub, t_mul, t_div;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //Start the appropriate thread based on the user's choice
    switch(choice) {
        case 1:
            pthread_create(&t_add, &attr, addition, (void*) &num1);
            pthread_join(t_add,NULL); //Wait for the thread to finish
            break;
        case 2:
            pthread_create(&t_sub, &attr, subtraction, (void*) &num1);
            pthread_join(t_sub,NULL);
            break;
        case 3:
            pthread_create(&t_mul, &attr, subtraction, (void*) &num1);
            pthread_join(t_mul,NULL);
            break;
        case 4:
            pthread_create(&t_div, &attr, division, (void*) &num1);
            pthread_join(t_div,NULL);
            break;
        default:
            printf("Invalid choice.\n");
    }

    //Print the result
    printf("Result: %.2lf\n", result);
    return 0;
}

void *addition(void *arg) {
    double num1 = *((double*)arg);
    double num2;
    printf("Enter second number for addition: ");
    scanf("%lf", &num2);
    result = num1 + num2;
    return NULL;
}

void *subtraction(void *arg) {
    double num1 = *((double*)arg);
    double num2;
    printf("Enter second number for subtraction: ");
    scanf("%lf", &num2);
    result = num1 - num2;
    return NULL;
}

void *multiplication(void *arg) {
    double num1 = *((double*)arg);
    double num2;
    printf("Enter second number for multiplication: ");
    scanf("%lf", &num2);
    result = num1 * num2;
    return NULL;
}

void *division(void *arg) {
    double num1 = *((double*)arg);
    double num2;
    printf("Enter second number for division: ");
    scanf("%lf", &num2);
    if(num2 == 0) {
        printf("Error: Divide by zero.\n");
        exit(EXIT_FAILURE);
    }
    result = num1 / num2;
    return NULL;
}
//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to add two numbers
void* add(void* arg) {
    int* nums = (int*) arg;
    int result = nums[0] + nums[1];
    printf("The sum is: %d\n", result);
    pthread_exit(NULL);
}

// Function to subtract two numbers
void* subtract(void* arg) {
    int* nums =(int*) arg;
    int result = nums[0] - nums[1];
    printf("The difference is: %d\n", result);
    pthread_exit(NULL);
}

// Function to multiply two numbers
void* multiply(void* arg) {
    int* nums =(int*) arg;
    int result = nums[0] * nums[1];
    printf("The product is: %d\n", result);
    pthread_exit(NULL);
}

// Function to divide two numbers
void* divide(void* arg) {
    int* nums = (int*) arg;
    if(nums[1] == 0) {
        printf("Error! Division by zero.\n");
        pthread_exit(NULL);
    }
    float result = (float) nums[0] / nums[1];
    printf("The quotient is: %.2f\n", result);
    pthread_exit(NULL);
}

// Main function
int main() {
    pthread_t tid[4];
    int nums[2];
    char op;
    printf("Enter two numbers: ");
    scanf("%d %d", &nums[0], &nums[1]);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);
    switch(op) {
        case '+':
            pthread_create(&tid[0], NULL, add, nums);
            pthread_join(tid[0], NULL);
            break;
        case '-':
            pthread_create(&tid[1], NULL, subtract, nums);
            pthread_join(tid[1], NULL);
            break;
        case '*':
            pthread_create(&tid[2], NULL, multiply, nums);
            pthread_join(tid[2], NULL);
            break;
        case '/':
            pthread_create(&tid[3], NULL, divide, nums);
            pthread_join(tid[3], NULL);
            break;
        default:
            printf("Error! Invalid operator.\n");
            break;
    }
    pthread_exit(NULL);
    return 0;
}
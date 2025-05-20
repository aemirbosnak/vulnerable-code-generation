//FormAI DATASET v1.0 Category: Calculator ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

void *addition(void *arg);
void *subtraction(void *arg);
void *multiplication(void *arg);
void *division(void *arg);

int main() {
    pthread_t tid[4]; // declaring array of thread IDs
    int num1, num2;
    
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);
    printf("Performing math operations on %d and %d...\n", num1, num2);
    
    pthread_create(&(tid[0]), NULL, &addition, (void *)&num1);
    pthread_create(&(tid[1]), NULL, &subtraction, (void *)&num2);
    pthread_create(&(tid[2]), NULL, &multiplication, (void *)&num1);
    pthread_create(&(tid[3]), NULL, &division, (void *)&num2);
    
    int result[4];
    for (int i = 0; i < 4; i++) {
        pthread_join(tid[i], (void *)&result[i]); // waiting for thread to complete
    }
    
    printf("The results of the operations are:\n");
    printf("Addition: %d\n", result[0]);
    printf("Subtraction: %d\n", result[1]);
    printf("Multiplication: %d\n", result[2]);
    printf("Division: %d\n", result[3]);
    
    return 0;
}

void *addition(void *arg) {
    int num = *(int *)arg;
    int sum = num + num;
    pthread_exit((void *)sum); // returning value from thread
}

void *subtraction(void *arg) {
    int num = *(int *)arg;
    int diff = num - 10;
    pthread_exit((void *)diff);
}

void *multiplication(void *arg) {
    int num = *(int *)arg;
    int product = num * num;
    pthread_exit((void *)product);
}

void *division(void *arg) {
    int num = *(int *)arg;
    int quotient = num / 2;
    pthread_exit((void *)quotient);
}
//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *addition(void *arg);         // function prototype for addition thread
void *subtraction(void *arg);      // function prototype for subtraction thread

int main()
{
    pthread_t thread1, thread2;    // variables for the two threads
    int num1, num2;                // variables for the two numbers

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // create the addition thread
    if (pthread_create(&thread1, NULL, addition, (void *) &num1) != 0)
    {
        fprintf(stderr, "Error creating thread1\n");
        return 1;
    }

    // create the subtraction thread
    if (pthread_create(&thread2, NULL, subtraction, (void *) &num2) != 0)
    {
        fprintf(stderr, "Error creating thread2\n");
        return 1;
    }

    // wait for the threads to complete
    if (pthread_join(thread1, NULL) != 0)
    {
        fprintf(stderr, "Error joining thread1\n");
        return 1;
    }
    if (pthread_join(thread2, NULL) != 0)
    {
        fprintf(stderr, "Error joining thread2\n");
        return 1;
    }

    printf("Both threads completed successfully\n");
    return 0;
}

void *addition(void *arg)
{
    int *num = (int *) arg;         // get the number to add
    printf("Adding 10 to %d...\n", *num);
    *num += 10;                     // add 10 to the number
    printf("Result: %d\n", *num);
    pthread_exit(NULL);             // exit the thread
}

void *subtraction(void *arg)
{
    int *num = (int *) arg;         // get the number to subtract
    printf("Subtracting 5 from %d...\n", *num);
    *num -= 5;                      // subtract 5 from the number
    printf("Result: %d\n", *num);
    pthread_exit(NULL);             // exit the thread
}
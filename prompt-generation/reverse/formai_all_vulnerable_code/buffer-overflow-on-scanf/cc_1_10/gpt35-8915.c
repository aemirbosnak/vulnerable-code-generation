//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS     5     /* Define maximum threads */

/*
 * Function prototype
 */
void *print_message(void *ptr);

int main()
{
    pthread_t threads[MAX_THREADS];     /* Define threads */
    int i, num_threads;     /* Declare variables */

    printf("How many threads do you want to create? ");
    scanf("%d", &num_threads);     /* Get number of threads to create */

    if (num_threads > MAX_THREADS)
    {
        printf("Maximum number of threads exceeded. Setting number of threads to %d\n", MAX_THREADS);
        num_threads = MAX_THREADS;
    }

    /*
     * Create threads
     */
    for (i = 0; i < num_threads; i++)
    {
        pthread_create(&threads[i], NULL, print_message, (void *)i);
    }

    /*
     * Wait for threads to complete
     */
    for (i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

/*
 * Function to print message on each thread created
 */
void *print_message(void *ptr)
{
    int thread_num = (int)ptr;
    printf("Thread %d: Hello, World!\n", thread_num);
    pthread_exit(NULL);
}
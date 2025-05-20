//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 10

void *thread_function(void *arg)
{
    int tid = *(int *)arg;
    srand(time(NULL)+tid); // seed random number generator with unique tid

    printf("Thread %d: Started\n", tid);
    
    // do some work that takes variable amount of time
    int work_time = rand() % 10 + 1; // work time between 1 and 10 seconds
    printf("Thread %d: Doing work for %d seconds\n", tid, work_time);
    sleep(work_time); // simulate work using sleep

    printf("Thread %d: Finished\n", tid);

    pthread_exit(NULL); // indicate thread has finished
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int tids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) 
    {
        tids[i] = i;
        int rc = pthread_create(&threads[i], NULL, thread_function, (void *)&tids[i]);
        if (rc) // check if pthread_create failed
        {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) 
    {
        int rc = pthread_join(threads[i], NULL); // wait for thread to finish
        if (rc) // check if pthread_join failed
        {
            printf("ERROR: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    printf("Main: All threads have finished\n");

    pthread_exit(NULL);
}
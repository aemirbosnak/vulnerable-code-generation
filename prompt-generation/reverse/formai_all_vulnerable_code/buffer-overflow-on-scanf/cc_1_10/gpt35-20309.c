//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: funny
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define MIN_THREADS 2
#define MAX_THREADS 10

int sum[2] = {0, 0};
int turn = 0;

void* threadFunc(void* tid)
{
    int id = *(int*)tid;
    int localSum = 0;
    int times = rand() % 10 + 1;
    
    printf("Thread %d computing %d times\n", id, times);
    
    for(int i=0; i<times; i++)
    {
        localSum += (rand() % 100 + 1);
        usleep(rand() % 100000);
    }
    
    while(turn != id);
    sum[id%2] += localSum;
    turn = (id+1)%2;
    
    printf("Thread %d finished computing. Local sum: %d\n", id, localSum);
    printf("Thread %d updated global sum to %d\n", id, sum[id%2]);
    
    pthread_exit(NULL);
}

int main(int argc, char** argv)
{
    int numThreads;
    
    // Get number of threads as input from user
    printf("Enter number of threads (2-10): ");
    scanf("%d", &numThreads);
    numThreads = numThreads < MIN_THREADS ? MIN_THREADS : numThreads;
    numThreads = numThreads > MAX_THREADS ? MAX_THREADS : numThreads;
    
    // Create an array of thread IDs and threads
    pthread_t threads[numThreads];
    int threadIds[numThreads];
    
    // Initiate random number generator
    srand(time(NULL));
    
    // Create threads
    for(int i=0; i<numThreads; i++)
    {
        threadIds[i] = i;
        pthread_create(&threads[i], NULL, threadFunc, &threadIds[i]);
    }
    
    // Join threads
    for(int i=0; i<numThreads; i++)
    {
        pthread_join(threads[i], NULL);
    }
    
    // Display final sum
    printf("Final sum: %d\n", sum[0]+sum[1]);
    
    return 0;
}
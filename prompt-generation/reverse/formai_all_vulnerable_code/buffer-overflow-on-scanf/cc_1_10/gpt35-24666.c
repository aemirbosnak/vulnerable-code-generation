//FormAI DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *writer(void *ptr);
void *reader(void *ptr);

int graph[N][N] = { {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0} };
int counter = 0;

int main()
{
    int i;
    pthread_t threads[2];
    pthread_create(&threads[0], NULL, writer, NULL); //creates new thread for writer
    pthread_create(&threads[1], NULL, reader, NULL); //creates new thread for reader
    for (i = 0; i < 2; i++)
    {
        pthread_join(threads[i], NULL); //waits for threads to terminate
    }
    return 0;
}

void *writer(void *ptr) //function for modifying the shared resource
{
    int i, j;
    int new_graph[N][N];
    printf("Enter the new graph:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &new_graph[i][j]);
        }
    }
    pthread_mutex_lock(&mutex); //locks mutex
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            graph[i][j] = new_graph[i][j]; //modifies the shared resource
        }
    }
    printf("Graph modified!\n");
    pthread_mutex_unlock(&mutex); //unlocks mutex
    pthread_exit(0);
}

void *reader(void *ptr) //function for accessing the shared resource
{
    int i, j;
    while (counter < 5)
    {
        pthread_mutex_lock(&mutex); //locks mutex
        printf("Graph:\n");
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                printf("%d ", graph[i][j]); //accesses the shared resource
            }
            printf("\n");
        }
        printf("\n");
        pthread_mutex_unlock(&mutex); //unlocks mutex
        counter++;
        sleep(1); //sleeps for 1 second
    }
    pthread_exit(0);
}
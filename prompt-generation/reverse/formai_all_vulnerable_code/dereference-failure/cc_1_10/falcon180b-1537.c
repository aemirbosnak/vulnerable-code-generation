//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 100

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int mutex = PTHREAD_MUTEX_INITIALIZER;

void* producer(void* arg)
{
    int id = *(int*) arg;
    int i;

    for(i=0; i<10; i++)
    {
        pthread_mutex_lock(&mutex);

        while(out == in && out!= 0)
            pthread_cond_wait(&mutex, &mutex);

        buffer[in] = i;
        in = (in + 1) % BUFFER_SIZE;

        printf("Producer %d produced %d\n", id, i);

        pthread_mutex_unlock(&mutex);
        usleep(50);
    }

    return NULL;
}

void* consumer(void* arg)
{
    int id = *(int*) arg;
    int i;

    for(i=0; i<10; i++)
    {
        pthread_mutex_lock(&mutex);

        while(in == out && in!= 0)
            pthread_cond_wait(&mutex, &mutex);

        i = buffer[out];
        out = (out + 1) % BUFFER_SIZE;

        printf("Consumer %d consumed %d\n", id, i);

        pthread_mutex_unlock(&mutex);
        usleep(50);
    }

    return NULL;
}

int main()
{
    int i, res;
    pthread_t threads[MAX_THREADS];

    for(i=0; i<MAX_THREADS; i++)
    {
        res = pthread_create(&threads[i], NULL, (i%2)? producer : consumer, (void*) &i);
        if(res)
        {
            printf("Error: unable to create thread, %d\n", res);
            exit(-1);
        }
    }

    for(i=0; i<MAX_THREADS; i++)
    {
        res = pthread_join(threads[i], NULL);
        if(res)
        {
            printf("Error: unable to join thread, %d\n", res);
            exit(-1);
        }
    }

    return 0;
}
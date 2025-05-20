//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 200

int thread_count = 0;
bool prime[BUFFER_SIZE];
int buffer[BUFFER_SIZE];
int front = -1, rear = -1;
sem_t empty, full;
pthread_mutex_t mutex;

void* thread_function(void* rank) {
    long my_rank = (long) rank;
    int number;
    bool is_prime;

    while (true) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        if (front != -1 || rear != -1) {
            number = buffer[front++];
            if (front > rear) {
                front = -1;
                rear = -1;
            }
        } else {
            pthread_mutex_unlock(&mutex);
            sem_post(&empty);
            break;
        }
        pthread_mutex_unlock(&mutex);

        is_prime = true;
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            prime[number] = true;
            printf("Thread %ld found prime %d\n", my_rank, number);
        }
        sem_post(&empty);
    }

    return NULL;
}

int main(int argc, char* argv[]) {
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    for (int i = 2; i <= n; i++) {
        pthread_mutex_lock(&mutex);
        if (rear == BUFFER_SIZE - 1) { // buffer full
            pthread_mutex_unlock(&mutex);
            sem_wait(&empty);
        } else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            buffer[rear] = i;
            pthread_mutex_unlock(&mutex);
            sem_post(&full);
        }
    }

    pthread_t* thread_handles = malloc(MAX_THREADS * sizeof(pthread_t));
    for (long thread = 0; thread < MAX_THREADS; thread++) {
        pthread_create(&thread_handles[thread], NULL, thread_function, (void*) thread);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(thread_handles[i], NULL);
    }

    printf("Prime numbers: ");
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    free(thread_handles);

    return 0;
}
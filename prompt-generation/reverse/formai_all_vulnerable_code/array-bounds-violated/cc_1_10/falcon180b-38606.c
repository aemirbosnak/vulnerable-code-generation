//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1000
#define NUM_THREADS 5
#define NUM_FILES 10
#define NUM_OPS 1000

//File system structure
typedef struct {
    char name[50];
    char content[BUFFER_SIZE];
    int size;
} File;

//File system
File fs[NUM_FILES];

//Semaphores
sem_t mutex;
sem_t empty;
sem_t full;

//Threads
pthread_t threads[NUM_THREADS];

//Thread function
void *thread_func(void *arg) {
    int id = (int) arg;
    char op;

    while (1) {
        //Wait for empty space
        sem_wait(&empty);

        //Lock mutex
        sem_wait(&mutex);

        //Get operation
        op = fs[id % NUM_FILES].content[fs[id % NUM_FILES].size - 1];

        //Unlock mutex
        sem_post(&mutex);

        if (op == 'W') {
            //Write operation
            fs[id % NUM_FILES].content[fs[id % NUM_FILES].size++] = 'W';
        }
        else if (op == 'R') {
            //Read operation
            fs[id % NUM_FILES].content[fs[id % NUM_FILES].size++] = 'R';
        }
        else if (op == 'D') {
            //Delete operation
            fs[id % NUM_FILES].content[fs[id % NUM_FILES].size++] = 'D';
        }
        else if (op == 'C') {
            //Create operation
            fs[id % NUM_FILES].content[fs[id % NUM_FILES].size++] = 'C';
        }

        //Signal full
        sem_post(&full);
    }

    return NULL;
}

//Main function
int main() {
    //Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, NUM_FILES);
    sem_init(&full, 0, 0);

    //Create files
    for (int i = 0; i < NUM_FILES; i++) {
        fs[i].size = 0;
        strcpy(fs[i].content, "");
    }

    //Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) i);
    }

    //Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
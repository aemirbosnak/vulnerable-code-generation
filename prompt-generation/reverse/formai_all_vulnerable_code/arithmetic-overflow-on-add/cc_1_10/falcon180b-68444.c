//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_TRIES 1000000
#define MAX_ALIENS 100

int num_invasions = 0;
int num_aliens_seen = 0;
int num_humans_left = 1000000;

struct alien {
    int type;
    int weapon;
    int strength;
};

void* thread_func(void* arg) {
    int thread_num = *((int*) arg);
    struct alien alien;

    srand(time(NULL) + thread_num);

    for (int i = 0; i < MAX_TRIES; i++) {
        alien.type = rand() % 3;
        alien.weapon = rand() % 10;
        alien.strength = rand() % 100;

        if (alien.type == 0) {
            printf("Thread %d has encountered a peaceful alien.\n", thread_num);
        } else if (alien.type == 1) {
            printf("Thread %d has encountered a hostile alien.\n", thread_num);
            if (alien.strength > 50) {
                printf("The alien has defeated the humans!\n");
                exit(0);
            }
        } else {
            printf("Thread %d has encountered a neutral alien.\n", thread_num);
        }

        num_aliens_seen++;
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    srand(time(NULL));

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total number of aliens seen: %d\n", num_aliens_seen);

    return 0;
}
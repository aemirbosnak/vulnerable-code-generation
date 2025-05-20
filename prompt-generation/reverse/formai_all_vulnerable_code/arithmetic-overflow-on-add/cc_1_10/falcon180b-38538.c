//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_CONSPIRACIES 100

typedef struct {
    int id;
    char name[50];
    char description[200];
} conspiracy_t;

conspiracy_t conspiracies[MAX_CONSPIRACIES];
pthread_t threads[MAX_THREADS];
int num_threads = 0;

void *generate_conspiracy(void *arg) {
    int i;
    conspiracy_t *conspiracy = (conspiracy_t *) arg;

    srand(time(NULL) + conspiracy->id);

    for (i = 0; i < 3; i++) {
        conspiracy->name[i] = 'A' + rand() % 26;
    }
    conspiracy->name[i] = '\0';

    sprintf(conspiracy->description, "Conspiracy %d: %s", conspiracy->id, conspiracy->name);

    pthread_exit(0);
}

int main() {
    int i, j;

    srand(time(NULL));

    for (i = 0; i < MAX_CONSPIRACIES; i++) {
        conspiracies[i].id = i;
        pthread_create(&threads[num_threads], NULL, generate_conspiracy, (void *) &conspiracies[i]);
        num_threads++;
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < MAX_CONSPIRACIES; i++) {
        printf("Conspiracy %d: %s\n", i, conspiracies[i].description);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_PLANETS 10

typedef struct {
    int id;
    char name[20];
    int x, y;
    int visited;
} Planet;

Planet planets[MAX_PLANETS];
pthread_t threads[NUM_THREADS];

void *travel(void *arg) {
    int id = *(int *) arg;
    char name[20] = "Thread ";
    name[11] = '0' + id;

    for (int i = 0; i < MAX_PLANETS; i++) {
        if (!planets[i].visited) {
            printf("%s visited planet %s\n", name, planets[i].name);
            planets[i].visited = 1;
        }
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_PLANETS; i++) {
        planets[i].id = i;
        planets[i].visited = 0;
        sprintf(planets[i].name, "Planet %d", i);
        planets[i].x = rand() % 100;
        planets[i].y = rand() % 100;
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, travel, (void *) i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
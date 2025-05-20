//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_PLAYERS 10
#define MAX_THREADS 100
#define MAX_NODES 1000
#define MAX_EDGES 5000
#define INF 1000000

typedef struct {
    int id;
    int x, y;
    int score;
} Player;

typedef struct {
    int id;
    int x, y;
    int cost;
} Node;

typedef struct {
    int u, v;
    int cost;
} Edge;

int num_players, num_threads;
Player players[MAX_PLAYERS];
pthread_t threads[MAX_THREADS];
sem_t lock;

void *runner(void *arg) {
    int id = *(int *)arg;
    int x = rand() % 1000;
    int y = rand() % 1000;
    int score = 0;

    while (score < 100) {
        sem_wait(&lock);
        for (int i = 0; i < num_players; i++) {
            if (i!= id && players[i].x == x && players[i].y == y) {
                score += 10;
                break;
            }
        }
        sem_post(&lock);

        x = rand() % 1000;
        y = rand() % 1000;
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++) {
        printf("Enter the coordinates of player %d: ", i);
        scanf("%d %d", &players[i].x, &players[i].y);
    }

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    sem_init(&lock, 0, 1);

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, runner, &i);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
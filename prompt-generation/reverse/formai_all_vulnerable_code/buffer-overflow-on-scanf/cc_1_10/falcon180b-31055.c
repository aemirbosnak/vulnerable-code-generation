//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PLAYERS 10
#define MAX_THREADS 20

typedef struct {
    char name[20];
    int score;
    int id;
} Player;

Player players[MAX_PLAYERS];
int num_players = 0;

void* game_loop(void* arg) {
    int id = *(int*)arg;
    printf("Player %d has joined the game!\n", id);

    while(1) {
        int choice;
        printf("Player %d, choose an action:\n1. Attack\n2. Defend\n3. Quit\n", id);
        scanf("%d", &choice);

        if(choice == 1) {
            int target;
            printf("Player %d, choose a target:\n", id);
            for(int i=0; i<num_players; i++) {
                printf("%d. %s\n", i, players[i].name);
            }
            scanf("%d", &target);

            players[target].score--;
            printf("Player %d attacks Player %d! Player %d's score is now %d.\n", id, target, target, players[target].score);
        } else if(choice == 2) {
            printf("Player %d defends.\n", id);
        } else if(choice == 3) {
            printf("Player %d has left the game.\n", id);
            pthread_exit(0);
        }
    }

    return NULL;
}

int main() {
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    for(int i=0; i<num_players; i++) {
        printf("Enter the name of player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].id = i+1;
        players[i].score = 10;
    }

    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    for(int i=0; i<num_players; i++) {
        pthread_create(&threads[i], NULL, game_loop, (void*)&i);
        thread_ids[i] = i+1;
    }

    for(int i=0; i<num_players; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

#define RED     0
#define YELLOW  1
#define GREEN    2
#define ORANGE  3

#define NUM_ROADWAYS 4

enum {EAST = 0, SOUTH = 1, WEST = 2, NORTH = 3};

struct Intersection {
    int cur_roadway;
    int next_roadway;
    int light_state[NUM_ROADWAYS];
    pthread_t controller_thread;
    pthread_mutex_t lock;
    sem_t sema[NUM_ROADWAYS];
};

struct Intersection intersection;

void* controller_thread(void* arg) {
    while (true) {
        pthread_mutex_lock(&intersection.lock);
        
        intersection.next_roadway = (intersection.cur_roadway + 1) % NUM_ROADWAYS;
        
        if (intersection.light_state[intersection.cur_roadway] == RED) {
            intersection.light_state[intersection.cur_roadway] = GREEN;
            intersection.light_state[intersection.next_roadway] = YELLOW;
            sem_post(&intersection.sema[intersection.cur_roadway]);
        } else if (intersection.light_state[intersection.cur_roadway] == YELLOW) {
            intersection.light_state[intersection.cur_roadway] = RED;
            intersection.light_state[intersection.next_roadway] = GREEN;
            intersection.cur_roadway = intersection.next_roadway;
            sem_post(&intersection.sema[intersection.cur_roadway]);
        }
        
        pthread_mutex_unlock(&intersection.lock);
        
        sleep(5);
    }
    
    return NULL;
}

int main() {
    intersection.cur_roadway = EAST;
    intersection.next_roadway = SOUTH;
    
    for (int i = 0; i < NUM_ROADWAYS; i++) {
        intersection.light_state[i] = RED;
        sem_init(&intersection.sema[i], 0, 0);
    }
    pthread_mutex_init(&intersection.lock, NULL);
    
    pthread_create(&intersection.controller_thread, NULL, controller_thread, NULL);
    
    while (true) {
        int roadway;
        
        printf("Enter roadway (0-3): ");
        scanf("%d", &roadway);
        
        if (roadway < 0 || roadway >= NUM_ROADWAYS) {
            printf("Invalid roadway\n");
            continue;
        }
        
        sem_wait(&intersection.sema[roadway]);
        
        printf("Roadway %d granted access\n", roadway);
        
        sleep(2);
        
        sem_post(&intersection.sema[roadway]);
    }
    
    return 0;
}
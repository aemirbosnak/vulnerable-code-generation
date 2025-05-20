//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_FLOORS 10
#define NUM_ELEVATORS 2

typedef struct {
    int current_floor;
    int destination_floor;
    int id;
    int is_free;
} Elevator;

typedef struct {
    Elevator elevators[NUM_ELEVATORS];
    int request_floor;
    int request_id;
    pthread_mutex_t lock;
} ElevatorSystem;

void *elevator_thread(void *arg) {
    ElevatorSystem *system = (ElevatorSystem *)arg;
    
    while (1) {
        pthread_mutex_lock(&system->lock);
        
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (system->elevators[i].is_free && system->request_floor != -1) {
                system->elevators[i].is_free = 0;
                system->elevators[i].destination_floor = system->request_floor;
                printf("Elevator %d moving to floor %d.\n", system->elevators[i].id, system->request_floor);
                
                // Simulate elevator movement
                while (system->elevators[i].current_floor != system->elevators[i].destination_floor) {
                    if (system->elevators[i].current_floor < system->elevators[i].destination_floor) {
                        system->elevators[i].current_floor++;
                    } else {
                        system->elevators[i].current_floor--;
                    }
                    printf("Elevator %d at floor %d...\n", system->elevators[i].id, system->elevators[i].current_floor);
                    sleep(1);
                }
                
                printf("Elevator %d arrived at floor %d.\n", system->elevators[i].id, system->elevators[i].current_floor);
                system->elevators[i].is_free = 1;
                system->request_floor = -1;
                break;
            }
        }

        pthread_mutex_unlock(&system->lock);
        sleep(1);
    }
}

void request_elevator(ElevatorSystem *system, int floor) {
    pthread_mutex_lock(&system->lock);
    
    if (floor >= 0 && floor < MAX_FLOORS) {
        system->request_floor = floor;
        printf("Request received for elevator to floor %d.\n", floor);
    }
    
    pthread_mutex_unlock(&system->lock);
}

int main() {
    ElevatorSystem system;
    pthread_t threads[NUM_ELEVATORS];
    
    system.request_floor = -1;
    pthread_mutex_init(&system.lock, NULL);
    
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        system.elevators[i].current_floor = 0;
        system.elevators[i].is_free = 1;
        system.elevators[i].id = i + 1;
        pthread_create(&threads[i], NULL, elevator_thread, (void *)&system);
    }
    
    int request_floor;
    while (1) {
        printf("Enter the floor number to call elevator (0 to exit): ");
        scanf("%d", &request_floor);
        
        if (request_floor == 0) {
            break;
        }
        
        request_elevator(&system, request_floor);
    }

    // Cleanup
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        pthread_cancel(threads[i]);
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&system.lock);
    return 0;
}
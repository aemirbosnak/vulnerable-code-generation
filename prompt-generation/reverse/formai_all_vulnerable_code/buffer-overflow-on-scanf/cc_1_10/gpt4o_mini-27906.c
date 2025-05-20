//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_FLOORS 5
#define NUM_ELEVATORS 2

// Elevator structure
typedef struct {
    int id;
    int current_floor;
    int target_floor;
    int direction; // 1 for up, -1 for down, 0 for idle
} Elevator;

Elevator elevators[NUM_ELEVATORS];
sem_t elevator_sem;

// Function prototypes
void* elevator_operation(void* arg);
void request_elevator(int requested_floor);
void move_elevator(Elevator* elevator);
void print_status();

int main() {
    // Initialize the semaphores
    sem_init(&elevator_sem, 0, 1);

    // Initialize elevators
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].id = i + 1;
        elevators[i].current_floor = 0; // Ground floor
        elevators[i].target_floor = -1;  // No target initially
        elevators[i].direction = 0;       // Idle
    }

    // Create elevator threads
    pthread_t elevator_threads[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        pthread_create(&elevator_threads[i], NULL, elevator_operation, (void*)&elevators[i]);
    }

    // Simulation loop for requesting elevators
    while (1) {
        int requested_floor;
        printf("Enter floor number to request elevator (0-%d) or -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &requested_floor);

        if (requested_floor == -1) {
            break; // Exit simulation
        }
        
        if (requested_floor < 0 || requested_floor >= MAX_FLOORS) {
            printf("Invalid floor number. Please try again.\n");
            continue;
        }
        
        request_elevator(requested_floor);
        print_status();
    }

    // Cleanup and exit
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        pthread_cancel(elevator_threads[i]);
        pthread_join(elevator_threads[i], NULL);
    }

    sem_destroy(&elevator_sem);
    printf("Simulation ended. Goodbye!\n");
    return 0;
}

void request_elevator(int requested_floor) {
    sem_wait(&elevator_sem);
    
    // Assign closest elevator
    int closest_elevator = -1;
    int min_distance = MAX_FLOORS;
    
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        int distance = abs(elevators[i].current_floor - requested_floor);
        
        if (distance < min_distance) {
            closest_elevator = i;
            min_distance = distance;
        }
    }
    
    if (closest_elevator != -1) {
        elevators[closest_elevator].target_floor = requested_floor;
        elevators[closest_elevator].direction = (requested_floor > elevators[closest_elevator].current_floor) ? 1 : -1;
    }

    sem_post(&elevator_sem);
}

void* elevator_operation(void* arg) {
    Elevator* elevator = (Elevator*)arg;

    while (1) {
        if (elevator->target_floor != -1) {
            move_elevator(elevator);
        }
        sleep(1); // add delay to simulate movement time
    }
    return NULL;
}

void move_elevator(Elevator* elevator) {
    sem_wait(&elevator_sem);
    
    if (elevator->current_floor < elevator->target_floor) {
        printf("Elevator %d is moving up from floor %d to floor %d\n", elevator->id, elevator->current_floor, elevator->target_floor);
        elevator->current_floor++;
        if (elevator->current_floor == elevator->target_floor) {
            printf("Elevator %d arrived at floor %d\n", elevator->id, elevator->current_floor);
            elevator->target_floor = -1; // Reset the target
            elevator->direction = 0;      // Set to idle
        }
    } else if (elevator->current_floor > elevator->target_floor) {
        printf("Elevator %d is moving down from floor %d to floor %d\n", elevator->id, elevator->current_floor, elevator->target_floor);
        elevator->current_floor--;
        if (elevator->current_floor == elevator->target_floor) {
            printf("Elevator %d arrived at floor %d\n", elevator->id, elevator->current_floor);
            elevator->target_floor = -1; // Reset the target
            elevator->direction = 0;      // Set to idle
        }
    }
    
    sem_post(&elevator_sem);
}

void print_status() {
    sem_wait(&elevator_sem);
    printf("\nCurrent status of elevators:\n");
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d: Current Floor: %d, Target Floor: %d, Direction: %s\n", 
            elevators[i].id, elevators[i].current_floor, elevators[i].target_floor, 
            elevators[i].direction == 1 ? "Up" : (elevators[i].direction == -1 ? "Down" : "Idle"));
    }
    printf("\n");
    sem_post(&elevator_sem);
}
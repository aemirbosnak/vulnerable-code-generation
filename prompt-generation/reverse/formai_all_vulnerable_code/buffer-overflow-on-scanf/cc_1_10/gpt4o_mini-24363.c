//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 5

typedef struct {
    int current_floor;
    int target_floor;
    int passengers;
} Elevator;

typedef struct {
    int floor;
} Request;

Elevator elevator;
sem_t elevator_sem;
Request requests[MAX_FLOORS][ELEVATOR_CAPACITY];
int request_count[MAX_FLOORS] = {0};

void* elevator_control(void* arg);
void request_elevator(int floor, int passengers);
void print_status();

int main() {
    pthread_t elevator_thread;
    sem_init(&elevator_sem, 0, 1);
    
    elevator.current_floor = 0;
    elevator.target_floor = -1;
    elevator.passengers = 0;

    if (pthread_create(&elevator_thread, NULL, elevator_control, NULL)) {
        fprintf(stderr, "Error creating elevator thread\n");
        return 1;
    }

    while (true) {
        int floor, passengers;
        printf("Request elevator to which floor (0-%d) and how many passengers? ", MAX_FLOORS - 1);
        scanf("%d %d", &floor, &passengers);
        if (floor < 0 || floor >= MAX_FLOORS || passengers < 1 || passengers > ELEVATOR_CAPACITY) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        request_elevator(floor, passengers);
        print_status();
    }

    pthread_join(elevator_thread, NULL);
    sem_destroy(&elevator_sem);
    return 0;
}

void request_elevator(int floor, int passengers) {
    sem_wait(&elevator_sem);
    
    if (request_count[floor] < ELEVATOR_CAPACITY) {
        requests[floor][request_count[floor]].floor = floor;
        request_count[floor]++;
    } else {
        printf("Request queue full at floor %d. Please try again later.\n", floor);
    }

    sem_post(&elevator_sem);
}

void* elevator_control(void* arg) {
    while (true) {
        sem_wait(&elevator_sem);
        
        if (elevator.passengers > 0) {
            printf("Elevator is currently at floor %d with %d passengers. ", elevator.current_floor, elevator.passengers);
        }

        if (elevator.target_floor == -1) {
            for (int i = 0; i < MAX_FLOORS; i++) {
                if (request_count[i] > 0) {
                    elevator.target_floor = i;
                    elevator.passengers = request_count[i];
                    request_count[i] = 0; // Clear the requests after taking them
                    printf("Elevator going to floor %d with %d passengers.\n", elevator.target_floor, elevator.passengers);
                    break;
                }
            }
        }

        if (elevator.target_floor != -1) {
            while (elevator.current_floor != elevator.target_floor) {
                sleep(1); // Simulate travel time
                elevator.current_floor += (elevator.target_floor > elevator.current_floor) ? 1 : -1;
                printf("Elevator moving to floor %d\n", elevator.current_floor);
            }
            elevator.target_floor = -1; // Reset target after reaching
            elevator.passengers = 0; // Passengers exited elevator
        }

        sem_post(&elevator_sem);
        sleep(1); // Time before the next loop iteration
    }
}

void print_status() {
    printf("Elevator Status:\n");
    printf("Current Floor: %d\n", elevator.current_floor);
    printf("Target Floor: %d\n", elevator.target_floor);
    printf("Passengers: %d\n", elevator.passengers);
    
    for (int i = 0; i < MAX_FLOORS; i++) {
        printf("Requests at floor %d: %d\n", i, request_count[i]);
    }
}
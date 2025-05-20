//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int current_floor;
    int direction; // 1 for up, -1 for down, 0 for stationary
    int passenger_count;
    sem_t elevator_sem;
} Elevator;

typedef struct {
    int request_floor;
    int direction; // 1 for up, -1 for down
} Request;

Elevator elevator;
Request requests[MAX_FLOORS];
int request_count = 0;
pthread_mutex_t request_mutex;

void* elevator_function(void* arg);
void* request_function(void* arg);
void add_request(int floor, int direction);

int main() {
    pthread_t elevator_thread, request_thread;
    elevator.current_floor = 0;
    elevator.direction = 0;
    elevator.passenger_count = 0;
    sem_init(&elevator.elevator_sem, 0, 1);
    pthread_mutex_init(&request_mutex, NULL);

    pthread_create(&elevator_thread, NULL, elevator_function, NULL);
    pthread_create(&request_thread, NULL, request_function, NULL);

    pthread_join(elevator_thread, NULL);
    pthread_join(request_thread, NULL);

    sem_destroy(&elevator.elevator_sem);
    pthread_mutex_destroy(&request_mutex);
    return 0;
}

void* elevator_function(void* arg) {
    while (1) {
        sem_wait(&elevator.elevator_sem);
        if (elevator.passenger_count == 0 && request_count == 0) {
            elevator.direction = 0; // Stationary
        } else {
            // Process requests
            for (int i = 0; i < request_count; i++) {
                if (requests[i].direction == 1 && requests[i].request_floor > elevator.current_floor) {
                    elevator.direction = 1; // Moving up
                    break;
                } else if (requests[i].direction == -1 && requests[i].request_floor < elevator.current_floor) {
                    elevator.direction = -1; // Moving down
                    break;
                }
            }

            // Move the elevator
            if (elevator.direction != 0) {
                elevator.current_floor += elevator.direction;
                printf("Elevator is moving %s to floor %d\n", elevator.direction == 1 ? "up" : "down", elevator.current_floor);
                sleep(1); // Simulate time taken to move
                if (elevator.passenger_count < MAX_CAPACITY) {
                    elevator.passenger_count++;
                    printf("Passenger entered. Current count: %d\n", elevator.passenger_count);
                }
                // Check if any requests are satisfied
                for (int i = 0; i < request_count; i++) {
                    if (requests[i].request_floor == elevator.current_floor) {
                        printf("Elevator reached floor %d. Request satisfied!\n", elevator.current_floor);
                        elevator.passenger_count--;
                        // Remove the satisfied request
                        requests[i] = requests[--request_count];
                        i--;
                    }
                }
            }
        }
        sem_post(&elevator.elevator_sem);
        sleep(1); // Allow some time before the next action
    }
    return NULL;
}

void* request_function(void* arg) {
    int floor, direction;
    while (1) {
        printf("Enter request floor (0 to %d) and direction (1 for up, -1 for down): ", MAX_FLOORS - 1);
        scanf("%d %d", &floor, &direction);
        if (floor >= 0 && floor < MAX_FLOORS && (direction == 1 || direction == -1)) {
            add_request(floor, direction);
        } else {
            printf("Invalid input. Try again.\n");
        }
        sleep(1); // Throttle input request
    }
    return NULL;
}

void add_request(int floor, int direction) {
    pthread_mutex_lock(&request_mutex);
    if (request_count < MAX_FLOORS) {
        requests[request_count].request_floor = floor;
        requests[request_count].direction = direction;
        request_count++;
        printf("Request added: Floor %d, Direction %d\n", floor, direction);
    } else {
        printf("Request queue full!\n");
    }
    pthread_mutex_unlock(&request_mutex);
}
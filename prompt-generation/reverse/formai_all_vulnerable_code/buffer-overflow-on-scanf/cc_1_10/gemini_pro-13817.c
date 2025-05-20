//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

// Elevator states
enum elevator_state {
    IDLE,
    MOVING_UP,
    MOVING_DOWN,
};

// Elevator direction
enum elevator_direction {
    UP,
    DOWN,
};

// Elevator data structure
struct elevator {
    int current_floor;
    enum elevator_state state;
    enum elevator_direction direction;
    int num_passengers;
    sem_t mutex;
    sem_t request_up;
    sem_t request_down;
};

// Initialize elevator
void elevator_init(struct elevator *e) {
    e->current_floor = 0;
    e->state = IDLE;
    e->direction = UP;
    e->num_passengers = 0;
    sem_init(&e->mutex, 0, 1);
    sem_init(&e->request_up, 0, 0);
    sem_init(&e->request_down, 0, 0);
}

// Destroy elevator
void elevator_destroy(struct elevator *e) {
    sem_destroy(&e->mutex);
    sem_destroy(&e->request_up);
    sem_destroy(&e->request_down);
}

// Request elevator to go up
void elevator_request_up(struct elevator *e, int floor) {
    sem_wait(&e->mutex);
    if (e->state == IDLE) {
        e->state = MOVING_UP;
        e->direction = UP;
    }
    sem_post(&e->mutex);
    sem_post(&e->request_up);
}

// Request elevator to go down
void elevator_request_down(struct elevator *e, int floor) {
    sem_wait(&e->mutex);
    if (e->state == IDLE) {
        e->state = MOVING_DOWN;
        e->direction = DOWN;
    }
    sem_post(&e->mutex);
    sem_post(&e->request_down);
}

// Elevator thread function
void *elevator_thread(void *arg) {
    struct elevator *e = (struct elevator *) arg;

    while (1) {
        // Wait for a request
        if (e->direction == UP) {
            sem_wait(&e->request_up);
        } else {
            sem_wait(&e->request_down);
        }

        // Move elevator
        while (1) {
            // Check if we have reached our destination
            if (e->direction == UP && e->current_floor == 10) {
                e->state = IDLE;
                break;
            } else if (e->direction == DOWN && e->current_floor == 0) {
                e->state = IDLE;
                break;
            }

            // Move elevator one floor
            if (e->direction == UP) {
                e->current_floor++;
            } else {
                e->current_floor--;
            }

            // Check for requests at this floor
            if (e->direction == UP) {
                // Check for requests to go up
                for (int i = e->current_floor; i <= 10; i++) {
                    if (sem_trywait(&e->request_up) == 0) {
                        // Someone wants to go up
                        e->num_passengers++;
                    }
                }
            } else {
                // Check for requests to go down
                for (int i = e->current_floor; i >= 0; i--) {
                    if (sem_trywait(&e->request_down) == 0) {
                        // Someone wants to go down
                        e->num_passengers++;
                    }
                }
            }

            // Sleep for a bit to simulate elevator movement
            usleep(100000);
        }
    }

    return NULL;
}

int main() {
    // Create elevator
    struct elevator e;
    elevator_init(&e);

    // Create elevator thread
    pthread_t tid;
    pthread_create(&tid, NULL, elevator_thread, &e);

    // Wait for user input
    while (1) {
        int floor;
        printf("Enter floor number (0-10): ");
        scanf("%d", &floor);

        if (floor < 0 || floor > 10) {
            printf("Invalid floor number\n");
        } else {
            // Request elevator to go to the specified floor
            if (floor > e.current_floor) {
                elevator_request_up(&e, floor);
            } else {
                elevator_request_down(&e, floor);
            }
        }
    }

    // Destroy elevator
    elevator_destroy(&e);

    return 0;
}
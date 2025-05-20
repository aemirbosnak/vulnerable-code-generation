//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 5

typedef struct {
    int floor;
    int people;
} Request;

typedef struct {
    Request requests[MAX_FLOORS];
    int request_count;
    pthread_mutex_t lock;
} Elevator;

Elevator elevator = {.request_count = 0, .lock = PTHREAD_MUTEX_INITIALIZER};

void paranoia_alert(const char *message) {
    printf("Paranoia Alert: %s\n", message);
}

void *elevator_thread(void *arg) {
    while (true) {
        pthread_mutex_lock(&elevator.lock);
        
        if (elevator.request_count > 0) {
            for (int i = 0; i < elevator.request_count; i++) {
                Request req = elevator.requests[i];
                printf("Elevator moving to floor %d to pick up %d people.\n", req.floor, req.people);
                
                // Simulate movement delay
                sleep(1);
                printf("Elevator arrived at floor %d. Bringing %d people.\n", req.floor, req.people);
                paranoia_alert("Are there too many people in the elevator?");
                
                // Remove request from list
                for (int j = i; j < elevator.request_count - 1; j++) {
                    elevator.requests[j] = elevator.requests[j + 1];
                }
                elevator.request_count--;
                i--;
            }
        } else {
            printf("No requests. Elevator is idle. Is it just me or is this too quiet...\n");
            paranoia_alert("Do we really have no one waiting for the elevator?");
        }
        
        pthread_mutex_unlock(&elevator.lock);
        sleep(2); // Prevent busy waiting
    }
    return NULL;
}

void take_request(int floor, int people) {
    pthread_mutex_lock(&elevator.lock);
    
    if (elevator.request_count < MAX_FLOORS) {
        elevator.requests[elevator.request_count].floor = floor;
        elevator.requests[elevator.request_count].people = people;
        elevator.request_count++;
        printf("Request added: Floor %d, People %d.\n", floor, people);
        paranoia_alert("What if there are hidden requests?");
    } else {
        printf("Elevator is busy. Requests can't be added right now.\n");
        paranoia_alert("What if someone is left waiting forever?");
    }
    
    pthread_mutex_unlock(&elevator.lock);
}

int main() {
    printf("Welcome to the Paranoia Elevator Simulation!\n");
    
    pthread_t elevator_thread_id;
    pthread_create(&elevator_thread_id, NULL, elevator_thread, NULL);
    
    int floor, people;
    while (true) {
        printf("\nEnter floor number (0 to %d) to request elevator (or -1 to quit): ", MAX_FLOORS - 1);
        scanf("%d", &floor);
        if (floor == -1) {
            paranoia_alert("Exiting the simulation? Are you sure?");
            break;
        }
        if (floor < 0 || floor >= MAX_FLOORS) {
            printf("Invalid floor. Try again.\n");
            continue;
        }
        
        printf("Enter number of people (1 to %d): ", ELEVATOR_CAPACITY);
        scanf("%d", &people);
        if (people < 1 || people > ELEVATOR_CAPACITY) {
            printf("Invalid number of people. Try again.\n");
            continue;
        }
        
        take_request(floor, people);
    }
    
    pthread_cancel(elevator_thread_id);
    pthread_join(elevator_thread_id, NULL);
    printf("Simulating emergency evacuation. Everyone exit NOW!\n");
    return 0;
}
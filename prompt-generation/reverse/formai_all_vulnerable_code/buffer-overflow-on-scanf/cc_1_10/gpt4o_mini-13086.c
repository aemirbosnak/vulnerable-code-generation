//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int current_floor;
    int destination_floor;
    int passengers_count;
    pthread_mutex_t mutex;
    sem_t sem;
} Elevator;

Elevator elevator;

void* elevator_function(void* arg) {
    while (true) {
        sem_wait(&elevator.sem);
        
        pthread_mutex_lock(&elevator.mutex);
        
        if (elevator.passengers_count > 0) {
            printf("Elevator moving from Floor %d to Floor %d\n", elevator.current_floor, elevator.destination_floor);
            elevator.current_floor = elevator.destination_floor;
            printf("Elevator arrived at Floor %d\n\n", elevator.current_floor);
        }
        
        pthread_mutex_unlock(&elevator.mutex);
        sleep(1); // simulate moving time
    }
    return NULL;
}

void board_passenger(int destination) {
    pthread_mutex_lock(&elevator.mutex);
    
    if (elevator.passengers_count < MAX_CAPACITY) {
        elevator.passengers_count++;
        elevator.destination_floor = destination;
        printf("Passenger boarded. Going to Floor %d. Passengers in elevator: %d\n", destination, elevator.passengers_count);
        if (elevator.passengers_count == 1) { // First passenger wakes up the elevator
            sem_post(&elevator.sem);
        }
    } else {
        printf("Elevator full! Passenger cannot board.\n");
    }
    
    pthread_mutex_unlock(&elevator.mutex);
}

void alight_passenger() {
    pthread_mutex_lock(&elevator.mutex);
    
    if (elevator.passengers_count > 0) {
        elevator.passengers_count--;
        printf("Passenger alighted at Floor %d. Passengers left in elevator: %d\n", elevator.current_floor, elevator.passengers_count);
        if (elevator.passengers_count == 0) {
            printf("No more passengers. Elevator is idle.\n");
            // The elevator will only move when a new passenger boards
        }
    } else {
        printf("No passengers to alight.\n");
    }
    
    pthread_mutex_unlock(&elevator.mutex);
}

void print_menu() {
    printf("Elevator Simulation Menu:\n");
    printf("1. Board a passenger (Enter destination floor 0 - %d)\n", MAX_FLOORS - 1);
    printf("2. Alight a passenger\n");
    printf("3. Exit simulation\n");
    printf("Choose an option: ");
}

int main() {
    pthread_t elevator_thread;
    elevator.current_floor = 0;
    elevator.passengers_count = 0;
    
    pthread_mutex_init(&elevator.mutex, NULL);
    sem_init(&elevator.sem, 0, 0);
    
    pthread_create(&elevator_thread, NULL, elevator_function, NULL);
    
    while (true) {
        int choice, destination;
        print_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter destination floor (0 - %d): ", MAX_FLOORS - 1);
                scanf("%d", &destination);
                if (destination < 0 || destination >= MAX_FLOORS) {
                    printf("Invalid floor. Please try again.\n");
                } else {
                    board_passenger(destination);
                }
                break;
            case 2:
                alight_passenger();
                break;
            case 3:
                printf("Exiting simulation...\n");
                pthread_cancel(elevator_thread);
                pthread_join(elevator_thread, NULL);
                pthread_mutex_destroy(&elevator.mutex);
                sem_destroy(&elevator.sem);
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    
    return 0;
}
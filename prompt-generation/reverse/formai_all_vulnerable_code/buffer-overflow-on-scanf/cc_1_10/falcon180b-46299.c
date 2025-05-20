//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define the maximum time travel distance in seconds
#define MAX_DISTANCE 1000000000

// Define the time machine structure
typedef struct {
    int current_time;
    int destination_time;
    int time_left;
} TimeMachine;

// Initialize the time machine
void init_time_machine(TimeMachine* tm) {
    tm->current_time = 0;
    tm->destination_time = 0;
    tm->time_left = MAX_DISTANCE;
}

// Check if the time travel is possible
int can_travel(TimeMachine* tm) {
    if (tm->time_left <= 0) {
        printf("You cannot travel back to the future.\n");
        return 0;
    }
    if (tm->destination_time < tm->current_time) {
        printf("You cannot travel back to the past.\n");
        return 0;
    }
    return 1;
}

// Travel through time
void time_travel(TimeMachine* tm) {
    if (can_travel(tm)) {
        if (tm->destination_time < tm->current_time) {
            tm->current_time -= tm->destination_time;
        } else {
            tm->current_time += tm->destination_time;
        }
        tm->time_left -= tm->destination_time;
    }
}

// Print the current time
void print_current_time(TimeMachine* tm) {
    printf("Current Time: %d\n", tm->current_time);
}

// Print the remaining time
void print_time_left(TimeMachine* tm) {
    printf("Time Left: %d\n", tm->time_left);
}

int main() {
    TimeMachine tm;
    init_time_machine(&tm);
    int choice;
    do {
        printf("1. Time travel\n");
        printf("2. Print current time\n");
        printf("3. Print remaining time\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                int destination_time;
                printf("Enter the destination time: ");
                scanf("%d", &destination_time);
                time_travel(&tm);
                break;
            }
            case 2: {
                print_current_time(&tm);
                break;
            }
            case 3: {
                print_time_left(&tm);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    } while(1);
    return 0;
}
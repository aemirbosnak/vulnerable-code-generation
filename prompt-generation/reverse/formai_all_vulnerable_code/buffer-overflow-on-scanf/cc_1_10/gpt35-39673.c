//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/* Define the states of the traffic light */
enum state {
    RED,
    YELLOW,
    GREEN
};

/* Function to execute the traffic light state machine */
void run_traffic_light_state_machine(enum state* current_state) {
    switch(*current_state) {
        case RED:
            printf("RED: Stop!\n");
            sleep(2);
            *current_state = GREEN;
            break;
        case YELLOW:
            printf("YELLOW: Prepare to stop!\n");
            sleep(1);
            *current_state = RED;
            break;
        case GREEN:
            printf("GREEN: Go!\n");
            sleep(3);
            *current_state = YELLOW;
            break;
        default:
            printf("Invalid state!\n");
            exit(EXIT_FAILURE);
    }
}

/* Main function */
int main() {
    enum state current_state = RED;  /* Start with the red light */
    bool running = true;  /* Flag to determine when to exit the program */

    while (running) {
        /* Execute the traffic light state machine */
        run_traffic_light_state_machine(&current_state);

        /* Ask the user if they want to continue */
        char user_input;
        printf("Continue (y/n)? ");
        scanf(" %c", &user_input);
        if (user_input == 'n') {
            running = false;
            printf("Goodbye!\n");
        }
    }

    return 0;
}
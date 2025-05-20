//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>

#define COMMAND_BUFFER_SIZE 256

volatile sig_atomic_t running = 1;

void handle_exit(int sig) {
    running = 0;
}

void *drone_control(void *arg) {
    char command[COMMAND_BUFFER_SIZE];

    printf("The drone is ready for your commands, Watson.\n");
    printf("Type 'takeoff', 'land', 'fly <direction>', 'status' or 'quit' to exit.\n");

    while (running) {
        printf("\n(Drone Control) Enter command: ");
        fflush(stdout);
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strncmp(command, "takeoff", 8) == 0) {
            printf("The drone gracefully takes flight, soaring high above the streets of London.\n");
        } else if (strncmp(command, "land", 5) == 0) {
            printf("The drone descends slowly, returning to the safety of the ground.\n");
        } else if (strncmp(command, "fly ", 4) == 0) {
            char direction[COMMAND_BUFFER_SIZE];
            sscanf(command + 4, "%s", direction);
            printf("The drone swoops towards the %s, deftly navigating the skies.\n", direction);
        } else if (strncmp(command, "status", 7) == 0) {
            printf("The drone's current status: Operational, with a battery life of 75%.\n");
        } else if (strncmp(command, "quit", 5) == 0) {
            printf("Halting all operations. The drone will cease to function.\n");
            running = 0;
        } else {
            printf("A rather perplexing command, Watson. Please try again.\n");
        }
    }

    return NULL;
}

int main() {
    signal(SIGINT, handle_exit);
    
    pthread_t control_thread;

    if (pthread_create(&control_thread, NULL, drone_control, NULL) != 0) {
        fprintf(stderr, "Could not create thread for drone control.\n");
        return 1;
    }

    pthread_join(control_thread, NULL);
    printf("The evening is much quieter now without the drone's hum.\n");

    return 0;
}
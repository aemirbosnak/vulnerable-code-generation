//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_HISTORY 10

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    time_t timestamp;
} CommandHistory;

CommandHistory history[MAX_HISTORY];
int history_index = 0;

void log_command(const char* command) {
    if (history_index < MAX_HISTORY) {
        strncpy(history[history_index].command, command, MAX_COMMAND_LENGTH);
        history[history_index].timestamp = time(NULL);
        history_index++;
    } else {
        // Shift history to the left to make room for new command
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i - 1] = history[i];
        }
        strncpy(history[MAX_HISTORY - 1].command, command, MAX_COMMAND_LENGTH);
        history[MAX_HISTORY - 1].timestamp = time(NULL);
    }
}

void display_history() {
    printf("Command History:\n");
    for (int i = 0; i < history_index; i++) {
        printf("%d: %s (Executed at: %s)", i+1, history[i].command, ctime(&history[i].timestamp));
    }
}

void takeoff() {
    printf("Drone taking off...\n");
    log_command("TAKEOFF");
    usleep(2000000); // Simulate time taken to takeoff
    printf("Drone is now in the air.\n");
}

void land() {
    printf("Drone landing...\n");
    log_command("LAND");
    usleep(2000000); // Simulate time taken to land
    printf("Drone has landed.\n");
}

void move_drone(const char* direction) {
    printf("Drone moving %s...\n", direction);
    char command[MAX_COMMAND_LENGTH];
    snprintf(command, sizeof(command), "MOVE %s", direction);
    log_command(command);
    usleep(1500000); // Simulate time taken to move
    printf("Drone has moved %s.\n", direction);
}

void display_menu() {
    printf("\nDrone Control Menu:\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Move North\n");
    printf("4. Move South\n");
    printf("5. Move East\n");
    printf("6. Move West\n");
    printf("7. Display Command History\n");
    printf("8. Exit\n");
}

int main() {
    int choice;
    
    while (true) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                takeoff();
                break;
            case 2:
                land();
                break;
            case 3:
                move_drone("North");
                break;
            case 4:
                move_drone("South");
                break;
            case 5:
                move_drone("East");
                break;
            case 6:
                move_drone("West");
                break;
            case 7:
                display_history();
                break;
            case 8:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}
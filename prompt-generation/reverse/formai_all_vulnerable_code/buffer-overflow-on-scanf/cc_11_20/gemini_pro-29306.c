//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TIME_STEPS 1000
#define MAX_COMMAND_LENGTH 100

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Date;

typedef struct {
    char *command;
    int value;
} Command;

int main() {
    // Initialize the time traveler's current date.
    Date currentDate = {2023, 1, 1, 0, 0, 0};

    // Initialize the array of commands.
    Command commands[MAX_TIME_STEPS];

    // Get the number of commands from the user.
    int numCommands;
    printf("Enter the number of commands: ");
    scanf("%d", &numCommands);

    // Get the commands from the user.
    for (int i = 0; i < numCommands; i++) {
        // Allocate memory for the command.
        commands[i].command = malloc(MAX_COMMAND_LENGTH);

        // Get the command from the user.
        printf("Enter command %d: ", i + 1);
        scanf("%s", commands[i].command);

        // Get the value from the user.
        printf("Enter value %d: ", i + 1);
        scanf("%d", &commands[i].value);
    }

    // Execute the commands.
    for (int i = 0; i < numCommands; i++) {
        // Get the command.
        char *command = commands[i].command;

        // Get the value.
        int value = commands[i].value;

        // Execute the command.
        if (strcmp(command, "forward") == 0) {
            // Move forward in time.
            currentDate.year += value;
        } else if (strcmp(command, "backward") == 0) {
            // Move backward in time.
            currentDate.year -= value;
        } else if (strcmp(command, "up") == 0) {
            // Move up in time.
            currentDate.month += value;
        } else if (strcmp(command, "down") == 0) {
            // Move down in time.
            currentDate.month -= value;
        } else if (strcmp(command, "left") == 0) {
            // Move left in time.
            currentDate.day -= value;
        } else if (strcmp(command, "right") == 0) {
            // Move right in time.
            currentDate.day += value;
        } else if (strcmp(command, "hour") == 0) {
            // Move forward in time by one hour.
            currentDate.hour += value;
        } else if (strcmp(command, "minute") == 0) {
            // Move forward in time by one minute.
            currentDate.minute += value;
        } else if (strcmp(command, "second") == 0) {
            // Move forward in time by one second.
            currentDate.second += value;
        }
    }

    // Print the time traveler's final date.
    printf("The time traveler's final date is: %d-%d-%d %d:%d:%d\n", currentDate.year, currentDate.month, currentDate.day, currentDate.hour, currentDate.minute, currentDate.second);

    // Free the memory allocated for the commands.
    for (int i = 0; i < numCommands; i++) {
        free(commands[i].command);
    }

    return 0;
}
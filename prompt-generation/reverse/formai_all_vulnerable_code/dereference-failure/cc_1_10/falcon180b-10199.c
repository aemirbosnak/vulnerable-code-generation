//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

// Struct to hold command and function pointer
typedef struct {
    char *command;
    void (*function)(void);
} command_t;

// Array of commands
command_t commands[MAX_COMMANDS];

// Function prototypes
void turn_on_light(void);
void turn_off_light(void);
void set_temperature(void);
void lock_door(void);
void unlock_door(void);

int main(void) {
    // Initialize commands
    commands[0] = (command_t) {"turn on light", turn_on_light};
    commands[1] = (command_t) {"turn off light", turn_off_light};
    commands[2] = (command_t) {"set temperature", set_temperature};
    commands[3] = (command_t) {"lock door", lock_door};
    commands[4] = (command_t) {"unlock door", unlock_door};

    // Main loop
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        // Check if input is a valid command
        bool found_command = false;
        for (int i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                commands[i].function();
                found_command = true;
                break;
            }
        }

        if (!found_command) {
            printf("Invalid command.\n");
        }
    }

    return 0;
}

// Function to turn on light
void turn_on_light(void) {
    printf("Turning on light.\n");
}

// Function to turn off light
void turn_off_light(void) {
    printf("Turning off light.\n");
}

// Function to set temperature
void set_temperature(void) {
    printf("Setting temperature.\n");
}

// Function to lock door
void lock_door(void) {
    printf("Locking door.\n");
}

// Function to unlock door
void unlock_door(void) {
    printf("Unlocking door.\n");
}
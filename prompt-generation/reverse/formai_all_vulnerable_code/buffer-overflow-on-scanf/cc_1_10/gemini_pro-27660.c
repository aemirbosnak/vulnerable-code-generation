//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: retro
// Welcome to the Retro Smart Home Light Control System!

#include <stdio.h>
#include <stdlib.h>

// Our trusty light switch
typedef enum {
    OFF,
    ON
} LightState;

// Our command line interface
typedef enum {
    CMD_UNKNOWN,
    CMD_HELP,
    CMD_TOGGLE,
    CMD_STATUS,
    CMD_EXIT
} Command;

// Our light state and command buffer
LightState light_state = OFF;
char command_buffer[100];

// Our retro-tastic user interface
void print_header() {
    printf("************************************************************************\n");
    printf("*                                                                      *\n");
    printf("*  Welcome to the Retro Smart Home Light Control System!                   *\n");
    printf("*                                                                      *\n");
    printf("************************************************************************\n");
}

void print_menu() {
    printf("\nAvailable commands:\n");
    printf("  - help: Print this help message\n");
    printf("  - toggle: Toggle the light on or off\n");
    printf("  - status: Show the current light state\n");
    printf("  - exit: Exit the program\n\n");
}

// Our command parser
Command parse_command(char *input) {
    if (strcmp(input, "help") == 0) {
        return CMD_HELP;
    } else if (strcmp(input, "toggle") == 0) {
        return CMD_TOGGLE;
    } else if (strcmp(input, "status") == 0) {
        return CMD_STATUS;
    } else if (strcmp(input, "exit") == 0) {
        return CMD_EXIT;
    } else {
        return CMD_UNKNOWN;
    }
}

// Our light controller
void toggle_light() {
    light_state = (light_state == OFF) ? ON : OFF;
}

// Our main loop
int main(void) {
    print_header();
    print_menu();

    while (1) {
        printf("\nEnter a command: ");
        scanf("%s", command_buffer);

        Command command = parse_command(command_buffer);

        switch (command) {
            case CMD_HELP:
                print_menu();
                break;
            case CMD_TOGGLE:
                toggle_light();
                break;
            case CMD_STATUS:
                printf("Light state: %s\n", (light_state == ON) ? "ON" : "OFF");
                break;
            case CMD_EXIT:
                printf("Exiting the program. Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid command. Please try again.\n");
                break;
        }
    }

    return EXIT_SUCCESS;
}
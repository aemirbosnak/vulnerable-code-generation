//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10

typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void turn_on_lights(void) {
    printf("The lights have been turned on.\n");
}

void turn_off_lights(void) {
    printf("The lights have been turned off.\n");
}

void open_door(void) {
    printf("The door has been opened.\n");
}

void close_door(void) {
    printf("The door has been closed.\n");
}

void start_fire(void) {
    printf("The fire has been started.\n");
}

void cook_meal(void) {
    printf("The meal has been cooked.\n");
}

void wash_dishes(void) {
    printf("The dishes have been washed.\n");
}

void play_music(void) {
    printf("The music has started playing.\n");
}

void stop_music(void) {
    printf("The music has been stopped.\n");
}

int main(int argc, char *argv[]) {
    command_t commands[MAX_COMMANDS] = {
        {"turn on lights", turn_on_lights},
        {"turn off lights", turn_off_lights},
        {"open door", open_door},
        {"close door", close_door},
        {"start fire", start_fire},
        {"cook meal", cook_meal},
        {"wash dishes", wash_dishes},
        {"play music", play_music},
        {"stop music", stop_music}
    };

    int num_commands = sizeof(commands) / sizeof(command_t);

    printf("Welcome to the Smart Home Automation System!\n\n");

    while (1) {
        printf("Enter a command:\n");
        char input[100];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        for (int i = 0; i < num_commands; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                commands[i].function();
            }
        }

        if (strcmp(input, "exit") == 0) {
            break;
        }
    }

    return 0;
}
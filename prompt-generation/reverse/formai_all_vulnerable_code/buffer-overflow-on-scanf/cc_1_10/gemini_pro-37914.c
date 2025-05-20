//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our cheerful home automation assistant
typedef struct {
    char *name;
    int (*action)(void);
} Assistant;

// Assistant actions
int turn_on_lights(void) {
    printf("Lights on! :)\n");
    return 0;
}

int turn_off_lights(void) {
    printf("Lights off! :(\n");
    return 0;
}

int set_temperature(int temp) {
    printf("Setting temperature to %d°C. Enjoy! :D\n", temp);
    return 0;
}

int play_music(void) {
    printf("Playing your favorite tunes! :D\n");
    return 0;
}

// Our cheerful assistant's database
Assistant assistants[] = {
    {"Lights", turn_on_lights},
    {"Lights", turn_off_lights},
    {"Temperature", set_temperature},
    {"Music", play_music},
};

int main(void) {
    // Welcome message
    printf("Welcome to your cheerful smart home! :)\n");

    // Get user input
    char input[100];
    printf("What would you like me to do today? ");
    scanf("%s", input);

    // Find the matching assistant and execute the action
    int i;
    int found = 0;
    for (i = 0; i < sizeof(assistants) / sizeof(Assistant); i++) {
        if (strcmp(input, assistants[i].name) == 0) {
            assistants[i].action();
            found = 1;
            break;
        }
    }

    // If no matching assistant is found, give a cheerful error message
    if (!found) {
        printf("Sorry, I couldn't find anything that matches your request. :(\n");
    }

    return 0;
}
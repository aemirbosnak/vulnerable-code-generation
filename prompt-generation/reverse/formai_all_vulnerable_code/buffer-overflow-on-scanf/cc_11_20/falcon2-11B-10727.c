//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 4
#define MAX_COMMANDS 16

struct light_info {
    int id;
    char name[16];
    int on;
    int brightness;
};

struct command {
    int id;
    char name[16];
};

int main() {
    struct light_info lights[MAX_LIGHTS] = {
        {1, "Living room", 1, 50},
        {2, "Bedroom", 0, 30},
        {3, "Kitchen", 1, 100},
        {4, "Bathroom", 0, 0},
    };

    struct command commands[MAX_COMMANDS] = {
        {"Turn on living room light", 1},
        {"Turn off living room light", 2},
        {"Turn on bedroom light", 3},
        {"Turn off bedroom light", 4},
        {"Turn on kitchen light", 5},
        {"Turn off kitchen light", 6},
        {"Turn on bathroom light", 7},
        {"Turn off bathroom light", 8},
        {"Brighten living room light", 9},
        {"Dim living room light", 10},
        {"Brighten bedroom light", 11},
        {"Dim bedroom light", 12},
        {"Brighten kitchen light", 13},
        {"Dim kitchen light", 14},
        {"Brighten bathroom light", 15},
        {"Dim bathroom light", 16},
    };

    int light_id = 0;
    int command_id = 0;
    char command[MAX_COMMANDS][16];

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Turn on/off a light\n");
        printf("2. Change the brightness of a light\n");
        printf("3. List all lights\n");
        printf("4. List all commands\n");
        printf("5. Exit\n");

        scanf("%d", &command_id);

        switch (command_id) {
            case 1:
                printf("Which light?\n");
                scanf("%d", &light_id);
                printf("What would you like to do with %s?\n", lights[light_id].name);
                scanf("%d", &command_id);

                switch (command_id) {
                    case 1:
                        printf("Turning on %s...\n", lights[light_id].name);
                        lights[light_id].on = 1;
                        break;
                    case 2:
                        printf("Turning off %s...\n", lights[light_id].name);
                        lights[light_id].on = 0;
                        break;
                }
                break;
            case 2:
                printf("Which light?\n");
                scanf("%d", &light_id);
                printf("How bright would you like %s to be?\n", lights[light_id].name);
                scanf("%d", &lights[light_id].brightness);
                break;
            case 3:
                printf("Here is a list of all lights:\n");
                for (int i = 0; i < MAX_LIGHTS; i++) {
                    printf("%d - %s - %d - %d\n", i, lights[i].name, lights[i].on, lights[i].brightness);
                }
                break;
            case 4:
                printf("Here is a list of all commands:\n");
                for (int i = 0; i < MAX_COMMANDS; i++) {
                    printf("%d - %s\n", i, commands[i].name);
                }
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid input!\n");
        }
    }
}
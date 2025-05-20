#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef enum { OFF, ON } state_t;

state_t lights[MAX_LIGHTS];

void init_lights() {
    for (size_t i = 0; i < MAX_LIGHTS; ++i) {
        lights[i] = OFF;
    }
}

void usage() {
    printf("Usage: light <command> <light_number> [on|off]\n");
}

int main(int argc, char *argv[]) {
    init_lights();

    if (argc != 4) {
        usage();
        return 1;
    }

    char command[10];
    char light_str[11];
    int light_num;
    state_t state;

    strncpy(command, argv[1], 9);
    command[9] = '\0';

    strncpy(light_str, argv[2], 10);
    light_str[10] = '\0';

    if (sscanf(light_str, "%d", &light_num) != 1 || light_num < 1 || light_num > MAX_LIGHTS) {
        printf("Invalid light number.\n");
        usage();
        return 1;
    }

    if (strcmp(command, "on") == 0) {
        lights[light_num - 1] = ON;
    } else if (strcmp(command, "off") == 0) {
        lights[light_num - 1] = OFF;
    } else {
        printf("Invalid command.\n");
        usage();
        return 1;
    }

    printf("Light %d is now %s.\n", light_num, lights[light_num - 1] ? "on" : "off");

    return 0;
}

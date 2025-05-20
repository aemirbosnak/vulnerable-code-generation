//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LEN 100
#define MAX_LIGHTS 10

typedef struct {
    char name[20];
    int level;
} Light;

Light lights[MAX_LIGHTS];
int num_lights = 0;

void add_light(char* name) {
    if (num_lights >= MAX_LIGHTS) {
        printf("Error: Maximum number of lights reached.\n");
        return;
    }

    strcpy(lights[num_lights].name, name);
    lights[num_lights].level = 0;

    num_lights++;
}

void set_light_level(char* name, int level) {
    int i;
    for (i = 0; i < num_lights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].level = level;
            break;
        }
    }
}

void turn_on_light(char* name) {
    int i;
    for (i = 0; i < num_lights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].level = 1;
            break;
        }
    }
}

void turn_off_light(char* name) {
    int i;
    for (i = 0; i < num_lights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].level = 0;
            break;
        }
    }
}

void print_light_status(char* name) {
    int i;
    for (i = 0; i < num_lights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            if (lights[i].level == 1) {
                printf("Light %s is on.\n", name);
            } else {
                printf("Light %s is off.\n", name);
            }
            break;
        }
    }
}

int main() {
    char command[MAX_COMMAND_LEN];
    while (1) {
        printf("Enter command (add_light light_name, set_light_level light_name level, turn_on_light light_name, turn_off_light light_name, print_light_status light_name): ");
        scanf("%s", command);

        char* token = strtok(command, " ");
        if (token == NULL) {
            printf("Error: Invalid command.\n");
            continue;
        }

        if (strcmp(token, "add_light") == 0) {
            char name[20];
            printf("Enter light name: ");
            scanf("%s", name);
            add_light(name);
        } else if (strcmp(token, "set_light_level") == 0) {
            char name[20];
            int level;
            printf("Enter light name: ");
            scanf("%s", name);
            printf("Enter level (0 or 1): ");
            scanf("%d", &level);
            set_light_level(name, level);
        } else if (strcmp(token, "turn_on_light") == 0) {
            char name[20];
            printf("Enter light name: ");
            scanf("%s", name);
            turn_on_light(name);
        } else if (strcmp(token, "turn_off_light") == 0) {
            char name[20];
            printf("Enter light name: ");
            scanf("%s", name);
            turn_off_light(name);
        } else if (strcmp(token, "print_light_status") == 0) {
            char name[20];
            printf("Enter light name: ");
            scanf("%s", name);
            print_light_status(name);
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}
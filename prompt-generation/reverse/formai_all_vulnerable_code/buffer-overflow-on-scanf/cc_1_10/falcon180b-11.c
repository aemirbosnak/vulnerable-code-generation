//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUM_LIGHTS 5

enum light_state {
    LIGHT_OFF,
    LIGHT_ON,
    LIGHT_DIM
};

typedef struct {
    char name[50];
    enum light_state state;
} Light;

void light_init(Light *lights) {
    for (int i = 0; i < NUM_LIGHTS; i++) {
        lights[i].state = LIGHT_OFF;
    }
}

void light_set_state(Light *lights, int index, enum light_state state) {
    if (index < 0 || index >= NUM_LIGHTS) {
        printf("Invalid light index\n");
        return;
    }
    lights[index].state = state;
}

void light_print_state(Light *lights) {
    for (int i = 0; i < NUM_LIGHTS; i++) {
        printf("%s: %s\n", lights[i].name, lights[i].state == LIGHT_ON? "ON" : lights[i].state == LIGHT_OFF? "OFF" : "DIM");
    }
}

int main() {
    Light lights[NUM_LIGHTS];
    light_init(lights);

    while (true) {
        printf("Select a light:\n");
        for (int i = 0; i < NUM_LIGHTS; i++) {
            printf("%d. %s\n", i+1, lights[i].name);
        }
        int choice;
        scanf("%d", &choice);
        choice--;

        printf("Select a state:\n");
        printf("1. ON\n");
        printf("2. OFF\n");
        printf("3. DIM\n");
        int state_choice;
        scanf("%d", &state_choice);
        enum light_state state;
        switch (state_choice) {
        case 1:
            state = LIGHT_ON;
            break;
        case 2:
            state = LIGHT_OFF;
            break;
        case 3:
            state = LIGHT_DIM;
            break;
        default:
            printf("Invalid state choice\n");
            continue;
        }
        light_set_state(lights, choice, state);
        light_print_state(lights);
    }

    return 0;
}
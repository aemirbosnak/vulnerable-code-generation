//Gemma-7B DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define NUM_LAMPS 5

typedef struct Lamp {
    int state;
    char name[20];
} Lamp;

Lamp lamps[NUM_LAMPS] = {
    { 0, "Living Room Lamp" },
    { 1, "Kitchen Lamp" },
    { 0, "Bedroom Lamp" },
    { 1, "Dining Room Lamp" },
    { 0, "Reading Lamp" }
};

void toggleLamp(char *name) {
    for (int i = 0; i < NUM_LAMPS; i++) {
        if (strcmp(lamps[i].name, name) == 0) {
            lamps[i].state ^= 1;
            printf("Lamp '%s' is now %s.\n", lamps[i].name, lamps[i].state ? "on" : "off");
            return;
        }
    }

    printf("Error: Lamp '%s' not found.\n", name);
}

int main() {
    char command[20];

    printf("Enter command (on/off/status): ");
    scanf("%s", command);

    if (strcmp(command, "on") == 0) {
        printf("Enter lamp name: ");
        char name[20];
        scanf("%s", name);
        toggleLamp(name);
    } else if (strcmp(command, "off") == 0) {
        printf("Enter lamp name: ");
        char name[20];
        scanf("%s", name);
        toggleLamp(name);
    } else if (strcmp(command, "status") == 0) {
        for (int i = 0; i < NUM_LAMPS; i++) {
            printf("Lamp '%s' is %s.\n", lamps[i].name, lamps[i].state ? "on" : "off");
        }
    } else {
        printf("Invalid command.\n");
    }

    return 0;
}
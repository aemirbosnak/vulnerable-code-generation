//FormAI DATASET v1.0 Category: Smart home automation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIGHT_PIN 1
#define FAN_PIN 2
#define DOOR_PIN 3

typedef enum {
    OFF,
    ON
} State;

typedef struct {
    char name[20];
    State state;
    int pin;
} Device;

Device light = {"Light", OFF, LIGHT_PIN};
Device fan = {"Fan", OFF, FAN_PIN};
Device door = {"Door", OFF, DOOR_PIN};

void toggle(Device *device) {
    if(device->state == OFF) {
        device->state = ON;
        printf("%s turned on\n", device->name);
    } else {
        device->state = OFF;
        printf("%s turned off\n", device->name);
    }
}

void handleInput(char* input) {
    if(strcmp(input, "toggle light") == 0) {
        toggle(&light);
    } else if(strcmp(input, "toggle fan") == 0) {
        toggle(&fan);
    } else if(strcmp(input, "toggle door") == 0) {
        toggle(&door);
    } else {
        printf("Invalid input\n");
    }
}

int main() {
    char input[20];
    printf("Welcome to the Smart Home Automation System!\n");
    while(1) {
        printf("Enter a command (toggle light/fan/door): ");
        scanf("%s", input);
        handleInput(input);
    }
    return 0;
}
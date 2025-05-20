//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: recursive
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Light {
    bool is_on;
    int brightness;
} Light;

void toggle_light(Light *light) {
    light->is_on = !light->is_on;
}

void set_brightness(Light *light, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Invalid brightness value.\n");
        return;
    }
    light->brightness = brightness;
}

void print_light_status(Light *light) {
    printf("Light is %s and brightness is %d%%.\n",
        light->is_on ? "on" : "off",
        light->brightness);
}

void control_light(Light *light, char *command) {
    if (!strcmp(command, "toggle")) {
        toggle_light(light);
    } else if (!strcmp(command, "on")) {
        light->is_on = true;
    } else if (!strcmp(command, "off")) {
        light->is_on = false;
    } else if (!strncmp(command, "brightness ", 10)) {
        int brightness = atoi(command + 10);
        set_brightness(light, brightness);
    } else {
        printf("Invalid command.\n");
    }
}

void smart_home_light_control() {
    Light light = { .is_on = false, .brightness = 0 };

    while (true) {
        char command[100];
        printf("Enter a command (toggle, on, off, brightness <0-100>): ");
        scanf("%s", command);

        control_light(&light, command);

        print_light_status(&light);

        printf("\n");
    }
}

int main() {
    smart_home_light_control();
    return 0;
}
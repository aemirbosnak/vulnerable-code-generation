//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIGHTS 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int brightness; // 0 to 100
    int is_on; // 1 for on, 0 for off
} Light;

Light lights[MAX_LIGHTS];
int light_count = 0;

void initialize_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        snprintf(lights[i].name, NAME_LENGTH, "Light %d", i + 1);
        lights[i].brightness = 100; // default brightness
        lights[i].is_on = 1; // lights are initially on
    }
    light_count = MAX_LIGHTS;
}

void print_light_status() {
    printf("Current Lights Status:\n");
    for (int i = 0; i < light_count; i++) {
        printf("%s - %s, Brightness: %d%%\n", 
            lights[i].name, 
            lights[i].is_on ? "On" : "Off", 
            lights[i].brightness);
    }
}

void turn_on_light(int index) {
    lights[index].is_on = 1;
    printf("%s is now ON.\n", lights[index].name);
}

void turn_off_light(int index) {
    lights[index].is_on = 0;
    printf("%s is now OFF.\n", lights[index].name);
}

void set_brightness(int index, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Error: Brightness must be between 0 and 100.\n");
        return;
    }
    lights[index].brightness = brightness;
    printf("Brightness of %s set to %d%%.\n", lights[index].name, brightness);
}

void execute_command(char *command) {
    char action[20], light_name[NAME_LENGTH];
    int brightness = -1;

    sscanf(command, "%s %s %d", action, light_name, &brightness);
    
    for (int i = 0; i < light_count; i++) {
        if (strcasecmp(lights[i].name, light_name) == 0) {
            if (strcasecmp(action, "turn_on") == 0) {
                turn_on_light(i);
            } else if (strcasecmp(action, "turn_off") == 0) {
                turn_off_light(i);
            } else if (strcasecmp(action, "set_brightness") == 0 && brightness != -1) {
                set_brightness(i, brightness);
            } else {
                printf("Invalid command.\n");
            }
            return;
        }
    }
    printf("Error: Light not found.\n");
}

int main() {
    char command[100];

    initialize_lights();
    print_light_status();

    while (1) {
        printf("\nEnter command (turn_on, turn_off, set_brightness, or exit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcasecmp(command, "exit") == 0) {
            break;
        }

        execute_command(command);
        print_light_status();
    }

    printf("Exiting Smart Home Light Control Program.\n");
    return 0;
}
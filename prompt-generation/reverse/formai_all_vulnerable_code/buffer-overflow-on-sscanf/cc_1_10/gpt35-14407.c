//FormAI DATASET v1.0 Category: Smart home light control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LIGHTS 10

struct Light {
    char name[25];
    bool status;
    int brightness;
};

int num_lights = 0;

bool get_input(char* input) {
    printf("\n>> ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character
    if(strcmp(input, "exit") == 0) {
        printf("Goodbye! Have a nice day.\n");
        return false;
    }
    return true;
}

int find_light(char* name, struct Light lights[]) {
    for(int i = 0; i < num_lights; i++) {
        if(strcmp(name, lights[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_light(char* name, struct Light lights[]) {
    printf("Adding a new light...\n");
    strcpy(lights[num_lights].name, name);
    lights[num_lights].status = false;
    lights[num_lights].brightness = 0;
    num_lights++;
}

void set_brightness(char* name, int brightness, struct Light lights[]) {
    int index = find_light(name, lights);
    if(index == -1) {
        printf("Error: Light not found.\n");
        return;
    }
    lights[index].brightness = brightness;
    printf("Set brightness of %s to %d.\n", name, brightness);
}

void toggle_light(char* name, struct Light lights[]) {
    int index = find_light(name, lights);
    if(index == -1) {
        printf("Error: Light not found.\n");
        return;
    }
    lights[index].status = !lights[index].status;
    printf("%s the light.\n", lights[index].status ? "Turned on" : "Turned off");
}

void list_lights(struct Light lights[]) {
    printf("Your smart home has the following lights:\n");
    for(int i = 0; i < num_lights; i++) {
        printf("%d. %s\n", i+1, lights[i].name);
        printf("   Status: %s\n", lights[i].status ? "On" : "Off");
        printf("   Brightness: %d\n", lights[i].brightness);
    }
}

int main() {
    struct Light lights[MAX_LIGHTS];
    char input[100];
    printf("Welcome to your smart home light control!\n");
    while(get_input(input)) {
        char command[25];
        char argument[25];
        sscanf(input, "%s %s", command, argument);
        if(strcmp(command, "add") == 0) {
            add_light(argument, lights);
        }
        else if(strcmp(command, "toggle") == 0) {
            toggle_light(argument, lights);
        }
        else if(strcmp(command, "brightness") == 0) {
            int brightness;
            sscanf(input, "%s %s %d", command, argument, &brightness);
            set_brightness(argument, brightness, lights);
        }
        else if(strcmp(command, "list") == 0) {
            list_lights(lights);
        }
        else {
            printf("Error: Invalid command.\n");
        }
    }
    return 0;
}
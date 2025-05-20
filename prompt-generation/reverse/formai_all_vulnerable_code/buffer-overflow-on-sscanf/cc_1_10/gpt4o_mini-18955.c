//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10
#define COMMAND_LENGTH 50

typedef struct {
    int id;
    char name[20];
    int brightness; // Range from 0 to 100
    int is_on;
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

// Function declarations
void add_light(const char *name);
void list_lights();
void control_light(int id, int is_on, int brightness);
void toggle_light(int id);
void set_brightness(int id, int brightness);
int find_light_by_id(int id);
void print_welcome_message();
void print_help();

int main() {
    char command[COMMAND_LENGTH];
    print_welcome_message();

    while (1) {
        printf("> ");
        fgets(command, COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline

        if (strncmp(command, "add", 3) == 0) {
            char name[20];
            sscanf(command + 4, "%s", name);
            add_light(name);
        } else if (strcmp(command, "list") == 0) {
            list_lights();
        } else if (strncmp(command, "control", 7) == 0) {
            int id, brightness;
            sscanf(command + 8, "%d %d", &id, &brightness);
            if (brightness < 0 || brightness > 100) {
                printf("Brightness should be between 0 and 100.\n");
                continue;
            }
            control_light(id, 1, brightness);
        } else if (strncmp(command, "toggle", 6) == 0) {
            int id;
            sscanf(command + 7, "%d", &id);
            toggle_light(id);
        } else if (strncmp(command, "brightness", 11) == 0) {
            int id, brightness;
            sscanf(command + 12, "%d %d", &id, &brightness);
            set_brightness(id, brightness);
        } else if (strcmp(command, "help") == 0) {
            print_help();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the smart home light control system.\n");
            break;
        } else {
            printf("Unknown command. Type 'help' for assistance.\n");
        }
    }
    return 0;
}

void add_light(const char *name) {
    if (light_count >= MAX_LIGHTS) {
        printf("Maximum light limit reached.\n");
        return;
    }
    lights[light_count].id = light_count + 1;
    strcpy(lights[light_count].name, name);
    lights[light_count].brightness = 0;
    lights[light_count].is_on = 0;
    light_count++;
    printf("Light '%s' added with ID %d.\n", name, light_count);
}

void list_lights() {
    if (light_count == 0) {
        printf("No lights added yet.\n");
        return;
    }
    for (int i = 0; i < light_count; i++) {
        printf("ID: %d, Name: %s, Brightness: %d%%, Status: %s\n",
               lights[i].id, lights[i].name,
               lights[i].brightness,
               lights[i].is_on ? "ON" : "OFF");
    }
}

void control_light(int id, int is_on, int brightness) {
    int light_index = find_light_by_id(id);
    if (light_index == -1) {
        printf("Light with ID %d not found.\n", id);
        return;
    }
    lights[light_index].is_on = is_on;
    lights[light_index].brightness = is_on ? brightness : 0;
    printf("Light '%s' turned %s at %d%% brightness.\n", 
           lights[light_index].name, 
           is_on ? "ON" : "OFF",
           lights[light_index].brightness);
}

void toggle_light(int id) {
    int light_index = find_light_by_id(id);
    if (light_index == -1) {
        printf("Light with ID %d not found.\n", id);
        return;
    }
    lights[light_index].is_on = !lights[light_index].is_on;
    printf("Light '%s' toggled to %s.\n", lights[light_index].name,
           lights[light_index].is_on ? "ON" : "OFF");
}

void set_brightness(int id, int brightness) {
    int light_index = find_light_by_id(id);
    if (light_index == -1) {
        printf("Light with ID %d not found.\n", id);
        return;
    }
    if (brightness < 0 || brightness > 100) {
        printf("Brightness should be between 0 and 100.\n");
        return;
    }
    lights[light_index].brightness = brightness;
    if (lights[light_index].is_on) {
        printf("Brightness of light '%s' set to %d%%.\n", 
               lights[light_index].name, brightness);
    } else {
        printf("Brightness of light '%s' is set to %d%% but it is OFF.\n",
               lights[light_index].name, brightness);
    }
}

int find_light_by_id(int id) {
    for (int i = 0; i < light_count; i++) {
        if (lights[i].id == id) {
            return i;
        }
    }
    return -1;
}

void print_welcome_message() {
    printf("Welcome to Smart Home Light Control System!\n");
    printf("Type 'help' to see available commands.\n");
}

void print_help() {
    printf("Available commands:\n");
    printf("1. add <light_name> - Add a new light\n");
    printf("2. list - List all lights\n");
    printf("3. control <id> <brightness> - Turn on light with ID and set brightness\n");
    printf("4. toggle <id> - Toggle the light with specified ID\n");
    printf("5. brightness <id> <brightness> - Set brightness of light with specified ID\n");
    printf("6. help - Display this help message\n");
    printf("7. exit - Exit the program\n");
}
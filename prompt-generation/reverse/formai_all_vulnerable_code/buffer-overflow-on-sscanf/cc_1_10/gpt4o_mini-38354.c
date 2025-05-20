//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VEHICLES 10

typedef struct {
    char name[30];
    float position;
    float speed;
    float distance;
} Vehicle;

Vehicle vehicles[MAX_VEHICLES];
int vehicle_count = 0;

void add_vehicle(const char *name) {
    if (vehicle_count < MAX_VEHICLES) {
        strncpy(vehicles[vehicle_count].name, name, sizeof(vehicles[vehicle_count].name) - 1);
        vehicles[vehicle_count].position = 0.0f;
        vehicles[vehicle_count].speed = 0.0f;
        vehicles[vehicle_count].distance = 0.0f;
        vehicle_count++;
        printf("Vehicle '%s' added!\n", name);
    } else {
        printf("Max vehicle limit reached!\n");
    }
}

void set_speed(const char *name, float speed) {
    for (int i = 0; i < vehicle_count; i++) {
        if (strcmp(vehicles[i].name, name) == 0) {
            vehicles[i].speed = speed;
            printf("Speed of '%s' set to %.2f.\n", name, speed);
            return;
        }
    }
    printf("Vehicle '%s' not found!\n", name);
}

void update_positions(float delta_time) {
    for (int i = 0; i < vehicle_count; i++) {
        vehicles[i].distance += vehicles[i].speed * delta_time;
        vehicles[i].position += vehicles[i].speed * delta_time;
        printf("Vehicle '%s' at position %.2f with speed %.2f.\n", 
               vehicles[i].name, vehicles[i].position, vehicles[i].speed);
    }
}

void display_vehicles() {
    printf("\nCurrent Vehicles and stats:\n");
    for (int i = 0; i < vehicle_count; i++) {
        printf("Vehicle Name: %s, Position: %.2f, Speed: %.2f, Distance: %.2f\n", 
               vehicles[i].name, vehicles[i].position, vehicles[i].speed, vehicles[i].distance);
    }
}

bool parse_command(char *input) {
    char command[30], arg1[30];
    float arg2;

    int num_args = sscanf(input, "%s %s %f", command, arg1, &arg2);
    if (strcmp(command, "add") == 0 && num_args == 2) {
        add_vehicle(arg1);
    } else if (strcmp(command, "speed") == 0 && num_args == 3) {
        set_speed(arg1, arg2);
    } else if (strcmp(command, "update") == 0 && num_args == 2) {
        float delta_time = atof(arg1);
        update_positions(delta_time);
    } else if (strcmp(command, "info") == 0) {
        display_vehicles();
    } else if (strcmp(command, "exit") == 0) {
        return false;
    } else {
        printf("Invalid command! Use 'add', 'speed', 'update', 'info', or 'exit'.\n");
    }
    return true;
}

int main() {
    char input[100];

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    
    while (true) {
        printf("\nEnter command: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (!parse_command(input)) {
            break;
        }
    }

    printf("Exiting simulation...\n");
    return 0;
}
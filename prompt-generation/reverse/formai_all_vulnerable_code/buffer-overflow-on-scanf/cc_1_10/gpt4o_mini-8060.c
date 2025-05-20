//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_VEHICLES 10
#define NAME_LEN 20

typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    STOP
} Direction;

typedef struct {
    char name[NAME_LEN];
    int speed; // Speed of the vehicle in units
    Direction direction;
} Vehicle;

Vehicle vehicles[MAX_VEHICLES];
int vehicle_count = 0;

void add_vehicle(const char *name, int speed) {
    if (vehicle_count < MAX_VEHICLES) {
        strncpy(vehicles[vehicle_count].name, name, NAME_LEN);
        vehicles[vehicle_count].speed = speed;
        vehicles[vehicle_count].direction = STOP;
        vehicle_count++;
        printf("Added vehicle: %s (Speed: %d)\n", name, speed);
    } else {
        printf("Cannot add more vehicles. Maximum limit reached.\n");
    }
}

void set_direction(int vehicle_index, Direction dir) {
    if (vehicle_index < 0 || vehicle_index >= vehicle_count) {
        printf("Invalid vehicle index!\n");
        return;
    }
    vehicles[vehicle_index].direction = dir;
    const char *dir_names[] = { "FORWARD", "BACKWARD", "LEFT", "RIGHT", "STOP" };
    printf("Vehicle %s is moving %s\n", vehicles[vehicle_index].name, dir_names[dir]);
}

void move_vehicles() {
    for (int i = 0; i < vehicle_count; i++) {
        if (vehicles[i].direction != STOP) {
            printf("Vehicle %s is moving at speed %d in direction %d\n", vehicles[i].name, vehicles[i].speed, vehicles[i].direction);
        }
    }
}

void stop_vehicle(int vehicle_index) {
    if (vehicle_index < 0 || vehicle_index >= vehicle_count) {
        printf("Invalid vehicle index!\n");
        return;
    }
    vehicles[vehicle_index].direction = STOP;
    printf("Vehicle %s has stopped.\n", vehicles[vehicle_index].name);
}

void list_vehicles() {
    printf("\nCurrent vehicles:\n");
    for (int i = 0; i < vehicle_count; i++) {
        printf("Index %d: Name: %s, Speed: %d, Direction: %d\n", i, vehicles[i].name, vehicles[i].speed, vehicles[i].direction);
    }
}

void simulate() {
    char command[50];
    int index, speed;
    char name[NAME_LEN];
    
    while (1) {
        printf("\nEnter a command (add/move/stop/list/exit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline
        
        if (strcmp(command, "add") == 0) {
            printf("Enter vehicle name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0; // Remove newline
            printf("Enter vehicle speed: ");
            scanf("%d", &speed);
            getchar(); // Consume newline
            add_vehicle(name, speed);
        } else if (strcmp(command, "move") == 0) {
            printf("Enter vehicle index (0 to %d): ", vehicle_count - 1);
            scanf("%d", &index);
            getchar(); // Consume newline
            printf("Enter direction (0=FORWARD, 1=BACKWARD, 2=LEFT, 3=RIGHT): ");
            int dir;
            scanf("%d", &dir);
            getchar(); // Consume newline
            set_direction(index, dir);
            move_vehicles();
        } else if (strcmp(command, "stop") == 0) {
            printf("Enter vehicle index (0 to %d): ", vehicle_count - 1);
            scanf("%d", &index);
            getchar(); // Consume newline
            stop_vehicle(index);
        } else if (strcmp(command, "list") == 0) {
            list_vehicles();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting simulation.\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }
}

int main() {
    simulate();
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_VEHICLES 10
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    int speed;
    int direction; // 0: Forward, 1: Backward, 2: Left, 3: Right
} RC_Vehicle;

RC_Vehicle vehicles[MAX_VEHICLES];
int vehicle_count = 0;

void add_vehicle(const char* name) {
    if (vehicle_count < MAX_VEHICLES) {
        strncpy(vehicles[vehicle_count].name, name, NAME_LENGTH);
        vehicles[vehicle_count].speed = 0;
        vehicles[vehicle_count].direction = 0;
        vehicle_count++;
        printf("Vehicle %s added!\n", name);
    } else {
        printf("Vehicle limit reached!\n");
    }
}

void set_speed(const char* name, int speed) {
    for (int i = 0; i < vehicle_count; i++) {
        if (strcmp(vehicles[i].name, name) == 0) {
            vehicles[i].speed = speed;
            printf("%s speed set to %d.\n", name, speed);
            return;
        }
    }
    printf("Vehicle %s not found!\n", name);
}

void set_direction(const char* name, int direction) {
    for (int i = 0; i < vehicle_count; i++) {
        if (strcmp(vehicles[i].name, name) == 0) {
            vehicles[i].direction = direction;
            char* dir;
            switch (direction) {
                case 0: dir = "Forward"; break;
                case 1: dir = "Backward"; break;
                case 2: dir = "Left"; break;
                case 3: dir = "Right"; break;
                default: dir = "Unknown"; break;
            }
            printf("%s direction set to %s.\n", name, dir);
            return;
        }
    }
    printf("Vehicle %s not found!\n", name);
}

void display_vehicle_status() {
    printf("\n--- Vehicle Status ---\n");
    for (int i = 0; i < vehicle_count; i++) {
        printf("Vehicle Name: %s, Speed: %d, Direction: %d\n",
               vehicles[i].name, vehicles[i].speed, vehicles[i].direction);
    }
}

void simulate_movement() {
    printf("\n--- Simulating Vehicle Movement ---\n");
    for (int i = 0; i < vehicle_count; i++) {
        printf("%s is moving at speed %d in direction %d.\n",
               vehicles[i].name, vehicles[i].speed, vehicles[i].direction);
        sleep(1); // Simulate time passage for movement
    }
}

void clear_vehicles() {
    vehicle_count = 0;
    printf("All vehicles cleared.\n");
}

void print_menu() {
    printf("\n--- RC Vehicle Control Menu ---\n");
    printf("1. Add Vehicle\n");
    printf("2. Set Speed\n");
    printf("3. Set Direction\n");
    printf("4. Display Vehicle Status\n");
    printf("5. Simulate Movement\n");
    printf("6. Clear All Vehicles\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, speed, direction;
    char name[NAME_LENGTH];

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter vehicle name: ");
                scanf("%s", name);
                add_vehicle(name);
                break;
            }
            case 2: {
                printf("Enter vehicle name: ");
                scanf("%s", name);
                printf("Enter speed: ");
                scanf("%d", &speed);
                set_speed(name, speed);
                break;
            }
            case 3: {
                printf("Enter vehicle name: ");
                scanf("%s", name);
                printf("Enter direction (0: Forward, 1: Backward, 2: Left, 3: Right): ");
                scanf("%d", &direction);
                set_direction(name, direction);
                break;
            }
            case 4: {
                display_vehicle_status();
                break;
            }
            case 5: {
                simulate_movement();
                break;
            }
            case 6: {
                clear_vehicles();
                break;
            }
            case 7: {
                printf("Exiting the program.\n");
                return 0;
            }
            default: {
                printf("Invalid choice! Please try again.\n");
                break;
            }
        }
    }

    return 0;
}
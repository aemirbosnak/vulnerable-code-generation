//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 50
#define MAX_VEHICLE_COUNT 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int x_position;
    int y_position;
} Vehicle;

Vehicle vehicles[MAX_VEHICLE_COUNT];
int vehicle_count = 0;

void add_vehicle(const char *name) {
    if (vehicle_count < MAX_VEHICLE_COUNT) {
        strncpy(vehicles[vehicle_count].name, name, MAX_NAME_LENGTH);
        vehicles[vehicle_count].x_position = 0;
        vehicles[vehicle_count].y_position = 0;
        vehicle_count++;
        printf("Vehicle '%s' added at position (0, 0).\n", name);
    } else {
        printf("Error: Maximum vehicle limit reached.\n");
    }
}

void move_vehicle(int index, int dx, int dy) {
    if (index >= 0 && index < vehicle_count) {
        vehicles[index].x_position += dx;
        vehicles[index].y_position += dy;
        printf("Moved vehicle '%s' to position (%d, %d).\n", vehicles[index].name, vehicles[index].x_position, vehicles[index].y_position);
    } else {
        printf("Error: Vehicle index out of bounds.\n");
    }
}

void display_positions() {
    printf("\nVehicle Positions:\n");
    for (int i = 0; i < vehicle_count; i++) {
        printf("  %s: (%d, %d)\n", vehicles[i].name, vehicles[i].x_position, vehicles[i].y_position);
    }
    printf("\n");
}

void clear_vehicles() {
    vehicle_count = 0;
    printf("All vehicles removed.\n");
}

void show_menu() {
    printf("Remote Control Vehicle Simulation\n");
    printf("1. Add Vehicle\n");
    printf("2. Move Vehicle\n");
    printf("3. Display Positions\n");
    printf("4. Clear Vehicles\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    int vehicle_index, dx, dy;

    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter vehicle name: ");
                scanf("%s", name);
                add_vehicle(name);
                break;
            case 2:
                printf("Enter vehicle index (0 to %d): ", vehicle_count - 1);
                scanf("%d", &vehicle_index);
                printf("Enter movement in x (dx): ");
                scanf("%d", &dx);
                printf("Enter movement in y (dy): ");
                scanf("%d", &dy);
                move_vehicle(vehicle_index, dx, dy);
                break;
            case 3:
                display_positions();
                break;
            case 4:
                clear_vehicles();
                break;
            case 5:
                printf("Exiting the simulation. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        sleep(1); // Sleep to mimic processing time and improve readability.
    }
    return 0;
}
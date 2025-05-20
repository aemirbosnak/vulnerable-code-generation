//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_VEHICLES 10

typedef struct {
    char name[50];
    float position;
    float speed;
    float direction; // in degrees
} Vehicle;

Vehicle vehicles[MAX_VEHICLES];
int vehicle_count = 0;

void add_vehicle(const char* name) {
    if (vehicle_count < MAX_VEHICLES) {
        strncpy(vehicles[vehicle_count].name, name, 49);
        vehicles[vehicle_count].name[49] = '\0'; // Ensure null-termination
        vehicles[vehicle_count].position = 0.0;
        vehicles[vehicle_count].speed = 0.0;
        vehicles[vehicle_count].direction = 0.0; // facing "forward"
        vehicle_count++;
        printf("Added vehicle: %s\n", name);
    } else {
        printf("Cannot add more vehicles. Maximum capacity reached.\n");
    }
}

void set_vehicle_speed(int index, float speed) {
    if (index >= 0 && index < vehicle_count) {
        vehicles[index].speed = speed;
        printf("Set speed of vehicle %s to %.2f\n", vehicles[index].name, speed);
    } else {
        printf("Invalid vehicle index\n");
    }
}

void set_vehicle_direction(int index, float direction) {
    if (index >= 0 && index < vehicle_count) {
        vehicles[index].direction = fmod(direction, 360.0); // Normalize to 0-359 range
        printf("Set direction of vehicle %s to %.2f degrees\n", vehicles[index].name, vehicles[index].direction);
    } else {
        printf("Invalid vehicle index\n");
    }
}

void move_vehicle(int index) {
    if (index >= 0 && index < vehicle_count) {
        float radians = vehicles[index].direction * (3.14159265 / 180.0); // Convert to radians
        vehicles[index].position += vehicles[index].speed * cos(radians);
        printf("Vehicle %s moved to position %.2f\n", vehicles[index].name, vehicles[index].position);
    } else {
        printf("Invalid vehicle index\n");
    }
}

void display_vehicles() {
    printf("\nCurrent State of Vehicles:\n");
    for (int i = 0; i < vehicle_count; i++) {
        printf("Vehicle: %-20s Position: %.2f Speed: %.2f Direction: %.2f\n",
               vehicles[i].name, vehicles[i].position, vehicles[i].speed, vehicles[i].direction);
    }
    printf("\n");
}

void simulate_vehicle_control() {
    int choice, vehicle_index;
    float speed, direction;

    do {
        printf("1. Add Vehicle\n2. Set Speed\n3. Set Direction\n4. Move Vehicle\n5. Display Vehicles\n6. Exit\n");
        printf("Select an action: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter vehicle name: ");
                char name[50];
                scanf("%s", name);
                add_vehicle(name);
                break;
            case 2:
                printf("Enter vehicle index (0 to %d): ", vehicle_count - 1);
                scanf("%d", &vehicle_index);
                printf("Enter speed: ");
                scanf("%f", &speed);
                set_vehicle_speed(vehicle_index, speed);
                break;
            case 3:
                printf("Enter vehicle index (0 to %d): ", vehicle_count - 1);
                scanf("%d", &vehicle_index);
                printf("Enter direction (0 to 359 degrees): ");
                scanf("%f", &direction);
                set_vehicle_direction(vehicle_index, direction);
                break;
            case 4:
                printf("Enter vehicle index (0 to %d): ", vehicle_count - 1);
                scanf("%d", &vehicle_index);
                move_vehicle(vehicle_index);
                break;
            case 5:
                display_vehicles();
                break;
            case 6:
                printf("Exiting simulation.\n");
                break;
            default:
                printf("Invalid selection. Please try again.\n");
        }
        sleep(1); // Pause for better visual separation
    } while (choice != 6);
}

int main() {
    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    simulate_vehicle_control();
    return 0;
}
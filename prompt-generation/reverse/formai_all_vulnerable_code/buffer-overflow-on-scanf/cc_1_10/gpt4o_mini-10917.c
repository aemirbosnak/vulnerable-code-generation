//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_VEHICLES 10
#define NAME_LENGTH 20

typedef enum VehicleType {
    CAR,
    TRUCK,
    MOTORCYCLE,
    MAX_TYPE
} VehicleType;

typedef struct {
    char name[NAME_LENGTH];
    VehicleType type;
    int speed; // Speed in km/h
    int fuel;  // Fuel percentage (0-100)
} Vehicle;

void initialize_vehicle(Vehicle *v, const char *name, VehicleType type) {
    strncpy(v->name, name, NAME_LENGTH);
    v->type = type;
    v->speed = rand() % 101; // Speed between 0 and 100
    v->fuel = 100; // Start with full fuel
}

void display_vehicle(Vehicle *v) {
    const char *vehicle_types[] = {"Car", "Truck", "Motorcycle"};
    printf("Name: %s, Type: %s, Speed: %d km/h, Fuel: %d%%\n",
           v->name, vehicle_types[v->type], v->speed, v->fuel);
}

void drive_vehicle(Vehicle *v) {
    if (v->fuel <= 0) {
        printf("%s cannot drive. Fuel empty!\n", v->name);
        return;
    }
    
    int distance = v->speed; // Driving for 1 hour
    printf("%s is driving for %d kilometers.\n", v->name, distance);
    
    // Decrease fuel based on distance driven (1km consumes 1% fuel)
    v->fuel -= distance > v->fuel ? v->fuel : distance;
}

void refuel_vehicle(Vehicle *v) {
    if (v->fuel == 100) {
        printf("%s is already full of fuel!\n", v->name);
        return;
    }
    
    v->fuel = 100; // Refuel to full
    printf("%s has been refueled to 100%%.\n", v->name);
}

void create_vehicle(Vehicle *vehicles, int *count, const char *name, VehicleType type) {
    if (*count >= MAX_VEHICLES) {
        printf("Cannot create more vehicles. Maximum limit reached.\n");
        return;
    }
    
    initialize_vehicle(&vehicles[*count], name, type);
    (*count)++;
}

int main() {
    srand(time(NULL));
    
    Vehicle vehicles[MAX_VEHICLES];
    int vehicle_count = 0;

    int choice;
    do {
        printf("\n--- Remote Control Vehicle Simulation ---\n");
        printf("1. Create Vehicle\n");
        printf("2. Display Vehicles\n");
        printf("3. Drive Vehicle\n");
        printf("4. Refuel Vehicle\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[NAME_LENGTH];
                int type;
                printf("Enter vehicle name: ");
                scanf("%s", name);
                printf("Enter vehicle type (0: Car, 1: Truck, 2: Motorcycle): ");
                scanf("%d", &type);
                if (type >= 0 && type < MAX_TYPE) {
                    create_vehicle(vehicles, &vehicle_count, name, (VehicleType)type);
                } else {
                    printf("Invalid vehicle type!\n");
                }
                break;
            }
            case 2: {
                printf("--- Vehicles List ---\n");
                for (int i = 0; i < vehicle_count; i++) {
                    display_vehicle(&vehicles[i]);
                }
                break;
            }
            case 3: {
                int index;
                printf("Enter vehicle index to drive (0-%d): ", vehicle_count - 1);
                scanf("%d", &index);
                if (index >= 0 && index < vehicle_count) {
                    drive_vehicle(&vehicles[index]);
                } else {
                    printf("Invalid index!\n");
                }
                break;
            }
            case 4: {
                int index;
                printf("Enter vehicle index to refuel (0-%d): ", vehicle_count - 1);
                scanf("%d", &index);
                if (index >= 0 && index < vehicle_count) {
                    refuel_vehicle(&vehicles[index]);
                } else {
                    printf("Invalid index!\n");
                }
                break;
            }
            case 5:
                printf("Exiting simulation. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
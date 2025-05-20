//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_VEHICLES 5
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int speed; // in km/h
    int direction; // in degrees
    int battery; // in percentage
} Vehicle;

void initializeVehicle(Vehicle *v, const char *name) {
    snprintf(v->name, MAX_NAME_LENGTH, "%s", name);
    v->speed = 0;
    v->direction = 0;
    v->battery = 100; // Start with full battery
}

void displayVehicleStatus(Vehicle *v) {
    printf("Vehicle Name: %s\n", v->name);
    printf("Speed: %d km/h\n", v->speed);
    printf("Direction: %d degrees\n", v->direction);
    printf("Battery Level: %d%%\n", v->battery);
}

void changeSpeed(Vehicle *v, int delta) {
    if ((v->speed + delta) >= 0 && (v->speed + delta) <= 100) {
        v->speed += delta;
    } else {
        printf("Speed out of bounds! Keeping speed at %d km/h.\n", v->speed);
    }
}

void changeDirection(Vehicle *v, int delta) {
    v->direction = (v->direction + delta) % 360;
    if (v->direction < 0)
        v->direction += 360;
}

void drainBattery(Vehicle *v) {
    if (v->battery > 0) {
        v->battery -= (v->speed / 10 + 1); // Drain battery more with speed
        if (v->battery < 0) {
            v->battery = 0;
        }
    }
}

int main() {
    Vehicle vehicles[MAX_VEHICLES];
    char names[MAX_VEHICLES][MAX_NAME_LENGTH] = {"Car", "Bike", "Truck", "Drone", "Tank"};
    for (int i = 0; i < MAX_VEHICLES; i++) {
        initializeVehicle(&vehicles[i], names[i]);
    }

    int choice, speedChange, directionChange, vehicleIndex;
    while (1) {
        printf("\nRemote Control Vehicle Simulation\n");
        printf("1. Show Vehicle Status\n");
        printf("2. Change Speed\n");
        printf("3. Change Direction\n");
        printf("4. Drain Battery\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 5) {
            break;
        }

        printf("Select Vehicle (0-%d): ", MAX_VEHICLES - 1);
        scanf("%d", &vehicleIndex);
        if (vehicleIndex < 0 || vehicleIndex >= MAX_VEHICLES) {
            printf("Invalid Vehicle Selection!\n");
            continue;
        }

        switch (choice) {
            case 1:
                displayVehicleStatus(&vehicles[vehicleIndex]);
                break;
            case 2:
                printf("Enter speed change (positive to increase, negative to decrease): ");
                scanf("%d", &speedChange);
                changeSpeed(&vehicles[vehicleIndex], speedChange);
                break;
            case 3:
                printf("Enter direction change (-360 to 360): ");
                scanf("%d", &directionChange);
                changeDirection(&vehicles[vehicleIndex], directionChange);
                break;
            case 4:
                drainBattery(&vehicles[vehicleIndex]);
                printf("%s's battery drained. Current level: %d%%\n", vehicles[vehicleIndex].name, vehicles[vehicleIndex].battery);
                break;
            default:
                printf("Invalid option!\n");
                break;
        }

        sleep(1); // To simulate passage of time
    }

    printf("Exiting simulation. Goodbye!\n");
    return 0;
}
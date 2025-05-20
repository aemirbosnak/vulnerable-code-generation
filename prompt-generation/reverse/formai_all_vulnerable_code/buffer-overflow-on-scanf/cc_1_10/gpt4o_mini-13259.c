//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_VEHICLES 10
#define COMMAND_SIZE 50

typedef enum { CAR, TRUCK, MOTORCYCLE } VehicleType;

typedef struct {
    VehicleType type;
    char name[30];
    int position;
    int speed;
} Vehicle;

void initializeVehicle(Vehicle *v, VehicleType type, const char *name) {
    v->type = type;
    strncpy(v->name, name, sizeof(v->name) - 1);
    v->name[sizeof(v->name) - 1] = '\0';
    v->position = 0;
    v->speed = 0;
}

void displayStatus(const Vehicle *v) {
    const char *typeStrings[] = { "Car", "Truck", "Motorcycle" };
    printf("Vehicle: %s\n", v->name);
    printf("Type: %s\n", typeStrings[v->type]);
    printf("Position: %d\n", v->position);
    printf("Speed: %d\n", v->speed);
}

void moveVehicle(Vehicle *v) {
    v->position += v->speed;
}

void increaseSpeed(Vehicle *v, int increment) {
    v->speed += increment;
    if (v->speed < 0) v->speed = 0;
}

void decreaseSpeed(Vehicle *v, int decrement) {
    v->speed -= decrement;
    if (v->speed < 0) v->speed = 0;
}

int main() {
    Vehicle garage[MAX_VEHICLES];
    int vehicleCount = 0;
    char command[COMMAND_SIZE];

    printf("=== Remote Control Vehicle Simulation ===\n");
    while (1) {
        printf("Enter a command (add, status, move, speedup, slowdown, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            if (vehicleCount >= MAX_VEHICLES) {
                printf("Garage is full!\n");
                continue;
            }
            char vehicleName[30];
            char vehicleType[30];

            printf("Enter vehicle name: ");
            scanf("%s", vehicleName);
            printf("Enter vehicle type (car, truck, motorcycle): ");
            scanf("%s", vehicleType);

            VehicleType type;
            if (strcmp(vehicleType, "car") == 0) {
                type = CAR;
            } else if (strcmp(vehicleType, "truck") == 0) {
                type = TRUCK;
            } else if (strcmp(vehicleType, "motorcycle") == 0) {
                type = MOTORCYCLE;
            } else {
                printf("Unknown vehicle type! Not added.\n");
                continue;
            }

            initializeVehicle(&garage[vehicleCount], type, vehicleName);
            vehicleCount++;
            printf("Vehicle added!\n");
        } 
        else if (strcmp(command, "status") == 0) {
            for (int i = 0; i < vehicleCount; i++) {
                displayStatus(&garage[i]);
                printf("\n");
            }
        } 
        else if (strcmp(command, "move") == 0) {
            int index;
            printf("Enter vehicle index to move (0 to %d): ", vehicleCount - 1);
            scanf("%d", &index);
            if (index >= 0 && index < vehicleCount) {
                moveVehicle(&garage[index]);
                printf("Vehicle moved!\n");
            } else {
                printf("Invalid index!\n");
            }
        } 
        else if (strcmp(command, "speedup") == 0) {
            int index, increment;
            printf("Enter vehicle index to speed up (0 to %d): ", vehicleCount - 1);
            scanf("%d", &index);
            if (index >= 0 && index < vehicleCount) {
                printf("Enter speed increment: ");
                scanf("%d", &increment);
                increaseSpeed(&garage[index], increment);
                printf("Vehicle speed increased!\n");
            } else {
                printf("Invalid index!\n");
            }
        } 
        else if (strcmp(command, "slowdown") == 0) {
            int index, decrement;
            printf("Enter vehicle index to slow down (0 to %d): ", vehicleCount - 1);
            scanf("%d", &index);
            if (index >= 0 && index < vehicleCount) {
                printf("Enter speed decrement: ");
                scanf("%d", &decrement);
                decreaseSpeed(&garage[index], decrement);
                printf("Vehicle speed decreased!\n");
            } else {
                printf("Invalid index!\n");
            }
        } 
        else if (strcmp(command, "exit") == 0) {
            printf("Exiting the simulation. Goodbye!\n");
            break;
        } 
        else {
            printf("Unknown command! Please try again.\n");
        }

        sleep(1);  // Simulate a brief pause
    }

    return 0;
}
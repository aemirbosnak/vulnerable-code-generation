//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of remote control vehicles that can be created
#define MAX_VEHICLES 10

// Define the structure for a remote control vehicle
typedef struct {
    char *name;
    int speed;
    int battery_level;
} RCVehicle;

// Function prototypes
void display_menu();
void create_vehicle(RCVehicle vehicles[], int *num_vehicles);
void display_vehicles(RCVehicle vehicles[], int num_vehicles);
void accelerate_vehicle(RCVehicle *vehicle);
void decelerate_vehicle(RCVehicle *vehicle);
void update_battery(RCVehicle vehicles[], int num_vehicles);

int main() {
    // Initialize variables
    RCVehicle vehicles[MAX_VEHICLES];
    int num_vehicles = 0;
    int option = 0;

    // Display the menu and take user input
    while (option != 5) {
        display_menu();
        scanf("%d", &option);

        // Perform the selected option
        switch(option) {
            case 1:
                create_vehicle(vehicles, &num_vehicles);
                break;
            case 2:
                display_vehicles(vehicles, num_vehicles);
                break;
            case 3:
                accelerate_vehicle(&vehicles[0]);
                update_battery(vehicles, num_vehicles);
                break;
            case 4:
                decelerate_vehicle(&vehicles[0]);
                update_battery(vehicles, num_vehicles);
                break;
            case 5:
                printf("Exiting remote control vehicle simulation\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Displays the menu options
void display_menu() {
    printf("\nRemote Control Vehicle Simulation\n");
    printf("1. Create new vehicle\n");
    printf("2. Display all vehicles\n");
    printf("3. Accelerate vehicle\n");
    printf("4. Decelerate vehicle\n");
    printf("5. Exit\n");
}

// Creates a new remote control vehicle and adds it to the array
void create_vehicle(RCVehicle vehicles[], int *num_vehicles) {
    // Check if the maximum number of vehicles has been reached
    if (*num_vehicles >= MAX_VEHICLES) {
        printf("Maximum number of vehicles reached\n");
        return;
    }

    // Allocate memory for the vehicle name
    char *name = (char*) malloc(20*sizeof(char));

    // Get the vehicle name and speed from user input
    printf("Enter vehicle name: ");
    scanf("%s", name);
    printf("Enter vehicle speed: ");
    int speed;
    scanf("%d", &speed);

    // Set the vehicle properties and add it to the vehicles array
    RCVehicle vehicle = {name, speed, 100};
    vehicles[*num_vehicles] = vehicle;
    *num_vehicles += 1;

    printf("Vehicle created successfully\n");
}

// Displays all remote control vehicles in the array
void display_vehicles(RCVehicle vehicles[], int num_vehicles) {
    if (num_vehicles == 0) {
        printf("No vehicles to display\n");
        return;
    }

    printf("List of all vehicles:\n");
    for (int i = 0; i < num_vehicles; i++) {
        printf("%d. %s (speed: %d, battery level: %d)\n",
                i+1, vehicles[i].name, vehicles[i].speed, vehicles[i].battery_level);
    }
}

// Accelerates the vehicle by increasing its speed by 10
void accelerate_vehicle(RCVehicle *vehicle) {
    int new_speed = vehicle->speed + 10;
    if (new_speed > 100) {
        printf("Cannot accelerate further. Maximum speed reached\n");
        return;
    }

    vehicle->speed = new_speed;
    printf("Vehicle accelerated to %d\n", vehicle->speed);
}

// Decelerates the vehicle by decreasing its speed by 10
void decelerate_vehicle(RCVehicle *vehicle) {
    int new_speed = vehicle->speed - 10;
    if (new_speed < 0) {
        printf("Cannot decelerate further. Vehicle stopped\n");
        vehicle->speed = 0;
        return;
    }

    vehicle->speed = new_speed;
    printf("Vehicle decelerated to %d\n", vehicle->speed);
}

// Updates the battery level of all vehicles in the array based on their speed
void update_battery(RCVehicle vehicles[], int num_vehicles) {
    for (int i = 0; i < num_vehicles; i++) {
        int battery_level = vehicles[i].battery_level - (vehicles[i].speed/10);
        if (battery_level < 0) {
            battery_level = 0;
        }
        vehicles[i].battery_level = battery_level;
    }
}
//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_VEHICLES 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int speed;
    int battery;
    int x, y;
} Vehicle;

void initialize_vehicle(Vehicle *v, const char *name) {
    strncpy(v->name, name, MAX_NAME_LENGTH - 1);
    v->speed = rand() % 21; // Speed between 0 - 20
    v->battery = 100; // Full battery
    v->x = rand() % 100; // Random start position
    v->y = rand() % 100;
}

void display_vehicle_info(const Vehicle *v) {
    printf("Vehicle Name: %s\n", v->name);
    printf("Speed: %d\n", v->speed);
    printf("Battery: %d%%\n", v->battery);
    printf("Current Position: (%d, %d)\n", v->x, v->y);
}

void move_vehicle(Vehicle *v) {
    if (v->battery <= 0) {
        printf("%s has no battery left and can't move!\n", v->name);
        return;
    }

    // Update position based on speed
    v->x += (rand() % 3 - 1) * v->speed; // Random movement in x direction
    v->y += (rand() % 3 - 1) * v->speed; // Random movement in y direction
    v->battery -= (rand() % 5 + 1); // Consume some battery

    if (v->battery < 0) {
        v->battery = 0;
    }

    printf("%s moved to (%d, %d) with battery at %d%%\n", v->name, v->x, v->y, v->battery);
}

void recharge_vehicle(Vehicle *v) {
    printf("Recharging %s...\n", v->name);
    v->battery = 100;
}

void print_battery_status(Vehicle *v) {
    if (v->battery > 75) {
        printf("%s is fully charged.\n", v->name);
    } else if (v->battery > 25) {
        printf("%s has enough power.\n", v->name);
    } else if (v->battery > 0) {
        printf("%s is running low on battery!\n", v->name);
    } else {
        printf("%s is out of battery!\n", v->name);
    }
}

int main() {
    srand(time(NULL));

    Vehicle vehicles[MAX_VEHICLES];
    int num_vehicles = 0;

    printf("Welcome to the Cyberpunk Remote Control Vehicle Simulator!\n");
    printf("Please enter the names of your vehicles (type 'END' to finish):\n");

    while (num_vehicles < MAX_VEHICLES) {
        char name[MAX_NAME_LENGTH];
        printf("Enter vehicle name [%d]: ", num_vehicles + 1);
        scanf("%s", name);

        if (strcmp(name, "END") == 0) {
            break;
        } else {
            initialize_vehicle(&vehicles[num_vehicles], name);
            num_vehicles++;
        }
    }
    
    int action;
    do {
        printf("\nSelect an action:\n");
        printf("1. Display vehicle info\n");
        printf("2. Move a vehicle\n");
        printf("3. Recharge a vehicle\n");
        printf("4. Check battery status\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &action);

        if (action == 1) {
            for (int i = 0; i < num_vehicles; i++) {
                display_vehicle_info(&vehicles[i]);
            }
        } else if (action == 2) {
            int vehicle_index;
            printf("Enter vehicle index (0 to %d): ", num_vehicles - 1);
            scanf("%d", &vehicle_index);
            if (vehicle_index >= 0 && vehicle_index < num_vehicles) {
                move_vehicle(&vehicles[vehicle_index]);
            } else {
                printf("Invalid vehicle index!\n");
            }
        } else if (action == 3) {
            int vehicle_index;
            printf("Enter vehicle index to recharge (0 to %d): ", num_vehicles - 1);
            scanf("%d", &vehicle_index);
            if (vehicle_index >= 0 && vehicle_index < num_vehicles) {
                recharge_vehicle(&vehicles[vehicle_index]);
            } else {
                printf("Invalid vehicle index!\n");
            }
        } else if (action == 4) {
            int vehicle_index;
            printf("Enter vehicle index to check battery (0 to %d): ", num_vehicles - 1);
            scanf("%d", &vehicle_index);
            if (vehicle_index >= 0 && vehicle_index < num_vehicles) {
                print_battery_status(&vehicles[vehicle_index]);
            } else {
                printf("Invalid vehicle index!\n");
            }
        }
    } while (action != 5);

    printf("Exiting Cyberpunk Vehicle Simulator. Stay safe out there!\n");
    return 0;
}
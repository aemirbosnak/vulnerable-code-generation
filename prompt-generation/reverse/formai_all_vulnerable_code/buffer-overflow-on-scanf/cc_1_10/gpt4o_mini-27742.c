//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_VEHICLES 5
#define MAX_NAME_LENGTH 20
#define MAX_COMMAND_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int battery_level;
    int position_x;
    int position_y;
} Vehicle;

void display_menu() {
    printf("\n--- Post-Apocalyptic Remote Control Vehicle Simulation ---\n");
    printf("1. Create Vehicle\n");
    printf("2. Move Vehicle\n");
    printf("3. Check Battery Level\n");
    printf("4. Display Vehicle Status\n");
    printf("5. Exit Simulation\n");
    printf("Choose an option (1-5): ");
}

Vehicle create_vehicle() {
    Vehicle v;
    printf("Enter vehicle name: ");
    scanf("%s", v.name);
    v.battery_level = 100;
    v.position_x = rand() % 20;
    v.position_y = rand() % 20;
    return v;
}

void move_vehicle(Vehicle *v) {
    if (v->battery_level <= 0) {
        printf("%s has no battery left to move!\n", v->name);
        return;
    }

    char direction[MAX_COMMAND_LENGTH];
    printf("Enter direction to move (up, down, left, right): ");
    scanf("%s", direction);

    if (strcmp(direction, "up") == 0) {
        v->position_y++;
    } else if (strcmp(direction, "down") == 0) {
        v->position_y--;
    } else if (strcmp(direction, "left") == 0) {
        v->position_x--;
    } else if (strcmp(direction, "right") == 0) {
        v->position_x++;
    } else {
        printf("Invalid direction. Please try again.\n");
        return;
    }

    v->battery_level -= 10;
    if (v->battery_level < 0) {
        v->battery_level = 0;
    }

    printf("%s moved to position (%d, %d) - Battery level: %d%%\n", v->name, v->position_x, v->position_y, v->battery_level);
}

void check_battery(Vehicle *v) {
    printf("Battery level for %s: %d%%\n", v->name, v->battery_level);
}

void display_vehicle_status(Vehicle *v) {
    printf("Vehicle Name: %s\n", v->name);
    printf("Position: (%d, %d)\n", v->position_x, v->position_y);
    printf("Battery Level: %d%%\n", v->battery_level);
}

int main() {
    srand(time(NULL));
    Vehicle vehicles[MAX_VEHICLES];
    int vehicle_count = 0;
    int choice;

    while(1) {
        display_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (vehicle_count < MAX_VEHICLES) {
                    vehicles[vehicle_count++] = create_vehicle();
                    printf("Vehicle created successfully!\n");
                } else {
                    printf("Maximum number of vehicles reached!\n");
                }
                break;
                
            case 2:
                if (vehicle_count > 0) {
                    int index;
                    printf("Select vehicle index (0-%d): ", vehicle_count - 1);
                    scanf("%d", &index);
                    if (index >= 0 && index < vehicle_count) {
                        move_vehicle(&vehicles[index]);
                    } else {
                        printf("Invalid index! Please choose a valid vehicle.\n");
                    }
                } else {
                    printf("No vehicles available!\n");
                }
                break;
                
            case 3:
                if (vehicle_count > 0) {
                    int index;
                    printf("Select vehicle index (0-%d): ", vehicle_count - 1);
                    scanf("%d", &index);
                    if (index >= 0 && index < vehicle_count) {
                        check_battery(&vehicles[index]);
                    } else {
                        printf("Invalid index! Please choose a valid vehicle.\n");
                    }
                } else {
                    printf("No vehicles available!\n");
                }
                break;

            case 4:
                if (vehicle_count > 0) {
                    int index;
                    printf("Select vehicle index (0-%d): ", vehicle_count - 1);
                    scanf("%d", &index);
                    if (index >= 0 && index < vehicle_count) {
                        display_vehicle_status(&vehicles[index]);
                    } else {
                        printf("Invalid index! Please choose a valid vehicle.\n");
                    }
                } else {
                    printf("No vehicles available!\n");
                }
                break;

            case 5:
                printf("Exiting simulation...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    }
    return 0;
}
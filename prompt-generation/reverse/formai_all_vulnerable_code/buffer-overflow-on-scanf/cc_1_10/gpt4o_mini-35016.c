//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define MAX_VEHICLES 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int speed; // Current speed
    int direction; // 0: stop, 1: forward, -1: backward
} Vehicle;

Vehicle vehicles[MAX_VEHICLES];
int vehicle_count = 0;

void init_termios();
void reset_termios();
char getch();
void display_menu();
void add_vehicle();
void list_vehicles();
void control_vehicle(int index);
void update_vehicle(Vehicle *vehicle);
void simulate_movement(Vehicle *vehicle);

int main() {
    init_termios();
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_vehicle();
                break;
            case 2:
                list_vehicles();
                break;
            case 3:
                if (vehicle_count == 0) {
                    printf("No vehicles available to control!\n");
                } else {
                    int index;
                    printf("Select vehicle index (0 to %d): ", vehicle_count - 1);
                    scanf("%d", &index);
                    if (index >= 0 && index < vehicle_count) {
                        control_vehicle(index);
                    } else {
                        printf("Invalid index!\n");
                    }
                }
                break;
            case 4:
                printf("Exiting simulation.\n");
                reset_termios();
                exit(0);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("\n--- Remote Control Vehicle Simulation ---\n");
    printf("1. Add Vehicle\n");
    printf("2. List Vehicles\n");
    printf("3. Control Vehicle\n");
    printf("4. Exit\n");
    printf("------------------------------------------\n");
}

void add_vehicle() {
    if (vehicle_count >= MAX_VEHICLES) {
        printf("Max vehicle limit reached!\n");
        return;
    }

    Vehicle new_vehicle;
    printf("Enter vehicle name: ");
    scanf("%s", new_vehicle.name);
    new_vehicle.speed = 0;
    new_vehicle.direction = 0;
    vehicles[vehicle_count++] = new_vehicle;
    printf("Vehicle '%s' added successfully!\n", new_vehicle.name);
}

void list_vehicles() {
    if (vehicle_count == 0) {
        printf("No vehicles to list!\n");
        return;
    }
    
    printf("\nRegistered Vehicles:\n");
    for (int i = 0; i < vehicle_count; i++) {
        printf("%d: %s - Speed: %d, Direction: %d\n", i, vehicles[i].name, vehicles[i].speed, vehicles[i].direction);
    }
}

void control_vehicle(int index) {
    char command;
    printf("Controlling vehicle: %s\n", vehicles[index].name);
    while (1) {
        printf("Control with [w: forward, s: backward, a: left, d: right, r: reset, q: quit]: ");
        command = getch();

        if (command == 'q') {
            break;
        }

        update_vehicle(&vehicles[index]);
        switch (command) {
            case 'w':
                vehicles[index].direction = 1;
                vehicles[index].speed += 5;
                break;
            case 's':
                vehicles[index].direction = -1;
                vehicles[index].speed -= 5;
                break;
            case 'a':
                printf("Turning %s left\n", vehicles[index].name);
                break;
            case 'd':
                printf("Turning %s right\n", vehicles[index].name);
                break;
            case 'r':
                vehicles[index].speed = 0;
                vehicles[index].direction = 0;
                printf("Resetting %s\n", vehicles[index].name);
                break;
            default:
                printf("Invalid command!\n");
                continue;
        }
        simulate_movement(&vehicles[index]);
    }
}

void update_vehicle(Vehicle *vehicle) {
    if (vehicle->speed < 0) {
        vehicle->speed = 0;
    }
}

void simulate_movement(Vehicle *vehicle) {
    if (vehicle->direction == 1) {
        printf("%s is moving forward at speed %d\n", vehicle->name, vehicle->speed);
    } else if (vehicle->direction == -1) {
        printf("%s is moving backward at speed %d\n", vehicle->name, vehicle->speed);
    } else {
        printf("%s is stopped\n", vehicle->name);
    }
}

void init_termios() {
    struct termios newt;
    tcgetattr(STDIN_FILENO, &newt);
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void reset_termios() {
    struct termios newt;
    tcgetattr(STDIN_FILENO, &newt);
    newt.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

char getch() {
    char ch;
    read(STDIN_FILENO, &ch, 1);
    return ch;
}
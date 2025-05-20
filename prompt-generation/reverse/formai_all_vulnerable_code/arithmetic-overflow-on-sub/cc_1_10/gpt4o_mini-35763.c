//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <stdbool.h>

#define MAX_VEHICLES 5
#define COMMAND_BUFFER_SIZE 100

typedef struct {
    char name[20];
    float speed;
    float direction; // in degrees
    bool is_running;
} Vehicle;

Vehicle vehicles[MAX_VEHICLES];
int vehicle_count = 0;

void init_vehicle(char *name) {
    if (vehicle_count < MAX_VEHICLES) {
        Vehicle v;
        snprintf(v.name, sizeof(v.name), "%s", name);
        v.speed = 0.0;
        v.direction = 0.0;
        v.is_running = false;

        vehicles[vehicle_count++] = v;
        printf("Initialized vehicle: %s\n", name);
    } else {
        printf("Cannot add more vehicles. Max limit reached.\n");
    }
}

void start_vehicle(int index) {
    if (index < vehicle_count && !vehicles[index].is_running) {
        vehicles[index].is_running = true;
        printf("Vehicle %s started.\n", vehicles[index].name);
    } else {
        printf("Vehicle %s is already running or does not exist.\n", vehicles[index].name);
    }
}

void stop_vehicle(int index) {
    if (index < vehicle_count && vehicles[index].is_running) {
        vehicles[index].is_running = false;
        printf("Vehicle %s stopped.\n", vehicles[index].name);
    } else {
        printf("Vehicle %s is already stopped or does not exist.\n", vehicles[index].name);
    }
}

void set_speed(int index, float speed) {
    if (index < vehicle_count) {
        vehicles[index].speed = speed;
        printf("Vehicle %s speed set to %.2f.\n", vehicles[index].name, speed);
    } else {
        printf("Vehicle does not exist.\n");
    }
}

void turn_vehicle(int index, float angle) {
    if (index < vehicle_count) {
        vehicles[index].direction += angle;
        if (vehicles[index].direction < 0) vehicles[index].direction += 360;
        if (vehicles[index].direction >= 360) vehicles[index].direction -= 360;
        printf("Vehicle %s turned. New direction: %.2f degrees.\n", vehicles[index].name, vehicles[index].direction);
    } else {
        printf("Vehicle does not exist.\n");
    }
}

void display_vehicle_status(int index) {
    if (index < vehicle_count) {
        Vehicle v = vehicles[index];
        printf("==== Vehicle Status ====\n");
        printf("Name: %s\n", v.name);
        printf("Speed: %.2f\n", v.speed);
        printf("Direction: %.2f\n", v.direction);
        printf("Status: %s\n", v.is_running ? "Running" : "Stopped");
        printf("========================\n");
    } else {
        printf("Vehicle does not exist.\n");
    }
}

int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void handle_input() {
    printf("Commands:\n");
    printf("1: Start vehicle\n");
    printf("2: Stop vehicle\n");
    printf("3: Set speed\n");
    printf("4: Turn vehicle\n");
    printf("5: Display status\n");
    printf("0: Exit\n");

    int command;
    while (true) {
        printf("\nEnter command: ");
        command = getch() - '0';
        
        if (command == 0) break;

        int vehicle_index;
        if (command >= 1 && command <= 5) {
            printf("Enter vehicle index (0 to %d): ", vehicle_count - 1);
            scanf("%d", &vehicle_index);

            switch (command) {
                case 1: start_vehicle(vehicle_index); break;
                case 2: stop_vehicle(vehicle_index); break;
                case 3: {
                    float speed;
                    printf("Enter speed: ");
                    scanf("%f", &speed);
                    set_speed(vehicle_index, speed);
                    break;
                }
                case 4: {
                    float angle;
                    printf("Enter turn angle: ");
                    scanf("%f", &angle);
                    turn_vehicle(vehicle_index, angle);
                    break;
                }
                case 5: display_vehicle_status(vehicle_index); break;
            }
        } else {
            printf("Invalid command!\n");
        }
        while (getchar() != '\n'); // Clear input buffer
    }
}

int main() {
    init_vehicle("Car1");
    init_vehicle("Bike1");
    init_vehicle("Drone1");

    handle_input();

    printf("Exiting simulation.\n");
    return 0;
}
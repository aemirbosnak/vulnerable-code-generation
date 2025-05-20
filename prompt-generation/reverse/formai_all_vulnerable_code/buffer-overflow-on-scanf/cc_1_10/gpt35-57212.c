//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of drones that can be controlled by this program
#define MAX_DRONES 10

// Define the struct for Drone
typedef struct drone {
    int id;
    int speed; // in m/s
    int altitude; // in meters
    int battery_life; // in minutes
    int is_connected; // 1 if connected, 0 if disconnected
} Drone;

// Define the struct for Remote Control
typedef struct remote_control {
    int num_drones; // the number of drones connected to the remote control
    Drone drones[MAX_DRONES]; // an array of Drone structs to store the connected drones
} Remote_Control;

// Function prototypes
void menu();
void connect_drone(Remote_Control *remote);
void disconnect_drone(Remote_Control *remote);
void fly_drone(Remote_Control remote);
void land_drone(Remote_Control remote);
void display_status(Remote_Control remote);

int main() {
    Remote_Control remote = {0}; // Initialize the Remote_Control struct
    
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                connect_drone(&remote);
                break;
            case 2:
                disconnect_drone(&remote);
                break;
            case 3:
                fly_drone(remote);
                break;
            case 4:
                land_drone(remote);
                break;
            case 5:
                display_status(remote);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 6);

    return 0;
}

void menu() {
    printf("\nDRONE REMOTE CONTROL\n");
    printf("1. Connect Drone\n");
    printf("2. Disconnect Drone\n");
    printf("3. Fly Drone\n");
    printf("4. Land Drone\n");
    printf("5. Display Status\n");
    printf("6. Quit\n");
    printf("Enter your choice: ");
}

void connect_drone(Remote_Control *remote) {
    if (remote->num_drones >= MAX_DRONES) {
        printf("Max limit of connected drones reached.\n");
        return;
    }
    Drone new_drone = {0};
    printf("Enter drone id: ");
    scanf("%d", &new_drone.id);
    printf("Enter drone speed (in m/s): ");
    scanf("%d", &new_drone.speed);
    printf("Enter drone altitude (in meters): ");
    scanf("%d", &new_drone.altitude);
    printf("Enter drone battery life (in minutes): ");
    scanf("%d", &new_drone.battery_life);
    new_drone.is_connected = 1;
    remote->drones[remote->num_drones] = new_drone;
    remote->num_drones++;
    printf("Drone connected successfully.\n");
}

void disconnect_drone(Remote_Control *remote) {
    if (remote->num_drones == 0) {
        printf("No drones connected.\n");
        return;
    }
    int drone_id;
    printf("Enter drone id to disconnect: ");
    scanf("%d", &drone_id);
    for (int i = 0; i < remote->num_drones; i++) {
        if (remote->drones[i].id == drone_id && remote->drones[i].is_connected == 1) {
            remote->drones[i].is_connected = 0;
            remote->num_drones--;
            printf("Drone disconnected successfully.\n");
            return;
        }
    }
    printf("Drone not found or already disconnected.\n");
}

void fly_drone(Remote_Control remote) {
    if (remote.num_drones == 0) {
        printf("No drones connected.\n");
        return;
    }
    int drone_id;
    printf("Enter drone id to fly: ");
    scanf("%d", &drone_id);
    for (int i = 0; i < remote.num_drones; i++) {
        if (remote.drones[i].id == drone_id && remote.drones[i].is_connected == 1) {
            printf("Flying drone %d...\n", drone_id);
            remote.drones[i].altitude = 50;
            remote.drones[i].speed = 10;
            remote.drones[i].battery_life--;
            printf("Drone %d flying at altitude %d meters, speed %d m/s.\n", 
                    drone_id, remote.drones[i].altitude, remote.drones[i].speed);
            return;
        }
    }
}

void land_drone(Remote_Control remote) {
    if (remote.num_drones == 0) {
        printf("No drones connected.\n");
        return;
    }
    int drone_id;
    printf("Enter drone id to land: ");
    scanf("%d", &drone_id);
    for (int i = 0; i < remote.num_drones; i++) {
        if (remote.drones[i].id == drone_id && remote.drones[i].is_connected == 1) {
            printf("Landing drone %d...\n", drone_id);
            remote.drones[i].altitude = 0;
            remote.drones[i].speed = 0;
            printf("Drone %d has landed.\n", drone_id);
            return;
        }
    }
}

void display_status(Remote_Control remote) {
    if (remote.num_drones == 0) {
        printf("No drones connected.\n");
        return;
    }
    printf("Connected Drones:\n");
    printf("ID | SPEED (m/s) | ALTITUDE (m) | BATTERY LIFE (min)\n");
    for (int i = 0; i < remote.num_drones; i++) {
        printf("%d | %d | %d | %d\n", remote.drones[i].id, 
                remote.drones[i].speed, remote.drones[i].altitude, remote.drones[i].battery_life);
    }
}
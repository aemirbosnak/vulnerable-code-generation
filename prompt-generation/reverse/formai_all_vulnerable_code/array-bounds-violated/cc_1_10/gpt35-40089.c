//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DRONES 10

// define struct drone
typedef struct drone {
    int id;
    int battery;
    bool is_flying;
} Drone;

// define function prototypes
void initialize_drones(Drone drones[]);
void display_menu();
void display_status(Drone drone);
int select_drone();
void check_battery(Drone *drone);
void take_off(Drone *drone);
void land(Drone *drone);
void move_left(Drone *drone);
void move_right(Drone *drone);
void move_forward(Drone *drone);
void move_backward(Drone *drone);

int main() {
    Drone drones[MAX_DRONES];
    initialize_drones(drones);

    while (true) {
        display_menu();

        int option;
        printf("\nEnter option: ");
        scanf("%d", &option);

        int drone_index = select_drone();
        Drone drone = drones[drone_index];

        switch (option) {
            case 1:
                display_status(drone);
                break;
            case 2:
                check_battery(&drone);
                break;
            case 3:
                take_off(&drone);
                break;
            case 4:
                land(&drone);
                break;
            case 5:
                move_left(&drone);
                break;
            case 6:
                move_right(&drone);
                break;
            case 7:
                move_forward(&drone);
                break;
            case 8:
                move_backward(&drone);
                break;
            case 9:
                exit(0);
            default:
                printf("\nInvalid option.");
        }
        drones[drone_index] = drone;
    }

    return 0;
}

void initialize_drones(Drone drones[]) {
    for (int i = 0; i < MAX_DRONES; i++) {
        drones[i].id = i + 1;
        drones[i].battery = 100;
        drones[i].is_flying = false;
    }
}

void display_menu() {
    printf("\n========== Drone Remote Control ==========");
    printf("\n1. Display Status");
    printf("\n2. Check Battery");
    printf("\n3. Take Off");
    printf("\n4. Land");
    printf("\n5. Move Left");
    printf("\n6. Move Right");
    printf("\n7. Move Forward");
    printf("\n8. Move Backward");
    printf("\n9. Exit");
}

int select_drone() {
    int drone_id;
    printf("\nEnter drone ID: ");
    scanf("%d", &drone_id);
    return drone_id - 1;
}

void display_status(Drone drone) {
    printf("\nDrone %d Status:", drone.id);
    printf("\nBattery: %d%%", drone.battery);
    printf("\nFlying: %s", drone.is_flying ? "Yes" : "No");
}

void check_battery(Drone *drone) {
    printf("\nDrone %d Battery: %d%%", drone->id, drone->battery);
}

void take_off(Drone *drone) {
    if (drone->is_flying) {
        printf("\nDrone %d is already flying.", drone->id);
    } else {
        drone->is_flying = true;
        printf("\nDrone %d has taken off.", drone->id);
    }
}

void land(Drone *drone) {
    if (drone->is_flying) {
        drone->is_flying = false;
        printf("\nDrone %d has landed.", drone->id);
    } else {
        printf("\nDrone %d is already on the ground.", drone->id);
    }
}

void move_left(Drone *drone) {
    if (drone->is_flying) {
        printf("\nDrone %d moved to the left.", drone->id);
    } else {
        printf("\nDrone %d cannot move left when on the ground.", drone->id);
    }
}

void move_right(Drone *drone) {
    if (drone->is_flying) {
        printf("\nDrone %d moved to the right.", drone->id);
    } else {
        printf("\nDrone %d cannot move right when on the ground.", drone->id);
    }
}

void move_forward(Drone *drone) {
    if (drone->is_flying) {
        printf("\nDrone %d moved forward.", drone->id);
    } else {
        printf("\nDrone %d cannot move forward when on the ground.", drone->id);
    }
}

void move_backward(Drone *drone) {
    if (drone->is_flying) {
        printf("\nDrone %d moved backward.", drone->id);
    } else {
        printf("\nDrone %d cannot move backward when on the ground.", drone->id);
    }
}
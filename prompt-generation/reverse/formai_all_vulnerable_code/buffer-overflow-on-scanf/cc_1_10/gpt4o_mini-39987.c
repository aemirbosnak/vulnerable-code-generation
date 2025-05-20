//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#define MAX_VEHICLES 5

typedef struct {
    int id;
    char type[20];
    int position;
    int speed;
} Vehicle;

typedef struct {
    Vehicle vehicles[MAX_VEHICLES];
    int count;
} Fleet;

void initialize_vehicle(Vehicle *v, int id, const char *type, int position) {
    v->id = id;
    snprintf(v->type, sizeof(v->type), "%s", type);
    v->position = position;
    v->speed = 0;
}

void add_vehicle(Fleet *fleet, const char *type) {
    if (fleet->count >= MAX_VEHICLES) {
        printf("Fleet is full!\n");
        return;
    }
    initialize_vehicle(&fleet->vehicles[fleet->count], fleet->count, type, 0);
    fleet->count++;
}

void display_fleet(const Fleet *fleet) {
    printf("Current Fleet Status:\n");
    for (int i = 0; i < fleet->count; i++) {
        printf("ID: %d, Type: %s, Position: %d, Speed: %d\n",
               fleet->vehicles[i].id, fleet->vehicles[i].type,
               fleet->vehicles[i].position, fleet->vehicles[i].speed);
    }
}

void update_position(Vehicle *v) {
    v->position += v->speed;
}

void accelerate(Vehicle *v, int increment) {
    v->speed += increment;
    if (v->speed < 0) v->speed = 0; // Don't allow negative speed
}

int getch(void) {
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

void control_vehicle(Vehicle *v) {
    char command;
    printf("Controlling Vehicle %d (Type: %s)\n", v->id, v->type);
    while (1) {
        printf("Enter command (w=accelerate, s=decelerate, d=display, q=quit): ");
        command = getch();
        if (command == 'w') {
            accelerate(v, 1);
            printf("Accelerating... Current Speed: %d\n", v->speed);
        } else if (command == 's') {
            accelerate(v, -1);
            printf("Decelerating... Current Speed: %d\n", v->speed);
        } else if (command == 'd') {
            update_position(v);
            display_fleet(v);
        } else if (command == 'q') {
            printf("Exiting control of vehicle %d.\n", v->id);
            break;
        }
        update_position(v);
        sleep(1); // Simulate time passing
    }
}

int main() {
    Fleet myFleet = { .count = 0 };
    char action;
    printf("Remote Control Vehicle Simulation\n");
    printf("==================================\n");

    while (1) {
        printf("Press 'a' to add a vehicle, 'c' to control a vehicle, 'q' to quit: ");
        action = getch();
        if (action == 'a') {
            add_vehicle(&myFleet, "RC Car");
            printf("Vehicle added. Current count: %d\n", myFleet.count);
        } else if (action == 'c') {
            if (myFleet.count == 0) {
                printf("No vehicles available to control.\n");
            } else {
                int id;
                printf("Enter vehicle ID to control (0 to %d): ", myFleet.count - 1);
                scanf("%d", &id);
                if (id >= 0 && id < myFleet.count) {
                    control_vehicle(&myFleet.vehicles[id]);
                } else {
                    printf("Invalid vehicle ID.\n");
                }
            }
        } else if (action == 'q') {
            printf("Exiting simulation.\n");
            break;
        }
    }
    
    return 0;
}
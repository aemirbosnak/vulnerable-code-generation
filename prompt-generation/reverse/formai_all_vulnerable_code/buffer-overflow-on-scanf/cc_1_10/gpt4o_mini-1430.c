//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    char name[30];
    int health;
    int altitude;
    int speed;
} Drone;

void initialize_drone(Drone *drone, const char *name) {
    snprintf(drone->name, sizeof(drone->name), "%s", name);
    drone->health = 100;
    drone->altitude = 0;
    drone->speed = 0;
}

void display_status(const Drone *drone) {
    printf("Behold the drone, %s!\n", drone->name);
    printf("Health: %d\n", drone->health);
    printf("Altitude: %d\n", drone->altitude);
    printf("Speed: %d\n\n", drone->speed);
}

void ascend(Drone *drone, int height) {
    if (drone->health > 0) {
        drone->altitude += height;
        printf("%s doth ascend by %d meters.\n", drone->name, height);
    } else {
        printf("%s cannot ascend, for it is too weak!\n", drone->name);
    }
}

void descend(Drone *drone, int height) {
    if (drone->altitude >= height) {
        drone->altitude -= height;
        printf("%s doth descend by %d meters.\n", drone->name, height);
    } else {
        printf("%s cannot descend further; it squanders in the sky!\n", drone->name);
    }
}

void set_speed(Drone *drone, int speed) {
    if (drone->health > 0) {
        drone->speed = speed;
        printf("%s now doth move at a speed of %d units.\n", drone->name, speed);
    } else {
        printf("%s cannot speed forth; it is worn down!\n", drone->name);
    }
}

void crash(Drone *drone) {
    printf("Alas! %s doth crash to the ground!\n", drone->name);
    drone->health = 0;
}

void repair(Drone *drone) {
    if (drone->health == 0) {
        drone->health = 50; // A gentle wizard's touch revives it
        printf("%s hath been repaired! Health restored to %d!\n", drone->name, drone->health);
    } else {
        printf("%s is already in good health!\n", drone->name);
    }
}

void menu() {
    printf("1. Ascend\n");
    printf("2. Descend\n");
    printf("3. Set Speed\n");
    printf("4. Crash\n");
    printf("5. Repair\n");
    printf("6. Status\n");
    printf("0. Exit\n");
}

int main() {
    Drone my_drone;
    initialize_drone(&my_drone, "Skywing");

    int choice, value;

    while (1) {
        menu();
        printf("Choose thy command: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter height to ascend: ");
                scanf("%d", &value);
                ascend(&my_drone, value);
                break;
            case 2:
                printf("Enter height to descend: ");
                scanf("%d", &value);
                descend(&my_drone, value);
                break;
            case 3:
                printf("Set desired speed: ");
                scanf("%d", &value);
                set_speed(&my_drone, value);
                break;
            case 4:
                crash(&my_drone);
                break;
            case 5:
                repair(&my_drone);
                break;
            case 6:
                display_status(&my_drone);
                break;
            case 0:
                printf("Farewell, brave warrior.\n");
                exit(0);
            default:
                printf("Prithee, choose a valid action.\n");
        }
        sleep(1);
    }

    return 0;
}
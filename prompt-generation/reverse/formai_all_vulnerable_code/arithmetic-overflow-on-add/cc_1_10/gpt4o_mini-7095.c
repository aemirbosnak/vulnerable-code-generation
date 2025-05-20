//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    char name[20];
    int speed; // Speed between 0 to 100
    int battery; // Battery percentage between 0 to 100
} Vehicle;

void displayVehicleStatus(Vehicle *v) {
    if (v->battery <= 0) {
        printf("%s, alas! Thy power is spent, thy journey halted.\n", v->name);
    } else {
        printf("%s doth possess speed of %d and battery of %d.\n", v->name, v->speed, v->battery);
    }
}

void moveVehicle(Vehicle *v, const char *direction) {
    if (v->battery <= 0) {
        printf("%s can go no further, for the battery is drained!\n", v->name);
    } else {
        printf("%s dost move %s with a speed of %d!\n", v->name, direction, v->speed);
        v->battery -= 10; // Drain battery on movement
        if (v->battery < 0) {
            v->battery = 0;
        }
    }
}

void chargeBattery(Vehicle *v) {
    printf("%s doth receive a charge of life!\n", v->name);
    v->battery += 50; // Charge vehicle by 50 percent
    if (v->battery > 100) {
        v->battery = 100;
    }
}

void printMenu() {
    printf("1. Move Forward\n");
    printf("2. Move Backward\n");
    printf("3. Turn Left\n");
    printf("4. Turn Right\n");
    printf("5. Charge Battery\n");
    printf("6. View Status\n");
    printf("7. Exit\n");
}

int main() {
    Vehicle car;
    strcpy(car.name, "Juliet");
    car.speed = 50;
    car.battery = 100;

    int choice;
    
    printf("Enter the name of thine chariot: ");
    scanf("%s", car.name);
    printf("Behold, %s, prince of vehicles!\n\n", car.name);
    
    do {
        printMenu();
        printf("Choose thy action: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                moveVehicle(&car, "forward");
                break;
            case 2:
                moveVehicle(&car, "backward");
                break;
            case 3:
                moveVehicle(&car, "left");
                break;
            case 4:
                moveVehicle(&car, "right");
                break;
            case 5:
                chargeBattery(&car);
                break;
            case 6:
                displayVehicleStatus(&car);
                break;
            case 7:
                printf("Farewell, fledgling adventurer!\n");
                break;
            default:
                printf("Choose wisely, for choices are the cradle of destiny!\n");
                break;
        }
        sleep(1); // Simulate a brief pause between actions
    } while (choice != 7);

    return 0;
}
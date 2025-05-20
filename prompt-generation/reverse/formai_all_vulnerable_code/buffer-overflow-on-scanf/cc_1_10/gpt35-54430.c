//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: interoperable
#include <stdio.h>

#define MAX_SPEED 100
#define MIN_SPEED 0

int speed = 0;
int batteryLevel = 100;
int distanceCovered = 0;

void printStatus() {
    printf("\nCurrent Speed: %d", speed);
    printf("\nBattery Level: %d", batteryLevel);
    printf("\nDistance Covered: %d\n", distanceCovered);
}

void accelerate() {
    if(speed == MAX_SPEED) {
        printf("Cannot accelerate further. Max speed reached.\n");
    } else {
        speed += 10;
        batteryLevel--;
        distanceCovered++;
        printf("Accelerating...\n");
    }
    printStatus();
}

void decelerate() {
    if(speed == MIN_SPEED) {
        printf("Cannot decelerate further. Already at minimum speed.\n");
    } else {
        speed -= 10;
        batteryLevel--;
        distanceCovered++;
        printf("Decelerating...\n");
    }
    printStatus();
}

void recharge() {
    batteryLevel = 100;
    printf("Recharging...\n");
    printStatus();
}

int main() {
    int choice;
    while(1) {
        printf("\n1. Accelerate\n2. Decelerate\n3. Recharge\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                accelerate();
                break;
            case 2:
                decelerate();
                break;
            case 3:
                recharge();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
}
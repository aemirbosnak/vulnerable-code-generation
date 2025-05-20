//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: creative
#include<stdio.h>

int distance = 0;
int battery = 100;
int speed = 0;

void moveForward() {
    if (battery <= 0) {
        printf("Battery low. Please recharge.\n");
        return;
    }
    if (distance > 999) {
        printf("Reached maximum distance limit.\n");
        return;
    }
    speed += 10;
    battery -= 5;
    distance += speed;
}

void moveBackward() {
    if (battery <= 0) {
        printf("Battery low. Please recharge.\n");
        return;
    }
    if (distance <= 0) {
        printf("Already at starting position.\n");
        return;
    }
    speed -= 5;
    battery -= 5;
    distance += speed;
}

void brake() {
    if (speed <= 0) {
        printf("Vehicle already stopped.\n");
        return;
    }
    speed = 0;
    printf("Vehicle stopped.\n");
}

void recharge(int amount) {
    battery += amount;
    if (battery > 100) {
        battery = 100;
        printf("Battery fully charged.\n");
    } else {
        printf("Battery partially charged.\n");
    }
}

void printStatus() {
    printf("Distance: %d\n", distance);
    printf("Current speed: %d\n", speed);
    printf("Battery: %d%%\n", battery);
}

int main() {
    printf("Starting remote control vehicle simulation.\n");
    printf("Enter a command: forward, backward, brake, recharge, status.\n");
    char input[10];
    while(1) {
        scanf("%s", input);
        if (strcmp(input, "forward") == 0) {
            moveForward();
        } else if (strcmp(input, "backward") == 0) {
            moveBackward();
        } else if (strcmp(input, "brake") == 0) {
            brake();
        } else if (strcmp(input, "recharge") == 0) {
            printf("Enter recharge amount: ");
            int amount;
            scanf("%d", &amount);
            recharge(amount);
        } else if (strcmp(input, "status") == 0) {
            printStatus();
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

struct Vehicle {
    int speed;
    int direction;
};

void setSpeed(struct Vehicle *veh, int speed) {
    veh->speed = speed;
}

void setDirection(struct Vehicle *veh, int direction) {
    veh->direction = direction;
}

void simulateRemoteControl(struct Vehicle *veh) {
    int choice, value;
    
    printf("Enter 1 to set Speed and 2 to set Direction\n");
    scanf("%d", &choice);
    
    if(choice == 1) {
        printf("Enter the speed: ");
        scanf("%d", &value);
        setSpeed(veh, value);
    }
    else if(choice == 2) {
        printf("Enter the direction (0 for Left and 1 for Right): ");
        scanf("%d", &value);
        setDirection(veh, value);
    }
    else {
        printf("Invalid choice!");
    }
}

int main() {
    struct Vehicle veh = {0, 0}; // initial speed and direction are 0
    
    while(1) { // infinite loop to keep simulating remote control
        simulateRemoteControl(&veh);
        
        printf("Current Speed: %d\n", veh.speed);
        if(veh.direction == 0) {
            printf("Current direction: Left\n");
        }
        else {
            printf("Current direction: Right\n");
        }
    }
    
    return 0;
}
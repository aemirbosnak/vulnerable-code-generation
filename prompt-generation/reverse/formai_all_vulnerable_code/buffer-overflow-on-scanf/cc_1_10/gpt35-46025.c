//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// data structures for the drone and remote control
typedef struct {
    int id;
    int battery;
    int altitude;
    int speed;
} Drone;

typedef struct {
    int up;
    int down;
    int left;
    int right;
} RemoteControl;

// function prototypes
void printDroneStats(Drone *drone);
void moveDrone(Drone *drone, RemoteControl *remote);

int main() {
    // creating a drone and remote control instance
    Drone drone1 = {1, 100, 0, 0};
    RemoteControl remote1 = {0, 0, 0, 0};

    // main loop for the program
    while (1) {
        // printing the current drone stats
        printDroneStats(&drone1);

        // getting input from the remote control
        printf("Enter 1 to go up, -1 to go down, 2 to go left, 3 to go right: ");
        scanf("%d", &remote1.up);
        scanf("%d", &remote1.down);
        scanf("%d", &remote1.left);
        scanf("%d", &remote1.right);

        // moving the drone according to the input
        moveDrone(&drone1, &remote1);
    }

    return 0;
}

// function to print the drone stats
void printDroneStats(Drone *drone) {
    printf("Drone ID: %d\n", drone->id);
    printf("Battery: %d%%\n", drone->battery);
    printf("Altitude: %d meters\n", drone->altitude);
    printf("Speed: %d m/s\n", drone->speed);
}

// function to move the drone based on input
void moveDrone(Drone *drone, RemoteControl *remote) {
    if (remote->up == 1 && drone->battery > 10) {
        drone->altitude += 10;
        drone->battery -= 10;
        drone->speed = 5;
    } else if (remote->down == -1) {
        drone->altitude -= 10;
        drone->speed = 5;
    } else if (remote->left == 2) {
        drone->speed = 10;
    } else if (remote->right == 3) {
        drone->speed = 10;
    } else {
        drone->speed = 0;
    }

    // checking if the drone has run out of battery
    if (drone->battery <= 0) {
        printf("Drone has run out of battery!\n");
        exit(0);
    }
}
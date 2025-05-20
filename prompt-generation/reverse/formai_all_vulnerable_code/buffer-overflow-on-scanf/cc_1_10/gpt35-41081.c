//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_DRONES 20
#define MAX_SPEED 100

typedef struct {
    int drone_id;
    int x_pos;
    int y_pos;
    int altitude;
    int speed;
} Drone;

void initiate(Drone drones[], int num_drones) {
    int i;
    for(i=0; i<num_drones; ++i) {
        drones[i].drone_id = i;
        drones[i].x_pos = 0;
        drones[i].y_pos = 0;
        drones[i].altitude = 0;
        drones[i].speed = 0;
    }
}

void takeoff(Drone * drone, int altitude, int speed) {
    drone->altitude = altitude;
    drone->speed = speed;
}

void move(Drone * drone, int x, int y) {
    drone->x_pos += x;
    drone->y_pos += y;
}

void land(Drone * drone) {
    drone->altitude = 0;
    drone->speed = 0;
}

int main() {
    int num_drones;
    printf("Enter the number of drones to simulate: ");
    scanf("%d", &num_drones);
    
    Drone drones[MAX_DRONES];
    initiate(drones, num_drones);
    
    int i, cmd, drone_id, altitude, speed, x, y;
    while(1) {
        printf("\nEnter the command (0:Exit, 1:Takeoff, 2:Move, 3:Land): ");
        scanf("%d", &cmd);
        
        if(cmd==0) break;
        
        printf("Enter the drone ID: ");
        scanf("%d", &drone_id);
        
        if(drone_id<0 || drone_id>=num_drones) {
            printf("Invalid drone ID! Try again.\n");
            continue;
        }
        
        switch(cmd) {
            case 1:
                printf("Enter the altitude: ");
                scanf("%d", &altitude);
                printf("Enter the speed: ");
                scanf("%d", &speed);
                
                if(speed>MAX_SPEED) {
                    printf("Speed is too high! Denying takeoff.\n");
                } else {
                    takeoff(&drones[drone_id], altitude, speed);
                    printf("Drone %d is now in the air at altitude %d and speed %d.\n", drone_id, altitude, speed);
                }
                break;
            case 2:
                printf("Enter the x movement: ");
                scanf("%d", &x);
                printf("Enter the y movement: ");
                scanf("%d", &y);
                move(&drones[drone_id], x, y);
                printf("Drone %d moved to position (%d,%d).\n", drone_id, drones[drone_id].x_pos, drones[drone_id].y_pos);
                break;
            case 3:
                land(&drones[drone_id]);
                printf("Drone %d landed safely.\n", drone_id);
                break;
            default:
                printf("Invalid command! Try again.\n");
                break;
        }
    }
    
    return 0;
}
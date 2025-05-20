//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define NUM_DRONES 5
#define NUM_COMMANDS 4

typedef struct {
    char name[20];
    int x, y, z;
    int battery;
} Drone;

void fly(Drone* drone, int dx, int dy, int dz) {
    printf("Drone %s is flying to (%d, %d, %d)\n", drone->name, drone->x + dx, drone->y + dy, drone->z + dz);
}

void takePicture(Drone* drone) {
    printf("Drone %s is taking a picture!\n", drone->name);
}

void land(Drone* drone) {
    printf("Drone %s is landing.\n", drone->name);
}

void emergencyLand(Drone* drone) {
    printf("Drone %s is making an emergency landing!\n", drone->name);
}

int main() {
    Drone drones[NUM_DRONES];
    for (int i = 0; i < NUM_DRONES; i++) {
        drones[i].name[0] = 'D' + i;
        drones[i].name[19] = '\0';
        drones[i].x = i * 10;
        drones[i].y = i * 20;
        drones[i].z = i * 30;
        drones[i].battery = 100;
    }

    int choice;
    do {
        printf("Choose a command:\n");
        printf("1. Fly\n2. Take picture\n3. Land\n4. Emergency land\n");
        scanf("%d", &choice);

        char droneName[21];
        printf("Enter drone name (D1, D2,...): ");
        scanf("%s", droneName);

        int dx, dy, dz;
        switch (choice) {
            case 1:
                printf("Enter destination coordinates (x, y, z): ");
                scanf("%d %d %d", &dx, &dy, &dz);
                for (int i = 0; i < NUM_DRONES; i++) {
                    if (strcmp(droneName, drones[i].name) == 0) {
                        fly(&drones[i], dx, dy, dz);
                        break;
                    }
                }
                break;
            case 2:
                for (int i = 0; i < NUM_DRONES; i++) {
                    if (strcmp(droneName, drones[i].name) == 0) {
                        takePicture(&drones[i]);
                        break;
                    }
                }
                break;
            case 3:
                for (int i = 0; i < NUM_DRONES; i++) {
                    if (strcmp(droneName, drones[i].name) == 0) {
                        land(&drones[i]);
                        break;
                    }
                }
                break;
            case 4:
                for (int i = 0; i < NUM_DRONES; i++) {
                    if (strcmp(droneName, drones[i].name) == 0) {
                        emergencyLand(&drones[i]);
                        break;
                    }
                }
                break;
            default:
                printf("Invalid command.\n");
        }
    } while (choice!= 0);

    return 0;
}
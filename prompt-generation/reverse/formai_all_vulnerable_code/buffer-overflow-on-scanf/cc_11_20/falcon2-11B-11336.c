//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_OF_VEHICLES 5

struct vehicle {
    char vehicle_name[50];
    int current_speed;
};

struct vehicle vehicles[MAX_NUM_OF_VEHICLES];

int main(int argc, char *argv[]) {
    // Initialize vehicles
    strcpy(vehicles[0].vehicle_name, "Car1");
    vehicles[0].current_speed = 0;
    strcpy(vehicles[1].vehicle_name, "Car2");
    vehicles[1].current_speed = 0;
    strcpy(vehicles[2].vehicle_name, "Car3");
    vehicles[2].current_speed = 0;
    strcpy(vehicles[3].vehicle_name, "Car4");
    vehicles[3].current_speed = 0;
    strcpy(vehicles[4].vehicle_name, "Car5");
    vehicles[4].current_speed = 0;

    // Control each vehicle
    printf("Press 1 to accelerate\n");
    printf("Press 2 to decelerate\n");
    printf("Press 3 to turn left\n");
    printf("Press 4 to turn right\n");
    printf("Press 0 to stop\n");

    while(1) {
        printf("\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);

        if(choice == 1) {
            for(int i = 0; i < MAX_NUM_OF_VEHICLES; i++) {
                vehicles[i].current_speed++;
            }
        }
        else if(choice == 2) {
            for(int i = 0; i < MAX_NUM_OF_VEHICLES; i++) {
                vehicles[i].current_speed--;
            }
        }
        else if(choice == 3) {
            for(int i = 0; i < MAX_NUM_OF_VEHICLES; i++) {
                strcpy(vehicles[i].vehicle_name, "Car1");
            }
        }
        else if(choice == 4) {
            for(int i = 0; i < MAX_NUM_OF_VEHICLES; i++) {
                strcpy(vehicles[i].vehicle_name, "Car2");
            }
        }
        else if(choice == 0) {
            for(int i = 0; i < MAX_NUM_OF_VEHICLES; i++) {
                vehicles[i].current_speed = 0;
            }
        }
        else {
            printf("Invalid choice!\n");
        }

        for(int i = 0; i < MAX_NUM_OF_VEHICLES; i++) {
            printf("Vehicle %d - Speed: %d\n", i+1, vehicles[i].current_speed);
        }
    }

    return 0;
}
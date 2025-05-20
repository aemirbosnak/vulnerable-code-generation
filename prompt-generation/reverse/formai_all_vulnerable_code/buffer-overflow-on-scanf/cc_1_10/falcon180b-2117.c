//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3
#define PED_CROSS 4
#define PED_WAIT 5

int light = GREEN;
int ped_light = PED_WAIT;
int count = 0;

void change_light() {
    if(light == GREEN) {
        light = YELLOW;
        printf("Light changed to YELLOW!\n");
    } else if(light == YELLOW) {
        light = RED;
        printf("Light changed to RED!\n");
    } else if(light == RED) {
        light = GREEN;
        printf("Light changed to GREEN!\n");
    }
}

void cross_pedestrian() {
    if(ped_light == PED_WAIT) {
        ped_light = PED_CROSS;
        printf("Pedestrians can now cross!\n");
    } else if(ped_light == PED_CROSS) {
        ped_light = PED_WAIT;
        printf("Pedestrians must wait!\n");
    }
}

void main() {
    srand(time(NULL));
    int choice;

    while(1) {
        printf("Current light status: ");
        if(light == GREEN) {
            printf("GREEN\n");
        } else if(light == YELLOW) {
            printf("YELLOW\n");
        } else if(light == RED) {
            printf("RED\n");
        }

        printf("Current pedestrian light status: ");
        if(ped_light == PED_WAIT) {
            printf("PEDESTRIANS WAIT\n");
        } else if(ped_light == PED_CROSS) {
            printf("PEDESTRIANS CROSS\n");
        }

        printf("Press 1 to change the light\n");
        printf("Press 2 to allow pedestrians to cross\n");
        printf("Press 3 to exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                change_light();
                break;
            case 2:
                cross_pedestrian();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }

        count++;
        if(count == 10) {
            light = GREEN;
            ped_light = PED_WAIT;
            count = 0;
        }
    }
}
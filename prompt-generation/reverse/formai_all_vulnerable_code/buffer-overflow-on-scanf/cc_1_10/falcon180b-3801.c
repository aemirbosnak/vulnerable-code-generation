//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TIME 1000000000 // 1 billion seconds

typedef struct {
    int time;
    int energy;
    int location;
    int status;
} TimeTraveler;

void init_traveler(TimeTraveler *tt) {
    tt->time = 0;
    tt->energy = 100;
    tt->location = 0;
    tt->status = 0;
}

void display_time(int time) {
    int hours = time / 3600;
    int minutes = (time % 3600) / 60;
    int seconds = time % 60;

    printf("%02d:%02d:%02d\n", hours, minutes, seconds);
}

void display_status(int status) {
    if (status == 0) {
        printf("You are in the present.\n");
    } else if (status == 1) {
        printf("You are in the past.\n");
    } else if (status == 2) {
        printf("You are in the future.\n");
    }
}

void display_menu() {
    printf("Time Travel Menu:\n");
    printf("1. Travel to the past\n");
    printf("2. Travel to the future\n");
    printf("3. Display current time\n");
    printf("4. Display current status\n");
    printf("5. Display energy level\n");
    printf("6. Quit\n");
}

int main() {
    srand(time(NULL));
    TimeTraveler tt;
    init_traveler(&tt);

    int choice;
    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (tt.energy >= 50) {
                    tt.time -= rand() % 100000;
                    tt.energy -= 50;
                    display_time(tt.time);
                    display_status(1);
                } else {
                    printf("Not enough energy to travel to the past.\n");
                }
                break;
            case 2:
                if (tt.energy >= 100) {
                    tt.time += rand() % 100000;
                    tt.energy -= 100;
                    display_time(tt.time);
                    display_status(2);
                } else {
                    printf("Not enough energy to travel to the future.\n");
                }
                break;
            case 3:
                display_time(tt.time);
                break;
            case 4:
                display_status(tt.status);
                break;
            case 5:
                printf("Energy level: %d\n", tt.energy);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 6);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT_DURATION 10
#define YELLOW_LIGHT_DURATION 5
#define GREEN_LIGHT_DURATION 15
#define CROSSWALK_DURATION 5
#define TOTAL_DURATION (RED_LIGHT_DURATION + YELLOW_LIGHT_DURATION + GREEN_LIGHT_DURATION + CROSSWALK_DURATION)

void traffic_light_controller() {
    int red_light_count = 0;
    int yellow_light_count = 0;
    int green_light_count = 0;
    int crosswalk_count = 0;

    while (1) {
        printf("Traffic Light Controller\n");
        printf("-------------------------\n");
        printf("Red light is on...\n");
        fflush(stdout);
        sleep(RED_LIGHT_DURATION);

        printf("Yellow light is on...\n");
        fflush(stdout);
        sleep(YELLOW_LIGHT_DURATION);

        printf("Green light is on...\n");
        fflush(stdout);
        sleep(GREEN_LIGHT_DURATION);

        printf("Crosswalk is on...\n");
        fflush(stdout);
        sleep(CROSSWALK_DURATION);

        red_light_count++;
        yellow_light_count++;
        green_light_count++;
        crosswalk_count++;

        if (red_light_count == 2) {
            printf("Red light is off...\n");
            fflush(stdout);
            red_light_count = 0;
        }

        if (yellow_light_count == 1) {
            printf("Yellow light is off...\n");
            fflush(stdout);
            yellow_light_count = 0;
        }

        if (green_light_count == 2) {
            printf("Green light is off...\n");
            fflush(stdout);
            green_light_count = 0;
        }

        if (crosswalk_count == 1) {
            printf("Crosswalk is off...\n");
            fflush(stdout);
            crosswalk_count = 0;
        }
    }
}

int main() {
    srand(time(NULL));

    int choice;

    printf("Welcome to the Traffic Light Controller!\n");
    printf("Press 1 to start the controller\n");
    printf("Press 2 to exit\n");
    scanf("%d", &choice);

    if (choice == 1) {
        traffic_light_controller();
    }

    return 0;
}
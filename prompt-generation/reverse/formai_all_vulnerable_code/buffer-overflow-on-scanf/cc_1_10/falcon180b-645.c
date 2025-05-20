//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#define RED "red"
#define YELLOW "yellow"
#define GREEN "green"

#define LIGHT_INTERVAL 5
#define PEDESTRIAN_INTERVAL 20

void traffic_light(char* direction, int duration) {
    switch(*direction) {
        case 'N': // North
            printf("Traffic light for North is now %s for %d seconds\n", RED, duration);
            break;
        case 'S': // South
            printf("Traffic light for South is now %s for %d seconds\n", RED, duration);
            break;
        case 'E': // East
            printf("Traffic light for East is now %s for %d seconds\n", RED, duration);
            break;
        case 'W': // West
            printf("Traffic light for West is now %s for %d seconds\n", RED, duration);
            break;
    }
    sleep(duration);
    printf("Traffic light for %s is now %s\n", direction, GREEN);
}

void pedestrian_light(char* direction, int duration) {
    switch(*direction) {
        case 'N': // North
            printf("Pedestrian light for North is now %s for %d seconds\n", YELLOW, duration);
            break;
        case 'S': // South
            printf("Pedestrian light for South is now %s for %d seconds\n", YELLOW, duration);
            break;
        case 'E': // East
            printf("Pedestrian light for East is now %s for %d seconds\n", YELLOW, duration);
            break;
        case 'W': // West
            printf("Pedestrian light for West is now %s for %d seconds\n", YELLOW, duration);
            break;
    }
    sleep(duration);
    printf("Pedestrian light for %s is now %s\n", direction, GREEN);
}

int main() {
    char direction;
    int duration;

    while(1) {
        printf("Enter direction (N/S/E/W): ");
        scanf("%c", &direction);

        printf("Enter duration in seconds: ");
        scanf("%d", &duration);

        if(direction == 'N' || direction == 'S' || direction == 'E' || direction == 'W') {
            traffic_light(&direction, duration);
        } else {
            printf("Invalid direction\n");
        }
    }

    return 0;
}
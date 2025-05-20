//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

#define RED_LIGHT "red_light.txt"
#define YELLOW_LIGHT "yellow_light.txt"
#define GREEN_LIGHT "green_light.txt"

int main() {
    FILE *red_light, *yellow_light, *green_light;
    int state = RED;

    red_light = fopen(RED_LIGHT, "w");
    yellow_light = fopen(YELLOW_LIGHT, "w");
    green_light = fopen(GREEN_LIGHT, "w");

    if (red_light == NULL || yellow_light == NULL || green_light == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    srand(time(NULL));
    int duration = rand() % 10 + 1;
    printf("Initial duration: %d seconds\n", duration);

    while (1) {
        switch (state) {
            case RED:
                fprintf(red_light, "on\n");
                fprintf(yellow_light, "off\n");
                fprintf(green_light, "off\n");
                printf("Red light is on.\n");
                break;
            case YELLOW:
                fprintf(red_light, "off\n");
                fprintf(yellow_light, "on\n");
                fprintf(green_light, "off\n");
                printf("Yellow light is on.\n");
                break;
            case GREEN:
                fprintf(red_light, "off\n");
                fprintf(yellow_light, "off\n");
                fprintf(green_light, "on\n");
                printf("Green light is on.\n");
                break;
        }

        fflush(stdout);
        fflush(red_light);
        fflush(yellow_light);
        fflush(green_light);

        sleep(duration);

        switch (state) {
            case RED:
                state = YELLOW;
                duration = rand() % 10 + 1;
                printf("Switching to yellow light for %d seconds.\n", duration);
                break;
            case YELLOW:
                state = GREEN;
                duration = rand() % 10 + 1;
                printf("Switching to green light for %d seconds.\n", duration);
                break;
            case GREEN:
                state = RED;
                duration = rand() % 10 + 1;
                printf("Switching to red light for %d seconds.\n", duration);
                break;
        }
    }

    return 0;
}
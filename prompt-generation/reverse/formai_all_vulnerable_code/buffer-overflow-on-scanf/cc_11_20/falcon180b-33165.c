//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TIME 1000000
#define TIME_INCREMENT 1000

int main() {
    int time_travel_count = 0;
    int current_time = 0;
    int destination_time = 0;
    int choice;

    srand(time(NULL));

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("You have the ability to travel through time, but be careful not to alter history.\n");

    do {
        printf("\nCurrent time: %d\n", current_time);
        printf("Enter your destination time (0 to exit): ");
        scanf("%d", &destination_time);

        if (destination_time == 0) {
            printf("Exiting time travel simulator.\n");
            break;
        }

        if (destination_time < current_time) {
            printf("You cannot travel back in time.\n");
        } else if (destination_time > current_time + (MAX_TIME - current_time)) {
            printf("You cannot travel too far into the future.\n");
        } else {
            printf("Traveling to %d...\n", destination_time);
            for (int i = current_time + 1; i <= destination_time; i++) {
                printf("%d: ", i);
                if (i % TIME_INCREMENT == 0) {
                    int event = rand() % 4;
                    switch (event) {
                        case 0:
                            printf("You witness a historical event.\n");
                            break;
                        case 1:
                            printf("You meet a famous person from history.\n");
                            break;
                        case 2:
                            printf("You accidentally change a small detail in history.\n");
                            break;
                        case 3:
                            printf("You narrowly avoid altering a major historical event.\n");
                            break;
                    }
                }
            }
            current_time = destination_time;
            time_travel_count++;
        }
    } while (1);

    printf("\nYou have traveled through time %d times.\n", time_travel_count);

    return 0;
}
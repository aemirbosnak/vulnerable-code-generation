//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3
#define PEDESTRIAN 4

#define TIME_RED 10
#define TIME_YELLOW 3
#define TIME_GREEN 15
#define TIME_PEDESTRIAN 10

int main() {
    int state = RED;
    int counter = 0;
    int pedestrian_counter = 0;
    int start_time = time(NULL);

    while(1) {
        counter++;

        if(counter >= TIME_RED) {
            state = YELLOW;
            counter = 0;
        }

        if(counter >= TIME_YELLOW) {
            state = GREEN;
            counter = 0;
        }

        if(counter >= TIME_GREEN) {
            state = RED;
            counter = 0;
        }

        if(state == RED) {
            printf("Traffic light is red\n");
        }
        else if(state == YELLOW) {
            printf("Traffic light is yellow\n");
        }
        else if(state == GREEN) {
            printf("Traffic light is green\n");
        }
        else if(state == PEDESTRIAN) {
            printf("Pedestrian crossing\n");
        }

        if(state == PEDESTRIAN) {
            pedestrian_counter++;

            if(pedestrian_counter >= TIME_PEDESTRIAN) {
                state = RED;
                pedestrian_counter = 0;
            }
        }

        if(state == RED) {
            printf("Press enter to cross\n");
            char ch;
            scanf("%c", &ch);

            if(ch == '\n') {
                state = PEDESTRIAN;
                pedestrian_counter = 0;
            }
        }

        sleep(1);
    }

    return 0;
}
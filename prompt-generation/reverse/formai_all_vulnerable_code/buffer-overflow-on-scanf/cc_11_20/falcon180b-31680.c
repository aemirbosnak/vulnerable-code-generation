//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

#define TIME_RED 10 // seconds
#define TIME_YELLOW 3 // seconds
#define TIME_GREEN 15 // seconds

int main() {
    int state = RED;
    int timer = 0;
    char input;

    do {
        system("clear");
        printf("Enter a command:\n");
        printf("p - Pedestrian crossing\n");
        printf("c - Change the state\n");
        printf("q - Quit\n");
        scanf("%c", &input);

        switch(input) {
            case 'p':
                printf("Pedestrians are crossing...\n");
                state = RED;
                break;
            case 'c':
                printf("Enter the new state (0-2): ");
                scanf("%d", &state);
                printf("The new state is %d.\n", state);
                break;
            case 'q':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid command.\n");
        }

        switch(state) {
            case RED:
                printf("The traffic light is red.\n");
                break;
            case YELLOW:
                printf("The traffic light is yellow.\n");
                break;
            case GREEN:
                printf("The traffic light is green.\n");
                break;
            default:
                printf("Invalid state.\n");
        }

        timer++;

        if(timer == TIME_RED) {
            state = YELLOW;
            timer = 0;
        } else if(timer == TIME_YELLOW) {
            state = GREEN;
            timer = 0;
        } else if(timer == TIME_GREEN + TIME_YELLOW) {
            state = RED;
            timer = 0;
        }

        sleep(1);

    } while(state!= 0);

    return 0;
}
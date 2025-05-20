//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char command;
    int battery = 100;
    float distance = 0;
    srand(time(NULL));
    printf("Welcome to Remote Control Vehicle Simulation\n");
    printf("Please enter a command (F/R/B/L) to move the vehicle:\n");

    while(1) {
        printf("Battery Level: %d Distance Travelled: %.2f m\n", battery, distance);
        scanf(" %c", &command);
        switch(command) {
            case 'F':
                if(battery >= 5) {
                    int move = rand() % 10 + 1;
                    printf("Moving Forward %d meters...\n", move);
                    distance += move;
                    battery -= 5;
                }
                else {
                    printf("Battery is too low to move forward.\n");
                }
                break;
            case 'R':
                if(battery >= 10) {
                    int move = rand() % 20 + 1;
                    printf("Moving Right %d meters...\n", move);
                    distance += move;
                    battery -= 10;
                }
                else {
                    printf("Battery is too low to move right.\n");
                }
                break;
            case 'B':
                if(battery >= 5) {
                    int move = rand() % 10 + 1;
                    printf("Moving Backward %d meters...\n", move);
                    distance -= move;
                    battery -= 5;
                }
                else {
                    printf("Battery is too low to move backward.\n");
                }
                break;
            case 'L':
                if(battery >= 10) {
                    int move = rand() % 20 + 1;
                    printf("Moving Left %d meters...\n", move);
                    distance -= move;
                    battery -= 10;
                }
                else {
                    printf("Battery is too low to move left.\n");
                }
                break;
            default:
                printf("Invalid command, please try again.\n");
        }
        if(distance >= 50) {
                printf("Congratulations, you have reached your destination!\n");
                break;
        }
        if(battery <= 0) {
                printf("Battery is dead, game over.\n");
                break;
        }
    }
    return 0;
}
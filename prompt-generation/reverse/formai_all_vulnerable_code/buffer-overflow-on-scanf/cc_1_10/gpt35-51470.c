//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int check_battery_level(int level) {
    if(level>=50) {
        printf("Battery level: %d%%\n", level);
        return 1;
    } else {
        printf("Battery level too low: %d%%\n", level);
        return 0;
    }
}

int main() {
    int battery_level = 100;
    int is_battery_good = check_battery_level(battery_level);
    if(is_battery_good) {
        printf("You are good to go!\n");
    } else {
        printf("Charge your drone first!\n");
        return 0;
    }
    printf("Enter commands (use WASD to move):\n");
    char command;
    while(1) {
        scanf("%c", &command);
        switch(command) {
            case 'W':
                printf("Moving forward\n");
                break;
            case 'A':
                printf("Moving left\n");
                break;
            case 'S':
                printf("Moving back\n");
                break;
            case 'D':
                printf("Moving right\n");
                break;
            case 'Q':
                printf("Exiting program\n");
                exit(0);
            case 'Z':
                printf("Auto-piloting\n");
                break;
            default:
                printf("Invalid command\n");
                break;
        }
    }
    return 0;
}
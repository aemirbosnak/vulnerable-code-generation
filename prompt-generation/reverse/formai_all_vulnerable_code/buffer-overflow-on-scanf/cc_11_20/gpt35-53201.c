//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: happy
#include <stdio.h>

int main() {
    int battery_life = 100;
    int altitude = 0;
    int speed = 0;
    char command;
    
    printf("Welcome to the happy drone remote control program!\n");
    printf("You can control your drone by entering the following commands:\n");
    printf("w - increase speed\n");
    printf("s - decrease speed\n");
    printf("a - move left\n");
    printf("d - move right\n");
    printf("q - move up\n");
    printf("z - move down\n");
    printf("x - stop\n");
    printf("b - check battery level\n");
    printf("e - exit program\n");
    
    while (1) {
        printf("Enter a command: ");
        scanf(" %c", &command);
        
        switch (command) {
            case 'w':
                speed += 10;
                printf("Speed is now %d\n", speed);
                break;
            case 's':
                speed -= 10;
                printf("Speed is now %d\n", speed);
                break;
            case 'a':
                printf("Moving left...\n");
                break;
            case 'd':
                printf("Moving right...\n");
                break;
            case 'q':
                altitude += 10;
                printf("Altitude is now %d\n", altitude);
                break;
            case 'z':
                altitude -= 10;
                printf("Altitude is now %d\n", altitude);
                break;
            case 'x':
                printf("Stopping drone...\n");
                speed = 0;
                break;
            case 'b':
                printf("Battery level: %d\n", battery_life);
                break;
            case 'e':
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid command. Please try again.\n");
        }
        
        if (altitude < 0) {
            printf("Warning: Drone is crashing!\n");
            altitude = 0;
        }
        
        if (battery_life <= 20) {
            printf("Warning: Battery level is low!\n");
        }
        
        battery_life -= speed / 10;
        if (battery_life <= 0) {
            printf("Battery drained, drone crashed!\n");
            return 0;
        }
    }
}
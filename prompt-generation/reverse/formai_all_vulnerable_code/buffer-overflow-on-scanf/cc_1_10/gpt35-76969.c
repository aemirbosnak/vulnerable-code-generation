//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    printf("Welcome to the C Drone Remote Control!\n\n");
    
    char command[50];
    int times = 0;
    int height = 0;
    int battery = 100;
    
    printf("Please enter the initial height (in meters): ");
    scanf("%d", &height);
    printf("The drone starts at %d meters.\n", height);
    printf("The battery is at %d%%.\n\n", battery);
    
    while (strcmp(command, "exit")) {
        printf("Please enter a command (up, down, left, right, land, battery, print, exit): ");
        scanf("%s", command);
        
        if (!strcmp(command, "up")) {
            printf("Moving the drone up!\n");
            height += 10;
            printf("The drone is now at %d meters.\n", height);
            battery -= 2;
            printf("The battery is now at %d%%.\n\n", battery);
        } else if (!strcmp(command, "down")) {
            printf("Moving the drone down!\n");
            height -= 10;
            printf("The drone is now at %d meters.\n", height);
            battery -= 2;
            printf("The battery is now at %d%%.\n\n", battery);
        } else if (!strcmp(command, "left")) {
            printf("Moving the drone left!\n");
            times++;
            printf("The drone has moved left %d times.\n", times);
            battery -= 1;
            printf("The battery is now at %d%%.\n\n", battery);
        } else if (!strcmp(command, "right")) {
            printf("Moving the drone right!\n");
            times++;
            printf("The drone has moved right %d times.\n", times);
            battery -= 1;
            printf("The battery is now at %d%%.\n\n", battery);
        } else if (!strcmp(command, "land")) {
            printf("Landing the drone!\n");
            height = 0;
            printf("The drone is now at %d meters.\n", height);
            battery -= 10;
            printf("The battery is now at %d%%.\n\n", battery);
        } else if (!strcmp(command, "battery")) {
            printf("Checking the battery!\n");
            printf("The battery is at %d%%.\n\n", battery);
        } else if (!strcmp(command, "print")) {
            printf("Printing the status!\n");
            printf("The drone is at %d meters.\n", height);
            printf("The drone has moved left %d times and right %d times.\n", times/2, times/2);
            printf("The battery is at %d%%.\n\n", battery);
        } else if (!strcmp(command, "exit")) {
            printf("Exiting the program!");
        } else {
            printf("Invalid command! Please try again.\n\n");
        }
    }
    
    return 0;
}
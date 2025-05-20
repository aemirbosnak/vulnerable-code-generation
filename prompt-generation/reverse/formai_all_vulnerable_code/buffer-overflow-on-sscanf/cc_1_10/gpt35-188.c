//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[50];
    char command[20];
    int distance;
    int altitude;
    int battery = 100;
    int signal = 100;
    
    printf("Welcome to the C Drone Remote Control Program! \n");
    printf("Please enter your commands below: \n");
    
    while(1) {
        printf("\n>>> ");
        fgets(input, 50, stdin);
        sscanf(input, "%s %d %d", command, &distance, &altitude);
        
        if(strcmp(command, "takeoff") == 0) {
            printf("Taking off to altitude %d meters... \n", altitude);
            battery -= 10;
            signal -= 5;
        }
        else if(strcmp(command, "land") == 0) {
            printf("Landing... \n");
            battery -= 10;
            signal -= 5;
            break;
        }
        else if(strcmp(command, "move") == 0) {
            printf("Moving %d meters forward... \n", distance);
            battery -= 5;
            signal -= 2;
        }
        else if(strcmp(command, "turn") == 0) {
            printf("Turning %d degrees... \n", distance);
            battery -= 5;
            signal -= 2;
        }
        else {
            printf("Invalid command. Please try again. \n");
        }
        
        printf("Battery level: %d%% \n", battery);
        printf("Signal strength: %d%% \n", signal);
        
        if(battery <= 0 || signal <= 0) {
            printf("Warning: Low battery or signal strength. Returning to home base... \n");
            break;
        }
    }
    
    printf("Thank you for using the C Drone Remote Control Program! \n");
    return 0;
}
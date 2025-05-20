//FormAI DATASET v1.0 Category: Smart home light control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    bool lightOn = false;
    int time = 0;
    
    while(true) {
        printf("Enter 1 to turn the light on, Enter 0 to turn it off: \n");
        int choice = 0;
        scanf("%d", &choice);
        
        if(choice == 1) {
            if(lightOn) {
                printf("The light is already on! \n");
            } else {
                printf("Turning the light on... \n");
                lightOn = true;
            }
        } else if(choice == 0) {
            if(!lightOn) {
                printf("The light is already off! \n");
            } else {
                printf("Turning the light off... \n");
                lightOn = false;
            }
        } else {
            printf("Invalid choice! \n");
        }

        printf("Enter the time in seconds for which you want to keep the light on (0 if you want to turn it off): \n");
        scanf("%d", &time);

        if(time < 0) {
            printf("Invalid time! \n");
        } else if(time == 0) {
            printf("Turning the light off... \n");
            lightOn = false;
        } else {
            printf("The light will remain on for %d seconds... \n", time);
            sleep(time);
            printf("The light has been turned off after %d seconds. \n", time);
            lightOn = false;
        }
        
        printf("Do you want to continue? Enter 1 to continue, Enter 0 to exit: \n");
        int exit_choice = 0;
        scanf("%d", &exit_choice);
        
        if(exit_choice == 0) {
            printf("Thank you for using Smart Home Light Control System! \n");
            break;
        }
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Smart home light control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int lightStatus = 0;
    int powerStatus = 1;
    srand(time(NULL));

    // Post-apocalyptic scenario
    printf("Welcome to the Smart Home Light Control System.\n");
    printf("In the dark, uncertain times after the apocalypse, reliable light is critical for survival.\n");
    printf("You look around your house, trying to control the lights with your phone...\n");

    // Control Loop
    while(powerStatus == 1){
        printf("Do you want to turn on the lights? (Enter 1 for Yes and 0 for No)");
        int input;
        scanf("%d", &input);

        if(input == 1){
            if(lightStatus == 0){
                printf("The lights are turning on...\n");
                lightStatus = 1;

                //Randomly turns off light after 1 to 5 seconds
                int turnOffTime = (rand() % 5) + 1;
                printf("The lights will automatically turn off in %d seconds.\n", turnOffTime);
                sleep(turnOffTime);
                printf("The lights have turned off.\n");
                lightStatus = 0;
            } else {
                printf("The lights are already turned on.\n");
            }
        } else if(input == 0){
            if(lightStatus == 1){
                printf("The lights are turning off...\n");
                lightStatus = 0;
            } else {
                printf("The lights are already turned off.\n");
            }
        } else {
            printf("Invalid input. Please enter 1 to turn on the lights, 0 to turn off the lights or -1 to exit.\n");
        }

        printf("Do you want to exit the program? (Enter -1 for Yes and 0 for No)");
        scanf("%d", &input);

        if(input == -1){
            powerStatus = 0;
        }
    }

    printf("Thanks for using the Smart Home Light Control System. Stay safe in the post-apocalyptic world.\n");
    return 0;
}
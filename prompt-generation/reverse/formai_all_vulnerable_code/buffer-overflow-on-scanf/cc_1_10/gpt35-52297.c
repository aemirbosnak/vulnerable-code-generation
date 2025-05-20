//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printSlow(char* str, int delay){
    for(int i = 0; str[i] != '\0'; i++){
        printf("%c", str[i]);
        fflush(stdout);
        usleep(delay);
    }
}

int main(){
    srand(time(0)); // seed for random number generation

    char playerName[100];
    printf("Welcome to the medieval space adventure!\n");
    printSlow("What is your name, brave adventurer?\n", 50000);
    scanf("%s", playerName);

    printf("\nWelcome, %s, to your space adventure!", playerName);
    printf("\n\nYou are a knight from the Kingdom of Aragon who has been sent on a quest to explore the galaxy and find a new planet to colonize. You have been given a spaceship, a crew of five, and a map of the galaxy.\n\n");

    int planetCount = 0;
    while(planetCount < 5){
        printf("You have reached planet %d. Do you want to explore it? (y/n)\n", planetCount+1);
        char exploreChoice;
        scanf(" %c", &exploreChoice); // space before %c to consume the newline left behind by previous scanf

        if(exploreChoice == 'y'){
            // planet exploration code goes here
            printf("\nYou have successfully explored planet %d!\n", planetCount+1);
            int resourceGatherResult = rand() % 3; // possible values: 0, 1, 2
            if(resourceGatherResult == 0){ // unsuccessful resource gathering
                printf("Unfortunately, you were not able to find any useful resources on this planet.\n");
            } else { // successful resource gathering
                printf("You were able to gather some resources from this planet:\n");
                if(resourceGatherResult == 1){ // found food
                    printf("- Food (enough for one day)\n");
                } else { // found fuel
                    printf("- Fuel (enough for one trip)\n");
                }
            }
            planetCount++;
        } else { // exploreChoice == 'n'
            printf("\nYou have decided not to explore planet %d and move on to the next one.\n", planetCount+1);            
        }
    }

    printf("\nYou have successfully explored %d planets and gathered resources from them. Congratulations, %s!\n", planetCount, playerName);
    return 0;
}
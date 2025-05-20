//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: funny
/*
Welcome to our newest project – our very own Elevator Simulation Program!
Instead of the usual dull and boring program, we present to you a simulator
that will make you roll on the floor laughing. This program is designed to simulate
a fantasy world where our elevator is not just a simple machine, but it can talk,
dance, sing or even fly. Time to let your imagination run wild, folks!

We are proud to introduce you to Elevator “Crazy Fun-time”!
*/

#include <stdio.h>
#include <stdlib.h>

// Defining our variables
int currentFloor = 1;

// Function for taking user input
int getUserInput() {
    printf("\n\nWhich floor would you like to go to? (1 to 10)\n");
    int floorChoice;
    scanf("%d", &floorChoice);

    // Validation
    if(floorChoice < 1 || floorChoice > 10) {
        printf("Invalid floor choice! Try again.\n");
        return getUserInput();
    }

    return floorChoice;
}

int main()
{
    printf("Welcome to Elevator Crazy Fun-time!\n\n");

    // Greeting
    printf("Elevator: Hey there, fancy meeting you here. Where would you like to go today?\n");

    while(1) {
        // Taking the user's input
        int floorChoice = getUserInput();

        // Elevator moves
        while(currentFloor != floorChoice) {
            if(currentFloor < floorChoice) {
                currentFloor++;
                printf("Elevator: Going up to floor %d...\n", currentFloor);
            }
            else {
                currentFloor--;
                printf("Elevator: Going down to floor %d...\n", currentFloor);
            }

            // Random actions by the elevator
            int actionChance = rand() % 10;
            if(actionChance == 0) {
                printf("Elevator: Whoopie, let's do a little dance.\n");
            }
            else if(actionChance == 1) {
                printf("Elevator: Hold on tight, we're about to fly!\n");
            }
            else if(actionChance == 2) {
                printf("Elevator: Oh my, would you look at that view!\n");
            }
            else if(actionChance == 3) {
                printf("Elevator: Let's sing a song together. ♫ Laa la laa la laa ♫\n");
            }
            else if(actionChance == 4) {
                printf("Elevator: So, what's your favourite joke?\n");
            }
            else if(actionChance == 5) {
                printf("Elevator: Up, up and awaaayyy!!\n");
            }
        }

        // Arrival message
        printf("\n\nElevator: You have arrived at floor %d! Have a great day ahead!\n", currentFloor);

        // Farewell message
        printf("Elevator: Thanks for riding with us. Don't forget to rate us five stars! *wink*\n");

        // Taking prompt
        printf("\n\nDo you want to go to another floor? (y/n)\n");
        char choice;
        scanf("%s", &choice);

        if(choice == 'n' || choice == 'N') {
            printf("Elevator: Alright, bye for now!\n");
            break;
        }
        else if(choice == 'y' || choice == 'Y') {
            printf("Elevator: Great! Let's continue our journey. Buckle up, folks!\n\n");
        }
        else {
            printf("Elevator: Sorry, I didn't quite catch that. *confused*\n");
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//function to clear console screen
void clearScreen() {
    system("cls");
}

//Function to generate the random number
int generateNumberInRange(int min, int max) {
    //seed the random number generator with the current time
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

//Function to simulate a spooky sound effect
void playSpookySound() {
    printf("\a");
}

//Function to simulate a lightning effect
void playLightningEffect() {
    printf("********\n");
}

int main() {
    char playerName[50];
    int choice;
    int flashlight = 0;
    int ghostAppeared = 0;
    int randomNumber;
    
    //Get the player's name
    printf("What's your name? ");
    scanf("%s", playerName);
    printf("Welcome %s! You have entered a haunted house simulator.\n", playerName);

    //Display the menu
    do {
        printf("1. Go left\n");
        printf("2. Go right\n");
        printf("3. Turn on Flashlight\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        clearScreen();

        switch(choice) {
            case 1: //Go left
                printf("You walk down a long creepy hallway...\n");

                //Generate a random number to see if there's a ghost
                randomNumber = generateNumberInRange(1, 10);

                //If the ghost appears
                if (randomNumber <= 3) {
                    playSpookySound();
                    printf("The ghost of the previous owner appears in front of you!\n");
                    ghostAppeared = 1;
                }
                else {
                    printf("You reach a dead end and turn around.\n");
                }
                break;

            case 2: //Go right
                printf("You walk down a narrow staircase...\n");

                //Generate a random number to see if there's a ghost
                randomNumber = generateNumberInRange(1, 10);

                //If the ghost appears
                if (randomNumber <= 3) {
                    playSpookySound();
                    printf("The ghost of the former caretaker appears in front of you!\n");
                    ghostAppeared = 1;
                }
                else {
                    printf("You reach a dead end and turn around.\n");
                }
                break;

            case 3: //Turn on flashlight
                printf("You turn on your flashlight and walk down a dimly lit hallway...\n");

                if (!flashlight) {
                    playLightningEffect();
                    printf("You find an old flashlight lying on the ground!\n");
                    flashlight = 1;
                }

                //Generate a random number to see if there's a ghost
                randomNumber = generateNumberInRange(1, 10);

                //If the ghost appears
                if (randomNumber <= 3) {
                    playSpookySound();
                    printf("The ghost of the former owner appears in front of you!\n");
                    ghostAppeared = 1;
                }
                else {
                    printf("You continue down the hallway.\n");
                }
                break;

            case 4: //Quit
                printf("Thanks for playing %s!\n", playerName);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        //If the ghost appeared, end the game
        if (ghostAppeared) {
            printf("GAME OVER!\n");
            return 0;
        }

    } while(choice != 4);

    return 0;
}
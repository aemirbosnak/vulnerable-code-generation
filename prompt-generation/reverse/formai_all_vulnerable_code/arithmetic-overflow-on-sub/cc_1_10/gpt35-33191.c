//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function declarations
void delay(int);
void gameIntroduction(void);
void gameMenu(void);
void startGame(char*);

//Main function
int main(){

    srand(time(NULL)); //Seed the random number generator

    //Call the functions
    gameIntroduction();
    gameMenu();

    return 0;
}

//Function to add a delay between messages for suspense
void delay(int milliseconds) {
    long pause;
    clock_t now, then;

    pause = milliseconds * (CLOCKS_PER_SEC/ 1000);
    now = then = clock();
    while (now - then < pause){
        now = clock();
    }
}

//Function to introduce the game story
void gameIntroduction() {
    printf("\nWelcome to the Adventure Game!\n");
    delay(2000);

    printf("\nYou are a brave adventurer on a quest to find treasure in a mysterious cave.\n\n");
    delay(2000);

    printf("You have heard rumors that the cave is haunted by evil spirits and dangerous creatures.\n\n");
    delay(2000);

    printf("Do you have what it takes to survive and claim the treasure? Let's find out!\n");
    delay(2000);

}

//Function to display the game menu and ask the user to enter their name
void gameMenu() {
    char playerName[20];

    printf("\nPlease enter your name to begin the adventure: \n");
    scanf("%s", &playerName);

    printf("\nWelcome %s! Are you ready to enter the cave? \n\n", playerName);
    delay(2000);

    printf("1. Yes, let's go!\n");
    printf("2. No, I'm not ready yet.\n");

    int choice;
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("\nGreat, let's get started!");
            startGame(playerName);
            break;
        case 2:
            printf("\nCome back when you're ready to embark on this adventure!");
            break;
        default:
            printf("\nInvalid choice. Please try again.");
            gameMenu();
            break;
    }
}

//Function to start the game
void startGame(char* playerName) {
    printf("\nYou enter the cave cautiously, wary of any danger that may be lurking inside.\n");
    delay(2000);

    printf("As you navigate through the cave, you come across a fork in the road.\n\n");
    delay(2000);

    printf("To the left, you see a faint light in the distance.\n");
    printf("To the right, you see a dark tunnel that stretches deeper into the cave.\n\n");
    delay(2000);

    printf("Which path will you take, %s?\n", playerName);
    printf("1. Left\n");
    printf("2. Right\n");

    int choice;
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("\nYou head towards the light, cautiously stepping around the rocks and stalagmites that litter the ground.\n");
            delay(2000);

            printf("As you get closer, you realize that the light is coming from a chest sitting in the middle of a small room.\n");
            delay(2000);

            printf("You approach the chest and realize that it is locked. Do you want to try and open it?\n");
            printf("1. Yes\n");
            printf("2. No\n");

            int chestChoice;
            scanf("%d", &chestChoice);

            if(chestChoice == 1){
                int chance = rand() % 3;

                if(chance == 1){
                    printf("\nCongratulations, %s! You successfully pick the lock and find a pile of treasure inside!\n\n", playerName);
                } else{
                    printf("\nOh no, the lock is too difficult to pick. You hear a loud noise and suddenly feel surrounded by enemies!\n\n");
                }
            } else{
                printf("\nYou decide to leave the chest alone and continue on your adventure.\n\n");
            }
            break;
        case 2:
            printf("\nYou venture deeper into the cave, your heart pounding with every step.\n");
            delay(2000);

            printf("As you round a corner, you come face to face with a terrifying monster!\n\n");
            delay(2000);

            printf("Will you fight or try to run away?\n");
            printf("1. Fight\n");
            printf("2. Run\n");

            int monsterChoice;
            scanf("%d", &monsterChoice);

            if(monsterChoice == 1){
                printf("\nYou bravely battle the monster and emerge victorious!\n\n");
            } else{
                printf("\nYou attempt to run, but the monster catches up to you and attacks.\n\n");
                printf("You have received a fatal injury and cannot continue. Better luck next time, %s!\n\n", playerName);
                exit(0);
            }
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            startGame(playerName);
            break;
    }

    printf("Congratulations, %s! You have completed the adventure and claimed your treasure!\n", playerName);
}
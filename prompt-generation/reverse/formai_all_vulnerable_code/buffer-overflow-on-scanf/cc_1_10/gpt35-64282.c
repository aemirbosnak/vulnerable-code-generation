//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function prototypes
void startGame();
void roomOne();
void roomTwo();
void roomThree();
void roomFour();
void gameOver();

// Global variables
int playerScore = 0, health = 100;
char playerName[20];

int main(){

    printf("Welcome to Happy Land Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);

    printf("\nWelcome %s! Let's get started!\n", playerName);
    printf("You are at the entrance of a magical land, ready to embark on a wild adventure!\n");

    startGame();
    return 0;

}

void startGame(){

    int choice;

    printf("\nWhat would you like to do?\n");
    printf("1. Enter the castle.\n");
    printf("2. Quit game.\n");

    scanf("%d", &choice);

    switch(choice){

        case 1: roomOne();
            break;

        case 2: printf("\nGoodbye %s! Thanks for playing!", playerName);
            exit(0);
            break;

        default: printf("\nInvalid choice! Please try again.\n");
            startGame();
            break;

    }

}

void roomOne(){

    int choice;

    printf("\nYou have entered the castle!\n");
    printf("You are in a room with four doors.\n");
    printf("Which door do you choose?\n");
    printf("1. Door one.\n");
    printf("2. Door two.\n");
    printf("3. Door three.\n");
    printf("4. Door four.\n");

    scanf("%d", &choice);

    switch(choice){

        case 1: printf("\nYou have entered room two!\n");
            roomTwo();
            break;

        case 2: printf("\nYou have entered room three!\n");
            roomThree();
            break;

        case 3: printf("\nYou have entered room four!\n");
            roomFour();
            break;

        case 4: printf("\nThis door is locked! Try another one.\n");
            roomOne();
            break;

        default: printf("\nInvalid choice! Please try again.\n");
            roomOne();
            break;

    }

}

void roomTwo(){

    int choice;

    printf("\nYou are in a room with a treasure chest!\n");
    printf("Do you want to open the chest?\n");
    printf("1. Yes\n");
    printf("2. No\n");

    scanf("%d", &choice);

    if(choice == 1){

        printf("\nYou found a sack of gold coins! +10 points to your score!\n");
        playerScore += 10;
        printf("\nYour current score is: %d\n", playerScore);
        roomThree();

    }else if(choice == 2){

        printf("\nYou leave the room and head to another one.\n");
        roomOne();

    }else{

        printf("\nInvalid choice! Please try again.\n");
        roomTwo();

    }

}

void roomThree(){

    int choice;

    printf("\nYou are in a room with a magical machine!\n");
    printf("Do you want to use the machine?\n");
    printf("1. Yes\n");
    printf("2. No\n");

    scanf("%d", &choice);

    if(choice == 1){

        printf("\nThe machine teleports you into a room filled with gold coins!\n");
        printf("You now have +20 points to your score!\n");
        playerScore += 20;
        printf("\nYour current score is: %d\n", playerScore);
        roomFour();

    }else if(choice == 2){

        printf("\nYou leave the room and head to another one.\n");
        roomTwo();

    }else{

        printf("\nInvalid choice! Please try again.\n");
        roomThree();

    }

}

void roomFour(){

    int choice;

    printf("\nYou are in a room with a huge dragon!\n");
    printf("Do you want to attack the dragon?\n");
    printf("1. Yes\n");
    printf("2. No\n");

    scanf("%d", &choice);

    switch(choice){

        case 1:printf("\nYou attack the dragon and slay it!\n");
            printf("You have completed Happy Land Adventure Game!\n");
            printf("Congratulations! Your score is: %d\n", playerScore);
            exit(0);
            break;

        case 2: printf("\nYou run out of the room, scared for your life!\n");
            roomThree();
            break;

        default: printf("Invalid choice! Please try again.\n");
            roomFour();
            break;

    }

}
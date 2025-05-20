//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complete
#include <stdio.h>

//Declare the function to print the story
void printStory();

//Declare the function to get the user's name
void getName(char name[]);

int main()
{
    //Welcome the user to the adventure
    printf("Welcome to the Procedural Space Adventure!\n");

    //Get the user's name
    char name[50];
    getName(name);

    //Print the story
    printf("\n\nHi %s! You are an astronaut on a mission to explore the galaxy. You were on your way to a planet when something went wrong with your spacecraft and you crash-landed on a distant planet. You have no means of communication or any way to get off this planet. You realize that you must explore the planet to find the necessary resources to fix your spacecraft and return home.\n", name);
    printStory();

    return 0;
}

void printStory()
{
    printf("\n\nYou start your adventure by examining the surrounding area. You find a strange structure ahead of you and decide to investigate. As you get closer, you realize that the structure is a pyramid-shaped temple. The entrance is sealed shut, but you notice that there are symbols etched on the walls that seem to be some sort of code. You decide to crack the code to enter the temple and explore what's inside.\n");

    //Declare the variables for the code
    int code1 = 3;
    int code2 = 5;
    int code3 = 9;
    int codeSum = code1 + code2 + code3;

    //Get the user's guess for the code
    int guess1, guess2, guess3, guessSum;
    printf("The code is a 3-digit number. Enter your guess for digit 1: ");
    scanf("%d", &guess1);
    printf("Enter your guess for digit 2: ");
    scanf("%d", &guess2);
    printf("Enter your guess for digit 3: ");
    scanf("%d", &guess3);
    guessSum = guess1 + guess2 + guess3;

    //Check if guess is correct
    if(guessSum == codeSum){
        printf("Congratulations! You have cracked the code and the entrance to the temple has opened!\n\n");
    } else {
        printf("Sorry, you have failed to crack the code and the entrance remains sealed.\n");
        return; //terminate program if guess is incorrect
    }

    printf("As you enter the temple, you find a room filled with treasure. Gold and jewels glitter in the light. You realize that you could take some treasure with you to sell and use the profits to fix your spacecraft.\n");

    //Get the user's decision on taking treasure
    char decision;
    printf("Do you want to take some treasure with you? (Y/N): ");
    scanf(" %c", &decision);

    if(decision == 'Y' || decision == 'y'){
        printf("You pack as much treasure as you can in your backpack and prepare to leave the temple. As you exit the temple, you hear a strange noise coming from the direction of your spacecraft. You decide to investigate and hope that this noise might lead you to a solution for your problem.\n\n");
    } else {
        printf("You decide not to take any treasure with you and prepare to leave the temple. As you exit the temple, you hear a strange noise coming from the direction of your spacecraft. You decide to investigate and hope that this noise might lead you to a solution for your problem.\n\n");
    }

    printf("As you approach your spacecraft, you notice that a group of alien creatures are trying to sabotage it. You must fight them off to save your spacecraft!\n");

    //Declare the variables for combat
    int alienHP = 100;
    int playerHP = 100;
    int alienAttack = 20;
    int playerAttack = 15;
    char attackChoice;

    //Loop for combat
    while(alienHP > 0 && playerHP > 0){
        printf("Alien HP: %d\nPlayer HP: %d\n", alienHP, playerHP);
        printf("\nEnter 'A' to attack or 'D' to defend: ");
        scanf(" %c", &attackChoice);

        if(attackChoice == 'A' || attackChoice == 'a'){
            printf("You attack the alien and deal %d damage.\n", playerAttack);
            alienHP -= playerAttack;
        } else if(attackChoice == 'D' || attackChoice == 'd'){
            printf("You defend yourself and take reduced damage.\n");
            playerHP -= (alienAttack/2);
        } else {
            printf("Invalid input. You lose your turn.\n");
        }

        if(alienHP > 0){
            printf("The alien attacks you and deals %d damage.\n", alienAttack);
            playerHP -= alienAttack;
        }
    }

    //Check who won the combat
    if(playerHP > 0){
        printf("\nYou successfully fend off the alien creatures and save your spacecraft! You quickly board your spacecraft and take off into space, leaving the planet and your adventure behind. You have successfully completed your mission.\n");
    } else {
        printf("\nUnfortunately, the aliens were too strong and you were defeated. Your mission ends here.\n");
    }
}

void getName(char name[]){
    printf("Please enter your name: ");
    scanf("%[^\n]s", name); //allows for names with spaces
}
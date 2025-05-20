//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to clear the screen
void clearScreen() {
    system("clear"); // for Mac/linux
    //system("cls"); // for Windows
}

// function to print the game title
void printTitle() {
    printf("\n******************\n");
    printf("*** HAPPY GAME ***\n");
    printf("******************\n\n");
}

// function to print the game instructions
void printInstructions() {
    printf("Welcome to the Happy Game!\n");
    printf("The objective of this game is to make the player happy by giving them a gift.\n");
    printf("The game will ask the player a series of questions to determine what gift will make them happy.\n");
    printf("At the end of the game, the player will receive a gift that is tailored to their preferences.\n");
    printf("Let's get started! Press enter to begin.\n");
}

// function to get input from the player
int getPlayerInput() {
    int choice;
    printf("Please enter '1' for yes or '0' for no:\n");
    scanf("%d", &choice);
    return choice;
}

// function to check if the player is happy
int checkHappy(int points) {
    if(points >= 3) {
        return 1;
    }
    else {
        return 0;
    }
}

// function to generate a random gift based on the player's answers
void generateGift(int points) {
    int giftNumber;
    printf("\nCongratulations! You have completed the Happy Game.\n");
    printf("Based on your answers, we have selected a gift just for you:\n");
    
    srand(time(0)); // seed srand with current time
    giftNumber = rand() % 5; // generate random number between 0 and 4
    
    switch(giftNumber) {
        case 0:
            printf("A dozen roses!\n");
            break;
        case 1:
            printf("A box of chocolates!\n");
            break;
        case 2:
            printf("A spa gift certificate!\n");
            break;
        case 3:
            printf("A bottle of champagne!\n");
            break;
        case 4:
            printf("A weekend getaway to a luxury resort!\n");
            break;
        default:
            printf("Error: Invalid Gift Number!\n");
            break;
    }
}

int main() {
    int points = 0, choice;
    
    // print the game title and instructions
    clearScreen();
    printTitle();
    printInstructions();
    getchar(); // wait for user to press enter
    
    // question 1
    printf("Do you like flowers?\n");
    choice = getPlayerInput();
    if(choice == 1) {
        printf("Great! Flowers can brighten anyone's day.\n");
        points += 1;
    }
    else {
        printf("That's okay, not everyone likes flowers.\n");
    }
    
    // question 2
    printf("Do you enjoy sweet treats?\n");
    choice = getPlayerInput();
    if(choice == 1) {
        printf("Awesome! A little bit of sugar can make anyone happy.\n");
        points += 1;
    }
    else {
        printf("That's okay, not everyone has a sweet tooth.\n");
    }
    
    // question 3
    printf("Do you like to be pampered?\n");
    choice = getPlayerInput();
    if(choice == 1) {
        printf("Who doesn't love a little TLC? You deserve it!\n");
        points += 1;
    }
    else {
        printf("That's okay, not everyone wants to be spoiled.\n");
    }
    
    // question 4
    printf("Do you enjoy drinking alcohol?\n");
    choice = getPlayerInput();
    if(choice == 1) {
        printf("Cheers to that! A drink always adds to the fun.\n");
        points += 1;
    }
    else {
        printf("That's okay, not everyone likes to drink.\n");
    }
    
    // question 5
    printf("Do you need a vacation?\n");
    choice = getPlayerInput();
    if(choice == 1) {
        printf("Who doesn't need a break once in a while? Time to relax and unwind!\n");
        points += 1;
    }
    else {
        printf("That's okay, not everyone needs a vacation.\n");
    }
    
    // check if player is happy and generate gift
    if(checkHappy(points)) {
        generateGift(points);
    }
    else {
        printf("\nWe're sorry to hear that we couldn't make you happy.\n");
    }
    
    return 0;
}
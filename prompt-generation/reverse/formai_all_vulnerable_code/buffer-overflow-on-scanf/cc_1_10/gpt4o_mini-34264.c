//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayIntro() {
    printf("==================================\n");
    printf("       Time Travel Simulator      \n");
    printf("          Medieval Edition        \n");
    printf("==================================\n");
    printf("Welcome, noble traveler! You possess a mystical device that allows you to travel through time.\n");
    printf("Your journey begins now!\n\n");
}

void displayEpochs() {
    printf("Choose a medieval epoch to travel to:\n");
    printf("1. Era of Kings\n2. Age of Knights\n3. Time of the Plague\n4. The Renaissance\n");
}

void encounterKings() {
    printf("\nYou arrive in the Era of Kings.\n");
    printf("Here, you meet King Arthur, who asks you to find his lost sword.\n");
    printf("Do you:\n1. Help him in his quest\n2. Refuse and leave\n");
}

void encounterKnights() {
    printf("\nYou find yourself in the Age of Knights.\n");
    printf("A brave knight challenges you to a duel to test your strength.\n");
    printf("Do you:\n1. Fight the knight\n2. Use your wit to outsmart him\n");
}

void encounterPlague() {
    printf("\nYou step into the Time of the Plague.\n");
    printf("People are in despair, and a wise healer asks for your help in gathering herbs.\n");
    printf("Do you:\n1. Help the healer\n2. Run away in fear\n");
}

void encounterRenaissance() {
    printf("\nWelcome to the Renaissance.\n");
    printf("You meet a famous artist who offers to teach you how to paint.\n");
    printf("Do you:\n1. Learn the art\n2. Decline and explore the town\n");
}

int getPlayerChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void pauseAndContinue() {
    printf("Press enter to continue...");
    while (getchar() != '\n'); // wait for enter
    getchar(); // consume the enter
}

void travelThroughTime() {
    int epochChoice, adventureChoice;
    
    displayIntro();
    displayEpochs();
    epochChoice = getPlayerChoice();
    
    switch (epochChoice) {
        case 1:
            encounterKings();
            adventureChoice = getPlayerChoice();
            if (adventureChoice == 1) {
                printf("You bravely embark on the quest and find the sword, earning the King's favor!\n");
            } else {
                printf("You decide to leave, and the King remembers your cowardice!\n");
            }
            break;
            
        case 2:
            encounterKnights();
            adventureChoice = getPlayerChoice();
            if (adventureChoice == 1) {
                printf("You fight valiantly but are defeated by the knight; your bravery is recognized, however.\n");
            } else {
                printf("Using your wit, you trick the knight and gain his respect!\n");
            }
            break;

        case 3:
            encounterPlague();
            adventureChoice = getPlayerChoice();
            if (adventureChoice == 1) {
                printf("Your help brings hope to the villagers, and they share their wisdom with you!\n");
            } else {
                printf("You flee, but your heart feels heavy with guilt.\n");
            }
            break;

        case 4:
            encounterRenaissance();
            adventureChoice = getPlayerChoice();
            if (adventureChoice == 1) {
                printf("You learn the secrets of painting and create a masterpiece!\n");
            } else {
                printf("Exploring the town, you find hidden artifacts of great value!\n");
            }
            break;

        default:
            printf("Invalid choice! No time travel for you.\n");
            break;
    }
    
    pauseAndContinue();
}

int main() {
    travelThroughTime();
    printf("\nThank you for playing the Time Travel Simulator!\n");
    return 0;
}
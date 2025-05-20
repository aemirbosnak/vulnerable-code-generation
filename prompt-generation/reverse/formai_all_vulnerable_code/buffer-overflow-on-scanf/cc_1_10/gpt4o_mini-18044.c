//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearScreen() {
    printf("\033[H\033[J"); // Clear the terminal screen
}

void welcomeMessage() {
    printf("Welcome to the Whimsical Forest Adventure!\n");
    printf("You are about to embark on a joyful journey filled with laughter and fun!\n");
    printf("----------------------------------------------------------------\n");
}

void choosePath() {
    printf("Ahead of you, there are two paths:\n");
    printf("1. The Rainbow Trail\n");
    printf("2. The Sparkling Stream\n");
    printf("Which path will you choose? (1 or 2): ");
}

void rainbowTrail() {
    printf("You take the Rainbow Trail!\n");
    printf("The path is vibrant, filled with colorful flowers.\n");
    printf("Suddenly, you meet a friendly Unicorn!\n");
    printf("The Unicorn offers you a magical wish. What will you wish for?\n");
    printf("1. A basket of delicious fruits\n");
    printf("2. A shiny new friend\n");

    int wishChoice;
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &wishChoice);

    if (wishChoice == 1) {
        printf("You receive a basket of the juiciest fruits! Yum!\n");
    } else if (wishChoice == 2) {
        printf("A lovely little bunny appears! You now have a fluffy friend!\n");
    } else {
        printf("The Unicorn looks confused! Remember to choose wisely next time.\n");
    }
}

void sparklingStream() {
    printf("You walk over to the Sparkling Stream.\n");
    printf("The water glimmers in the sunlight and you can hear laughter nearby.\n");
    printf("You spot a group of friendly Gnomes having a tea party!\n");
    printf("They invite you to join them. What would you like to do?\n");
    printf("1. Join the tea party\n");
    printf("2. Sing a merry song\n");

    int gnomeChoice;
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &gnomeChoice);

    if (gnomeChoice == 1) {
        printf("You sit down and enjoy the finest tea and cookies with the Gnomes! Delightful!\n");
    } else if (gnomeChoice == 2) {
        printf("You sing a joyful song and the Gnomes dance around you! What a lively party!\n");
    } else {
        printf("The Gnomes look puzzled. Just be yourself and have fun!\n");
    }
}

void playAgain() {
    char playChoice;
    printf("Would you like to play again? (y/n): ");
    scanf(" %c", &playChoice);

    if (playChoice == 'y' || playChoice == 'Y') {
        clearScreen();
        welcomeMessage();
        choosePath();
    } else {
        printf("Thank you for playing! Have a magical day!\n");
        exit(0);
    }
}

int main() {
    clearScreen();
    welcomeMessage();
    choosePath();

    int pathChoice;
    scanf("%d", &pathChoice);

    if (pathChoice == 1) {
        rainbowTrail();
    } else if (pathChoice == 2) {
        sparklingStream();
    } else {
        printf("Oh no! That path doesn't exist! Let’s try again.\n");
        playAgain();
    }

    playAgain();
    return 0;
}
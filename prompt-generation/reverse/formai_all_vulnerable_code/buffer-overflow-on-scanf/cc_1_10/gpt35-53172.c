//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearScreen() {
    system("clear || cls");
}

void pause() {
    printf("\n\nPress any key to continue...");
    getchar();
}

void gameOver() {
    printf("\n\nGame Over!\n\n");
    pause();
}

void win() {
    printf("\n\nYou have won the game!\n\n");
    pause();
}

int getInput(char * question, char ** options, int numOptions) {
    printf("%s", question);
    for (int i = 0; i < numOptions; i++) {
        printf("%d. %s\n", i+1, options[i]);
    }
    int choice = 0;
    while (choice < 1 || choice > numOptions) {
        printf("Enter a valid choice: ");
        scanf("%d", &choice);
        getchar();
    }
    return choice;
}

int main() {
    clearScreen();
    printf("Welcome to the Text-Based Adventure Game!\n\n");

    int score = 0;
    int maxScore = 5;

    char name[20];
    printf("What is your name? ");
    scanf("%s", name);
    printf("Welcome, %s!\n\n", name);

    char * question1 = "You come across a fork in the road. Which direction do you go?\n";
    char * options1[] = {"Left", "Right", "Straight"};
    int choice1 = getInput(question1, options1, 3);
    if (choice1 == 1) {
        printf("\nYou go left and fall into a pit. ");
        gameOver();
        return 0;
    } else if (choice1 == 2) {
        printf("\nYou go right and find a treasure chest. ");
        score++;
    } else {
        printf("\nYou go straight and encounter a monster. ");
        score++;
    }

    char * question2 = "You see a river in front of you. What do you do?\n";
    char * options2[] = {"Swim across", "Find a bridge", "Follow the river"};
    int choice2 = getInput(question2, options2, 3);
    if (choice2 == 1) {
        printf("\nYou try to swim across but get caught in a current. ");
        gameOver();
        return 0;
    } else if (choice2 == 2) {
        printf("\nYou find a bridge and safely cross the river. ");
        score++;
    } else {
        printf("\nYou follow the river and find a waterfall. ");
        gameOver();
        return 0;
    }

    char * question3 = "You come across a village. What do you do?\n";
    char * options3[] = {"Explore the village", "Rest at the inn", "Leave the village"};
    int choice3 = getInput(question3, options3, 3);
    if (choice3 == 1) {
        printf("\nYou explore the village and meet a wise old man. ");
        score++;
    } else if (choice3 == 2) {
        printf("\nYou rest at the inn and regain your strength. ");
        score++;
    } else {
        printf("\nYou leave the village and get lost in the forest. ");
        gameOver();
        return 0;
    }

    char * question4 = "You come across a castle. What do you do?\n";
    char * options4[] = {"Sneak in", "Fight the guards", "Befriend the king"};
    int choice4 = getInput(question4, options4, 3);
    if (choice4 == 1) {
        printf("\nYou sneak in and steal the king's treasure. ");
        score++;
    } else if (choice4 == 2) {
        printf("\nYou try to fight the guards but are outnumbered. ");
        gameOver();
        return 0;
    } else {
        printf("\nYou befriend the king and he gives you a quest. ");
        score++;
    }

    char * question5 = "You reach the end of the game. Did you enjoy it?\n";
    char * options5[] = {"Yes", "No", "It was okay"};
    int choice5 = getInput(question5, options5, 3);
    if (choice5 == 1) {
        printf("\nThank you for playing the Text-Based Adventure Game! ");
        win();
    } else {
        printf("\nWe're sorry to hear that. ");
        gameOver();
        return 0;
    }

    printf("\nYou scored %d out of %d points!\n\n", score, maxScore);
    pause();
    return 0;
}
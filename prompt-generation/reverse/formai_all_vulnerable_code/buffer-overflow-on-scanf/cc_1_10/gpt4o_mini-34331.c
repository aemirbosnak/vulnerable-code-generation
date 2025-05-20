//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void displayIntro() {
    printf("Welcome to 'A Romantic Journey'!\n");
    printf("In this game, you will choose your path to win the heart of your beloved.\n");
    printf("Choose wisely, as your decisions will determine your fate!\n\n");
}

void displayChoices() {
    printf("You find yourself at a beautiful park, where your beloved often comes. What do you want to do?\n");
    printf("1. Write a heartfelt poem and read it aloud.\n");
    printf("2. Prepare a surprise picnic with their favorite food.\n");
    printf("3. Invite them for a romantic walk at sunset.\n");
    printf("Enter your choice (1-3): ");
}

int getChoice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

void outcomePoem() {
    printf("\nYou recite your poem with passion, your words painting pictures of love.\n");
    printf("Your beloved is touched by your sincerity and the deep emotions you express.\n");
    printf("Afterward, they smile and say, \"Your words are as beautiful as a summer's day.\"\n");
    printf("You feel a spark igniting between you!\n");
}

void outcomePicnic() {
    printf("\nYou lay out a colorful blanket and fill it with delicious treats.\n");
    printf("As you enjoy the meal under the sun, laughter fills the air.\n");
    printf("Your beloved looks at you with admiration and says, \"You always know how to take my breath away!\"\n");
    printf("A bond starts to form, stronger than any crosswind.\n");
}

void outcomeWalk() {
    printf("\nThe sun begins to set, painting the sky with hues of orange and pink as you walk hand in hand.\n");
    printf("You share stories, dreams, and secrets, creating a moment that feels timeless.\n");
    printf("Your beloved gazes into your eyes and whispers, \"With you, I found my favorite place.\"\n");
    printf("Love blossoms in this serene atmosphere! \n");
}

void playAgain() {
    char choice[3];
    printf("\nWould you like to play again? (yes/no): ");
    scanf("%s", choice);
    if (strcmp(choice, "yes") == 0) {
        main();
    } else {
        printf("Thank you for playing 'A Romantic Journey'! May love find you always.\n");
    }
}

int main() {
    srand(time(0));
    displayIntro();
    int choice;
    do {
        displayChoices();
        choice = getChoice();
        
        switch (choice) {
            case 1:
                outcomePoem();
                break;
            case 2:
                outcomePicnic();
                break;
            case 3:
                outcomeWalk();
                break;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
                break;
        }
        
    } while (choice < 1 || choice > 3);
    
    playAgain();
    return 0;
}
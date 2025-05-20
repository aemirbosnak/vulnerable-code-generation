//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntro();
void game();
void choosePath();
void forest();
void river();
void mountain();
void gameOver();

int main(){
    printIntro();
    game();
    return 0;
}

void printIntro(){
    printf("Welcome to the Adventure Game!\n");
    printf("You are an explorer and you have three paths to choose from:\n");
    printf("1. Through the Forest\n");
    printf("2. Across the River\n");
    printf("3. Over the Mountain\n");
}

void game(){
    int path;

    do {
        printf("Choose your path (1-3): ");
        scanf("%d", &path);
    } while (path < 1 || path > 3);

    if (path == 1) {
        forest();
    } else if (path == 2) {
        river();
    } else {
        mountain();
    }
}

void choosePath(){
    printf("\nChoose your next path:\n");
    printf("1. Through the Forest\n");
    printf("2. Across the River\n");
    printf("3. Over the Mountain\n");
}

void forest(){
    printf("\nYou have chosen to go through the forest...\n");
    printf("As you walk through the forest you hear strange noises coming from the trees.\n");
    printf("You see a small cabin in the distance and decide to investigate.\n");
    printf("As you approach the cabin you hear a growl coming from inside.\n");
    printf("Do you:\n");
    printf("1. Knock on the door?\n");
    printf("2. Run away?\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nThe door swings open and a giant bear charges at you!\n");
        printf("You try to run but the bear is too fast and catches you.\n");
        gameOver();
    } else {
        printf("\nYou run as fast as you can back to the path you came from.\n");
        choosePath();
        game();
    }
}

void river(){
    printf("\nYou have chosen to cross the river...\n");
    printf("The water is cold and the current is strong.\n");
    printf("As you make your way across the river, you realize that there are piranhas in the water!\n");
    printf("Do you:\n");
    printf("1. Keep going?\n");
    printf("2. Turn back?\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nYou feel something biting at your legs and realize that the piranhas are attacking you!\n");
        printf("You try to fight them off but it's too late. You are eaten alive.\n");
        gameOver();
    } else {
        printf("\nYou make your way back to the shore and decide to go a different way.\n");
        choosePath();
        game();
    }
}

void mountain(){
    printf("\nYou have chosen to climb the mountain...\n");
    printf("The climb is steep and treacherous with loose rocks and slippery ice.\n");
    printf("As you climb higher you see a beautiful view of the valley below.\n");
    printf("Suddenly, a snowstorm comes in and you lose your way.\n");
    printf("Do you:\n");
    printf("1. Keep going?\n");
    printf("2. Try to find shelter?\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nYou fall off the mountain and plummet to your death.\n");
        gameOver();
    } else {
        printf("\nYou find a small cave and take shelter from the storm.\n");
        printf("As the storm passes, you make your way back down the mountain.\n");
        printf("Congratulations! You have successfully completed your adventure!\n");
    }
}

void gameOver(){
    printf("\nGAME OVER\n");
    printf("Do you want to play again? (1-Yes, 2-No): ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        game();
    } else {
        printf("\nThanks for playing!\n");
        exit(0);
    }
}
//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void printLogo() {
    printf("      _______ _______ _______ _______ _______ _______ _______ _______ \n");
    printf("     |   _   \\   _   \\     __|    |  |  |  | |     __|    ___|\n");
    printf("     |       |  |_|  |__     |       |  |  | |__     |    ___|\n");
    printf("     |___|___|_______|_______|__|____|\_____/|_______|_______|\n\n");
}

void printIntro() {
    printf("Welcome to the Procedural Space Adventure! You are Sherlock Holmes, the famous detective from Earth. You have been tasked with investigating a series of strange events that have been occurring in the outer regions of space. Your mission is to gather clues, solve puzzles, and uncover the truth behind these sinister happenings. Good luck!\n\n");
}

int main() {
    char playerName[25];
    char input[50];
    int inputNum;

    printLogo();
    printf("Please enter your name: ");
    fgets(playerName, 25, stdin);
    playerName[strcspn(playerName, "\n")] = 0;
    printf("Hello, %s! Are you ready to begin your adventure? (1) Yes, (2) No\n", playerName);
    while (1) {
        fgets(input, 50, stdin);
        if (sscanf(input, "%d", &inputNum) == 1) {
            if (inputNum == 1) {
                printf("\nExcellent! Let's get started...\n");
                break;
            } else if (inputNum == 2) {
                printf("\nVery well. Goodbye!\n");
                return 0;
            }
        }
        printf("Invalid input. Please choose (1) Yes or (2) No\n");
    }

    printf("\nYou board your spaceship and set course for the outer regions of space. As you drift through the vast expanse, you see something in the distance...a large object floating in space. As you draw closer, you realize that it is a small planet! Your curiosity piqued, you decide to investigate...\n");

    printf("\nYou land your spaceship on the planet's surface and step out into the unknown. The air is thin and the ground is rocky, but your detective instincts tell you that there is something unusual about this place. You see a factory in the distance, belching smoke into the sky. Perhaps there are clues to be found there...\n");

    printf("\nAs you approach the factory, you notice that the door is locked. You decide to search the area for another way in. After a few minutes of searching, you spot a vent near the top of the building. It looks like it might be big enough for you to crawl through...\n");

    printf("\nYou climb up to the top of the building and peer inside the vent. It's dark, but you can just make out a series of pipes and machinery. You take a deep breath and begin to crawl...\n");

    printf("\nAfter what seems like an eternity, you emerge from the vent and find yourself in a dimly lit room. There are machines and computers everywhere, and a strange humming noise fills the air. You see a console in the corner, and it looks like it might be the control center for the entire factory...\n");

    printf("\nYou walk over to the console and begin to investigate. There are buttons and switches everywhere, and you can't make heads or tails of it. Suddenly, you hear a noise behind you...\n");

    printf("\nYou turn around and see a group of aliens standing there, pointing their weapons at you! They are tall and slimy, with tentacles for arms and glowing eyes. You realize that they must be the ones behind the strange events in space!\n");

    printf("\nYou try to negotiate with the aliens, but they are not interested. It seems that they will stop at nothing to achieve their evil plans. You will need to use all of your detective skills if you hope to survive...\n");

    printf("\nAfter a tense standoff, you notice a weakness in the aliens' defenses. You make your move, dodging their attacks and disabling their weapons. In the end, you emerge victorious!\n");

    printf("\nAs you make your way back to Earth, you reflect on your adventure. It was a close call, but you managed to save the day once again. You are Sherlock Holmes, after all.\n");

    printf("\nThanks for playing!\n");

    return 0;
}
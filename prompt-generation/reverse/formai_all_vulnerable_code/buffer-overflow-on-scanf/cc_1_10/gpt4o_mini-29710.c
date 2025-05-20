//GPT-4o-mini DATASET v1.0 Category: Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clearScreen() {
    // Clear the screen function for Linux
    printf("\033[H\033[J");
}

void pause() {
    printf("\nPress Enter to continue...");
    while (getchar() != '\n') {}
}

void welcomeMessage() {
    clearScreen();
    printf("Welcome to the Serene Forest Adventure!\n");
    printf("In this game, you will explore a tranquil forest and encounter various animals.\n");
    printf("Your choices will influence your journey through this serene landscape.\n");
    pause();
}

void encounterDeer() {
    clearScreen();
    printf("You come across a graceful deer. It looks at you with curiosity.\n");
    printf("Would you like to:\n");
    printf("1. Approach the deer\n");
    printf("2. Stand still and observe\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("The deer seems to trust you and approaches closer. You feel a sense of calm.\n");
    } else if (choice == 2) {
        printf("The deer watches you for a moment and then continues grazing peacefully.\n");
    } else {
        printf("That's not a valid choice!\n");
    }
    pause();
}

void encounterFox() {
    clearScreen();
    printf("You spot a sleek red fox peeking from behind a tree.\n");
    printf("What do you want to do?\n");
    printf("1. Call out to the fox\n");
    printf("2. Remain quiet and observe\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("The fox tilts its head, intrigued by your voice, but eventually scurries away.\n");
    } else if (choice == 2) {
        printf("The fox stays for a while, seemingly comfortable in your presence, before trotting off.\n");
    } else {
        printf("That's not a valid choice!\n");
    }
    pause();
}

void encounterBird() {
    clearScreen();
    printf("A vibrant bird flutters above you, singing a soft melody.\n");
    printf("Would you like to:\n");
    printf("1. Try to imitate the bird's song\n");
    printf("2. Just enjoy the music\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Your attempt at mimicking the bird fails, but it flies down, curious about you.\n");
    } else if (choice == 2) {
        printf("You sit quietly, letting the enchanting sounds of nature fill your soul.\n");
    } else {
        printf("That's not a valid choice!\n");
    }
    pause();
}

void endGame() {
    clearScreen();
    printf("Thank you for exploring the serene forest with us.\n");
    printf("May the tranquility of nature stay with you as you continue your journey.\n");
    printf("Goodbye!\n");
}

int main() {
    welcomeMessage();
    
    int continueAdventure = 1;
    while (continueAdventure) {
        clearScreen();
        printf("You find yourself at a fork in the path.\n");
        printf("Which direction will you choose?\n");
        printf("1. Left (towards the deer)\n");
        printf("2. Right (towards the fox)\n");
        printf("3. Straight (towards the singing bird)\n");
        printf("4. Exit the adventure\n");

        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                encounterDeer();
                break;
            case 2:
                encounterFox();
                break;
            case 3:
                encounterBird();
                break;
            case 4:
                continueAdventure = 0;
                break;
            default:
                printf("That's not a valid choice!\n");
                pause();
                break;
        }
    }
    
    endGame();
    return 0;
}
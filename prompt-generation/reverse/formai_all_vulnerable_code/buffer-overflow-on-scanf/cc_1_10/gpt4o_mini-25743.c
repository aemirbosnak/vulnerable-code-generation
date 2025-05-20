//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPTIONS 4
#define MAX_DESC_LENGTH 256

typedef struct {
    char description[MAX_DESC_LENGTH];
    void (*action)();
} Option;

typedef struct {
    char title[MAX_DESC_LENGTH];
    char description[MAX_DESC_LENGTH];
    Option options[MAX_OPTIONS];
    int option_count;
} Scene;

void fight() {
    printf("You have chosen to fight! Your cybernetic enhancements give you an advantage.\n");
    // Randomly decide if you win or lose the fight
    if (rand() % 2 == 0) {
        printf("You overpower your opponent! You've gained a reputation in the Neon District.\n");
    } else {
        printf("You were defeated. Better luck next time, you wake up in a dark alley...\n");
    }
}

void hack() {
    printf("You attempt to hack the security system...\n");
    // Random chance to succeed
    if (rand() % 100 < 70) {
        printf("Success! You unlocked a stash of chips and data in the server room.\n");
    } else {
        printf("Failed! Alarm bells ring, escape now or face the guards!\n");
    }
}

void escape() {
    printf("You decide to escape into the shadows.\n");
    // Random chance to successfully escape
    if (rand() % 100 < 50) {
        printf("You managed to vanish into the neon haze of the city!\n");
    } else {
        printf("Caught in the act! You need to fight or hack your way out!\n");
    }
}

void quit() {
    printf("You chose to quit the game. Living on the edge is not for everyone.\n");
    exit(0);
}

void displayScene(Scene scene) {
    printf("\n=== %s ===\n", scene.title);
    printf("%s\n", scene.description);
    for (int i = 0; i < scene.option_count; i++) {
        printf("%d: %s\n", i + 1, scene.options[i].description);
    }
}

void proceed(int choice, Scene scene) {
    if (choice > 0 && choice <= scene.option_count) {
        scene.options[choice - 1].action();
    } else {
        printf("Invalid choice, try again.\n");
    }
}

int main() {
    srand(time(NULL));

    Scene startingScene = {
        "Neon District: Arrival",
        "You've just landed in the Neon District, where cyborgs roam and hackers rule. What will you do?",
        {
            {"Fight a local gang member", fight},
            {"Attempt to hack into a local terminal", hack},
            {"Try to escape into the shadows", escape},
            {"Quit the game", quit}
        },
        4
    };

    while (1) {
        displayScene(startingScene);
        
        int choice = 0;
        printf("Enter your choice (1-%d): ", startingScene.option_count);
        scanf("%d", &choice);
        
        proceed(choice, startingScene);
    }

    return 0;
}
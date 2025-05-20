//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define NAME_LENGTH 10
#define NUM_QUESTS 3

// Prototypes
void startGame(int numQuests);
void playGame(int numQuests);
void makeDecision(int numQuests);
void showMenu();
void playQuest(int questNum);
void showQuest(int questNum);
void playCharacter(int characterNum);
void showCharacter(int characterNum);
void playLocation(int locationNum);
void showLocation(int locationNum);
void playItem(int itemNum);
void showItem(int itemNum);
void playText(int textNum);
void showText(int textNum);

int main() {
    int numQuests;
    int characterNum;
    int locationNum;
    int itemNum;
    int textNum;

    srand(time(0));

    startGame(NUM_QUESTS);

    return 0;
}

void startGame(int numQuests) {
    printf("Welcome to the Adventure Game!\n");
    printf("There are %d quests to choose from.\n", numQuests);
    printf("Which quest would you like to play?\n");
    printf("1. Quest 1\n");
    printf("2. Quest 2\n");
    printf("3. Quest 3\n");
    printf("4. Exit\n");
    printf("Please choose a number: ");
    scanf("%d", &numQuests);

    if (numQuests < 1 || numQuests > NUM_QUESTS) {
        printf("Invalid choice. Please try again.\n");
        startGame(NUM_QUESTS);
    } else {
        playGame(numQuests);
    }
}

void playGame(int numQuests) {
    int choice;
    int decision;

    while (1) {
        showMenu();
        printf("Please choose a number: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playQuest(numQuests);
                break;
            case 2:
                playCharacter(numQuests);
                break;
            case 3:
                playLocation(numQuests);
                break;
            case 4:
                printf("Thank you for playing the Adventure Game!\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("What would you like to do next?\n");
        printf("1. Make a decision\n");
        printf("2. View more information\n");
        printf("3. Exit\n");
        printf("Please choose a number: ");
        scanf("%d", &decision);

        if (decision == 1) {
            makeDecision(numQuests);
        } else if (decision == 2) {
            showQuest(numQuests);
            showCharacter(numQuests);
            showLocation(numQuests);
            showItem(numQuests);
            showText(numQuests);
        } else if (decision == 3) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void makeDecision(int numQuests) {
    int choice;
    int decision;

    while (1) {
        showMenu();
        printf("Please choose a number: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                decision = 1;
                break;
            case 2:
                decision = 2;
                break;
            case 3:
                decision = 3;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        if (decision == 1) {
            printf("You made a good decision!\n");
        } else if (decision == 2) {
            printf("You made a bad decision!\n");
        } else if (decision == 3) {
            printf("You made a neutral decision!\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void showMenu() {
    printf("What would you like to do next?\n");
    printf("1. Play a quest\n");
    printf("2. Play a character\n");
    printf("3. Play a location\n");
    printf("4. Play an item\n");
    printf("5. Play a text\n");
    printf("6. Exit\n");
}

void playQuest(int numQuests) {
    int questNum;

    while (1) {
        showQuest(numQuests);
        printf("Which quest would you like to play?\n");
        printf("1. Quest 1\n");
        printf("2. Quest 2\n");
        printf("3. Quest 3\n");
        printf("4. Exit\n");
        printf("Please choose a number: ");
        scanf("%d", &questNum);

        if (questNum < 1 || questNum > NUM_QUESTS) {
            printf("Invalid choice. Please try again.\n");
            playQuest(numQuests);
        } else {
            playQuest(questNum);
        }
    }
}

void playCharacter(int numQuests) {
    int characterNum;

    while (1) {
        showCharacter(numQuests);
        printf("Which character would you like to play?\n");
        printf("1. Character 1\n");
        printf("2. Character 2\n");
        printf("3. Character 3\n");
        printf("4. Exit\n");
        printf("Please choose a number: ");
        scanf("%d", &characterNum);

        if (characterNum < 1 || characterNum > NUM_QUESTS) {
            printf("Invalid choice. Please try again.\n");
            playCharacter(numQuests);
        } else {
            playCharacter(characterNum);
        }
    }
}

void playLocation(int numQuests) {
    int locationNum;

    while (1) {
        showLocation(numQuests);
        printf("Which location would you like to play?\n");
        printf("1. Location 1\n");
        printf("2. Location 2\n");
        printf("3. Location 3\n");
        printf("4. Exit\n");
        printf("Please choose a number: ");
        scanf("%d", &locationNum);

        if (locationNum < 1 || locationNum > NUM_QUESTS) {
            printf("Invalid choice. Please try again.\n");
            playLocation(numQuests);
        } else {
            playLocation(locationNum);
        }
    }
}

void playItem(int numQuests) {
    int itemNum;

    while (1) {
        showItem(numQuests);
        printf("Which item would you like to play?\n");
        printf("1. Item 1\n");
        printf("2. Item 2\n");
        printf("3. Item 3\n");
        printf("4. Exit\n");
        printf("Please choose a number: ");
        scanf("%d", &itemNum);

        if (itemNum < 1 || itemNum > NUM_QUESTS) {
            printf("Invalid choice. Please try again.\n");
            playItem(numQuests);
        } else {
            playItem(itemNum);
        }
    }
}

void playText(int numQuests) {
    int textNum;

    while (1) {
        showText(numQuests);
        printf("Which text would you like to play?\n");
        printf("1. Text 1\n");
        printf("2. Text 2\n");
        printf("3. Text 3\n");
        printf("4. Exit\n");
        printf("Please choose a number: ");
        scanf("%d", &textNum);

        if (textNum < 1 || textNum > NUM_QUESTS) {
            printf("Invalid choice. Please try again.\n");
            playText(numQuests);
        } else {
            playText(textNum);
        }
    }
}

void showQuest(int numQuests) {
    printf("Quest %d:\n", numQuests);
    printf("You are a brave adventurer who has been tasked with defeating a powerful dragon.\n");
    printf("You have three choices: you can choose to fight the dragon, try to reason with it, or flee.\n");
    printf("What would you like to do?\n");
}

void showCharacter(int numQuests) {
    printf("Character %d:\n", numQuests);
    printf("You are a kind-hearted wizard who has been tasked with protecting a small village from an army of goblins.\n");
    printf("You have three choices: you can choose to cast a spell, use a weapon, or run away.\n");
    printf("What would you like to do?\n");
}

void showLocation(int numQuests) {
    printf("Location %d:\n", numQuests);
    printf("You are a daring explorer who has been tasked with exploring a mysterious cave.\n");
    printf("You have three choices: you can choose to explore deeper into the cave, search for treasure, or leave.\n");
    printf("What would you like to do?\n");
}

void showItem(int numQuests) {
    printf("Item %d:\n", numQuests);
    printf("You are a resourceful adventurer who has been tasked with finding a rare artifact.\n");
    printf("You have three choices: you can choose to use a tool, talk to a NPC, or leave.\n");
    printf("What would you like to do?\n");
}

void showText(int numQuests) {
    printf("Text %d:\n", numQuests);
    printf("You are a curious explorer who has been tasked with exploring an ancient ruin.\n");
    printf("You have three choices: you can choose to read a book, examine a statue, or leave.\n");
    printf("What would you like to do?\n");
}
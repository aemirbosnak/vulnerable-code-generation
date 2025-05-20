//Falcon-180B DATASET v1.0 Category: Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void startGame();
void displayMenu();
void playGame();
void endGame();

int main() {
    srand(time(NULL)); // Seed the random number generator
    startGame();
    return 0;
}

void startGame() {
    printf("Welcome to Cyberpunk 2077!\n");
    printf("You are a hacker trying to infiltrate a corporate database.\n");
    printf("Choose your character:\n");
    printf("1. Male\n2. Female\n3. Non-binary\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("You are a male hacker.\n");
    } else if (choice == 2) {
        printf("You are a female hacker.\n");
    } else {
        printf("You are a non-binary hacker.\n");
    }
    printf("Press any key to continue...\n");
    getchar();
    system("clear"); // Clear the console
    displayMenu();
}

void displayMenu() {
    printf("Choose an action:\n");
    printf("1. Hack into the database\n2. Check your inventory\n3. Save game\n4. Load game\n5. Quit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            playGame();
            break;
        case 2:
            printf("You have:\n- A hacking device\n- A cyberdeck\n- A neural interface\n");
            break;
        case 3:
            printf("Game saved!\n");
            break;
        case 4:
            printf("Game loaded!\n");
            break;
        case 5:
            endGame();
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    printf("Press any key to continue...\n");
    getchar();
    system("clear"); // Clear the console
    displayMenu();
}

void playGame() {
    int success = rand() % 2; // Randomly determine success or failure
    if (success == 0) {
        printf("You successfully hacked into the database!\n");
    } else {
        printf("You failed to hack into the database.\n");
    }
    printf("Press any key to continue...\n");
    getchar();
    system("clear"); // Clear the console
}

void endGame() {
    printf("Thanks for playing Cyberpunk 2077!\n");
    exit(0);
}
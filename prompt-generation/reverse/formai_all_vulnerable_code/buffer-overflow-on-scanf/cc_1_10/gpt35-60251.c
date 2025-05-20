//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void clearScreen();
void printDivider();
void printIntro();
void startGame();
void enterCastle();
void exploreDungeon();
void battle();
int generateRandom(int min, int max);
void printGameOver();

int main()
{
    srand(time(NULL)); // Initialize random number generator with current time
    clearScreen();
    printIntro();
    startGame();

    return 0;
}

void clearScreen()
{
    system("clear");
}

void printDivider()
{
    printf("\n==========================================\n\n");
}

void printIntro()
{
    printf("Welcome to the Medieval Adventure Game!\n");
    printf("In this game, you will embark on a quest to slay the dragon and save the kingdom.\n");
    printf("You will need to explore the castle, battle monsters, and discover hidden treasures.\n");
    printf("Are you ready to begin?\n\n");
    printf("Press enter to continue...");
    getchar();
    clearScreen();
}

void startGame()
{
    printf("You stand outside the castle gate.\n");
    printf("You can:\n");
    printf("1) Enter the castle\n");
    printf("2) Quit the game\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        enterCastle();
        break;
    case 2:
        printf("Thanks for playing!\n");
        exit(0);
        break;
    default:
        printf("Invalid choice. Please try again.\n");
        startGame();
        break;
    }
}

void enterCastle()
{
    printf("You enter the castle and find yourself in the great hall.\n");
    printf("You can:\n");
    printf("1) Explore the dungeon\n");
    printf("2) Leave the castle\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        exploreDungeon();
        break;
    case 2:
        startGame();
        break;
    default:
        printf("Invalid choice. Please try again.\n");
        enterCastle();
        break;
    }
}

void exploreDungeon()
{
    printf("You descend into the dungeon and come face to face with a monster!\n");
    printf("Prepare for battle!\n");
    battle();
}

void battle()
{
    int playerHealth = 100;
    int monsterHealth = generateRandom(50, 100);

    char playerName[20];
    printf("What is your name, brave warrior?\n");
    scanf("%s", playerName);

    printf("%s: %d health\n", playerName, playerHealth);
    printf("Monster: %d health\n", monsterHealth);

    while (playerHealth > 0 && monsterHealth > 0)
    {
        printf("\n%s's turn.\n", playerName);
        printf("Choose your action:\n");
        printf("1) Attack\n");
        printf("2) Defend\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("%s attacks the monster!\n", playerName);
            monsterHealth -= generateRandom(10, 20);
            printf("Monster: %d health\n", monsterHealth);
            break;
        case 2:
            printf("%s defends!\n", playerName);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

        if (monsterHealth <= 0)
        {
            printf("Congratulations, %s! You have defeated the monster!\n", playerName);
            printf("You find a chest containing a rare treasure!\n");
            printGameOver();
        }

        printf("\nMonster's turn.\n");
        playerHealth -= generateRandom(5, 15);
        printf("%s takes damage!\n", playerName);
        printf("%s: %d health\n", playerName, playerHealth);

        if (playerHealth <= 0)
        {
            printf("You have been defeated by the monster...\n");
            printGameOver();
        }
    }
}

int generateRandom(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void printGameOver()
{
    printf("\n\n==========================================\n");
    printf("Game Over!\n");
    printf("Thanks for playing the Medieval Adventure Game!\n");
    printf("==========================================\n");
    exit(0);
}
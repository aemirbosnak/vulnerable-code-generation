//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

int main()
{
    time_t t;
    srand((unsigned) time(&t));

    // Game setup
    int health = 100;
    int level = 1;
    int xp = 0;
    bool gameOver = false;
    char name[20];

    printf("Welcome to the Adventure Game!\n");
    printf("Please enter your character's name: ");
    scanf("%s", name);
    printf("\nHello, %s! Let's begin your adventure.\n", name);

    while (!gameOver)
    {
        // Randomly generated challenge
        int challenge = rand() % 3;
        int challengeDifficulty = rand() % (level * 10) + 1;

        switch (challenge)
        {
            case 0: // Combat challenge
                printf("\nYou have encountered an enemy!\n");
                printf("The enemy's level is %d.\n", challengeDifficulty);

                // Battle simulation
                while (health > 0)
                {
                    int playerAttack = rand() % (level * 5) + 1;
                    int enemyAttack = rand() % (challengeDifficulty * 5) + 1;

                    printf("\nYou attacked the enemy for %d damage.\n", playerAttack);
                    challengeDifficulty -= playerAttack;

                    if (challengeDifficulty <= 0)
                    {
                        xp += level * 10;
                        printf("\nCongratulations! You have defeated the enemy.\n");
                        printf("You have earned %d xp.\n", level * 10);
                        break;
                    }

                    printf("The enemy attacked you for %d damage.\n", enemyAttack);
                    health -= enemyAttack;

                    if (health <= 0)
                    {
                        printf("\nGame over! You have been defeated.\n");
                        gameOver = true;
                        break;
                    }
                }

                break;

            case 1: // Treasure challenge
                printf("\nYou have stumbled upon a treasure chest!\n");
                printf("The chest requires a code to open.\n");

                // Code cracking simulation
                int code = rand() % (level * 5) + 1;
                int attempts = 3;

                while (attempts > 0)
                {
                    int guess;
                    printf("\nEnter your guess (1-%d): ", level * 5);
                    scanf("%d", &guess);

                    if (guess == code)
                    {
                        int treasure = rand() % (level * 10) + 1;
                        printf("\nCongratulations! You have cracked the code!\n");
                        printf("You have found %d treasure.\n", treasure);
                        xp += level * 5;
                        printf("You have earned %d xp.\n", level * 5);
                        break;
                    }
                    else
                    {
                        attempts--;
                        printf("\nIncorrect code! You have %d attempts remaining.\n", attempts);
                    }
                }

                if (attempts == 0)
                {
                    printf("\nYou have failed to crack the code. Better luck next time.\n");
                }

                break;

            case 2: // Puzzle challenge
                printf("\nYou have come across a strange puzzle...\n");
                printf("Solve the puzzle within %d seconds to earn xp.\n", level * 5);

                // Puzzle solving simulation
                time_t startTime, endTime;
                int timeLimit = level * 5;
                int solution = rand() % (level * 10) + 1;

                printf("\nThe puzzle is: What is %d multiplied by %d?\n", level * 5, level * 10);

                time(&startTime);

                int answer;
                printf("Enter your answer: ");
                scanf("%d", &answer);

                time(&endTime);

                int timeElapsed = (int) difftime(endTime, startTime);

                if (timeElapsed <= timeLimit && answer == (level * 5) * (level * 10))
                {
                    int puzzleReward = rand() % (level * 5) + 1;
                    printf("\nYou solved the puzzle in time and earned %d xp!\n", puzzleReward);
                    xp += puzzleReward;
                }
                else
                {
                    printf("\nTime's up or incorrect answer. Better luck next time.\n");
                }

                break;
        }

        if (xp >= level * 20)
        {
            level++;
            health = 100;
            printf("\nCongratulations! You have leveled up to level %d.\n", level);
        }
    }

    return 0;
}
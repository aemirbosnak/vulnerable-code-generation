//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main() {
    char playerName[20];
    int playerAge;
    int playerHealth = 100;
    int playerScore = 0;
    int playerCoins = 0;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);

    printf("Please enter your age: ");
    scanf("%d", &playerAge);

    if (playerAge < 18) {
        printf("Sorry, you must be 18 or older to play this game.\n");
        return 0;
    }

    printf("\n%s, you have entered the haunted house. You have %d health points, %d coins and %d score points.\n\n",
            playerName, playerHealth, playerCoins, playerScore);

    int roomNumber = 1; // Start in room 1
    int numberOfRooms = 10; // The house has 10 rooms

    while (roomNumber <= numberOfRooms && playerHealth > 0) { // Keep playing until all rooms are explored or player dies
        printf("You are in room %d.\n", roomNumber);

        int roomType = generateRandomNumber(1, 3); // Generate a random room type

        if (roomType == 1) { // Monster room
            printf("Oh no! You have encountered a monster in this room!\n");
            int monsterHealth = generateRandomNumber(50, 100); // Generate a random monster health
            printf("The monster has %d health points. You have to defeat him!\n", monsterHealth);
            printf("Press 1 to attack the monster, press 2 to run away.\n");
            int playerChoice;
            scanf("%d", &playerChoice);
            if (playerChoice == 1) { // Player chooses to attack
                int playerAttack = generateRandomNumber(10, 20); // Generate a random player attack damage
                printf("You have attacked the monster and dealt %d damage points.\n", playerAttack);
                monsterHealth -= playerAttack; // Decrease monster health by playerAttack
                if (monsterHealth <= 0) { // Monster is defeated
                    printf("Congratulations, you have defeated the monster and gained 10 score points and 2 coins!\n");
                    playerScore += 10;
                    playerCoins += 2;
                }
                else { // Monster is still alive
                    printf("The monster has %d health points left. He counters your attack with his own attack.\n", monsterHealth);
                    int monsterAttack = generateRandomNumber(5, 15); // Generate a random monster attack damage
                    printf("The monster has attacked you and dealt %d damage points.\n", monsterAttack);
                    playerHealth -= monsterAttack; // Decrease player health by monsterAttack
                    if (playerHealth <= 0) { // Player dies
                        printf("Sorry, you have died. Game over.\n");
                        return 0;
                    }
                }
            }
            else { // Player chooses to run away
                printf("You have run away from the monster and gained 1 score point.\n");
                playerScore += 1;
            }
        }
        else if (roomType == 2) { // Treasure room
            printf("Yay! You have found a treasure chest in this room!\n");
            int treasureCoins = generateRandomNumber(5, 10); // Generate a random number of coins
            printf("The chest contains %d coins. You have gained them!\n", treasureCoins);
            playerCoins += treasureCoins; // Increase player coins by treasureCoins
            int treasureScore = generateRandomNumber(10, 20); // Generate a random treasure score
            printf("You have also gained %d score points.\n", treasureScore);
            playerScore += treasureScore; // Increase player score by treasureScore
        }
        else { // Puzzle room
            printf("You have found a puzzle in this room!\n");
            printf("The puzzle is to guess the correct number between 1 and 10.\n");
            int puzzleAnswer = generateRandomNumber(1, 10); // Generate a random puzzle answer
            int playerGuess;
            scanf("%d", &playerGuess); // Get player guess
            if (playerGuess == puzzleAnswer) { // Player guess is correct
                printf("Congratulations, you have solved the puzzle and gained 5 score points and 1 coin!\n");
                playerScore += 5;
                playerCoins += 1;
            }
            else { // Player guess is incorrect
                printf("Sorry, your guess is incorrect. The correct answer was %d.\n", puzzleAnswer);
            }
        }

        printf("You have %d health points, %d coins and %d score points.\n\n",
                playerHealth, playerCoins, playerScore);

        roomNumber++; // Move to the next room
    }

    // All rooms are explored or player is dead
    if (playerHealth > 0) {
        printf("Congratulations, you have explored all the rooms in the haunted house and gained %d score points!\n", playerScore);
    }
    else {
        printf("Sorry, you have died before exploring all the rooms. Game over.\n");
    }

    return 0;
}
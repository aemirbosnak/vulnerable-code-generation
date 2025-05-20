//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROLLS 50

void rollDice(int rolls[], int numRolls);
void displayResults(int rolls[], int numRolls);
void prizeDistribution(int rolls[], int numRolls);
void displayInstructions();

int main() {
    int rolls[MAX_ROLLS];
    int numRolls, i;

    // Seed the random number generator
    srand(time(NULL));

    displayInstructions();

    printf("Enter the number of times to roll the dice (max %d): ", MAX_ROLLS);
    scanf("%d", &numRolls);

    if (numRolls < 1 || numRolls > MAX_ROLLS) {
        printf("Invalid number of rolls! Please restart the program.\n");
        return 1;
    }

    rollDice(rolls, numRolls);
    displayResults(rolls, numRolls);
    prizeDistribution(rolls, numRolls);

    return 0;
}

void rollDice(int rolls[], int numRolls) {
    for (int i = 0; i < numRolls; i++) {
        rolls[i] = (rand() % 6) + 1; // Roll a dice (1 to 6)
    }
}

void displayResults(int rolls[], int numRolls) {
    printf("\n--- Dice Roll Results ---\n");
    for (int i = 0; i < numRolls; i++) {
        printf("Roll %d: %d\n", i + 1, rolls[i]);
    }
}

void prizeDistribution(int rolls[], int numRolls) {
    int sum = 0;
    int count[7] = {0}; // Array to count the frequency of each dice face (1-6)

    for (int i = 0; i < numRolls; i++) {
        sum += rolls[i];
        count[rolls[i]]++; // Increment the corresponding face count
    }

    // Display the summary
    printf("\n--- Summary ---\n");
    printf("Total Rolls: %d\n", numRolls);
    printf("Sum of Rolls: %d\n", sum);
    printf("Average Roll: %.2f\n", (float)sum / numRolls);
    
    printf("\nRoll Frequency:\n");
    for (int i = 1; i <= 6; i++) {
        printf("Face %d: %d times\n", i, count[i]);
    }

    // Prize deduction based on average roll
    float average = (float)sum / numRolls;
    if (average == 6) {
        printf("Congratulations! You rolled a perfect average of 6! 🎉\n");
    } else if (average >= 5) {
        printf("Great job! Your average roll was %.2f, you get a small prize! 🏆\n", average);
    } else if (average >= 3) {
        printf("Not bad! Your average roll was %.2f, keep trying for better! 🎈\n", average);
    } else {
        printf("Oh no! Your average roll was %.2f. Better luck next time! 🙁\n", average);
    }
}

void displayInstructions() {
    printf("Welcome to the C Dice Roller!\n");
    printf("You can roll a six-sided die up to %d times.\n", MAX_ROLLS);
    printf("The program will display the results, a summary, and a prize based on your rolls.\n");
    printf("Let's have some fun!\n\n");
}
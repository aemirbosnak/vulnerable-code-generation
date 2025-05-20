//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int numDice;
	int numSides;
	int i, j;
	int roll;
	int sum = 0;
	int maxRoll = 0;
	int minRoll = 100;
	int numRolls = 0;
	char playAgain;

	srand(time(0)); // Seed the random number generator

	printf("Welcome to the Dice Roller!\n");

	printf("How many dice would you like to roll? ");
	scanf("%d", &numDice);

	printf("How many sides should each dice have? ");
	scanf("%d", &numSides);

	printf("Rolling %d %d-sided dice...\n", numDice, numSides);

	for (i = 0; i < numDice; i++) {

		roll = rand() % numSides + 1; // Roll the dice

		printf("Dice %d rolled a %d.\n", i + 1, roll);

		sum += roll; // Add the roll to the total sum

		if (roll > maxRoll) {
			maxRoll = roll; // Update the maximum roll
		}

		if (roll < minRoll) {
			minRoll = roll; // Update the minimum roll
		}

		numRolls++; // Increment the number of rolls
	}

	printf("\nTotal sum: %d\n", sum);
	printf("Max roll: %d\n", maxRoll);
	printf("Min roll: %d\n", minRoll);
	printf("Average roll: %.2f\n", (float)sum / numRolls);

	printf("\nPlay again? (y/n): ");
	scanf(" %c", &playAgain);

	if (playAgain == 'y' || playAgain == 'Y') {
		main(); // Play again
	}

	return 0;
}
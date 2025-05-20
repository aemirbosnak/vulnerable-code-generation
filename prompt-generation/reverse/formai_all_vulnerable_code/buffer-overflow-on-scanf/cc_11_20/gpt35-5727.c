//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	// Seed the random number generator
	srand(time(0));
	
	// Define the haunted house map
	char houseMap[10][10] = {
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
		{'#', '.', '#', '.', '.', '#', '.', '#', '.', '#'},
		{'#', '.', '#', '.', '#', '#', '.', '#', '.', '#'},
		{'#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
		{'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
		{'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
	};
	
	// Define starting position of the player
	int playerX = 1;
	int playerY = 1;
	
	// Define variable to track if the player found the exit
	int foundExit = 0;
	
	// Define variable to track if the player is alive
	int isAlive = 1;
	
	// Define the main game loop
	while (isAlive && !foundExit) {
		// Clear the screen
		system("clear");
		
		// Display the haunted house map
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				// Check if the player is at this position
				if (i == playerY && j == playerX) {
					printf("X");
				} else {
					printf("%c", houseMap[i][j]);
				}
			}
			printf("\n");
		}
		
		// Ask the player for input
		printf("Use WASD to move: ");
		char input;
		scanf(" %c", &input);
		
		// Move the player based on input
		switch (input) {
			case 'w':
				if (houseMap[playerY - 1][playerX] != '#') {
					playerY--;
				}
				break;
			case 'a':
				if (houseMap[playerY][playerX - 1] != '#') {
					playerX--;
				}
				break;
			case 's':
				if (houseMap[playerY + 1][playerX] != '#') {
					playerY++;
				}
				break;
			case 'd':
				if (houseMap[playerY][playerX + 1] != '#') {
					playerX++;
				}
				break;
		}
		
		// Check if the player found the exit
		if (houseMap[playerY][playerX] == 'E') {
			foundExit = 1;
			printf("\nCongratulations! You found the exit!\n");
		}
		
		// Check if the player is dead
		if (houseMap[playerY][playerX] == '#' || (rand() % 4 == 0)) {
			isAlive = 0;
			printf("\nOh no! You died.\n");
		}
	}
	
	return 0;
}
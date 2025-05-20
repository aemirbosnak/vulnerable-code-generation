//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

void takeOff() {
	printf("Taking off...\n");
}

void land() {
	printf("Landing...\n");
}

void moveUp(int height) {
	printf("Moving up to altitude %d...\n", height);
}

void moveDown(int height) {
	printf("Moving down to altitude %d...\n", height);
}

void moveLeft(int distance) {
	printf("Moving left %d meters...\n", distance);
}

void moveRight(int distance) {
	printf("Moving right %d meters...\n", distance);
}

int main() {
	int input;
	int height = 0;
	int distance = 0;
	
	printf("Welcome to the C Drone Remote Control!\n");
	
	do {
		printf("\nEnter 1 to take off, 2 to land, 3 to move up, 4 to move down, 5 to move left, 6 to move right, and 0 to exit: ");
		scanf("%d", &input);
		
		switch(input) {
			case 1:
				takeOff();
				break;
			case 2:
				land();
				break;
			case 3:
				printf("Enter altitude: ");
				scanf("%d", &height);
				moveUp(height);
				break;
			case 4:
				printf("Enter altitude: ");
				scanf("%d", &height);
				moveDown(height);
				break;
			case 5:
				printf("Enter distance: ");
				scanf("%d", &distance);
				moveLeft(distance);
				break;
			case 6:
				printf("Enter distance: ");
				scanf("%d", &distance);
				moveRight(distance);
				break;
			case 0:
				printf("Exiting program...\n");
				break;
			default:
				printf("Invalid input. Please enter a number between 0 and 6.\n");
				break;
		}
	} while(input != 0);
	
	return 0;
}
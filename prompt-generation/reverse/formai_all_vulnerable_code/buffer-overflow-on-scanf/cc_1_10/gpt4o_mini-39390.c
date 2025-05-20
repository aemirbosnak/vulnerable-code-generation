//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: real-life
#include <stdio.h>

// Function to perform Tower of Hanoi
void towerOfHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, target);
    printf("Move disk %d from %c to %c\n", n, source, target);
    towerOfHanoi(n - 1, auxiliary, target, source);
}

// Function to simulate a real-life scenario of moving boxes
void moveBoxes(int n, char source, char target, char auxiliary) {
    printf("Starting the process of moving %d boxes from %c to %c using %c as buffer.\n", n, source, target, auxiliary);
    towerOfHanoi(n, source, target, auxiliary);
    printf("All boxes have been moved from %c to %c.\n", source, target);
}

// Function to find a suitable number of boxes to move
int chooseNumberOfBoxes() {
    int numBoxes;

    printf("Enter the number of boxes you need to move (1-10): ");
    while (1) {
        if (scanf("%d", &numBoxes) != 1 || numBoxes < 1 || numBoxes > 10) {
            printf("Invalid input. Please enter a number between 1 and 10: ");
            while(getchar() != '\n'); // clear the invalid input
        } else {
            break;
        }
    }
    return numBoxes;
}

int main() {
    int numBoxes;
    char source = 'A';
    char target = 'C';
    char auxiliary = 'B';

    // Display a welcome message
    printf("Welcome to the Box Moving Simulator!\n");
    printf("You can simulate moving boxes from one location to another using the Tower of Hanoi method.\n");

    // Get the number of boxes to move
    numBoxes = chooseNumberOfBoxes();

    // Move boxes using the Tower of Hanoi method
    moveBoxes(numBoxes, source, target, auxiliary);

    printf("Thank you for using the Box Moving Simulator. Have a great day!\n");
    
    return 0;
}
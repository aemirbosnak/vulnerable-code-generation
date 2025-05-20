//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int level = 1; // Variable to track the game level
    int score = 0; // Variable to track the player score
    int lives = 3; // Variable to track the remaining lives of the player
    int num1, num2, operation; // Variables to store the operands and operator of the math problem
    int answer; // Variable to store the user's answer
    srand(time(NULL)); // Initialize the random number generator seed
    
    printf("\n*** Welcome to Math Maze ***\n");
    printf("Reach the end of the maze to progress to the next level!\n");
    printf("Enter the correct answer to the math problem to move forward.\n");
    printf("Remember, you only have 3 lives!\n\n");
    
    while (lives > 0) { // Loop until the player runs out of lives
        printf("\n***** Level %d *****\n", level);
        printf("Score: %d\n", score);
        printf("Lives: %d\n\n", lives);
        
        num1 = (rand() % 10) + 1; // Generate a random integer between 1 and 10
        num2 = (rand() % 10) + 1;
        operation = rand() % 3; // Generate a random integer between 0 and 2
        
        switch (operation) {
            case 0:
                printf("What is %d + %d?\n", num1, num2);
                answer = num1 + num2;
                break;
            case 1:
                printf("What is %d - %d?\n", num1, num2);
                answer = num1 - num2;
                break;
            case 2:
                printf("What is %d * %d?\n", num1, num2);
                answer = num1 * num2;
                break;
        }
        
        int playerAnswer; // Variable to hold user's answer
        scanf("%d", &playerAnswer);
        
        if (playerAnswer == answer) { // if user answer matches with correct answer and increase score by 1
            printf("\nCorrect! You may proceed to the next level.\n");
            score++;
            if (score % 3 == 0) { // Increase level every 3 correct answers
                level++;
            }
        } else { 
            printf("\nWrong answer! You have lost one life.\n");
            lives--; // Decrease remaining lives by 1
        }
    }
    
    printf("\nGAME OVER!\n");
    printf("Your final score: %d\n", score);
    printf("Better luck next time!\n");
    
    return 0;
}
//FormAI DATASET v1.0 Category: Robot movement control ; Style: energetic
// Welcome to the energetic world of C Robot movement control! 

// First, let's import some necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Let's define some constants to represent our robot's movements
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

// Next, let's define a function to generate a random movement for our robot
int generate_random_movement() {
    // Set the seed for our random number generator
    srand(time(NULL));
    
    // Generate a random number between 1 and 4
    int random_number = (rand() % 4) + 1;
    
    return random_number;
}

// Now, let's define our main function
int main() {
    // Initialize our robot's starting position and score
    int x_pos = 0;
    int y_pos = 0;
    int score = 0;
    
    // Print a welcome message and instructions for our user
    printf("Welcome to C Robot movement control!\n");
    printf("Your goal is to navigate the robot through the maze and collect as many points as possible.\n");
    printf("Use the following commands to control the robot:\n");
    printf("1. 'f' to move forward\n");
    printf("2. 'b' to move backward\n");
    printf("3. 'l' to turn left\n");
    printf("4. 'r' to turn right\n");
    
    // Loop until the user decides to quit
    while(1) {
        // Generate a random movement for our robot
        int movement = generate_random_movement();
        
        // Print out the current position and score of our robot
        printf("Current Position: (%d, %d) | Score: %d\n", x_pos, y_pos, score);
        
        // Prompt the user for their next move
        printf("Enter your next move: ");
        char user_move;
        scanf(" %c", &user_move);
        
        // Process the user's move
        switch(user_move) {
            case 'f':
                if(movement == FORWARD) {
                    printf("You moved forward!\n");
                    y_pos++;
                    score += 10;
                }
                else {
                    printf("You did not move forward.\n");
                    score -= 5;
                }
                break;
            case 'b':
                if(movement == BACKWARD) {
                    printf("You moved backward!\n");
                    y_pos--;
                    score += 10;
                }
                else {
                    printf("You did not move backward.\n");
                    score -= 5;
                }
                break;
            case 'l':
                if(movement == LEFT) {
                    printf("You turned left!\n");
                    x_pos--;
                    score += 5;
                }
                else {
                    printf("You did not turn left.\n");
                    score -= 2;
                }
                break;
            case 'r':
                if(movement == RIGHT) {
                    printf("You turned right!\n");
                    x_pos++;
                    score += 5;
                }
                else {
                    printf("You did not turn right.\n");
                    score -= 2;
                }
                break;
            case 'q':
                printf("Thanks for playing!\n");
                return 0;
            default:
                printf("Invalid move!\n");
                score -= 2;
                break;
        }
        
        // Check if our robot has reached the end of the maze and exit the loop if so
        if(x_pos == 10 && y_pos == 10) {
            printf("Congratulations, you reached the end of the maze!\n");
            printf("Your final score is: %d\n", score);
            break;
        }
    }
    
    return 0;
}
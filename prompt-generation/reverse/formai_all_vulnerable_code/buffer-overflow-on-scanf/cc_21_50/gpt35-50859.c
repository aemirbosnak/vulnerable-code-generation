//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, outcome = 0, room = 1, health = 100; // initial values for the game
    srand(time(NULL)); // seeding the random number generator
    
    printf("Welcome to the Mathematical Adventure!\n\n"); // welcome message
    
    while (outcome == 0) { // game loop continues until outcome is set to 1 or 2
        
        switch (room) { // switch case for each room
            
            case 1:
                printf("You are in room 1. Choose a path:\n1. Path A\n2. Path B\n3. Quit the game\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You have chosen Path A.\n");
                    room = 2;
                }
                else if (choice == 2) {
                    printf("You have chosen Path B.\n");
                    room = 3;
                }
                else if (choice == 3) {
                    printf("Quitting the game...");
                    outcome = 2;
                }
                else {
                    printf("Invalid choice.\n");
                }
                break;
                
            case 2:
                printf("You are in room 2. Solve the following equation to proceed:\n");
                int a = rand() % 10, b = rand() % 10, c = rand() % 10; // random coefficients
                int answer = (a * 2) + b + c;
                printf("%d x + %d y + %d z = ?\n", a, b, c);
                scanf("%d", &choice);
                if (choice == answer) {
                    printf("Correct answer! You can proceed to the next room.\n");
                    room = 4;
                }
                else {
                    printf("Wrong answer! You have lost 20 health points.\n");
                    health -= 20;
                    if (health <= 0) {
                        printf("You have no health points left. Game Over.\n");
                        outcome = 1;
                    }
                    else {
                        printf("You can try again in the same room.\n");
                    }
                }
                break;
                
            case 3:
                printf("You are in room 3. Find the derivative of the following function to proceed:\n");
                printf("f(x) = x^3 + 2x^2 - 4x + 7\n");
                printf("Enter your solution: ");
                scanf("%d", &choice);
                if (choice == 3) {
                    printf("Correct answer! You can proceed to the next room.\n");
                    room = 5;
                }
                else {
                    printf("Wrong answer! You have lost 20 health points.\n");
                    health -= 20;
                    if (health <= 0) {
                        printf("You have no health points left. Game Over.\n");
                        outcome = 1;
                    }
                    else {
                        printf("You can try again in the same room.\n");
                    }
                }
                break;
                
            case 4:
                printf("You are in room 4. Choose a number between 1 and 10: ");
                scanf("%d", &choice);
                if (choice < 1 || choice > 10) {
                    printf("Invalid choice. You have lost 20 health points.\n");
                    health -= 20;
                    if (health <= 0) {
                        printf("You have no health points left. Game Over.\n");
                        outcome = 1;
                    }
                    else {
                        printf("You can try again in the same room.\n");
                    }
                }
                else if (choice == 7) {
                    printf("Correct answer! You can proceed to the next room.\n");
                    room = 6;
                }
                else {
                    printf("Wrong answer! You have lost 20 health points.\n");
                    health -= 20;
                    if (health <= 0) {
                        printf("You have no health points left. Game Over.\n");
                        outcome = 1;
                    }
                    else {
                        printf("You can try again in the same room.\n");
                    }
                }
                break;
                
            case 5:
                printf("You are in room 5. Complete the following sequence to proceed:\n");
                printf("2, 3, 5, 7, 11, ?\n");
                scanf("%d", &choice);
                if (choice == 13) {
                    printf("Correct answer! You can proceed to the next room.\n");
                    room = 7;
                }
                else {
                    printf("Wrong answer! You have lost 20 health points.\n");
                    health -= 20;
                    if (health <= 0) {
                        printf("You have no health points left. Game Over.\n");
                        outcome = 1;
                    }
                    else {
                        printf("You can try again in the same room.\n");
                    }
                }
                break;
                
            case 6:
                printf("You are in room 6. You have reached the treasure!\nCongratulations!\n");
                outcome = 1;
                break;
                
            case 7:
                printf("You are in room 7. Solve the following inequality to proceed:\n");
                printf("(x - 3)/2 >= 5\n");
                printf("Enter your solution: ");
                scanf("%d", &choice);
                if (choice == 13) {
                    printf("Correct answer! You can proceed to the next room.\n");
                    room = 6;
                }
                else {
                    printf("Wrong answer! You have lost 20 health points.\n");
                    health -= 20;
                    if (health <= 0) {
                        printf("You have no health points left. Game Over.\n");
                        outcome = 1;
                    }
                    else {
                        printf("You can try again in the same room.\n");
                    }
                }
                break;
                
            default:
                printf("Invalid room. Quitting the game...");
                outcome = 2;
        }
    }
    return 0;
}
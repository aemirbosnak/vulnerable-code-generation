//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random integer within a given range
int generateRandomNumber(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

// Function for the game room scene
void gameRoom(int* score) {
    printf("You are in a room with a gaming console in front of you.\n");
    printf("There are three games available to play: a shooter, a puzzle, and a racing game.\n");
    printf("Which game do you want to play?\n");
    
    char choice[10];
    scanf("%s", &choice);
    
    if (strcmp(choice, "shooter") == 0) {
        printf("\nYou have chosen the shooter game.\n");
        (*score) += generateRandomNumber(1, 10); // Add random score between 1-10
    }
    else if (strcmp(choice, "puzzle") == 0) {
        printf("\nYou have chosen the puzzle game.\n");
        (*score) += generateRandomNumber(5, 15); // Add random score between 5-15
    }
    else if (strcmp(choice, "racing") == 0) {
        printf("\nYou have chosen the racing game.\n");
        (*score) += generateRandomNumber(10, 20); // Add random score between 10-20
    }
    else {
        printf("\nInvalid choice! Please try again.\n");
    }
}

// Function for the kitchen scene
void kitchen(int* score) {
    printf("You are in a kitchen with a fridge and a cupboard.\n");
    printf("Which one do you want to open?\n");
    
    char choice[10];
    scanf("%s", &choice);
    
    if (strcmp(choice, "fridge") == 0) {
        printf("\nYou have opened the fridge and found a sandwich.\n");
        (*score) += 5; // Add 5 points for finding a sandwich
    }
    else if (strcmp(choice, "cupboard") == 0) {
        printf("\nYou have opened the cupboard and found a packet of chips.\n");
        (*score) += 10; // Add 10 points for finding chips
    }
    else {
        printf("\nInvalid choice! Please try again.\n");
    }
}

// Main function for the game
int main() {
    srand(time(0)); // Initialize random seed
    
    int score = 0;
    
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Your objective is to explore different rooms and gain as many points as possible.\n");
    
    while(1) {
        printf("\n");
        printf("Enter 'game' to enter the game room.\n");
        printf("Enter 'kitchen' to enter the kitchen.\n");
        printf("Enter 'score' to check your current score.\n");
        printf("Enter 'exit' to quit the game.\n");
        
        char choice[10];
        scanf("%s", &choice);
        
        if (strcmp(choice, "game") == 0) {
            gameRoom(&score);
        }
        else if (strcmp(choice, "kitchen") == 0) {
            kitchen(&score);
        }
        else if (strcmp(choice, "score") == 0) {
            printf("\nYour current score is %d.\n", score);
        }
        else if (strcmp(choice, "exit") == 0) {
            printf("\nThanks for playing! Your final score is %d.\n", score);
            break; // Exit the while loop and end the game
        }
        else {
            printf("\nInvalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
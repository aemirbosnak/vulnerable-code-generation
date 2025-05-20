//FormAI DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user_choice, computer_choice;
    int user_score = 0, computer_score = 0;
    int rounds = 1;
    srand(time(NULL)); // Initialize random seed 
    
    printf("Welcome to Rock Paper Scissors game!\n");
    
    while(rounds <= 5) {
        printf("\nRounds %d\n", rounds);
        printf("Select your choice:\n");
        printf("1 - Rock\n2 - Paper\n3 - Scissors\n");
        scanf("%d", &user_choice);
        
        if(user_choice < 1 || user_choice > 3) { // Handle invalid input
            printf("Invalid input. Please choose between 1 to 3.\n");
            continue; // Restart the loop
        }
        
        computer_choice = rand() % 3 + 1; // Randomly generate computer's choice 
        printf("Computer chooses: ");
        
        switch(computer_choice) {
            case 1:
                printf("Rock\n");
                break;
            case 2:
                printf("Paper\n");
                break;
            case 3:
                printf("Scissors\n");
                break;
        }
        
        // Check user vs computer choices 
        if(user_choice == computer_choice) {
            printf("It's a tie.\n");
        }
        else if((user_choice == 1 && computer_choice == 3) ||
                (user_choice == 2 && computer_choice == 1) ||
                (user_choice == 3 && computer_choice == 2)) {
            printf("You won!\n");
            user_score++;
        }
        else {
            printf("You lost.\n");
            computer_score++;
        }
        
        rounds++;
    }
    
    // Display final score 
    printf("\nGame over!\n");
    printf("Your score: %d\nComputer score: %d\n", user_score, computer_score);
    
    if(user_score > computer_score) {
        printf("You win!\n");
    }
    else if(user_score < computer_score) {
        printf("Computer wins.\n");
    }
    else {
        printf("It's a tie.\n");
    }
    
    return 0;
}
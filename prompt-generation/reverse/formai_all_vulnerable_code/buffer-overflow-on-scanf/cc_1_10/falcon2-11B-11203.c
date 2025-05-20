//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>

// Function to generate a random number between 1 and 10
int getRandomNumber() 
{ 
    return (rand() % 10) + 1; 
} 

// Function to play the game
void playGame() 
{ 
    // Generate a secret number 
    int secretNumber = getRandomNumber(); 
    
    // Print out the game rules 
    printf("Guess the secret number!\n"); 
    printf("You have 3 chances to guess the correct number.\n"); 
    
    // Ask user for their guess 
    int guess; 
    printf("Enter your guess (1-10): "); 
    scanf("%d", &guess); 
    
    // Compare the guess with the secret number 
    while (guess!= secretNumber) 
    { 
        // If user guesses correctly, congratulate them 
        if (guess == secretNumber) 
        { 
            printf("Congratulations! You guessed correctly.\n"); 
            break; 
        } 
        // If user runs out of tries, tell them they lost 
        else if (guess > secretNumber) 
        { 
            printf("Sorry, your guess was too high.\n"); 
        } 
        else 
        { 
            printf("Sorry, your guess was too low.\n"); 
        } 
        // Ask user to try again 
        printf("Try again: "); 
        scanf("%d", &guess); 
    } 
    
    // Display the results 
    if (guess == secretNumber) 
    { 
        printf("You won!\n"); 
    } 
    else 
    { 
        printf("You lost!\n"); 
    } 
} 

// Main function 
int main() 
{ 
    playGame(); 
    
    return 0; 
}
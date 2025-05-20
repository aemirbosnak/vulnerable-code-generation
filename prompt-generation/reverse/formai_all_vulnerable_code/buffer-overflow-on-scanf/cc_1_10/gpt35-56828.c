//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate a random number between min and max
int random_generator(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

// Function to determine the result of the player's choice
int determine_result(int choice, int alien_choice) {
    if (choice == alien_choice) {
        return 0; // tie
    }
    else if (choice == 1 && alien_choice == 3) {
        return 1; // player wins
    }
    else if (choice == 2 && alien_choice == 1) {
        return 1; // player wins
    }
    else if (choice == 3 && alien_choice == 2) {
        return 1; // player wins
    }
    else {
        return -1; // player loses
    }
}

// Function to display the player's available choices
void display_choices() {
    printf("1. Laser Gun\n");
    printf("2. Plasma Sword\n");
    printf("3. Atomic Bomb\n");
}

// Function to display the result of the game
void display_result(int result) {
    if (result == 0) {
        printf("It's a tie!\n");
    }
    else if (result == 1) {
        printf("You defeated the alien!\n");
    }
    else {
        printf("The alien defeated you!\n");
    }
}

// Main function to run the game
int main() {
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You have been challenged to a battle by an alien!\n");
    printf("Choose your weapon:\n");
    display_choices();
    
    int player_choice;
    scanf("%d", &player_choice);
    
    int alien_choice = random_generator(1, 3);
    printf("The alien chose weapon %d\n", alien_choice);
    
    int result = determine_result(player_choice, alien_choice);
    display_result(result);
    
    return 0;
}
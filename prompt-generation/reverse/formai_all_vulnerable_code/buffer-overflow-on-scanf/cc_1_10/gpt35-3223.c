//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 3
#define ROOMS 5

int main() {
    srand(time(NULL)); // initialize random seed
    int current_room = 1; // start in room 1
    int room_guesses[ROOMS] = {0}; // array to track guesses for each room
    int total_guesses = 0; // track total number of guesses
    int game_over = 0; // flag to end game
    
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You are currently in Room 1. You have %d guesses for each room.\n", MAX_GUESSES);
    
    // game loop
    while (!game_over) {
        int guess_count = 1; // start with 1 guess
        int room_number = current_room; // start in current room
        
        // check if player has used all their guesses in this room
        if (room_guesses[room_number - 1] >= MAX_GUESSES) {
            printf("You have used all your guesses in this room! Move to another room to continue.\n");
            printf("You are currently in Room %d. You have %d guesses for each room.\n", current_room, MAX_GUESSES);
            continue; // jump back to start of game loop
        }
        
        printf("Enter guess #%d for Room %d: ", room_guesses[room_number - 1] + 1, room_number);
        int guess;
        scanf("%d", &guess);
        
        // check if guess is correct
        if (guess == rand() % 10 + 1) {
            printf("Congratulations! You have guessed the correct number.\n\n");
            room_guesses[room_number - 1]++; // increment guess count
            total_guesses++; // increment total guess count
            
            // check if player has found the exit
            if (current_room == ROOMS) {
                printf("You have successfully escaped the haunted house in %d total guesses!\n\n", total_guesses);
                game_over = 1;
            }
            else {
                current_room++; // move to next room
                printf("You are now in Room %d. You have %d guesses for each room.\n", current_room, MAX_GUESSES);
            }
        }
        else {
            printf("Sorry, that guess is incorrect. Please try again.\n");
            room_guesses[room_number - 1]++; // increment guess count
            
            // check if player has used all their guesses in this room
            if (room_guesses[room_number - 1] >= MAX_GUESSES) {
                printf("You have used all your guesses in this room! Move to another room to continue.\n");
                printf("You are currently in Room %d. You have %d guesses for each room.\n", current_room, MAX_GUESSES);
            }
        }
    }
    
    return 0;
}
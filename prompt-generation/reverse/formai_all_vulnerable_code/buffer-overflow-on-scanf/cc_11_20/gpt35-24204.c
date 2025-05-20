//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {

    // Setting up the rules for the game

    printf("\n======================================================================\n\n");
    printf("Welcome to the Haunted House Simulator! You need to navigate through a spooky\n");
    printf("house and find the key that unlocks the way out. But beware, there are ghosts\n");
    printf("and other supernatural beings lurking behind every corner.\n\n");
    printf("You only have five chances to find the key. Good luck!\n\n");
    printf("======================================================================\n\n");
    
    // Initializing the game variables

    int key_location, player_choice, chances_left = 5;
    bool found_key = false;
    
    // Generating random location of key
    
    srand(time(NULL));
    key_location = rand() % 3 + 1;
    
    // Beginning the game
    
    while(chances_left > 0 && !found_key) {
        
        // Displaying the current game status and prompt for player input
        
        printf("\nYou are in room %d. You have %d chance(s) left.\n", player_choice, chances_left);
        printf("Choose a door to enter (1, 2, or 3): ");
        scanf("%d", &player_choice);
        
        // Checking player input
        
        if(player_choice < 1 || player_choice > 3) {
            printf("Invalid choice! Choose a door between 1 and 3.\n");
            continue;
        }
        
        // Checking if key is found
        
        if(player_choice == key_location) {
            printf("\nYou found the key! You have successfully unlocked the way out!\n");
            found_key = true;
            break;
        }
        
        // If key is not found, decrement chances left and display a spooky message
        
        chances_left--;
        switch(rand() % 5) {
            case 0:
                printf("\nYou hear a loud creaking noise behind you, but no one is there.\n");
                break;
            case 1:
                printf("\nA sudden gust of wind blows out all the candles in the room.\n");
                break;
            case 2:
                printf("\nYou see a ghostly apparition looming in the distance.\n");
                break;
            case 3:
                printf("\nAn invisible hand pushes you back as you try to open the door.\n");
                break;
            case 4:
                printf("\nThe room suddenly goes pitch black and you can't see anything.\n");
                break;
        }
    }
    
    // Displaying end game message
    
    if(found_key == false) {
        printf("\nYou have run out of chances! The ghosts of the house have claimed another victim.\n");
        printf("\nThe key was in room %d. Better luck next time!\n", key_location);
    }
    
    return 0;
}
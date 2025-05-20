//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player_score = 0;
    int ghost_attack = 0;
    int room_number = 1;
    char play_again;
    srand(time(NULL)); // Seed the random number generator
    
    do {
        printf("Welcome to the Haunted House Simulator!\n");
        printf("You are in Room %d.\n", room_number);
        printf("Enter 1 to move to the next room, or 2 to stay in this room.\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) { // Move to the next room
            room_number++;
            ghost_attack = rand() % room_number; // Generate a random attack value
            printf("You move to the next room.\n");
            printf("Suddenly, a ghost appears!\n");
            printf("It attacks you for %d points of damage!\n", ghost_attack);
            player_score -= ghost_attack;
            if (player_score < 0) {
                printf("You have died. Game over.\n");
                printf("Your final score is %d.\n", player_score);
                return 0;
            }
        }
        else if (choice == 2) { // Stay in the room
            int treasure = rand() % room_number; // Generate a random treasure value
            printf("You stay in this room.\n");
            printf("You find %d points of treasure!\n", treasure);
            player_score += treasure;
        }
        else { // Invalid choice
            printf("Invalid choice. Try again.\n");
        }
    } while (room_number <= 10); // End the game after 10 rooms
    
    printf("Congratulations, you have completed the Haunted House Simulator!\n");
    printf("Your final score is %d.\n", player_score);
    printf("Would you like to play again? (Y/N)\n");
    scanf(" %c", &play_again);
    if (play_again == 'Y' || play_again == 'y') {
        main(); // Restart the game
    }
    return 0;
}
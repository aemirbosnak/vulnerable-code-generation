//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Mystery House!\n");
    printf("You are lost in this creepy place and need to find your way out.\n");
    printf("You see two doors. Which one would you like to take?\n");
    printf("1. Door on the left\n");
    printf("2. Door on the right\n");
    
    int door_choice;
    scanf("%d", &door_choice);
    
    if (door_choice == 1) {
        printf("\nYou open the door and enter a dark room.\n");
        printf("Suddenly, the door slams shut behind you!\n");
        printf("You hear a faint whisper...\n");
        printf("\"Your time is up...\"\n\n");
        printf("GAME OVER.\n");
    } else if (door_choice == 2) {
        printf("\nYou open the door and step inside.\n");
        printf("The room is dimly lit and you see a shadowy figure in the corner.\n");
        printf("What would you like to do?\n");
        printf("1. Walk towards the figure\n");
        printf("2. Ignore the figure and search the room\n");
        
        int room_choice;
        scanf("%d", &room_choice);
        
        if (room_choice == 1) {
            printf("\nAs you approach the figure, it suddenly disappears.\n");
            printf("You feel a cold breeze and hear a loud scream...\n\n");
            printf("GAME OVER.\n");
        } else if (room_choice == 2) {
            printf("\nYou search the room and find a key!\n");
            printf("This must be the key to the front door.\n");
            printf("You quickly make your way out of the room and towards the front door.\n");
            printf("As you approach the door, you hear footsteps behind you...\n");
            printf("What would you like to do?\n");
            printf("1. Turn around and face the footsteps\n");
            printf("2. Flee through the front door\n");
            
            int action_choice;
            scanf("%d", &action_choice);
            
            if (action_choice == 1) {
                printf("\nYou turn around to face the footsteps and see a ghostly figure.\n");
                printf("You feel a chill go down your spine as it approaches you...\n\n");
                printf("GAME OVER.\n");
            } else if (action_choice == 2) {
                printf("\nYou quickly unlock the door and make your escape.\n");
                printf("As you exit the Mystery House, you feel a sense of relief wash over you.\n");
                printf("You made it out alive!\n\n");
                printf("CONGRATULATIONS, YOU WON!\n");
            } else {
                printf("\nInvalid choice.\n");
                printf("GAME OVER.\n");
            }
        } else {
            printf("\nInvalid choice.\n");
            printf("GAME OVER.\n");
        }
    } else {
        printf("\nInvalid choice.\n");
        printf("GAME OVER.\n");
    }
    
    return 0;
}
//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

void play_the_game()
{
    char answer;
    int room_num = 1;

    // Loop until the player chooses to leave the room
    while (room_num != 0)
    {
        // Print the current room description
        switch (room_num)
        {
            case 1:
                printf("You are in a dimly lit room with a single flickering light bulb. There is a door to the east and a mysterious box on the table.\n");
                break;
            case 2:
                printf("You are in a spacious hall with a long, winding corridor. There is a door to the south and a secret passage to the east.\n");
                break;
            case 3:
                printf("You are in a hidden chamber with a treasure chest and a bunch of gold coins.\n");
                break;
        }

        // Get the player's answer
        printf("What do you want to do? (e.g. go east, open box, etc.) ");
        scanf("%c", &answer);

        // Process the player's answer
        switch (answer)
        {
            case 'e':
                room_num = 2;
                break;
            case 'o':
                // Open the box and reveal a secret message
                printf("You opened the box and found a secret message: 'The key to victory is in the hidden chamber.'\n");
                room_num = 3;
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }
    }

    // The player has left the room
    printf("Thank you for playing. You have escaped the room.\n");
}

int main()
{
    play_the_game();

    return 0;
}
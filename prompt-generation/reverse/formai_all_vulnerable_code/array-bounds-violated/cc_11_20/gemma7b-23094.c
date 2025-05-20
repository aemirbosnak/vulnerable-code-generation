//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int choice, rand_num, current_room = 1, inventory[] = {0, 0, 0}, room_map[] = {1, 2, 3, 4, 5};

    // Display room description
    switch (current_room)
    {
        case 1:
            printf("You are in a dimly lit tavern.\n");
            break;
        case 2:
            printf("You are in a grand hall.\n");
            break;
        case 3:
            printf("You are in a creepy dungeon.\n");
            break;
        case 4:
            printf("You are in a mysterious forest.\n");
            break;
        case 5:
            printf("You are in a hidden chamber.\n");
            break;
    }

    // Get user input
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    // Randomly generate a number
    rand_num = rand() % 3;

    // Check if the user's choice is valid
    if (choice > 0 && choice <= 3)
    {
        // Move to the next room
        current_room = room_map[choice] + rand_num;

        // Add item to inventory
        inventory[current_room] = 1;

        // Display room description
        switch (current_room)
        {
            case 1:
                printf("You have entered a new tavern.\n");
                break;
            case 2:
                printf("You have entered a secret chamber.\n");
                break;
            case 3:
                printf("You have entered a treacherous dungeon.\n");
                break;
            case 4:
                printf("You have entered a mysterious forest.\n");
                break;
            case 5:
                printf("You have entered a hidden chamber.\n");
                break;
        }

        // Check if the player has won
        if (current_room == 5)
        {
            printf("Congratulations! You have won the game!\n");
        }
    }
    else
    {
        printf("Invalid choice.\n");
    }

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, room_num = 1, inventory[] = {0, 0, 0}, item_num = 0;

    system("clear");

    // Display room description
    printf("You are in Room %d. It is a small room with a single bed and a dresser.\n", room_num);

    // Display inventory
    printf("Your inventory: ");
    for(int i = 0; i < item_num; i++)
    {
        if(inventory[i] != 0)
        {
            printf("%d ", inventory[i]);
        }
    }

    // Present options
    printf("\nWhat do you want to do? (1) Search the dresser, (2) Examine the bed, (3) Leave the room\n");

    // Get user input
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            // Code to search the dresser
            printf("You searched the dresser and found a key.\n");
            inventory[item_num++] = 1;
            break;
        case 2:
            // Code to examine the bed
            printf("You examined the bed and found a hidden compartment. You opened the compartment and found a map.\n");
            inventory[item_num++] = 2;
            break;
        case 3:
            // Code to leave the room
            printf("You left the room.\n");
            room_num = 2;
            break;
        default:
            printf("Invalid input.\n");
    }

    system("clear");

    // Display room description
    printf("You are in Room %d. It is a larger room with a table and chairs.\n", room_num);

    // Display inventory
    printf("Your inventory: ");
    for(int i = 0; i < item_num; i++)
    {
        if(inventory[i] != 0)
        {
            printf("%d ", inventory[i]);
        }
    }

    // Present options
    printf("\nWhat do you want to do? (1) Move forward, (2) Use the key, (3) Leave the room\n");

    // Get user input
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            // Code to move forward
            printf("You moved forward and found a secret room.\n");
            room_num = 3;
            break;
        case 2:
            // Code to use the key
            printf("You used the key and opened the secret room.\n");
            room_num = 3;
            break;
        case 3:
            // Code to leave the room
            printf("You left the room.\n");
            room_num = 2;
            break;
        default:
            printf("Invalid input.\n");
    }

    system("clear");

    // Display room description
    printf("You are in Room %d. It is a small room with a single bed and a dresser.\n", room_num);

    // Display inventory
    printf("Your inventory: ");
    for(int i = 0; i < item_num; i++)
    {
        if(inventory[i] != 0)
        {
            printf("%d ", inventory[i]);
        }
    }

    // Game over
    printf("\nGame Over!\n");

    return 0;
}
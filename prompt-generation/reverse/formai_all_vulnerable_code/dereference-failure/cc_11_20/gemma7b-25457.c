//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char choice;
    int room_num, treasure_found = 0;

    // Create a map of rooms
    char **map = (char**)malloc(5 * sizeof(char*));
    for (int i = 0; i < 5; i++)
    {
        map[i] = (char*)malloc(10 * sizeof(char));
    }

    // Initialize the map
    map[0][0] = 'A';
    map[0][1] = 'B';
    map[0][2] = 'C';
    map[1][0] = 'D';
    map[1][1] = 'E';
    map[1][2] = 'F';
    map[2][0] = 'G';
    map[2][1] = 'H';
    map[2][2] = 'I';
    map[3][0] = 'J';
    map[3][1] = 'K';
    map[3][2] = 'L';
    map[4][0] = 'M';
    map[4][1] = 'N';
    map[4][2] = 'O';

    // The adventure begins...
    printf("You wake up in a mysterious room. You have no memory of how you got here. A map is on the table in front of you.\n");

    // Display the map
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }

    // Get the player's choice
    printf("Please enter the letter of the room you want to go to: ");
    scanf("%c", &choice);

    // Move to the chosen room
    switch (choice)
    {
        case 'A':
            room_num = 0;
            break;
        case 'B':
            room_num = 1;
            break;
        case 'C':
            room_num = 2;
            break;
        case 'D':
            room_num = 3;
            break;
        case 'E':
            room_num = 4;
            break;
        default:
            printf("Invalid input.\n");
            return 1;
    }

    // Check if the treasure has been found
    if (map[room_num][0] == 'T')
    {
        treasure_found = 1;
    }

    // Display the results of the move
    printf("You have moved to room %c.\n", map[room_num][0]);

    // If the treasure has been found, the player wins
    if (treasure_found)
    {
        printf("Congratulations! You have found the treasure!\n");
    }

    // Free the memory allocated for the map
    for (int i = 0; i < 5; i++)
    {
        free(map[i]);
    }
    free(map);

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, room_num, treasure_found = 0;
    char name[20];

    printf("Welcome to the wondrous world of Text-Based Adventures! Please enter your name: ");
    scanf("%s", name);

    printf("Greetings, %s! You have found yourself in a mysterious mansion. You have no memory of how you got here, but you do know that there are three rooms to explore: the living room, the dining room, and the secret room. Which room would you like to enter? ", name);

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            room_num = 1;
            break;
        case 2:
            room_num = 2;
            break;
        case 3:
            room_num = 3;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            return;
    }

    // Each room has its own unique set of events and secrets
    switch (room_num)
    {
        case 1:
            printf("You enter the living room. There is a grand piano, a comfortable sofa, and a coffee table. You find a hidden key under the sofa. You have a feeling that this key is important.\n");
            treasure_found = 1;
            break;
        case 2:
            printf("You enter the dining room. There is a table, chairs, and a fireplace. You find a secret passage behind the bookshelf. You have unlocked a secret chamber.\n");
            treasure_found = 1;
            break;
        case 3:
            printf("You enter the secret room. There is a treasure chest, a map, and a sword. You have found the hidden treasure.\n");
            treasure_found = 1;
            break;
    }

    if (treasure_found)
    {
        printf("Congratulations, %s! You have found the hidden treasure!\n", name);
    }
    else
    {
        printf("Sorry, %s. You have not found the hidden treasure.\n", name);
    }

    return;
}
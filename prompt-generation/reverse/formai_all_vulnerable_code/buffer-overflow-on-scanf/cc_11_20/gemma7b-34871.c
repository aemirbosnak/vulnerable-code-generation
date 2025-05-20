//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    srand(time(NULL));
    int i, j, r;
    char c;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    system("cls");

    // Haunted House Entrance
    printf("\nWelcome to the Haunted House!\n");
    printf("Press any key to enter...");
    scanf("%c", &c);

    // Random Room Selection
    r = rand() % 10;
    i = a[r];
    j = b[r];

    // Room Description
    switch (i)
    {
        case 1:
            printf("\nYou find yourself in a dusty living room. The air is thick with the scent of decay and despair.\n");
            break;
        case 2:
            printf("\nYou enter a cluttered kitchen. The smell of burnt food and blood fills your senses.\n");
            break;
        case 3:
            printf("\nYou find yourself in a creepy bedroom. The bed is made, but the room is empty.\n");
            break;
        case 4:
            printf("\nYou enter a bloodstained hallway. The walls are covered in gore.\n");
            break;
        case 5:
            printf("\nYou find yourself in a dark and oppressive library. The bookshelves are filled with ancient texts.\n");
            break;
        case 6:
            printf("\nYou enter a ghostly ballroom. The music is playing, but there is no one there.\n");
            break;
        case 7:
            printf("\nYou find yourself in a blood-soaked bathroom. The mirror is covered in blood.\n");
            break;
        case 8:
            printf("\nYou enter a secret room. The walls are covered in hieroglyphics.\n");
            break;
        case 9:
            printf("\nYou find yourself in a haunted attic. The air is thick with the scent of decay and despair.\n");
            break;
        case 10:
            printf("\nYou enter a demonic portal. The world spins and you are gone.\n");
            break;
    }

    // Haunted House Exit
    printf("\nPress any key to leave...");
    scanf("%c", &c);

    return;
}
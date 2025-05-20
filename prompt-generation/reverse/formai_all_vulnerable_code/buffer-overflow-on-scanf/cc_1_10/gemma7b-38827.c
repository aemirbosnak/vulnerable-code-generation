//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: light-weight
#include <stdio.h>

int main()
{
    char current_room = 'a';
    int inventory[] = {0, 0, 0};

    while (1)
    {
        switch (current_room)
        {
            case 'a':
                printf("You are in the first room.\n");
                printf("There is a door to the north and a chest in the east.\n");
                break;
            case 'b':
                printf("You are in the second room.\n");
                printf("There is a door to the south and a key in the west.\n");
                break;
            case 'c':
                printf("You are in the third room.\n");
                printf("There is a door to the east and a treasure in the south.\n");
                break;
        }

        printf("What do you want to do? (north, south, east, west, use item): ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "north") == 0)
        {
            current_room = 'b';
        }
        else if (strcmp(command, "south") == 0)
        {
            current_room = 'a';
        }
        else if (strcmp(command, "east") == 0)
        {
            current_room = 'c';
        }
        else if (strcmp(command, "west") == 0)
        {
            // Use item logic
        }
        else if (strcmp(command, "use item") == 0)
        {
            printf("What item do you want to use? ");
            char item_name[20];
            scanf("%s", item_name);

            // Use item logic
        }
    }

    return 0;
}
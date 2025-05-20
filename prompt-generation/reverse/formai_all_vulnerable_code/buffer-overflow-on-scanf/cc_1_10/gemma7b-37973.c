//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

void goto_room(int room_num)
{
    switch (room_num)
    {
        case 1:
            printf("You are in a dimly lit tavern. The smell of ale and smoke hangs in the air. A lone bartender stands behind the bar, and a few patrons are huddled in the corner.\n");
            break;
        case 2:
            printf("You are in a dusty warehouse. The air is thick with the smell of decay and rust. A broken down machine sits in the center of the room, and a few crates are piled high against the walls.\n");
            break;
        case 3:
            printf("You are in a grand hall. The walls are adorned with intricate tapestries, and the ceiling is vaulted. A wealthy family sits in the center of the room, and a servant is attending to their needs.\n");
            break;
    }
}

int main()
{
    int room_num = 1;

    while (room_num != 3)
    {
        goto_room(room_num);

        printf("What do you want to do? (e.g. go north, go south, go east, go west)\n");
        char input[20];
        scanf("%s", input);

        if (strcmp(input, "go north") == 0)
        {
            room_num = 2;
        }
        else if (strcmp(input, "go south") == 0)
        {
            room_num = 1;
        }
        else if (strcmp(input, "go east") == 0)
        {
            room_num = 3;
        }
        else if (strcmp(input, "go west") == 0)
        {
            room_num = 1;
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }

    goto_room(room_num);

    printf("You have reached the end of the adventure.\n");

    return 0;
}
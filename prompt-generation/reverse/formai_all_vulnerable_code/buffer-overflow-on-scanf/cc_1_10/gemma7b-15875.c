//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int choice;
    printf("You have stumbled upon an abandoned Victorian mansion. Do you dare enter?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("You cautiously open the creaking oak door and step inside. The air is thick with the scent of decay and despair.\n");
        printf("A cold wind whips through the halls, carrying with it the whispers of the dead. You hear the sound of your own heartbeat echoing through the empty rooms.\n");

        int room_num = rand() % 3 + 1;
        switch (room_num)
        {
            case 1:
                printf("You find yourself in a dimly lit parlor, filled with ghostly figures dancing to a sinister tune.\n");
                break;
            case 2:
                printf("You stumble upon a bloodstained dining hall, where a gruesome massacre has taken place.\n");
                break;
            case 3:
                printf("You enter a shadowy bedroom, where the remnants of a former life linger.\n");
                break;
        }

        printf("Suddenly, you hear a loud bang and a chilling scream. You turn around to find a ghostly figure standing behind you, its eyes burning with rage.\n");
        printf("The figure's voice is dripping with hate as it tells you that you are not welcome in the mansion. It demands that you leave, but you are trapped in a labyrinth of winding corridors and dead ends.\n");

        int escape_choice = rand() % 2 + 1;
        switch (escape_choice)
        {
            case 1:
                printf("You frantically search for a way to escape, but the ghostly figure is too close. You hear its footsteps approaching and feel its cold hand brush against your skin.\n");
                break;
            case 2:
                printf("You try to flee, but the ghostly figure is too quick. It grabs you and drags you deeper into the mansion.\n");
                break;
        }
    }
    else
    {
        printf("You turn around and flee, leaving the haunted mansion behind.\n");
    }

    return 0;
}
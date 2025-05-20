//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

void play_game()
{
    int choice, room, inventory[5] = {0, 0, 0, 0, 0};
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    room = 1;
    while (room)
    {
        switch (room)
        {
            case 1:
                printf("You are in the Entrance Hall.\n");
                printf("You see a door to the North and a door to the East.\n");
                printf("What do you want to do? (N/E): ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    room = 2;
                }
                else if (choice == 2)
                {
                    room = 3;
                }
                else
                {
                    printf("Invalid input.\n");
                }
                break;

            case 2:
                printf("You are in the Living Room.\n");
                printf("You see a door to the South and a door to the West.\n");
                printf("What do you want to do? (S/W): ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    room = 1;
                }
                else if (choice == 2)
                {
                    room = 4;
                }
                else
                {
                    printf("Invalid input.\n");
                }
                break;

            case 3:
                printf("You are in the Kitchen.\n");
                printf("You see a door to the East and a door to the South.\n");
                printf("What do you want to do? (E/S): ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    room = 2;
                }
                else if (choice == 2)
                {
                    room = 5;
                }
                else
                {
                    printf("Invalid input.\n");
                }
                break;

            case 4:
                printf("You are in the Bedroom.\n");
                printf("You see a door to the North and a door to the West.\n");
                printf("What do you want to do? (N/W): ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    room = 2;
                }
                else if (choice == 2)
                {
                    room = 3;
                }
                else
                {
                    printf("Invalid input.\n");
                }
                break;

            case 5:
                printf("You are in the Garden.\n");
                printf("You see a door to the South and a door to the East.\n");
                printf("What do you want to do? (S/E): ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    room = 3;
                }
                else if (choice == 2)
                {
                    room = 1;
                }
                else
                {
                    printf("Invalid input.\n");
                }
                break;
        }

        if (inventory[0] == 1 && inventory[1] == 1)
        {
            printf("You have won!\n");
            room = 0;
        }
    }

    printf("Thank you for playing, %s!\n", name);
}

int main()
{
    play_game();

    return 0;
}
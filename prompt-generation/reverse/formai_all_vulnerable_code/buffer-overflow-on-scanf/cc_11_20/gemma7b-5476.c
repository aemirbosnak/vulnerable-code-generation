//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, inventory[] = {0, 0, 0}, room = 1, secret_flag = 0;

    system("clear");
    printf("You wake up in a dim, cold, and empty apartment. The only sound is your breathing and the ticking clock.\n");

    while (room != 3)
    {
        switch (room)
        {
            case 1:
                printf("You find a dusty box in the corner of the room. It's slightly ajar. What do you do?\n");
                scanf("%d", &choice);

                switch (choice)
                {
                    case 1:
                        inventory[0] = 1;
                        room = 2;
                        break;
                    case 2:
                        inventory[1] = 1;
                        room = 2;
                        break;
                    case 3:
                        room = 3;
                        break;
                    default:
                        printf("Invalid input. Please try again.\n");
                }
                break;

            case 2:
                printf("You hear a noise in the hallway and feel a cold hand brush against your arm. You have two options. You can either run or try to fight back.\n");
                scanf("%d", &choice);

                switch (choice)
                {
                    case 1:
                        room = 3;
                        break;
                    case 2:
                        inventory[2] = 1;
                        room = 3;
                        break;
                    default:
                        printf("Invalid input. Please try again.\n");
                }
                break;

            case 3:
                if (secret_flag == 0)
                {
                    printf("You find a hidden key and a secret message. The message leads you to a hidden room.\n");
                    secret_flag = 1;
                }
                else
                {
                    printf("You already found the secret message. There is nothing else to do here.\n");
                }
                break;
        }
    }

    return 0;
}
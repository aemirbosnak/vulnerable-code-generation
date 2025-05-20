//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, flag = 0, room = 1;
    char name[20];

    printf("Please enter your name: ");
    scanf("%s", name);

    while (flag == 0)
    {
        switch (room)
        {
            case 1:
                printf("You are in a dusty attic. You hear a scratching sound.\n");
                printf("1. Investigate the sound.\n");
                printf("2. Search for a way out.\n");
                scanf("%d", &choice);

                switch (choice)
                {
                    case 1:
                        room = 2;
                        break;
                    case 2:
                        room = 3;
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }

                break;
            case 2:
                printf("You hear a ticking sound and smell burning rubber.\n");
                printf("1. Try to find the source of the sound.\n");
                printf("2. Try to escape.\n");
                scanf("%d", &choice);

                switch (choice)
                {
                    case 1:
                        room = 3;
                        break;
                    case 2:
                        flag = 1;
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }

                break;
            case 3:
                printf("You are in a burning room. You see a way out.\n");
                printf("1. Try to escape.\n");
                printf("2. Try to put out the fire.\n");
                scanf("%d", &choice);

                switch (choice)
                {
                    case 1:
                        flag = 1;
                        break;
                    case 2:
                        room = 2;
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }

                break;
        }
    }

    printf("Thank you, %s. You have survived the adventure.\n", name);
}
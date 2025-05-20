//FormAI DATASET v1.0 Category: Smart home light control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int room, light;
    char option;

    printf("Welcome to the Smart Home Light Control System\n");

    do
    {
        printf("\nEnter the room number (1-5): ");
        scanf("%d", &room);
        
        if(room < 1 || room > 5)
        {
            printf("\nInvalid Room Number! Please try again.\n");
            continue;
        }

        printf("\nEnter the light number (1-3): ");
        scanf("%d", &light);

        if(light < 1 || light > 3)
        {
            printf("\nInvalid Light Number! Please try again.\n");
            continue;
        }

        printf("\nSelect the action you want to perform:\n");
        printf(" 1. Turn ON the light.\n");
        printf(" 2. Turn OFF the light.\n");
        printf(" 3. Get light status.\n");
        printf(" 4. Exit the system.\n");

        scanf(" %c", &option);

        switch(option)
        {
            case '1':
                printf("\nTurning ON the light %d in room %d.\n", light, room);
                break;
            case '2':
                printf("\nTurning OFF the light %d in room %d.\n", light, room);
                break;
            case '3':
                printf("\nThe light %d in room %d is currently ON.\n", light, room);
                break;
            case '4':
                printf("\nExiting the Smart Home Light Control System.\n");
                exit(0);
            default:
                printf("\nIncorrect option selected! Please try again.\n");
                break;
        }

    } while(1);

    return 0;
}
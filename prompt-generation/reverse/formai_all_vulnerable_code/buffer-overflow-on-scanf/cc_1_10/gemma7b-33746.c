//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20];
    printf("Please enter your name: ");
    scanf("%s", name);

    int room = 1;
    char **map = (char**)malloc(room * sizeof(char *));
    for(int i = 0; i < room; i++)
    {
        map[i] = (char*)malloc(20 * sizeof(char));
    }

    map[0][0] = 'A';
    map[0][1] = 'B';
    map[0][2] = 'C';
    map[1][0] = 'D';
    map[1][1] = 'E';

    int move = 0;
    while(move != -1)
    {
        printf("You are in room %d. There are three doors: A, B, C. Please enter the door you want to open: ", room);
        scanf("%d", &move);

        switch(move)
        {
            case 1:
                room = 2;
                break;
            case 2:
                printf("Sorry, that door is not open.");
                break;
            case 3:
                printf("You have chosen the wrong door.");
                break;
            default:
                printf("Invalid input.");
                break;
        }

        free(map[0]);
        free(map);
        map = (char**)malloc(room * sizeof(char *));
        for(int i = 0; i < room; i++)
        {
            map[i] = (char*)malloc(20 * sizeof(char));
        }

        map[0][0] = 'A';
        map[0][1] = 'B';
        map[0][2] = 'C';
        map[1][0] = 'D';
        map[1][1] = 'E';
    }

    printf("Thank you for playing, %s!", name);

    return 0;
}
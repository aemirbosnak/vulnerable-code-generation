//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x = 1, y = 1, z = 1, r = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    char ch;
    srand(time(NULL));

    printf("Welcome to the Labyrinth of Doom, traveler.\n");
    printf("You find yourself in a dark and twisted corridor.\n");

    while (1)
    {
        printf("Enter your command (look, north, south, east, west, attack): ");
        scanf("%c", &ch);

        switch (ch)
        {
            case 'l':
                printf("You see a glowing light ahead.\n");
                break;
            case 'n':
                y++;
                printf("You travel north.\n");
                break;
            case 's':
                y--;
                printf("You travel south.\n");
                break;
            case 'e':
                x++;
                printf("You travel east.\n");
                break;
            case 'w':
                x--;
                printf("You travel west.\n");
                break;
            case 'a':
                a = rand() % 3;
                switch (a)
                {
                    case 0:
                        printf("You attack a goblin and slay it.\n");
                        break;
                    case 1:
                        printf("You attack a troll and wound it.\n");
                        break;
                    case 2:
                        printf("You attack a dragon and damage it.\n");
                        break;
                }
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        if (x == 5 && y == 5)
        {
            printf("You have reached the center of the labyrinth. You have won!\n");
            break;
        }
    }

    return 0;
}
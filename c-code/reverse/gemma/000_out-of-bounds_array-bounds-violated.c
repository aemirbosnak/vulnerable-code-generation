#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int warrior_1_health = 100;
    int warrior_2_health = 100;

    while (warrior_1_health > 0 && warrior_2_health > 0)
    {
        int move_1 = rand() % 4;
        int move_2 = rand() % 4;

        switch (move_1)
        {
            case 0:
                warrior_1_health--;
                printf("Warrior 1 attacks and deals 1 damage.\n");
                break;
            case 1:
                warrior_2_health--;
                printf("Warrior 1 attacks and deals 1 damage.\n");
                break;
            case 2:
                printf("Warrior 1 moves randomly.\n");
                break;
            case 3:
                printf("Warrior 1 moves randomly.\n");
                break;
        }

        switch (move_2)
        {
            case 0:
                warrior_2_health--;
                printf("Warrior 2 attacks and deals 1 damage.\n");
                break;
            case 1:
                warrior_1_health--;
                printf("Warrior 2 attacks and deals 1 damage.\n");
                break;
            case 2:
                printf("Warrior 2 moves randomly.\n");
                break;
            case 3:
                printf("Warrior 2 moves randomly.\n");
                break;
        }
    }

    if (warrior_1_health <= 0)
    {
        printf("Warrior 1 wins!\n");
    }
    else
    {
        printf("Warrior 2 wins!\n");
    }

    return 0;
}

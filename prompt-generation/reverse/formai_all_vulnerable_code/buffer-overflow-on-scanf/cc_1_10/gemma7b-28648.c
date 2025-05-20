//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void play_adventure()
{
    char name[20];
    printf("What is your name, traveler?\n");
    scanf("%s", name);

    int location = 1;
    char map[5][5] = {
        { 'A', 'B', 'C', 'D', 'E' },
        { 'F', 'G', 'H', 'I', 'J' },
        { 'K', 'L', 'M', 'N', 'O' },
        { 'P', 'Q', 'R', 'S', 'T' },
        { 'U', 'V', 'W', 'X', 'Y' }
    };

    while (1)
    {
        switch (location)
        {
            case 1:
                printf("You are in a quaint village. You see a path leading north and south.\n");
                break;
            case 2:
                printf("You are in a forest. You see a path leading east and west.\n");
                break;
            case 3:
                printf("You are in a cave. You see a path leading south and east.\n");
                break;
            case 4:
                printf("You are in a mountain range. You see a path leading north and west.\n");
                break;
            case 5:
                printf("You have reached the final destination!\n");
                break;
            default:
                printf("Invalid location.\n");
                break;
        }

        int direction = 0;
        printf("Enter the direction you want to go (north, south, east, west): ");
        scanf("%d", &direction);

        switch (direction)
        {
            case 1:
                location++;
                break;
            case 2:
                location--;
                break;
            case 3:
                location += 2;
                break;
            case 4:
                location -= 2;
                break;
            default:
                printf("Invalid direction.\n");
                break;
        }
    }
}

int main()
{
    play_adventure();

    return 0;
}
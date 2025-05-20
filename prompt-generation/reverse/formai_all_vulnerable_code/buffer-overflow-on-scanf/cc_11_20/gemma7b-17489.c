//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void playGame(int currentRoom);

int main()
{
    playGame(1);
    return 0;
}

void playGame(int currentRoom)
{
    switch (currentRoom)
    {
        case 1:
            printf("You are in the first room. There is a door to the north and a door to the east.\n");
            printf("What direction do you want to go? (n/e): ");
            char direction;
            scanf("%c", &direction);

            switch (direction)
            {
                case 'n':
                    playGame(2);
                    break;
                case 'e':
                    playGame(3);
                    break;
                default:
                    printf("Invalid direction.\n");
                    playGame(1);
                    break;
            }
            break;

        case 2:
            printf("You are in the second room. There is a door to the south and a door to the west.\n");
            printf("What direction do you want to go? (s/w): ");
            direction = getchar();

            switch (direction)
            {
                case 's':
                    playGame(1);
                    break;
                case 'w':
                    playGame(4);
                    break;
                default:
                    printf("Invalid direction.\n");
                    playGame(2);
                    break;
            }
            break;

        case 3:
            printf("You are in the third room. There is a door to the east and a door to the south.\n");
            printf("What direction do you want to go? (e/s): ");
            direction = getchar();

            switch (direction)
            {
                case 'e':
                    playGame(2);
                    break;
                case 's':
                    playGame(5);
                    break;
                default:
                    printf("Invalid direction.\n");
                    playGame(3);
                    break;
            }
            break;

        case 4:
            printf("You are in the fourth room. There is a door to the west and a door to the north.\n");
            printf("What direction do you want to go? (w/n): ");
            direction = getchar();

            switch (direction)
            {
                case 'w':
                    playGame(2);
                    break;
                case 'n':
                    playGame(6);
                    break;
                default:
                    printf("Invalid direction.\n");
                    playGame(4);
                    break;
            }
            break;

        case 5:
            printf("You are in the fifth room. You have won the game!\n");
            break;

        case 6:
            printf("You are in the sixth room. There is a door to the east and a door to the south.\n");
            printf("What direction do you want to go? (e/s): ");
            direction = getchar();

            switch (direction)
            {
                case 'e':
                    playGame(4);
                    break;
                case 's':
                    playGame(7);
                    break;
                default:
                    printf("Invalid direction.\n");
                    playGame(6);
                    break;
            }
            break;

        case 7:
            printf("You are in the seventh room. There is a door to the west and a door to the north.\n");
            printf("What direction do you want to go? (w/n): ");
            direction = getchar();

            switch (direction)
            {
                case 'w':
                    playGame(6);
                    break;
                case 'n':
                    playGame(8);
                    break;
                default:
                    printf("Invalid direction.\n");
                    playGame(7);
                    break;
            }
            break;

        case 8:
            printf("You are in the eighth room. You have lost the game!\n");
            break;
    }
}
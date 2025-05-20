//FormAI DATASET v1.0 Category: Game ; Style: funny
/*Welcome to Drunk Adventure Game!
A game where you play as a drunk person trying to find their way home*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); //seeds the random number generator
    int steps = 0; //tracks the number of steps taken
    int direction = 0; //tracks the direction drunk person is currently facing
    int x = 0, y = 0; //tracks the position of the drunk person
    char playAgain = 'y'; //tracks if the user wants to play again or not

    printf("Welcome to Drunk Adventure Game!\n");
    printf("You are lost and trying to find your way home, but you are also very drunk.\n");
    printf("Let's see if you can make it home without passing out!\n");

    do //play until the user decides to quit
    {
        printf("\n\nYou are currently at (%d,%d) facing ", x, y);

        switch (direction)
        {
            case 0:
                printf("north");
                break;
            case 1:
                printf("east");
                break;
            case 2:
                printf("south");
                break;
            case 3:
                printf("west");
                break;
        }

        printf("\n\nWhat would you like to do?\n");
        printf("1 - take a step\n");
        printf("2 - turn left\n");
        printf("3 - turn right\n");
        printf("4 - go home (quit the game)\n");

        int choice = 0;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: //take a step
                steps++;
                int distance = rand() % 10 + 1; //take a random distance between 1 and 10
                printf("You stumble forward %d steps.\n", distance);

                switch (direction)
                {
                    case 0:
                        y += distance;
                        break;
                    case 1:
                        x += distance;
                        break;
                    case 2:
                        y -= distance;
                        break;
                    case 3:
                        x -= distance;
                        break;
                }

                printf("You are now at (%d,%d).\n", x, y);

                break;

            case 2: //turn left
                direction--;
                if (direction < 0)
                {
                    direction = 3;
                }
                printf("You turn left and are now facing ");
                switch (direction)
                {
                    case 0:
                        printf("north.\n");
                        break;
                    case 1:
                        printf("east.\n");
                        break;
                    case 2:
                        printf("south.\n");
                        break;
                    case 3:
                        printf("west.\n");
                        break;
                }

                break;

            case 3: //turn right
                direction++;
                if (direction > 3)
                {
                    direction = 0;
                }
                printf("You turn right and are now facing ");

                switch (direction)
                {
                    case 0:
                        printf("north.\n");
                        break;
                    case 1:
                        printf("east.\n");
                        break;
                    case 2:
                        printf("south.\n");
                        break;
                    case 3:
                        printf("west.\n");
                        break;
                }

                break;

            case 4: //quit the game
                printf("You give up and start passing out right there.\n");
                printf("You took %d steps before passing out... at least for now.\n", steps);
                printf("Thanks for playing Drunk Adventure Game! Bye!\n");
                playAgain = 'n'; //end the loop

                break;

            default: //invalid input
                printf("\nYou fumble around and can't figure out which way to go.\n");
                printf("You take another sip from your flasks and try again.\n");
                break;
        }

        if (abs(x) + abs(y) > 25)
        {
            printf("\nYou've wandered too far from home and start to feel more lost... and also sober.\n");
            printf("You take another sip and try to focus on finding your way back home.\n");
        }
        else if (x == 0 && y == 0)
        {
            printf("\nYou fall to the ground in a drunken stupor, right where you started.\n");
            printf("You took %d steps before passing out... at least for now.\n", steps);
            printf("Thanks for playing Drunk Adventure Game! Bye!\n");
            playAgain = 'n'; //end the loop
        }
        else
        {
            printf("\nYou take another sip from your flasks and stumble forward.\n");
        }

    } while (playAgain == 'y');

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int shape = 0, choice = 0;
    char name[20] = "";

    printf("Please enter your name: ");
    scanf("%s", name);

    while (1)
    {
        printf("What shape do you want to be? (1) human, (2) cat, (3) snake, (4) dragon: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                shape = 1;
                break;
            case 2:
                shape = 2;
                break;
            case 3:
                shape = 3;
                break;
            case 4:
                shape = 4;
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        if (shape)
        {
            switch (shape)
            {
                case 1:
                    printf("You are now human.\n");
                    break;
                case 2:
                    printf("You are now a cat.\n");
                    break;
                case 3:
                    printf("You are now a snake.\n");
                    break;
                case 4:
                    printf("You are now a dragon.\n");
                    break;
            }
        }

        printf("Would you like to continue? (y/n): ");
        scanf("%c", &choice);

        if (choice == 'n')
        {
            break;
        }
    }

    printf("Thank you for playing, %s. See you next time.\n", name);
    return 0;
}
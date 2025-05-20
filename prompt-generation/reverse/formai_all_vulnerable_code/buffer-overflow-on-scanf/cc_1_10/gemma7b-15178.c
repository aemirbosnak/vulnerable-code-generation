//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int shape = 0, choice = 0, i = 0;
    char name[20];

    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Welcome, %s! You have the ability to shape shift. Choose a shape: ", name);

    printf("1. Human\n");
    printf("2. Wolf\n");
    printf("3. Dragon\n");
    printf("4. Phoenix\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            shape = 1;
            printf("You have chosen to be human.\n");
            break;
        case 2:
            shape = 2;
            printf("You have chosen to be a wolf.\n");
            break;
        case 3:
            shape = 3;
            printf("You have chosen to be a dragon.\n");
            break;
        case 4:
            shape = 4;
            printf("You have chosen to be a phoenix.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    for (i = 0; i < 10; i++)
    {
        switch (shape)
        {
            case 1:
                printf("You are walking like a human.\n");
                break;
            case 2:
                printf("You are running like a wolf.\n");
                break;
            case 3:
                printf("You are soaring like a dragon.\n");
                break;
            case 4:
                printf("You are rising from the ashes like a phoenix.\n");
                break;
        }

        sleep(1);
    }

    return 0;
}
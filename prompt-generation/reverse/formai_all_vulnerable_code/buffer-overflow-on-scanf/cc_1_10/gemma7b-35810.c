//Gemma-7B DATASET v1.0 Category: Error handling ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void frog_voice(int);
void worm_slurping(char *);

int main()
{
    int choice = -1;
    char message[1024] = "";

    while (choice != 0)
    {
        printf("Please choose an option:\n");
        printf("1. Hear the frog's voice.\n");
        printf("2. Have the worm slurp a message.\n");
        printf("3. Quit.\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                frog_voice(42);
                break;
            case 2:
                worm_slurping(message);
                break;
            case 3:
                printf("Thank you for your time.\n");
                choice = 0;
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }

    return 0;
}

void frog_voice(int volume)
{
    printf("Ribbit! The frog is singing!\n");
    for (int i = 0; i < volume; i++)
    {
        printf("Bla bla bla...\n");
    }
}

void worm_slurping(char *message)
{
    printf("The worm is slurping...\n");
    message = "Yum yum yum";
    printf("%s\n", message);
}
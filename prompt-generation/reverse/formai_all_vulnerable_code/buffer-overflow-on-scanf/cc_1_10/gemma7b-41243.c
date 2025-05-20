//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    srand(time(NULL));

    int choice = 0;
    int spooky_house_num = rand() % 3;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Please choose an option:\n");
    printf("1. Enter the house\n");
    printf("2. Leave the house\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You have entered the haunted house.\n");
            printf("The doors slam shut.\n");
            printf("You hear a scream from the upstairs.\n");
            printf("Suddenly, the air becomes cold and you feel a presence watching you.\n");
            printf("Do you want to continue exploring? (Y/N) ");

            char cont_yn;
            scanf("%c", &cont_yn);

            if (cont_yn == 'Y')
            {
                // Spooky house 1
                if (spooky_house_num == 0)
                {
                    printf("You hear footsteps coming towards you.\n");
                    printf("You see a ghostly figure standing in the hallway.\n");
                    printf("The ghostly figure moves towards you and you feel its cold hand on your skin.\n");
                    printf("You scream and flee from the house.\n");
                }
                // Spooky house 2
                else if (spooky_house_num == 1)
                {
                    printf("You hear voices chanting in the house.\n");
                    printf("You see a bloodstained knife on the floor.\n");
                    printf("The voices grow louder and you feel like they are surrounding you.\n");
                    printf("You run from the house.\n");
                }
                // Spooky house 3
                else if (spooky_house_num == 2)
                {
                    printf("You hear a ringing telephone.\n");
                    printf("You answer the phone and hear a voice on the other end.\n");
                    printf("The voice tells you that you are trapped in the house.\n");
                    printf("You attempt to flee, but the voice won't let you.\n");
                    printf("You hear a scream from the upstairs. It's your own.\n");
                }
            }
            else
            {
                printf("You have left the haunted house.\n");
            }

            break;
        case 2:
            printf("You have left the haunted house.\n");
            break;
    }

    return;
}
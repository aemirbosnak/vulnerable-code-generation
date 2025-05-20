//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunt(int);

int main()
{
    int choice;
    printf("Welcome to the Haunted House of Montague and Capulet.\n");
    printf("Would you like to enter? (1/2): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        haunt(1);
    }
    else if (choice == 2)
    {
        haunt(2);
    }
    else
    {
        printf("Invalid input.\n");
    }

    return 0;
}

void haunt(int side)
{
    int i;
    char sound[20];
    time_t t;

    printf("You have chosen side %d.\n", side);

    for (i = 0; i < 5; i++)
    {
        t = time(NULL);
        srand(t);

        switch (side)
        {
            case 1:
                sprintf(sound, "Montague screams!");
                break;
            case 2:
                sprintf(sound, "Capulet cries!");
                break;
        }

        printf("%s\n", sound);

        sleep(rand() % 3);
    }

    printf("You have escaped the Haunted House of Montague and Capulet.\n");
}
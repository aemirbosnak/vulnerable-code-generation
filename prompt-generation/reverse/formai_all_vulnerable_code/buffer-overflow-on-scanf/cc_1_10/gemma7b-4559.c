//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunt(int);

int main()
{
    int choice;
    time_t t = time(NULL);
    srand(t);

    printf("Welcome to the Haunted House of Morrigan Manor.\n");
    printf("You find yourself in a dimly lit hallway. The only sound is your own breathing and the clock ticking.\n");

    do
    {
        printf("What do you want to do? (1 - Listen, 2 - Search, 3 - Leave): ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                haunt(1);
                break;
            case 2:
                haunt(2);
                break;
            case 3:
                printf("You flee the manor and escape the horrors that lay within.\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void haunt(int type)
{
    switch (type)
    {
        case 1:
            printf("Suddenly, a cold wind blows through the hallway, extinguishing the candle you hold.\n");
            printf("A disembodied voice whispers in your ear, 'You will not escape...'\n");
            break;
        case 2:
            printf("As you search, you find a hidden room filled with decaying furniture and bloodstained walls.\n");
            printf("The air is thick with the scent of decay and despair. A feeling of dread washes over you.\n");
            break;
    }
}
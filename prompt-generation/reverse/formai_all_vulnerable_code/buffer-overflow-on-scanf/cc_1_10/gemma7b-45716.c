//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20];
    int age;
    int choice;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Hello, %s! You are %d years old.\n", name, age);

    printf("You are in a forest. You see two paths. Path 1 is to the right, and Path 2 is to the left.\n");

    printf("Please choose a path by entering 1 or 2: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("You took Path 1 and traveled to the east. You encounter a dragon.\n");
        printf("What do you want to do? (fight, flee, negotiate): ");
        scanf("%s", name);

        if (name[0] == 'f')
        {
            printf("You flee and escape the dragon.\n");
        }
        else if (name[0] == 'n')
        {
            printf("You negotiate with the dragon and make a deal.\n");
        }
        else
        {
            printf("You fight the dragon and defeat it.\n");
        }
    }
    else if (choice == 2)
    {
        printf("You took Path 2 and traveled to the west. You encounter a troll.\n");
        printf("What do you want to do? (fight, flee, negotiate): ");
        scanf("%s", name);

        if (name[0] == 'f')
        {
            printf("You flee and escape the troll.\n");
        }
        else if (name[0] == 'n')
        {
            printf("You negotiate with the troll and make a deal.\n");
        }
        else
        {
            printf("You fight the troll and defeat it.\n");
        }
    }
    else
    {
        printf("Invalid input. Please try again.\n");
    }

    return 0;
}
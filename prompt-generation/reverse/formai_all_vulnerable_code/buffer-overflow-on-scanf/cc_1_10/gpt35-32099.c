//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int enterHauntedHouse();
int lookAround();
int approachDoor();
int openDoor();
int hallway();
int encounterGhost();
int office();
int basement();
int exitHauntedHouse();

int main()
{
    srand(time(NULL));
    int choice;
    choice = enterHauntedHouse();

    switch(choice)
    {
        case 1: 
            lookAround();
            break;
        case 2: 
            approachDoor();
            break;
        default: 
            printf("You can't decide what to do and freeze in terror\n");
            break;
    }

    return 0;
}

int enterHauntedHouse()
{
    int choice;
    printf("You find yourself at the entrance of a haunted house. What will you do?\n\n");
    printf("1. Look around\n");
    printf("2. Approach the door\n\n");
    printf("Enter 1 or 2: ");
    scanf("%d", &choice);
    printf("\n");

    return choice;
}

int lookAround()
{
    int choice;
    printf("You look around and see that the outside of the house is overgrown with vines. The windows are boarded up and the door is covered in cobwebs.\n\n");
    printf("1. Approach the door\n");
    printf("2. Leave the area\n\n");
    printf("Enter 1 or 2: ");
    scanf("%d", &choice);
    printf("\n");

    switch(choice)
    {
        case 1: 
            approachDoor();
            break;
        case 2: 
            printf("You leave the area in fear and never return\n");
            break;
        default: 
            printf("You can't decide what to do and freeze in terror\n");
            break;
    }

    return 0;
}

int approachDoor()
{
    int choice;
    int roll = (rand() % 10) + 1;
    printf("You approach the door and notice that it is slightly ajar. Do you:\n\n");
    printf("1. Open the door\n");
    printf("2. Leave the area\n\n");
    printf("Enter 1 or 2: ");
    scanf("%d", &choice);
    printf("\n");

    switch(choice)
    {
        case 1: 
            if (roll >= 5)
            {
                printf("You open the door and step inside the foyer.\n\n");
                hallway();
            }
            else
            {
                printf("As you reach out to push the door open, it slams shut in your face with such force that you nearly fall.\n");
                printf("You quickly leave the area\n");
            }
            break;
        case 2:
            printf("You leave the area in fear and never return\n");
            break;
        default:
            printf("You can't decide what to do and freeze in terror\n");
            break;
    }

    return 0;
}

int hallway()
{
    int choice;
    int roll = (rand() % 10) + 1;
    printf("You find yourself in a dimly lit hallway. To your left is a door that seems to lead to an office, and to your right is a staircase that leads down to the basement. Do you:\n\n");
    printf("1. Check out the office\n");
    printf("2. See what's in the basement\n\n");
    printf("Enter 1 or 2: ");
    scanf("%d", &choice);
    printf("\n");

    switch(choice)
    {
        case 1: 
            office();
            break;
        case 2: 
            if (roll >= 5)
            {
                printf("You cautiously make your way down the creaky stairs to the basement.\n\n");
                basement();
            }
            else
            {
                printf("As you descend the stairs, you feel a cold breeze brush against your face. Suddenly, a ghostly apparition appears before you.\n");
                encounterGhost();
            }
            break;
        default: 
            printf("You can't decide what to do and freeze in terror\n");
            break;
    }

    return 0;
}

int office()
{
    printf("You slowly open the door to the office and step inside. Shelves line the walls and an old desk sits in the center of the room.\n");
    printf("As you approach the desk, a gust of wind blows through the open window, causing the papers on the desk to flutter.\n\n");
    exitHauntedHouse();
    
    return 0;
}

int basement()
{
    printf("You reach the bottom of the stairs and find yourself in a musty basement. Cobwebs line the walls and old furniture sits covered in sheets.\n");
    printf("As you explore the basement, you begin to feel uneasy. Suddenly, the door at the top of the stairs slams shut, and you are plunged into darkness.\n\n");
    encounterGhost();

    return 0;
}

int encounterGhost()
{
    printf("There is no escape from the ghostly apparition that stands before you. You are trapped in the haunted house forever.\n\n");
    exitHauntedHouse();
    
    return 0;
}

int exitHauntedHouse()
{
    printf("Thank you for visiting the haunted house. Please come again...\n");
    
    return 0;
}
//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20];
    printf("Please enter your name: ");
    scanf("%s", name);

    int room_num = rand() % 3 + 1;
    switch (room_num)
    {
        case 1:
            printf("You are in the Grand Hall.\n");
            break;
        case 2:
            printf("You are in the Dining Hall.\n");
            break;
        case 3:
            printf("You are in the Library.\n");
            break;
    }

    int item_num = rand() % 3 + 1;
    switch (item_num)
    {
        case 1:
            printf("You have a sword.\n");
            break;
        case 2:
            printf("You have a potion.\n");
            break;
        case 3:
            printf("You have a bow and arrow.\n");
            break;
    }

    printf("What do you want to do? (e.g. go north, south, east, west) ");
    char command[20];
    scanf("%s", command);

    if (strcmp(command, "go north") == 0)
    {
        printf("You went north.\n");
    }
    else if (strcmp(command, "go south") == 0)
    {
        printf("You went south.\n");
    }
    else if (strcmp(command, "go east") == 0)
    {
        printf("You went east.\n");
    }
    else if (strcmp(command, "go west") == 0)
    {
        printf("You went west.\n");
    }
    else
    {
        printf("Invalid command.\n");
    }

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    char name[20];
    char location = 'a';

    printf("Welcome, traveler. Please enter your name:");
    scanf("%s", name);

    printf("You are in the Cave of Wonders, %s. You have three choices:\n", name);
    printf("1. Enter the glowing tunnel.\n");
    printf("2. Push the heavy boulder.\n");
    printf("3. Attack the menacing creature.\n");

    printf("Please make a choice:");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            location = 'b';
            printf("You entered the glowing tunnel and traveled to the second chamber.\n");
            break;
        case 2:
            location = 'c';
            printf("You pushed the heavy boulder and opened the hidden room.\n");
            break;
        case 3:
            location = 'd';
            printf("You attacked the menacing creature and defeated it.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    switch (location)
    {
        case 'b':
            printf("You are in the second chamber. There is a glowing bridge ahead.\n");
            break;
        case 'c':
            printf("You are in the hidden room. There is a treasure chest in the center.\n");
            break;
        case 'd':
            printf("You have defeated the menacing creature and saved the world.\n");
            break;
        default:
            printf("Invalid location. Please try again.\n");
    }

    return 0;
}
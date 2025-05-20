//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice;
    char name[20];
    int health = 100;

    printf("Welcome, traveler! What is your name?\n");
    scanf("%s", name);

    printf("Hello, %s! You find yourself in a mysterious cave. There are three doors before you:\n", name);
    printf("Door 1: It appears to be made of emerald and is glowing with a faint green light.\n");
    printf("Door 2: It is constructed of ruby and emanates a vibrant red glow.\n");
    printf("Door 3: It is forged from gold and radiates a warm, golden glow.\n");

    printf("Please choose a door number: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You open the emerald door and step inside. You find yourself in a lush, green forest.\n");
            break;
        case 2:
            printf("You open the ruby door and step into a fiery, red desert. \n");
            break;
        case 3:
            printf("You open the gold door and step into a grand, golden hall. \n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    // Battle sequence
    // ...

    // Health check
    if (health <= 0)
    {
        printf("Your health has reached 0. You have perished.\n");
    }
    else
    {
        printf("You have successfully completed your journey. Congratulations!\n");
    }

    return;
}
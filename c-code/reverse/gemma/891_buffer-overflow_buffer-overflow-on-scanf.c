#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20];
    int health = 100;
    int choice;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Welcome, %s, to the Haunted House of Thornwood Manor.\n", name);

    printf("You wake up in a cold sweat, hearing strange noises coming from the hallway.\n");
    printf("You have two options: \n");
    printf("1. You decide to investigate the source of the noise.\n");
    printf("2. You try to flee the house.\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            health -= 20;
            printf("You cautiously explore the hallway, but find nothing suspicious.\n");
            break;
        case 2:
            health -= 10;
            printf("You sprint out of the house, but the ghosts catch up, reducing your health to zero.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    if (health <= 0)
    {
        printf("Game Over. You have succumbed to the horrors of Thornwood Manor.\n");
    }
    else
    {
        printf("You have survived the haunted house of Thornwood Manor. Congratulations!\n");
    }

    return 0;
}

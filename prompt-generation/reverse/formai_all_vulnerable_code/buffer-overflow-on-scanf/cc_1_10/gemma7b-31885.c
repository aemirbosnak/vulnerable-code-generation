//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20];
    int age, health, inventory[10] = {0};

    printf("Welcome to the wacky world of Squiggly Quest!\n");
    printf("Please tell me your name: ");
    scanf("%s", name);

    printf("And how old are you, %s? ", name);
    scanf("%d", &age);

    printf("Oh no! A troll has stolen your grandma's priceless diamond necklace! You must journey to the troll's lair to get it back.\n");

    // Inventory management
    inventory[0] = "Sword";
    inventory[1] = "Shield";
    inventory[2] = "Magic Potion";

    // Battle with the troll
    printf("You encounter a menacing troll. Prepare for battle!\n");

    // Use your inventory items to attack the troll
    printf("What do you want to use? (sword, shield, potion) ");
    scanf("%s", inventory);

    if (strcmp(inventory, "sword") == 0)
    {
        printf("You swung your sword with might, but the troll was too strong. He laughed at your puny attempt and ate your sandwich.\n");
    }
    else if (strcmp(inventory, "shield") == 0)
    {
        printf("You used your shield to deflect the troll's attack. He was surprised by your resilience and ran away.\n");
    }
    else if (strcmp(inventory, "potion") == 0)
    {
        printf("You drank the potion and gained strength. You charged at the troll and he was defeated. You saved your grandma's necklace!\n");
    }
    else
    {
        printf("Invalid item. Please try again.\n");
    }

    // Rest and repeat
    printf("You have saved the day, %s! You are a hero! Now, rest up and we'll do it all again.\n", name);

    return 0;
}
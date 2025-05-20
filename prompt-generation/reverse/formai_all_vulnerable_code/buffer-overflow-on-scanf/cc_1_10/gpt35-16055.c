//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: creative
#include <stdio.h>
#include <string.h>

void clearInputBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main() {
    printf("Welcome to the Text-Based Adventure Game!\n\n");

    int health = 100;
    int strength = 10;
    int intel = 10;
    int points = 0;

    printf("You are about to embark on a journey across a vast and dangerous land!\n");
    printf("Before we begin, let's customize your character...\n");

    printf("\nEnter your character's name: ");
    char name[50];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("\nHi, %s! Let's assign some initial stats for your character.\n", name);
    printf("You have 100 points to spend. How many points do you want to spend on health (max 50)? ");
    scanf("%d", &health);
    clearInputBuffer();

    while (health > 50 || health < 0) {
        printf("Invalid input! You have %d points remaining. How many points do you want to spend on health (max 50)? ", points);
        scanf("%d", &health);
        clearInputBuffer();
    }
    points += health;

    printf("You have %d points remaining. How many points do you want to spend on strength? ", points);
    scanf("%d", &strength);
    clearInputBuffer();

    while (strength > points || strength < 0) {
        printf("Invalid input! You have %d points remaining. How many points do you want to spend on strength? ", points);
        scanf("%d", &strength);
        clearInputBuffer();
    }
    points -= strength;

    printf("You have %d points remaining. How many points do you want to spend on intelligence? ", points);
    scanf("%d", &intel);
    clearInputBuffer();

    while (intel > points || intel < 0) {
        printf("Invalid input! You have %d points remaining. How many points do you want to spend on intelligence? ", points);
        scanf("%d", &intel);
        clearInputBuffer();
    }

    printf("\nYou're all set, %s!\n", name);
    printf("Your starting stats are:\n");
    printf("Health: %d\n", health);
    printf("Strength: %d\n", strength);
    printf("Intelligence: %d\n", intel);

    printf("\nAre you ready to embark on your adventure? Type 'y' for yes or 'n' for no: ");
    char choice;
    scanf("%c", &choice);
    clearInputBuffer();

    if (choice != 'y') {
        printf("\nYou chickened out?! Don't worry %s, you can always come back later!\n\n", name);
        return 0;
    }

    printf("\nGreat! You pack your bags and head out on your journey.\n");
    printf("You eventually come to a fork in the road. Which path do you take?\n");
    printf("Enter '1' for the left path or '2' for the right path: ");

    int path;
    scanf("%d", &path);
    clearInputBuffer();

    if (path == 1) {
        printf("\nYou take the left path, but it's a dead end! The only way out is back.\n");
        printf("You lose a few health points from all the backtracking and start moving right.\n");
        health -= 5;
    }
    else if (path == 2) {
        printf("\nYou take the right path and soon come across a stream.\n");
        printf("Do you swim across or follow the stream to find a bridge?\n");
        printf("Enter '1' to swim across or '2' to find the bridge: ");

        int choice;
        scanf("%d", &choice);
        clearInputBuffer();

        if (choice == 1) {
            printf("\nYou brave the cold water and swim across. However, you slip on a rock and hit your head.\n");
            printf("You lose some strength and intelligence points.\n");
            strength -= 2;
            intel -= 2;
        } 
        else if (choice == 2) {
            printf("\nYou follow the stream and eventually find a bridge! You safely cross to the other side.\n");
            printf("You recover a few health points from the break and continue on your journey.\n");
            health += 3;
        }
    }

    printf("\nYou eventually come across a village and decide to rest and restock.\n");
    printf("You see a stall selling various weapons and equipment. What do you buy?\n");
    printf("Enter '1' for a sword, '2' for a bow, or '3' for healing potions: ");

    int purchase;
    scanf("%d", &purchase);
    clearInputBuffer();

    switch (purchase) {
        case 1:
            printf("\nYou purchase a sword and feel much more secure. You gain some strength points.\n");
            strength += 3;
            break;
        case 2:
            printf("\nYou purchase a bow and some arrows. You gain some intelligence points.\n");
            intel += 3;
            break;
        case 3:
            printf("\nYou purchase some healing potions and feel much better. You gain some health points.\n");
            health += 10;
            break;
        default:
            printf("\nInvalid selection. You leave the village empty-handed.\n");
            break;
    }

    printf("\nYou keep moving and eventually stumble upon an abandoned castle.\n");
    printf("Do you try to explore the castle or keep moving? Enter '1' to explore or '2' to keep moving: ");

    int explore;
    scanf("%d", &explore);
    clearInputBuffer();

    if (explore == 1) {
        printf("\nYou make your way into the castle, but soon realize it was a mistake.\n");
        printf("You encounter a group of goblins and get ambushed. Your health takes a beating.\n");
        health -= 20;
    } 
    else if (explore == 2) {
        printf("\nYou keep moving and eventually come across a group of friendly travelers.\n");
        printf("You join forces with them and continue on your journey together.\n");
        printf("Your strength and intelligence points improve from learning from their experiences.\n");
        strength += 5;
        intel += 5;
    }

    printf("\nAfter many more obstacles, you finally reach your destination!\n");
    printf("You look back on all the challenges you faced and feel proud of yourself!\n");
    printf("Final stats:\n");
    printf("Name: %s\n", name);
    printf("Health: %d\n", health);
    printf("Strength: %d\n", strength);
    printf("Intelligence: %d\n", intel);

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void introduction() {
    printf("==========================================\n");
    printf("      Quest for the Lost Artifact       \n");
    printf("==========================================\n");
    printf("You are an adventurer on a quest to find the legendary Lost Artifact.\n");
    printf("Your journey will take you through treacherous terrain and dangerous creatures.\n");
    printf("Choose wisely, and you might just find the artifact!\n");
    printf("==========================================\n");
}

int forest() {
    int choice;
    printf("You find yourself in a dense forest. You can:\n");
    printf("1. Follow the path to the north.\n");
    printf("2. Explore a cave to the east.\n");
    printf("3. Climb a tree to get a better view.\n");
    printf("What do you want to do? (1-3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You follow the path and encounter a friendly villager who gives you a magical map! +1 to your inventory.\n");
        return 1; // Proceed to the village next
    } else if (choice == 2) {
        printf("You enter the cave and are ambushed by a bat! You manage to escape, but lose some health.\n");
        return 0; // Return to the forest
    } else if (choice == 3) {
        printf("You climb the tree and spot smoke in the distance. It's a village!\n");
        return 1; // Proceed to the village
    } else {
        printf("Invalid choice! You stumble and fall.\n");
        return 0; // Return to the forest
    }
}

int village(int inventory) {
    int choice;
    printf("You arrive at a small village. You can:\n");
    printf("1. Visit the blacksmith to buy weapons.\n");
    printf("2. Talk to the villagers to gather information.\n");
    printf("3. Leave the village and return to the forest.\n");
    
    if (inventory > 0) {
        printf("(You have a magical map!)\n");
    }

    printf("What do you want to do? (1-3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You buy a sword from the blacksmith. Equip it in your inventory!\n");
        return -1; // Continue with the story
    } else if (choice == 2) {
        printf("The villagers tell you about a dragon that guards the Lost Artifact. It has a weak spot behind its left wing!\n");
        return -1; // Continue with the story
    } else if (choice == 3) {
        printf("You leave the village and head back to the forest.\n");
        return 0; // Return to the forest
    } else {
        printf("Invalid choice! You feel lost and confused.\n");
        return -1; // Continue with the story
    }
}

int dragonCave() {
    int choice;
    printf("You arrive at a dark cave. The dragon is asleep, but you see the Lost Artifact glowing!\n");
    printf("You can:\n");
    printf("1. Attempt to sneak up and grab the artifact.\n");
    printf("2. Use your sword to challenge the dragon!\n");
    printf("3. Leave the cave and regroup outside.\n");
    printf("What do you want to do? (1-3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You successfully sneak up and grab the artifact! You've completed your quest!\n");
        return 10; // Win
    } else if (choice == 2) {
        printf("The dragon wakes up angrily! You fight bravely but succumb to its flames. Game Over.\n");
        return -1; // Lose
    } else if (choice == 3) {
        printf("You wisely choose to regroup. You can strategize better this time!\n");
        return -1; // Lose, but continue
    } else {
        printf("Invalid choice! The dragon awakens.\n");
        return -1; // Lose
    }
}

int main() {
    introduction();
    int inventory = 0;
    int gameState = 0;

    while (gameState != -1) {
        if (gameState == 0) {
            gameState = forest();
        } else if (gameState == 1) {
            inventory += village(inventory);
        } else if (gameState == 2) {
            gameState = dragonCave();
        }
    }

    if (gameState == 10) {
        printf("Congratulations! You have retrieved the Lost Artifact and are celebrated as a hero!\n");
    } else {
        printf("Thank you for playing! Better luck next time.\n");
    }

    return 0;
}
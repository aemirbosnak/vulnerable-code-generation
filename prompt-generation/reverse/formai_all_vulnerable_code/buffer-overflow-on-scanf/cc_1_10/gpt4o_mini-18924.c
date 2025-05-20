//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INVENTORY 5

void displayIntro() {
    printf("Welcome to the Enchanted Forest Adventure!\n");
    printf("You are a brave explorer on a quest to find the lost treasure of the Elders.\n");
    printf("Make your choices wisely and see where your adventure takes you!\n\n");
}

void displayInventory(char inventory[MAX_INVENTORY][50], int count) {
    printf("Your inventory: ");
    if (count == 0) {
        printf("empty\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%s ", inventory[i]);
        }
        printf("\n");
    }
}

void addItemToInventory(char inventory[MAX_INVENTORY][50], int *count, const char *item) {
    if (*count < MAX_INVENTORY) {
        strcpy(inventory[*count], item);
        (*count)++;
        printf("You have added %s to your inventory.\n", item);
    } else {
        printf("Your inventory is full! Cannot add %s.\n", item);
    }
}

void encounterEnemy(char inventory[MAX_INVENTORY][50], int *count) {
    printf("Oh no! A wild goblin appears!\n");
    printf("Do you fight (f) or run away (r)? ");
    
    char choice;
    scanf(" %c", &choice);
    
    if (choice == 'f') {
        if (rand() % 2 == 0) {
            printf("You bravely fought the goblin and emerged victorious!\n");
            addItemToInventory(inventory, count, "Goblin Tooth");
        } else {
            printf("The goblin was too strong. You ran away...\n");
        }
    } else {
        printf("You chose to run away successfully!\n");
    }
}

void exploreForest(char inventory[MAX_INVENTORY][50], int *count) {
    printf("You venture deeper into the enchanted forest...\n");
    int encounter = rand() % 3;
    
    if (encounter == 0) {
        printf("You found a sparkling stream. You can drink some refreshing water.\n");
        printf("Do you drink (d) or keep exploring (e)? ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'd') {
            printf("You feel rejuvenated!\n");
            addItemToInventory(inventory, count, "Refreshment Potion");
        } else {
            printf("You continue your adventure.\n");
        }
    } else if (encounter == 1) {
        encounterEnemy(inventory, count);
    } else {
        printf("You discover a mysterious old tree with a hollow trunk. Inside, you find...\n");
        printf("A strange key! Do you take it (t) or leave it (l)? ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 't') {
            addItemToInventory(inventory, count, "Mysterious Key");
        } else {
            printf("You decided to leave the key behind.\n");
        }
    }
}

void visitVillage(char inventory[MAX_INVENTORY][50], int *count) {
    printf("You arrive at a quaint village filled with friendly villagers.\n");
    printf("They offer to trade with you. You can trade items from your inventory.\n");
    displayInventory(inventory, *count);
    
    if (*count > 0) {
        printf("Which item do you want to trade? (Enter item name): ");
        char tradeItem[50];
        scanf("%s", tradeItem);

        int found = 0;
        for (int i = 0; i < *count; i++) {
            if (strcmp(inventory[i], tradeItem) == 0) {
                found = 1;
                printf("You traded %s for a shiny new gem!\n", tradeItem);
                strcpy(inventory[i], "Shiny Gem"); // Trade item
                break;
            }
        }

        if (!found) {
            printf("You don't have that item in your inventory!\n");
        }
    } else {
        printf("You have no items to trade.\n");
    }
}

void gameLoop() {
    char inventory[MAX_INVENTORY][50] = {""};
    int inventoryCount = 0;
    int gameRunning = 1;

    while (gameRunning) {
        printf("You stand at a crossroads. Where do you want to go?\n");
        printf("1. Explore the forest\n");
        printf("2. Visit the nearby village\n");
        printf("3. Check inventory\n");
        printf("4. Exit game\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                exploreForest(inventory, &inventoryCount);
                break;
            case 2:
                visitVillage(inventory, &inventoryCount);
                break;
            case 3:
                displayInventory(inventory, inventoryCount);
                break;
            case 4:
                gameRunning = 0;
                printf("Thank you for playing! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    displayIntro();
    gameLoop();
    return 0;
}
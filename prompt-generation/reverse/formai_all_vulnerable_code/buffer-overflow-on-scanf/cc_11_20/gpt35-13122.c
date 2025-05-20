//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char name[50];
    int health = 100;
    int gold = 0;
    int experience = 0;
    int level = 1;

    printf("Welcome adventurer! What is your name?\n");
    scanf("%s", name);
    printf("Nice to meet you, %s! Your journey begins.\n", name);

    while (health > 0) {
        printf("You are currently at a crossroad. Which way will you choose? (North/South/East/West)\n");
        char choice[10];
        scanf("%s", choice);

        if (strcmp(choice, "North") == 0) {
            printf("You encounter a friendly merchant who offers to sell you a powerful sword. Do you buy it? (Yes/No)\n");
            char buyChoice[10];
            scanf("%s", buyChoice);
            if (strcmp(buyChoice, "Yes") == 0) {
                gold -= 50;
                printf("You bought the sword! You are left with %d gold.\n", gold);
            }
            else {
                printf("You decide to save your gold for later.\n");
            }
        }
        else if (strcmp(choice, "South") == 0) {
            printf("You stumble upon a hidden treasure chest! You found 100 gold.\n");
            gold += 100;
            experience += 50;
            printf("You now have %d gold and %d experience points.\n", gold, experience);
        }
        else if (strcmp(choice, "East") == 0) {
            printf("You come across a group of hostile goblins. Prepare for battle!\n");
            int goblinHealth = 50;
            while (goblinHealth > 0) {
                printf("You have %d health and the goblin has %d health. What will you do? (Attack/Defend/Run)\n", health, goblinHealth);
                char battleChoice[10];
                scanf("%s", battleChoice);
                if (strcmp(battleChoice, "Attack") == 0) {
                    goblinHealth -= 20;
                    printf("You dealt 20 damage to the goblin! It has %d health left.\n", goblinHealth);
                }
                else if (strcmp(battleChoice, "Defend") == 0) {
                    goblinHealth -= 5;
                    printf("You defended and took only 5 damage! The goblin has %d health left.\n", goblinHealth);
                    health -= 10;
                    printf("You also lost 10 health points for defending.\n");
                }
                else {
                    printf("You ran away from the battle. Coward!\n");
                    health -= 20;
                    printf("You lost 20 health points while escaping.\n");
                    break;
                }
            }
            if (goblinHealth <= 0) {
                printf("Congratulations! You defeated the goblin. You found 50 gold and gained 100 experience points.\n");
                gold += 50;
                experience += 100;
                printf("You now have %d gold and %d experience points.\n", gold, experience);
            }
        }
        else if (strcmp(choice, "West") == 0) {
            printf("You stumble upon a friendly village. They give you a warm welcome and invite you to stay for the night. Do you accept? (Yes/No)\n");
            char villageChoice[10];
            scanf("%s", villageChoice);
            if (strcmp(villageChoice, "Yes") == 0) {
                health = 100;
                printf("You enjoyed a good night's sleep and regained all of your health.\n");
            }
            else {
                printf("You decide to continue your journey through the night.\n");
                health -= 20;
                printf("You lost 20 health points while travelling.\n");
            }
        }
        else {
            printf("Invalid choice. Try again.\n");
        }

        if (experience >= 200 && level == 1) {
            level = 2;
            health = 150;
            printf("Congratulations! You have reached level 2. Your health has increased to 150.\n");
        }
        else if (experience >= 500 && level == 2) {
            level = 3;
            health = 200;
            printf("Congratulations! You have reached level 3. Your health has increased to 200.\n");
        }

        if (health <= 0) {
            printf("Game over! You have died.\n");
            break;
        }
    }

    printf("Thank you for playing, %s! Your final stats:\n", name);
    printf("Health: %d\n", health);
    printf("Gold: %d\n", gold);
    printf("Experience: %d\n", experience);
    printf("Level: %d\n", level);

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void introduction();
void choose_path();
void forest_path();
void cave_path();

int main() {
    introduction();
    choose_path();
    return 0;
}

void introduction() {
    printf("Welcome to the Adventure Game!\n");
    printf("You find yourself standing at a crossing in a mystical land.\n");
    printf("To your left is a dark, ominous forest.\n");
    printf("To your right is a shadowy cave that emanates a strange glow.\n");
    printf("Which path will you choose? (forest/cave): ");
}

void choose_path() {
    char choice[10];
    scanf("%s", choice);
    
    if (strcmp(choice, "forest") == 0) {
        forest_path();
    } else if (strcmp(choice, "cave") == 0) {
        cave_path();
    } else {
        printf("Invalid choice! Please try again.\n");
        choose_path();
    }
}

void forest_path() {
    printf("\nYou walk into the dark forest. The trees are tall and the air is filled with the sound of rustling leaves.\n");
    printf("You have two options here: you can either climb a tree to get a better view, or you can explore deeper into the forest.\n");
    printf("What will you do? (climb/explore): ");
    
    char choice[10];
    scanf("%s", choice);
    
    if (strcmp(choice, "climb") == 0) {
        printf("\nYou climb the tree and discover a hidden treasure chest in the branches!\n");
        printf("Congratulations, you found 100 gold coins!\n");
    } else if (strcmp(choice, "explore") == 0) {
        printf("\nYou venture deeper into the forest and encounter a fierce tiger!\n");
        printf("It sees you and prepares to attack! You must run or fight.\n");
        printf("What will you do? (run/fight): ");
        
        scanf("%s", choice);
        
        if (strcmp(choice, "run") == 0) {
            printf("\nYou run as fast as you can and manage to escape the tiger!\n");
            printf("As you catch your breath, you find a path that leads you safely out of the forest.\n");
        } else if (strcmp(choice, "fight") == 0) {
            printf("\nYou bravely fight the tiger, but unfortunately, it overpowers you.\n");
            printf("Game Over!\n");
            return;
        } else {
            printf("Invalid choice! You hesitate and the tiger seizes the moment.\n");
            printf("Game Over!\n");
            return;
        }
    } else {
        printf("Invalid choice! You hesitate and get lost in the forest.\n");
        printf("Game Over!\n");
    }
    printf("You have completed your adventure in the forest!\n");
}

void cave_path() {
    printf("\nYou step into the shadowy cave. The air is cool and damp, and you can hear water dripping nearby.\n");
    printf("Inside, you find two paths: one leading straight ahead and one spiraling downwards.\n");
    printf("Which path will you take? (straight/down): ");
    
    char choice[10];
    scanf("%s", choice);
    
    if (strcmp(choice, "straight") == 0) {
        printf("\nYou walk straight ahead and discover glowing crystals lining the cave walls.\n");
        printf("Suddenly, a friendly cave troll appears and offers to trade with you.\n");
        printf("You can exchange some gold for a magical item. Do you want to trade? (yes/no): ");
        
        scanf("%s", choice);
        
        if (strcmp(choice, "yes") == 0) {
            printf("\nYou trade 20 gold coins for a magical amulet that grants you protection!\n");
            printf("You feel empowered as you leave the cave safely.\n");
        } else if (strcmp(choice, "no") == 0) {
            printf("\nYou choose not to trade. As you leave the cave, you find a stash of 50 gold coins!\n");
        } else {
            printf("Invalid choice! You wander aimlessly and the cave starts to collapse.\n");
            printf("Game Over!\n");
            return;
        }
    } else if (strcmp(choice, "down") == 0) {
        printf("\nYou take the spiral path downwards and encounter a hidden underground lake.\n");
        printf("As you approach, you see a reflection of a treasure chest beneath the water.\n");
        printf("Will you try to retrieve it? (yes/no): ");
        
        scanf("%s", choice);
        
        if (strcmp(choice, "yes") == 0) {
            printf("\nYou dive into the water and manage to pull out the chest!\n");
            printf("Inside, there are gold coins and gems worth a fortune!\n");
            printf("Congratulations, you are now rich!\n");
        } else if (strcmp(choice, "no") == 0) {
            printf("\nYou decide against retrieving the chest. Wise move! You safely walk back home with your life.\n");
        } else {
            printf("Invalid choice! You hesitate and become trapped in the underwater cave.\n");
            printf("Game Over!\n");
            return;
        }
    } else {
        printf("Invalid choice! You stumble in the darkness and get lost.\n");
        printf("Game Over!\n");
    }
    printf("You have completed your adventure in the cave!\n");
}
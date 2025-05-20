//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FLOWERS 10
#define MAX_WEEDS 5

typedef struct {
    char name[20];
    int health;
} Flower;

typedef struct {
    char name[20];
} Weed;

Flower garden[MAX_FLOWERS];
Weed weeds[MAX_WEEDS];
int flowerCount = 0;
int score = 0;

void initialize_garden() {
    strcpy(garden[0].name, "Rose");
    garden[0].health = 5;

    strcpy(garden[1].name, "Tulip");
    garden[1].health = 5;

    strcpy(garden[2].name, "Daisy");
    garden[2].health = 5;

    flowerCount = 3;

    strcpy(weeds[0].name, "Dandelion");
    strcpy(weeds[1].name, "Crabgrass");
}

void display_garden() {
    printf("\n=== Cheerful Garden ===\n");
    for (int i = 0; i < flowerCount; i++) {
        printf("Flower: %s (Health: %d)\n", garden[i].name, garden[i].health);
    }
    printf("========================\n");
}

void tend_flower() {
    printf("\nWhich flower would you like to tend to? (0-%d)\n", flowerCount - 1);
    int choice;
    scanf("%d", &choice);

    if (choice >= 0 && choice < flowerCount) {
        garden[choice].health += 1;
        score += 10;
        printf("You tended to the %s! Its health is now %d.\n", garden[choice].name, garden[choice].health);
    } else {
        printf("Invalid choice! Please try again.\n");
    }
}

void battle_weed() {
    printf("\nBattling weeds in the garden!\n");
    int weed_choice = rand() % MAX_WEEDS;
    
    printf("A wild %s has appeared!\n", weeds[weed_choice].name);
    printf("Choose a flower to defend!\n");

    for (int i = 0; i < flowerCount; i++) {
        printf("%d: %s\n", i, garden[i].name);
    }

    int choice;
    scanf("%d", &choice);
    
    if (choice >= 0 && choice < flowerCount) {
        garden[choice].health -= 2;
        if (garden[choice].health > 0) {
            printf("You fought off the %s with %s! But the health of %s is now %d.\n", weeds[weed_choice].name, garden[choice].name, garden[choice].name, garden[choice].health);
            score += 20;
        } else {
            printf("Oh no! The %s has withered away due to the battle with the %s!\n", garden[choice].name, weeds[weed_choice].name);
            garden[choice] = garden[flowerCount - 1];  // Replace with last flower
            flowerCount--;
        }
    } else {
        printf("Invalid choice! Please try again.\n");
    }
}

void display_score() {
    printf("\nYour current score is: %d\n", score);
}

int main() {
    srand(time(NULL));
    printf("Welcome to Cheerful Garden Adventure!\n");
    initialize_garden();
    
    int choice = 0;

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Display the garden\n");
        printf("2. Tend a flower\n");
        printf("3. Battle a weed\n");
        printf("4. Display score\n");
        printf("5. Exit the game\n");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                display_garden();
                break;
            case 2:
                tend_flower();
                break;
            case 3:
                battle_weed();
                break;
            case 4:
                display_score();
                break;
            case 5:
                printf("Thank you for playing Cheerful Garden Adventure! Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
    return 0;
}
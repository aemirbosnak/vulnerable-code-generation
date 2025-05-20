//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INGREDIENTS 5
#define MAX_POTS 3

typedef struct {
    char name[20];
    int amount;
} Ingredient;

typedef struct {
    char name[20];
    int amount;
} Pot;

Ingredient ingredients[MAX_INGREDIENTS] = {
    {"Flour", 200},
    {"Sugar", 100},
    {"Eggs", 3},
    {"Butter", 100},
    {"Vanilla", 1}
};

Pot pots[MAX_POTS] = {
    {"Small", 50},
    {"Medium", 100},
    {"Large", 150}
};

int current_pot = 0;
int current_ingredient = 0;
int cooking_time = 0;

void add_ingredient(Ingredient ingredient) {
    if (current_pot < MAX_POTS && cooking_time < 100) {
        ingredients[current_ingredient].amount += ingredient.amount;
        current_ingredient++;
    }
}

void cook() {
    int i;
    for (i = 0; i < current_ingredient; i++) {
        if (ingredients[i].amount > 0) {
            cooking_time += (rand() % 100) + 1;
            ingredients[i].amount--;
        }
    }
}

void stir() {
    int i;
    for (i = 0; i < current_ingredient; i++) {
        if (ingredients[i].amount > 0) {
            printf("Stirring %s...\n", ingredients[i].name);
            sleep(rand() % 5 + 1);
        }
    }
}

int main() {
    srand(time(NULL));
    while (1) {
        printf("Welcome to the kitchen! You have the following ingredients:\n");
        for (int i = 0; i < current_ingredient; i++) {
            printf("%d %s\n", ingredients[i].amount, ingredients[i].name);
        }
        printf("\nSelect a pot: ");
        scanf("%d", &current_pot);
        if (current_pot < 0 || current_pot >= MAX_POTS) {
            printf("Invalid pot selection. Please try again.\n");
            continue;
        }
        printf("\nSelect an ingredient to add: ");
        scanf("%d", &current_ingredient);
        if (current_ingredient < 0 || current_ingredient >= MAX_INGREDIENTS) {
            printf("Invalid ingredient selection. Please try again.\n");
            continue;
        }
        add_ingredient(ingredients[current_ingredient]);
        cook();
        stir();
        printf("\nDo you want to continue cooking? (y/n): ");
        char answer = getchar();
        if (answer != 'y' && answer != 'Y') {
            break;
        }
    }
    return 0;
}
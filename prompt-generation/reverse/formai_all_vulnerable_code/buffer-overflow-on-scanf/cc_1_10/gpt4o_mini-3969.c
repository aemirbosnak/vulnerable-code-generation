//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10
#define MAX_CATEGORIES 3
#define MAX_CATEGORY_NAME 20

typedef struct {
    char category[MAX_CATEGORY_NAME];
    char fortunes[MAX_FORTUNES][256];
    int fortune_count;
} FortuneCategory;

void initialize_fortune_categories(FortuneCategory categories[]) {
    // Category 1: Love
    snprintf(categories[0].category, sizeof(categories[0].category), "Love");
    categories[0].fortune_count = 5;
    snprintf(categories[0].fortunes[0], sizeof(categories[0].fortunes[0]), "You will find love in unexpected places.");
    snprintf(categories[0].fortunes[1], sizeof(categories[0].fortunes[1]), "A new relationship may blossom soon.");
    snprintf(categories[0].fortunes[2], sizeof(categories[0].fortunes[2]), "Love is around the corner; be perceptive!");
    snprintf(categories[0].fortunes[3], sizeof(categories[0].fortunes[3]), "The stars align for a romantic encounter.");
    snprintf(categories[0].fortunes[4], sizeof(categories[0].fortunes[4]), "Trust your heart; it knows what you need.");

    // Category 2: Career
    snprintf(categories[1].category, sizeof(categories[1].category), "Career");
    categories[1].fortune_count = 5;
    snprintf(categories[1].fortunes[0], sizeof(categories[1].fortunes[0]), "Your hard work will pay off soon.");
    snprintf(categories[1].fortunes[1], sizeof(categories[1].fortunes[1]), "An opportunity will present itself unexpectedly.");
    snprintf(categories[1].fortunes[2], sizeof(categories[1].fortunes[2]), "Networking is key; reach out to old contacts.");
    snprintf(categories[1].fortunes[3], sizeof(categories[1].fortunes[3]), "A project you start will lead to great success.");
    snprintf(categories[1].fortunes[4], sizeof(categories[1].fortunes[4]), "Be prepared for a leadership role in the near future.");

    // Category 3: Wellness
    snprintf(categories[2].category, sizeof(categories[2].category), "Wellness");
    categories[2].fortune_count = 5;
    snprintf(categories[2].fortunes[0], sizeof(categories[2].fortunes[0]), "Taking time for yourself is essential right now.");
    snprintf(categories[2].fortunes[1], sizeof(categories[2].fortunes[1]), "A change in diet will benefit you immensely.");
    snprintf(categories[2].fortunes[2], sizeof(categories[2].fortunes[2]), "Exercise will bring mental clarity; start today.");
    snprintf(categories[2].fortunes[3], sizeof(categories[2].fortunes[3]), "Connect with nature; it will rejuvenate your soul.");
    snprintf(categories[2].fortunes[4], sizeof(categories[2].fortunes[4]), "Mindfulness can lead to significant changes in your life.");
}

void display_menu(FortuneCategory categories[]) {
    printf("Welcome to the Decentralized Fortune Teller!\n");
    printf("Please choose a category for your fortune:\n");
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        printf("%d. %s\n", i + 1, categories[i].category);
    }
    printf("%d. Exit\n", MAX_CATEGORIES + 1);
}

void tell_fortune(FortuneCategory categories[], int choice) {
    if (choice >= 1 && choice <= MAX_CATEGORIES) {
        int random_index = rand() % categories[choice - 1].fortune_count;
        printf("Your fortune: %s\n", categories[choice - 1].fortunes[random_index]);
    } else {
        printf("Exiting the Fortune Teller. Come back soon!\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    FortuneCategory categories[MAX_CATEGORIES];
    initialize_fortune_categories(categories);

    int choice;
    do {
        display_menu(categories);
        printf("Enter your choice (1-%d): ", MAX_CATEGORIES + 1);
        scanf("%d", &choice);
        
        if (choice >= 1 && choice <= MAX_CATEGORIES) {
            tell_fortune(categories, choice);
        }
    } while (choice != MAX_CATEGORIES + 1);

    return 0;
}
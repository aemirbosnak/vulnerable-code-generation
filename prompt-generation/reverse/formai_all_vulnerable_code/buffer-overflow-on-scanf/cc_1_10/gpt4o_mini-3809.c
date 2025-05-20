//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 256
#define NUM_THEORIES 10
#define NUM_CATEGORIES 5

// Categories for conspiracy theories
char *categories[NUM_CATEGORIES] = {
    "government",
    "aliens",
    "economy",
    "technology",
    "health"
};

// Array of conspiracy theory components
char *components[NUM_THEORIES][3] = {
    {"the moon landing", "was staged", "to distract us from technology advancements."},
    {"aliens", "are controlling world leaders", "through telepathy."},
    {"the stock market crash", "was orchestrated", "by a secret society."},
    {"5G technology", "is a method of mind control", "developed by tech giants."},
    {"vaccines", "are a plot", "to reduce the global population."},
    {"climate change", "is a hoax", "created by scientists for funding."},
    {"the mass media", "is in cahoots", "with the government to spread misinformation."},
    {"Big Tech", "is spying", "on us through smart devices."},
    {"cryptocurrency", "was invented", "by a cabal of bankers."},
    {"social media", "is a tool", "to manipulate public opinion."},
};

void generateTheory() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Randomly choose a theory component
    int randomIndex = rand() % NUM_THEORIES;

    // Construct and print the theory
    printf("🚀 Exciting Conspiracy Theory! 🚀\n");
    printf("Did you know that %s %s %s\n", 
           components[randomIndex][0], 
           components[randomIndex][1], 
           components[randomIndex][2]);
}

void generateCategoryTheory() {
    // Select a random category
    int categoryIndex = rand() % NUM_CATEGORIES;
    printf("\n🎉 Let's dive into the realm of %s conspiracies! 🎉\n", categories[categoryIndex]);
    
    // Generate a random theory from the selected category
    switch (categoryIndex) {
        case 0: // Government
            printf("🔥 Here's a wild theory: The government is using psychics to influence our decisions! 🔥\n");
            break;
        case 1: // Aliens
            printf("👽 Have you heard? Aliens abducting politicians to implant devices in them! 😱\n");
            break;
        case 2: // Economy
            printf("💰 The economy will crash every 20 years because it's a plan by an elite group! 💣\n");
            break;
        case 3: // Technology
            printf("💻 Social media is a front for a massive surveillance operation by tech companies! 😲\n");
            break;
        case 4: // Health
            printf("🧪 Big Pharma is hiding cures for diseases to maintain profits! 🤫\n");
            break;
        default:
            printf("💥 Error in conspiracy generation! 💥\n");
    }
}

void menu() {
    int choice;
    do {
        printf("\nWelcome to the Conspiracy Theory Generator! 🚀\n");
        printf("1. Generate a random conspiracy theory\n");
        printf("2. Generate a conspiracy theory by category\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateTheory();
                break;
            case 2:
                generateCategoryTheory();
                break;
            case 3:
                printf("🌀 Thanks for exploring the wild world of conspiracy theories! Until next time! 🌀\n");
                break;
            default:
                printf("❌ Invalid choice! Please select 1, 2, or 3. ❌\n");
                break;
        }
    } while (choice != 3);
}

int main() {
    menu();
    return 0;
}
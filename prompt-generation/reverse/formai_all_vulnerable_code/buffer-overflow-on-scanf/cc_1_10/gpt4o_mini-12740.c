//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 20
#define MAX_CATEGORIES 5

// Structure to hold the fortune teller data
typedef struct {
    char* categories[MAX_CATEGORIES];
    char* fortunes[MAX_FORTUNES];
} FortuneTeller;

// Function to initialize the fortune teller data
void initializeFortuneTeller(FortuneTeller* ft) {
    ft->categories[0] = "Love";
    ft->categories[1] = "Career";
    ft->categories[2] = "Health";
    ft->categories[3] = "Wealth";
    ft->categories[4] = "Happiness";

    ft->fortunes[0] = "You will find love where you least expect it.";
    ft->fortunes[1] = "Success is on the horizon; stay focused.";
    ft->fortunes[2] = "Health will improve; maintain a balanced diet.";
    ft->fortunes[3] = "A financial opportunity will come your way.";
    ft->fortunes[4] = "Embrace change; happiness is waiting for you.";
    ft->fortunes[5] = "Your soulmate is closer than you realize.";
    ft->fortunes[6] = "A promotion is coming; keep working hard.";
    ft->fortunes[7] = "Physical activity will lead to new energy.";
    ft->fortunes[8] = "Unexpected wealth will flow to you.";
    ft->fortunes[9] = "A journey will bring you joy and satisfaction.";
    ft->fortunes[10] = "Your past will catch up with you in a good way.";
    ft->fortunes[11] = "Collaboration will bring success in your projects.";
    ft->fortunes[12] = "A moment of self-care will rejuvenate your spirit.";
    ft->fortunes[13] = "Invest wisely; the returns will surprise you.";
    ft->fortunes[14] = "Seek joy in little things; it will pay off.";
    ft->fortunes[15] = "A friend will bring good news.";
    ft->fortunes[16] = "Prepare for a big change; it's for the best.";
    ft->fortunes[17] = "Your intuition will guide you well in a dilemma.";
    ft->fortunes[18] = "A new hobby will enrich your life.";
    ft->fortunes[19] = "Love yourself; great things are coming.";
}

// Function to get a random fortune
void getRandomFortune(FortuneTeller* ft) {
    int randomIndex = rand() % MAX_FORTUNES;
    printf("Your fortune: %s\n", ft->fortunes[randomIndex]);
}

// Function to display the categories
void displayCategories(FortuneTeller* ft) {
    printf("Choose a category for your fortune:\n");
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        printf("%d. %s\n", i + 1, ft->categories[i]);
    }
}

// Main function
int main() {
    srand(time(0)); // Seed for random number generation
    FortuneTeller ft;
    initializeFortuneTeller(&ft);

    printf("Welcome to the Automated Fortune Teller!\n");
    
    char continueFortune = 'y';
    while (continueFortune == 'y') {
        displayCategories(&ft);
        
        printf("Pick a category (1-%d): ", MAX_CATEGORIES);
        int categoryChoice;
        scanf("%d", &categoryChoice);

        if (categoryChoice < 1 || categoryChoice > MAX_CATEGORIES) {
            printf("Invalid choice. Please choose from the available categories.\n");
        } else {
            printf("You chose: %s\n", ft.categories[categoryChoice - 1]);
            getRandomFortune(&ft);
        }
        
        printf("Would you like another fortune? (y/n): ");
        scanf(" %c", &continueFortune); // Space before %c to consume any extra newline
    }

    printf("Thank you for using the Automated Fortune Teller! Goodbye!\n");
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

void displayWelcomeMessage() {
    printf("========================================\n");
    printf("        Welcome to the Happy Fortune Teller!       \n");
    printf("========================================\n");
    printf("Tell me about your current mood, and I'll reveal your fortune!\n");
}

void displayMoodOptions() {
    printf("\nHow are you feeling today?\n");
    printf("1. Happy\n");
    printf("2. Sad\n");
    printf("3. Excited\n");
    printf("4. Anxious\n");
    printf("5. Content\n");
    printf("6. Curious\n");
    printf("Please enter the number corresponding to your mood: ");
}

void generateFortune(int mood) {
    const char *fortunes[NUM_FORTUNES] = {
        "A joyful surprise is waiting for you!",
        "Something wonderful will happen this week!",
        "You will make a lasting connection with someone special.",
        "Embrace change; it will lead you to great things!",
        "Your creativity will shine through today!",
        "Adventure is on the horizon – pack your bags!",
        "You will find peace in an unexpected place.",
        "A new opportunity approaches; be ready to seize it!",
        "Your kindness will brighten someone's day.",
        "Believe in yourself; great things are coming!"
    };

    // Randomly select a fortune based on mood; mood % NUM_FORTUNES ensures it's within bounds
    srand(time(0));  // Seed the random number generator
    int fortuneIndex = rand() % NUM_FORTUNES;
    
    printf("\nYour Fortune:\n");
    printf("%s\n", fortunes[fortuneIndex]);

    // Display a happy ending
    printf("========================================\n");
    printf("Thank you for visiting the Happy Fortune Teller!\n");
    printf("May your day be filled with joy and positivity!\n");
    printf("========================================\n");
}

int main() {
    displayWelcomeMessage();
    displayMoodOptions();

    int mood;
    scanf("%d", &mood);

    if (mood < 1 || mood > 6) {
        printf("Oops! That doesn't seem to be a valid mood option. Please try again.\n");
    } else {
        generateFortune(mood);
    }

    return 0;
}
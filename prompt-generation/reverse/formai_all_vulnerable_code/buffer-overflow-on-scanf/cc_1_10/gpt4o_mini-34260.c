//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNE_LENGTH 100
#define MAX_NAME_LENGTH 50
#define MAX_COLOR_LENGTH 20
#define NUMBER_OF_FORTUNES 10

const char* fortunes[NUMBER_OF_FORTUNES] = {
    "You will find luck in unexpected places.",
    "Adventure awaits you, be ready to seize it!",
    "A surprise gift is coming your way.",
    "Love is just around the corner; keep your heart open.",
    "Good things come to those who wait.",
    "You will soon embark on a journey that will change your life.",
    "Your kindness will be rewarded in the near future.",
    "Believe in yourself; great things are on the horizon.",
    "A challenge will present itself; face it with courage.",
    "Today is the day to take that leap of faith!"
};

void display_instructions() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name and favorite color to receive your fortune.\n");
    printf("Press Ctrl+C to exit the program anytime.\n\n");
}

void get_user_input(char *name, char *color) {
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline character

    printf("Enter your favorite color: ");
    fgets(color, MAX_COLOR_LENGTH, stdin);
    color[strcspn(color, "\n")] = 0; // Remove trailing newline character
}

void generate_fortune(char *name, char *color) {
    // Seed the random number generator
    srand(time(NULL));

    // Get a random fortune
    int fortune_index = rand() % NUMBER_OF_FORTUNES;
    
    // Display the fortune
    printf("\n--- %s's Fortune ---\n", name);
    printf("With your love for %s, %s,\n", color, fortunes[fortune_index]);
    printf("-----------------------\n\n");
}

int main() {
    char name[MAX_NAME_LENGTH];
    char color[MAX_COLOR_LENGTH];

    display_instructions();

    while (1) {
        get_user_input(name, color);

        if (strlen(name) == 0 || strlen(color) == 0) {
            printf("Please provide both your name and your favorite color.\n");
            continue; // Skip the fortune generation if input is incomplete
        }

        generate_fortune(name, color);
        printf("Would you like to know another fortune? (y/n): ");
        
        char response;
        scanf(" %c", &response);
        while (getchar() != '\n'); // Clear the input buffer

        if (response != 'y' && response != 'Y') {
            printf("Thank you for visiting the Automated Fortune Teller! Have a great day!\n");
            break;
        } else {
            // Continue to the next fortune
            printf("\nLet's see what fate has in store for you...\n");
        }
    }
    
    return 0;
}
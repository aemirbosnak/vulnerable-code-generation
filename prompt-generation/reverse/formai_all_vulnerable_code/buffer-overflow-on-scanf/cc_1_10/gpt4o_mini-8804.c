//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10
#define MAX_FORTUNE_LENGTH 100

// Function prototypes
void display_greeting();
void display_fortunes(const char fortunes[][MAX_FORTUNE_LENGTH], int number_of_fortunes);
int get_user_choice();
void show_fortune(int choice, const char fortunes[][MAX_FORTUNE_LENGTH]);

int main() {
    const char fortunes[NUM_FORTUNES][MAX_FORTUNE_LENGTH] = {
        "You will find joy in unexpected places.",
        "A thrilling time is in your near future.",
        "A lifetime friend shall soon be made.",
        "You will discover a hidden talent within you.",
        "Adventure awaits you at every turn.",
        "Success is just around the corner.",
        "Embrace the unknown, it holds the key to your happiness.",
        "You will be faced with a choice, choose wisely.",
        "A pleasant surprise is in store for you.",
        "You will meet someone special."
    };

    srand(time(NULL)); // Seed random number generator
    display_greeting();
    display_fortunes(fortunes, NUM_FORTUNES);

    int choice = get_user_choice();
    show_fortune(choice, fortunes);

    return 0;
}

// Function to display the greeting
void display_greeting() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Let me show you your future...\n\n");
}

// Function to display the available fortunes to the user
void display_fortunes(const char fortunes[][MAX_FORTUNE_LENGTH], int number_of_fortunes) {
    printf("Here are some fortunes you can choose from:\n");
    for (int i = 0; i < number_of_fortunes; i++) {
        printf("%d: %s\n", i + 1, fortunes[i]);
    }
}

// Function to get user choice
int get_user_choice() {
    int choice;
    printf("Please enter the number of the fortune you would like to hear (1-%d): ", NUM_FORTUNES);
    
    while (1) {
        scanf("%d", &choice);
        if (choice >= 1 && choice <= NUM_FORTUNES) {
            break; // Valid input received
        }
        printf("Invalid choice. Please try again (1-%d): ", NUM_FORTUNES);
    }
    
    return choice - 1; // Adjust for zero-based index
}

// Function to show the chosen fortune
void show_fortune(int choice, const char fortunes[][MAX_FORTUNE_LENGTH]) {
    printf("\nYour chosen fortune is:\n");
    printf("** %s **\n", fortunes[choice]);
    printf("May your future be bright!\n");
}
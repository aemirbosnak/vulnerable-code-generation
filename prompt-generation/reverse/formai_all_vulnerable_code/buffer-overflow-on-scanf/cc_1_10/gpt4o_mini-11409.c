//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10

const char* fortunes[MAX_FORTUNES] = {
    "You will have a great day filled with opportunities.",
    "A surprise will change your perspective.",
    "A journey long overdue is about to begin.",
    "Fortune favors the brave - don't hesitate!",
    "You will meet someone special soon.",
    "An unexpected event will bring you joy.",
    "Learn to say no for your own well-being.",
    "Financial luck is on your side this week.",
    "Open your mind to new experiences.",
    "Love is around the corner; be ready!"
};

// Function to get a random fortune
const char* get_random_fortune() {
    srand(time(NULL)); // Seed the random number generator
    int random_index = rand() % MAX_FORTUNES; // Generate a random index
    return fortunes[random_index]; // Return a random fortune
}

// Function to display the fortune
void display_fortune(const char* fortune) {
    printf("\nYour fortune for today is:\n");
    printf("%s\n", fortune);
    printf("Remember, the future is not set in stone!\n");
}

// Function to keep prompting the user
void start_fortune_teller() {
    char continue_choice;

    printf("Welcome to the Automated Fortune Teller!\n");
    
    do {
        const char* fortune = get_random_fortune();
        display_fortune(fortune);
        
        printf("\nWould you like to know your fortune again? (y/n): ");
        scanf(" %c", &continue_choice);
        
        if (continue_choice != 'y' && continue_choice != 'n') {
            printf("Invalid option. Exiting the program.\n");
            break;
        }
        
    } while (continue_choice == 'y');

    printf("Thank you for visiting! Have a great day!\n");
}

int main() {
    start_fortune_teller();
    return 0;
}
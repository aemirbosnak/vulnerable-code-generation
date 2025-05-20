//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10

// Function prototypes
void display_welcome_message();
void display_fortune(int fortune_index);
int get_user_input();

int main() {
    // Seed the random number generator
    srand(time(NULL));

    display_welcome_message();

    int user_choice;
    while (1) {
        // Get user input for fortune telling
        user_choice = get_user_input();

        // User wants to exit the program
        if (user_choice == 0) {
            printf("Thank you for using the Automated Fortune Teller! Goodbye!\n");
            break;
        }

        // Generate a random fortune
        int fortune_index = rand() % MAX_FORTUNES;
        display_fortune(fortune_index);
    }

    return 0;
}

void display_welcome_message() {
    printf("====================================\n");
    printf("      Automated Fortune Teller      \n");
    printf("====================================\n");
    printf("Welcome! Would you like to know your fortune?\n");
    printf("Press 1 to receive your fortune.\n");
    printf("Press 0 to exit the program.\n");
    printf("====================================\n");
}

void display_fortune(int fortune_index) {
    const char *fortunes[MAX_FORTUNES] = {
        "You will find luck in unexpected places.",
        "A thrilling time is in your immediate future.",
        "An old friend will reconnect with you soon.",
        "An opportunity will come knocking, be ready to seize it!",
        "A great fortune will arrive soon, be prepared!",
        "You will be surrounded by love and friendship.",
        "Changes are coming, embrace them!",
        "A long-lost dream will soon become a reality.",
        "Your talents will be acknowledged, leading to new opportunities.",
        "A surprise is waiting for you at the end of the week."
    };

    printf("Your fortune: %s\n", fortunes[fortune_index]);
    printf("====================================\n");
}

int get_user_input() {
    int input;
    printf("Enter your choice: ");
    while (1) {
        if (scanf("%d", &input) != 1) {
            // Clear input buffer on invalid input
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number (0 to exit, 1 to get your fortune): ");
        } else if (input < 0 || input > 1) {
            printf("Please enter a valid option (0 to exit, 1 to get your fortune): ");
        } else {
            // Clear input buffer for valid input
            while (getchar() != '\n');
            return input;
        }
    }
}
//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10

const char *fortunes[MAX_FORTUNES] = {
    "You will find happiness in unexpected places.",
    "Adventure awaits you, be ready to embrace it.",
    "A new friendship will blossom very soon.",
    "Your hard work will soon pay off in ways you cannot imagine.",
    "Be cautious, someone close may not have good intentions.",
    "An opportunity will present itself; seize it wisely.",
    "You will travel to a place that brings you joy.",
    "Expect to receive a surprising message from afar.",
    "Someone will seek your advice; give it kindly.",
    "Trust your instincts, they will guide you to success."
};

void display_welcome_message() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I will predict your future based on your answers.\n\n");
}

int get_user_input() {
    int choice;
    printf("Please select a number between 1 and 10 (0 to exit): ");
    scanf("%d", &choice);
    return choice;
}

void tell_fortune(int choice) {
    if (choice < 1 || choice > 10) {
        printf("That number is outside of the range. Please try again.\n");
    } else {
        printf("Your fortune: %s\n", fortunes[choice - 1]);
    }
}

void suggest_fortune() {
    srand(time(NULL));
    int random_index = rand() % MAX_FORTUNES;
    printf("Your randomly suggested fortune: %s\n", fortunes[random_index]);
}

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Get a specific fortune\n");
    printf("2. Get a random fortune\n");
    printf("3. Exit\n");
}

int main() {
    display_welcome_message();

    int choice = 0;

    while (1) {
        display_menu();
        printf("Please select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int fortune_choice = get_user_input();
                    if (fortune_choice == 0) {
                        return 0; // Exit the program
                    }
                    tell_fortune(fortune_choice);
                }
                break;
            case 2:
                suggest_fortune();
                break;
            case 3:
                printf("Thank you for visiting the fortune teller! Goodbye!\n");
                return 0; // Exit the program
            default:
                printf("Invalid option, please choose again.\n");
                break;
        }
    }

    return 0;
}
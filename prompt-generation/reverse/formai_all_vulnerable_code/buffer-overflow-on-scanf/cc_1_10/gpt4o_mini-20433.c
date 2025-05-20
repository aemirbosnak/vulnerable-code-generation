//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 5
#define MAX_NAME_LENGTH 50

void print_intro() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Enter your name and let the mystical forces guide you!\n");
}

void get_user_name(char *name) {
    printf("Please enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove the newline character
}

void generate_fortune(char *name) {
    const char *fortunes[MAX_FORTUNES] = {
        "You will find happiness in unexpected places.",
        "A thrilling adventure is in your future.",
        "Someone from your past will come back into your life.",
        "You will soon have an important choice to make.",
        "A new opportunity will bring you great wealth."
    };

    // Seed the random number generator
    srand(time(NULL));
    
    // Select a random fortune
    int random_index = rand() % MAX_FORTUNES;

    // Print the fortune
    printf("Dear %s, your fortune is: %s\n", name, fortunes[random_index]);
}

void create_choice_menu() {
    printf("Choose an option to receive your fortune:\n");
    printf("1. Love\n");
    printf("2. Career\n");
    printf("3. Adventure\n");
    printf("4. Health\n");
    printf("5. Happiness\n");
    printf("Enter your choice (1-5): ");
}

void offer_choice_fortune(char *name) {
    int choice;

    create_choice_menu();
    scanf("%d", &choice);
    
    // Check for valid input
    while (choice < 1 || choice > 5) {
        printf("Invalid choice! Please enter a number between 1 and 5: ");
        scanf("%d", &choice);
    }

    if (choice == 1) {
        printf("Ah, matters of the heart! Here's your love fortune:\n");
        generate_fortune(name);
    } else if (choice == 2) {
        printf("Career paths are filled with choices! Here's your career fortune:\n");
        generate_fortune(name);
    } else if (choice == 3) {
        printf("Adventure awaits! Here's what the fates say:\n");
        generate_fortune(name);
    } else if (choice == 4) {
        printf("Health is wealth, let's see your health fortune:\n");
        generate_fortune(name);
    } else if (choice == 5) {
        printf("Happiness comes from within. Here's your happiness fortune:\n");
        generate_fortune(name);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];

    print_intro();
    get_user_name(name);
    
    printf("\nNow, let’s see what the universe has in store for you, %s!\n", name);
    offer_choice_fortune(name);

    printf("\nThank you for visiting the Automated Fortune Teller!\n");
    return 0;
}
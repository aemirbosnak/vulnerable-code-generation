//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 10
#define MAX_NAME_LEN 30

void print_welcome_message();
void get_user_name(char *name);
void display_fortune(int option);
int get_user_choice();
void show_random_fortune();

const char *fortunes[MAX_FORTUNES] = {
    "You will find a hidden talent!",
    "A thrilling time is in your near future.",
    "A fresh start will put you on your way.",
    "Something unexpected will soon happen.",
    "Your hard work will soon pay off.",
    "You will come into great wealth.",
    "Friendship is just around the corner.",
    "Very soon, you will receive an important message.",
    "You will discover a new passion.",
    "Adventure awaits you just beyond the horizon."
};

int main() {
    char name[MAX_NAME_LEN];

    print_welcome_message();
    get_user_name(name);

    printf("\nHello %s! Welcome to the Automated Fortune Teller.\n", name);
    printf("Would you like to:\n");
    printf("1. Get a specific fortune\n");
    printf("2. Receive a random fortune\n");
    printf("3. Exit\n");

    int choice = get_user_choice();
    
    switch (choice) {
        case 1:
            printf("Please select a fortune option (1-10): ");
            int option;
            scanf("%d", &option);
            if (option >= 1 && option <= 10) {
                display_fortune(option - 1);
            } else {
                printf("Invalid selection! Please run the program again and select a valid option.\n");
            }
            break;
        case 2:
            show_random_fortune();
            break;
        case 3:
            printf("Thank you for visiting, %s! Goodbye!\n", name);
            break;
        default:
            printf("Invalid choice! Exiting the program.\n");
            break;
    }

    return 0;
}

void print_welcome_message() {
    printf("================================\n");
    printf("       Automated Fortune Teller  \n");
    printf("================================\n");
}

void get_user_name(char *name) {
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character
}

void display_fortune(int option) {
    printf("Your fortune: %s\n", fortunes[option]);
}

int get_user_choice() {
    int choice;
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    return choice;
}

void show_random_fortune() {
    srand(time(0)); // Seed random number generator
    int random_index = rand() % MAX_FORTUNES;
    printf("Your random fortune: %s\n", fortunes[random_index]);
}
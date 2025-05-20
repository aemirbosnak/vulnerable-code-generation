//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 10
#define MAX_NAME_LENGTH 50

const char *fortunes[MAX_FORTUNES] = {
    "You will embark on a great journey.",
    "A mysterious person will enter your life.",
    "Fortune favors the bold; take that leap!",
    "Success is on the horizon; stay true to your path.",
    "A surprise will bring you joy soon.",
    "Don't overlook the small details in life.",
    "An old friend will reconnect with you shortly.",
    "Creativity will abound; embrace it!",
    "An unexpected gift is on its way.",
    "Tomorrow will bring a new opportunity."
};

void welcomeUser(char name[]) {
    printf("Welcome, %s, to the Mystical Fortune Teller!\n", name);
    printf("Let's discover what the universe has in store for you...\n\n");
}

void getUserName(char name[]) {
    printf("Please enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline character
}

void tellFortune() {
    int randomIndex = rand() % MAX_FORTUNES;
    printf("Your fortune is: %s\n\n", fortunes[randomIndex]);
}

void inquireContinue() {
    char response[3];
    printf("Would you like to know another fortune? (yes/no): ");
    fgets(response, sizeof(response), stdin);
    response[strcspn(response, "\n")] = '\0';  // Remove newline character

    if (strcmp(response, "yes") == 0) {
        tellFortune();
        inquireContinue();
    } else {
        printf("Thank you for visiting! May your path be filled with light.\n");
    }
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. Tell me my fortune\n");
    printf("2. Exit\n");
}

int main() {
    char name[MAX_NAME_LENGTH];

    srand(time(0)); // Seed for randomness

    getUserName(name);
    welcomeUser(name);
    
    int choice;
    
    do {
        displayMenu();
        printf("Please select an option (1-2): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after scanf

        if (choice == 1) {
            tellFortune();
            inquireContinue();
        } else if (choice == 2) {
            printf("Thank you for visiting, %s! Goodbye!\n", name);
        } else {
            printf("Invalid choice! Please select again.\n");
        }

    } while (choice != 2);

    return 0;
}
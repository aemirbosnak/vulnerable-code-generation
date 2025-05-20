//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 10
#define MAX_LENGTH 256

void print_fortune(char fortunes[MAX_FORTUNES][MAX_LENGTH]) {
    int random_index = rand() % MAX_FORTUNES;
    printf("\nYour fortune reading is: %s\n", fortunes[random_index]);
}

void display_menu() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("1. Read my fortune\n");
    printf("2. Add a new fortune\n");
    printf("3. View all fortunes\n");
    printf("4. Exit\n");
}

void add_fortune(char fortunes[MAX_FORTUNES][MAX_LENGTH], int *count) {
    if (*count >= MAX_FORTUNES) {
        printf("Sorry, the fortune list is full!\n");
        return;
    }
    
    printf("Enter your new fortune: ");
    fgets(fortunes[*count], MAX_LENGTH, stdin);
    
    // Remove newline character
    fortunes[*count][strcspn(fortunes[*count], "\n")] = 0;
    (*count)++;
    printf("Fortune added successfully!\n");
}

void view_fortunes(char fortunes[MAX_FORTUNES][MAX_LENGTH], int count) {
    if (count == 0) {
        printf("No fortunes available.\n");
        return;
    }
    
    printf("\nList of all fortunes:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, fortunes[i]);
    }
}

int main() {
    char fortunes[MAX_FORTUNES][MAX_LENGTH] = {
        "You will find great fortune in unexpected places.",
        "A thrilling time is in your near future.",
        "Your talents will be recognized and suitably rewarded.",
        "A friend will become an ally.",
        "Success is on the horizon; stay positive.",
        "Adventure is coming; embrace it.",
        "A new opportunity will present itself soon.",
        "Happiness is a choice; choose wisely.",
        "You will discover a hidden talent.",
        "Wisdom is the reward for patience."
    };

    int count = 10; // Predefined fortunes
    int choice;
    
    srand(time(NULL));
    
    while (1) {
        display_menu();
        printf("Please select an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after scanf

        switch (choice) {
            case 1:
                print_fortune(fortunes);
                break;
            case 2:
                add_fortune(fortunes, &count);
                break;
            case 3:
                view_fortunes(fortunes, count);
                break;
            case 4:
                printf("Thank you for visiting the Automated Fortune Teller! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
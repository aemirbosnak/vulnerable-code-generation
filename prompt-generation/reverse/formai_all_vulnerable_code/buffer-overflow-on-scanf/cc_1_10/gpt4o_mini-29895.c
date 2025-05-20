//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 10
#define MAX_LENGTH 256

void display_menu() {
    printf("\n======================\n");
    printf("  Automated Fortune Teller\n");
    printf("======================\n");
    printf("1. Get a Fortune\n");
    printf("2. Add a new Fortune\n");
    printf("3. Exit\n");
    printf("======================\n");
}

void get_fortune(char fortunes[MAX_FORTUNES][MAX_LENGTH], int count) {
    if (count == 0) {
        printf("No fortunes available! Please add some first.\n");
        return;
    }
    int index = rand() % count; // Generate a random index
    printf("Your fortune: %s\n", fortunes[index]);
}

void add_fortune(char fortunes[MAX_FORTUNES][MAX_LENGTH], int *count) {
    if (*count >= MAX_FORTUNES) {
        printf("Fortune list is full! Can't add more.\n");
        return;
    }
    printf("Enter your new fortune: ");
    fgets(fortunes[*count], MAX_LENGTH, stdin);
    fortunes[*count][strcspn(fortunes[*count], "\n")] = 0; // Remove trailing newline
    (*count)++;
    printf("Fortune added successfully!\n");
}

int main() {
    srand(time(0)); // Seed random number generator
    char fortunes[MAX_FORTUNES][MAX_LENGTH] = {
        "You will find great wealth soon.",
        "A new opportunity will come your way.",
        "Love is just around the corner.",
        "Success is on its way, trust the journey.",
        "You will meet someone special today.",
        "Unexpected news will brighten your day.",
        "Adventure awaits you, embrace it.",
        "Hard work will pay off soon.",
        "Remember the past, but do not dwell on it.",
        "A pleasant surprise is in your near future."
    };
    int fortune_count = 10; // Initial count of fortunes
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1:
                get_fortune(fortunes, fortune_count);
                break;
            case 2:
                add_fortune(fortunes, &fortune_count);
                break;
            case 3:
                printf("Thank you for visiting the Automated Fortune Teller. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
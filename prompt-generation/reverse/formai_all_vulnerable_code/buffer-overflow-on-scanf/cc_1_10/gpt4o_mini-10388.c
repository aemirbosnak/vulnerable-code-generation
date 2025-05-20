//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 5
#define MAX_LENGTH 256

void display_menu() {
    printf("\nWelcome to the Automated Fortune Teller!\n");
    printf("Please select an option:\n");
    printf("1. Get your fortune\n");
    printf("2. Add a fortune\n");
    printf("3. View all fortunes\n");
    printf("4. Exit\n");
}

void get_fortune(char fortunes[][MAX_LENGTH], int fortune_count) {
    if (fortune_count == 0) {
        printf("No fortunes available. Please add some fortunes first.\n");
        return;
    }

    srand(time(NULL));
    int index = rand() % fortune_count;
    printf("Your fortune: %s\n", fortunes[index]);
}

void add_fortune(char fortunes[][MAX_LENGTH], int *fortune_count) {
    if (*fortune_count >= MAX_FORTUNES) {
        printf("Cannot add more fortunes. The limit of %d has been reached.\n", MAX_FORTUNES);
        return;
    }

    printf("Please enter a fortune: ");
    fgets(fortunes[*fortune_count], MAX_LENGTH, stdin);
    
    strtok(fortunes[*fortune_count], "\n"); // Remove trailing newline character
    (*fortune_count)++;
    printf("Fortune added successfully!\n");
}

void view_fortunes(char fortunes[][MAX_LENGTH], int fortune_count) {
    if (fortune_count == 0) {
        printf("No fortunes available.\n");
        return;
    }

    printf("\nCurrent fortunes:\n");
    for (int i = 0; i < fortune_count; i++) {
        printf("%d: %s\n", i + 1, fortunes[i]);
    }
}

int main() {
    char fortunes[MAX_FORTUNES][MAX_LENGTH] = {0}; // Array of fortunes
    int fortune_count = 0; // Tracks number of added fortunes
    int option;

    while (1) {
        display_menu();
        printf("Enter your option: ");
        
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        getchar(); // To consume the newline character after integer input

        switch (option) {
            case 1:
                get_fortune(fortunes, fortune_count);
                break;
            case 2:
                add_fortune(fortunes, &fortune_count);
                break;
            case 3:
                view_fortunes(fortunes, fortune_count);
                break;
            case 4:
                printf("Thank you for using the Automated Fortune Teller! Goodbye!\n");
                return 0;
            default:
                printf("Invalid option, please choose from 1 to 4.\n");
        }
    }

    return 0;
}
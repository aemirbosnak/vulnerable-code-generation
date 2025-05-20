//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 10
#define MAX_LENGTH 256

void display_menu();
void get_fortune(char fortunes[MAX_FORTUNES][MAX_LENGTH]);

int main() {
    srand(time(0));  // Seed the random number generator
    char fortunes[MAX_FORTUNES][MAX_LENGTH] = {
        "You will find a new source of inspiration today.",
        "A surprising event will bring you joy.",
        "Your efforts will be rewarded in the near future.",
        "A conversation will lead to an unexpected opportunity.",
        "A stranger will change the course of your day.",
        "Your passion will lead you to great heights.",
        "Trust your instincts; they will guide you wisely.",
        "Take a break; your mind needs some rest.",
        "A close friend will need your support.",
        "You will discover a hidden talent within yourself."
    };

    int choice;
    do {
        display_menu();
        printf("Enter your choice (1 to get a fortune, 0 to exit): ");
        scanf("%d", &choice);

        if (choice == 1) {
            get_fortune(fortunes);
        } else if (choice != 0) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    printf("Thank you for visiting the Automated Fortune Teller. Goodbye!\n");
    return 0;
}

void display_menu() {
    printf("\n************ Automated Fortune Teller ************\n");
    printf("1. Get your fortune\n");
    printf("0. Exit\n");
    printf("**************************************************\n");
}

void get_fortune(char fortunes[MAX_FORTUNES][MAX_LENGTH]) {
    int index = rand() % MAX_FORTUNES;  // Randomly select a fortune
    printf("Your fortune: %s\n", fortunes[index]);
    printf("Would you like to draw another fortune? (1 for Yes, 0 for No): ");
    
    int response;
    scanf("%d", &response);
    
    // Loop to keep asking until the user responds with No (0)
    while (response == 1) {
        index = rand() % MAX_FORTUNES;
        printf("Your new fortune: %s\n", fortunes[index]);
        printf("Would you like to draw another fortune? (1 for Yes, 0 for No): ");
        scanf("%d", &response);
    }

    if (response == 0) {
        printf("Thanks for the visit! Your fortunes await next time.\n");
    } else {
        printf("Invalid response. Returning to the main menu.\n");
    }
}
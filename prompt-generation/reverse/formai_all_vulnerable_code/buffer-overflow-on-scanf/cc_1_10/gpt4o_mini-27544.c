//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10

void displayWelcomeMessage() {
    printf("****************************************\n");
    printf("*            Welcome to the            *\n");
    printf("*    C Automated Fortune Teller 3000   *\n");
    printf("****************************************\n");
    printf("Prepare to unlock the mysteries of your future!\n\n");
}

void displayFortunes(char fortunes[MAX_FORTUNES][256]) {
    printf("Here are the fortunes you can choose from:\n");
    for (int i = 0; i < MAX_FORTUNES; i++) {
        printf("%d: %s\n", i + 1, fortunes[i]);
    }
}

int getUserChoice() {
    int choice;
    printf("\nEnter the number of your desired fortune (1-%d): ", MAX_FORTUNES);
    scanf("%d", &choice);
    
    // Validate user input
    while (choice < 1 || choice > MAX_FORTUNES) {
        printf("Invalid choice. Please try again (1-%d): ", MAX_FORTUNES);
        scanf("%d", &choice);
    }
    return choice - 1; // Adjust for zero indexing
}

void revealFortune(int choice, char fortunes[MAX_FORTUNES][256]) {
    printf("\nYour fortune is:\n");
    printf("------------------------------------------------\n");
    printf("* %s *\n", fortunes[choice]);
    printf("------------------------------------------------\n");
}

void additionalFortuneWheel(char fortunes[MAX_FORTUNES][256]) {
    printf("\nWould you like to spin the fortune wheel for a surprise? (y/n): ");
    char spin;
    scanf(" %c", &spin);

    if (spin == 'y' || spin == 'Y') {
        srand(time(NULL));
        int randomIndex = rand() % MAX_FORTUNES;
        printf("\nSurprise Fortune!\n");
        printf("------------------------------------------------\n");
        printf("* %s *\n", fortunes[randomIndex]);
        printf("------------------------------------------------\n");
    } else {
        printf("\nThank you for visiting the C Automated Fortune Teller 3000!\n");
    }
}

int main() {
    char fortunes[MAX_FORTUNES][256] = {
        "You will find great success in your career.",
        "A new love is on the horizon.",
        "Traveling will bring you wisdom and joy.",
        "A friend will become a valuable ally.",
        "Unexpected fortune will find you soon.",
        "You will help someone in need this week.",
        "Stay focused on your goals; success is near.",
        "A surprise invitation will lead to great things.",
        "Adventure awaits, embrace the unknown.",
        "Your creativity will pave the way for greatness."
    };

    displayWelcomeMessage();
    displayFortunes(fortunes);

    int choice = getUserChoice();
    revealFortune(choice, fortunes);
    additionalFortuneWheel(fortunes);

    printf("\nGoodbye! May your future shine bright!\n");
    return 0;
}
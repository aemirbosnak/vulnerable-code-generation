//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10

void display_welcome_message() {
    printf("******************************************\n");
    printf("           Welcome to your Fortune       \n");
    printf("         Teller! A Grateful Journey      \n");
    printf("******************************************\n");
}

void display_fortunes(char *fortunes[], int total_fortunes) {
    printf("Here are the fortunes you can choose from:\n");
    for(int i = 0; i < total_fortunes; i++) {
        printf("%d. %s\n", i + 1, fortunes[i]);
    }
}

void tell_fortune(char *fortune) {
    printf("Your fortune is: %s\n", fortune);
}

int main() {
    char *fortunes[MAX_FORTUNES] = {
        "You will find joy in unexpected places.",
        "A surprise will bring you happiness soon.",
        "You will receive a compliment from a stranger.",
        "An old friend will re-enter your life.",
        "A great opportunity will come your way.",
        "You will gain wisdom through challenges.",
        "Trust your instincts, they will guide you well.",
        "A creative spark is on the horizon.",
        "Your kindness will be acknowledged.",
        "A new adventure awaits you, embrace it!"
    };

    srand(time(NULL)); // Initialize random number generator

    display_welcome_message();

    int choice;
    while (1) {
        printf("Pick a fortune number from the list or press 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thank you for visiting the Fortune Teller!\n");
            printf("May your days be filled with gratitude and wonder!\n");
            break;
        } else if (choice < 1 || choice > MAX_FORTUNES) {
            printf("Please enter a valid choice between 1 and %d.\n", MAX_FORTUNES);
            continue;
        }

        // Provide fortune
        tell_fortune(fortunes[choice - 1]);
        printf("\n"); // Just to separate output nicely
    }

    return 0;
}
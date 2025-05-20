//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(0)); // Seed the random number generator with the current time

    // Define the fortunes
    char* fortunes[] = {
        "Your future is looking bright!",
        "You will have good luck today.",
        "A new opportunity is coming your way.",
        "You will meet someone special soon.",
        "Success is within your reach.",
        "You will receive a pleasant surprise.",
        "Your hard work will pay off.",
        "You will overcome any obstacles in your path.",
        "Your dreams will come true.",
        "You will achieve greatness."
    };

    int numFortunes = sizeof(fortunes) / sizeof(char*); // Get the number of fortunes

    printf("Welcome to the Automated Fortune Teller!\n");

    int userChoice;
    char input[10];

    do {
        printf("Please enter your choice:\n");
        printf("1. Get a fortune\n");
        printf("2. Exit\n");
        scanf("%d", &userChoice);

        // Validate user input
        while (userChoice < 1 || userChoice > 2) {
            printf("Invalid choice. Please enter a number between 1 and 2.\n");
            scanf("%d", &userChoice);
        }

        if (userChoice == 1) {
            printf("Your fortune is:\n");

            // Generate a random fortune
            int fortuneIndex = rand() % numFortunes;
            printf("%s\n", fortunes[fortuneIndex]);

        } else if (userChoice == 2) {
            printf("Thank you for using the Automated Fortune Teller. Goodbye!\n");

        } else {
            // Invalid choice, do nothing
        }

    } while (userChoice!= 2);

    return 0;
}
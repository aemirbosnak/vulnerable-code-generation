//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayWelcomeMessage() {
    printf("****************************************\n");
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Ask your question and see what the future holds.\n");
    printf("****************************************\n\n");
}

int getUserInput() {
    int choice;
    printf("Press 1 to ask a question or 0 to exit: ");
    scanf("%d", &choice);
    return choice;
}

void printFortune(int fortuneIndex) {
    const char *fortunes[] = {
        "You will have a great day ahead!",
        "Expect the unexpected today.",
        "A thrilling time is in your future!",
        "A friend will bring exciting news.",
        "Your hard work will soon pay off.",
        "Beware of bad decisions today.",
        "You will discover a hidden talent.",
        "An invitation will bring joy.",
        "Love is around the corner, but you have to take the first step.",
        "You will encounter an interesting stranger."
    };

    printf("Your fortune: %s\n", fortunes[fortuneIndex]);
}

int main() {
    srand(time(0)); // Seed the random number generator
    int userChoice;

    displayWelcomeMessage();

    do {
        userChoice = getUserInput();

        if(userChoice == 1) {
            int fortuneIndex = rand() % 10; // Get a random index for the fortunes
            printFortune(fortuneIndex);
        } else if(userChoice != 0) {
            printf("Invalid input! Please enter 1 to ask a question or 0 to exit.\n");
        }

    } while (userChoice != 0);
    
    printf("Thank you for visiting! Your future awaits.\n");
    return 0;
}
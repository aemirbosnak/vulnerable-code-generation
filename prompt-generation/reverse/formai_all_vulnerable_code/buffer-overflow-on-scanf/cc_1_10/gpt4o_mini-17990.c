//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

void display_welcome_message() {
    printf("********************************************\n");
    printf("*          Welcome to the Fortune         *\n");
    printf("*               Teller Program!            *\n");
    printf("********************************************\n");
    printf("Let the stars align and reveal your fate!\n\n");
}

void display_fortunes(char fortunes[NUM_FORTUNES][100]) {
    for (int i = 0; i < NUM_FORTUNES; i++) {
        printf("%d. %s\n", i + 1, fortunes[i]);
    }
}

int get_user_choice() {
    int choice;
    printf("Choose a fortune by entering a number (1-%d) or enter 0 for a random fortune: ", NUM_FORTUNES);
    scanf("%d", &choice);
    return choice;
}

void reveal_fortune(int choice, char fortunes[NUM_FORTUNES][100]) {
    if (choice >= 1 && choice <= NUM_FORTUNES) {
        printf("Your chosen fortune is: %s\n", fortunes[choice - 1]);
    } else if (choice == 0) {
        // Random fortune
        int random_choice = rand() % NUM_FORTUNES;
        printf("Your random fortune is: %s\n", fortunes[random_choice]);
    } else {
        printf("Oops! That number is out of range. Please try again.\n");
    }
}

void display_farewell_message() {
    printf("\nThank you for visiting the Fortune Teller!\n");
    printf("May your day be filled with magic and surprises!\n");
    printf("********************************************\n");
}

int main() {
    char fortunes[NUM_FORTUNES][100] = {
        "You will find joy in unexpected places.",
        "A new adventure is on the horizon.",
        "Trust your instincts; they will lead you well.",
        "A hidden talent will come to light soon.",
        "You are about to encounter a fascinating person.",
        "Hard work pays off, stay the course!",
        "Your friends are true gems, cherish them.",
        "An opportunity will knock at your home soon.",
        "A positive change is on its way, embrace it!",
        "Believe in yourself, and the world will too."
    };

    srand(time(0)); // Seed the random number generator

    display_welcome_message();
    display_fortunes(fortunes);

    int user_choice = get_user_choice();
    reveal_fortune(user_choice, fortunes);
    
    display_farewell_message();
    
    return 0;
}
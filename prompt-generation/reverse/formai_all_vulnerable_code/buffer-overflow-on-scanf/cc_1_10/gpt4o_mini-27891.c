//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10

const char *fortunes[MAX_FORTUNES] = {
    "You will achieve great success in your career!",
    "A thrilling adventure is in your near future.",
    "Don't be afraid to take risks; fortune favors the bold!",
    "Love is just around the corner; keep your heart open!",
    "A financial opportunity will present itself unexpectedly.",
    "Travel is in your stars; prepare for a journey!",
    "You will make a valuable new friendship soon.",
    "A surprise is waiting for you today—keep your eyes peeled!",
    "Trust your instincts; they will guide you well.",
    "Happiness will find you when you least expect it!",
};

void displayWelcomeMessage() {
    printf("======================================\n");
    printf("        Welcome to the Magic        \n");
    printf("        Automated Fortune Teller!   \n");
    printf("======================================\n");
    printf("Ask a yes or no question and see your fate unfold!\n");
    printf("======================================\n");
}

void giveFortune() {
    int randomIndex = rand() % MAX_FORTUNES;
    printf("🌀 Your Fortune: %s\n", fortunes[randomIndex]);
}

int main() {
    char continueFortune = 'y';
    
    // Initialize random number generator
    srand(time(NULL));

    displayWelcomeMessage();

    while (continueFortune == 'y' || continueFortune == 'Y') {
        char question[256];
        
        printf("\nType your question (yes/no): ");
        fgets(question, sizeof(question), stdin);

        printf("Thinking...\n");
        sleep(2); // Pause for dramatic effect!

        giveFortune();
        
        printf("\nWould you like to ask another question? (y/n): ");
        scanf(" %c", &continueFortune);
        getchar(); // clear the newline from buffer
    }

    printf("Thank you for visiting the Magic Automated Fortune Teller! ✨\n");
    printf("Have a wonderful day ahead! 🌟\n");
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10

// Function prototypes
void displayWelcomeMessage();
void displayFarewellMessage();
void displayFortune(const char *fortune);
const char* getRandomFortune();

const char *fortunes[MAX_FORTUNES] = {
    "You will find a great adventure in the near future.",
    "A financial opportunity is coming your way!",
    "An old friend will reconnect with you soon.",
    "A surprise event will bring you great joy.",
    "Patience is your ally, great things take time.",
    "You will make a meaningful impact on someone's life.",
    "A new hobby will bring you fulfillment.",
    "Travel will be a source of happiness this year.",
    "Your intuition is strong, trust your instincts.",
    "An unexpected encounter will lead to a new friendship."
};

int main() {
    // Seed for random number generation
    srand(time(NULL));
    
    displayWelcomeMessage();
    
    char choice;
    
    do {
        const char *fortune = getRandomFortune();
        displayFortune(fortune);
        
        printf("Do you want to receive another fortune? (y/n): ");
        scanf(" %c", &choice); // Space before %c to consume any leftover newline from previous input

    } while (choice == 'y' || choice == 'Y');

    displayFarewellMessage();
    
    return 0;
}

void displayWelcomeMessage() {
    printf("=========================================\n");
    printf("        Welcome to the Fortune Teller!  \n");
    printf("=========================================\n");
    printf("Get ready to receive some mystical fortunes!\n\n");
}

void displayFarewellMessage() {
    printf("\n=========================================\n");
    printf("        Thank you for visiting!         \n");
    printf("=========================================\n");
    printf("May your path ahead be as bright as your fortune!\n");
}

void displayFortune(const char *fortune) {
    printf("\nYour fortune is: %s\n", fortune);
}

const char* getRandomFortune() {
    int index = rand() % MAX_FORTUNES;
    return fortunes[index];
}
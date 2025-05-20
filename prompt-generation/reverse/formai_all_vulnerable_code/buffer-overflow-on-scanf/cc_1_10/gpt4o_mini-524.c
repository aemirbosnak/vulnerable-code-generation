//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayFortune(int index) {
    const char *fortunes[] = {
        "A thrilling adventure is about to begin!",
        "A new opportunity will present itself soon.",
        "Your kindness will bring you great rewards.",
        "An unexpected package will arrive shortly.",
        "Be bold and mighty forces will come to your aid.",
        "You will find what you seek in an unusual place.",
        "Your future is as bright as your spirit!",
        "Someone you admire will take notice of you.",
        "A long-lost friend will reconnect with you!",
        "The stars are aligned for you today!"
    };

    int totalFortunes = sizeof(fortunes) / sizeof(fortunes[0]);
    
    // Ensure index is within bounds
    if (index >= 0 && index < totalFortunes) {
        printf("✨ Fortune: %s ✨\n", fortunes[index]);
    } else {
        printf("Oops! Fortune not found. Try again!\n");
    }
}

int getRandomIndex(int max) {
    return rand() % max;
}

void showInstructions() {
    printf("----------- Welcome to the Energetic Fortune Teller! -----------\n");
    printf("✨ Just press enter to unveil your fortune! ✨\n");
    printf("--------------------------------------------------------------\n");
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    showInstructions();

    // Wait for user input
    getchar();

    // Fetch a random fortune
    int fortuneIndex = getRandomIndex(10);
    
    // Display the fortune
    displayFortune(fortuneIndex);

    // Prompt for further reading
    char continueReading;
    do {
        printf("Would you like to learn about another fortune? (y/n): ");
        scanf(" %c", &continueReading);

        if (continueReading == 'y' || continueReading == 'Y') {
            fortuneIndex = getRandomIndex(10);
            displayFortune(fortuneIndex);
        }

    } while (continueReading == 'y' || continueReading == 'Y');

    printf("Thank you for visiting the Energetic Fortune Teller! 🌟\n");
    return 0;
}
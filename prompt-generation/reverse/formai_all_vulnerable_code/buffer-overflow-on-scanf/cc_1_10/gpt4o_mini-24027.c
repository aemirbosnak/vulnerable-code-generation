//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 5
#define MAX_NAME_LENGTH 50

void displayWelcomeMessage() {
    printf("*****************************************\n");
    printf("*           Welcome to Fortune Teller   *\n");
    printf("*****************************************\n");
    printf("Let the stars guide you to your destiny.\n");
    printf("What's your name, brave seeker of knowledge?\n");
}

void displayFortuneOptions() {
    printf("Please choose a category to receive your fortune:\n");
    printf("1. Love\n");
    printf("2. Career\n");
    printf("3. Health\n");
    printf("4. General\n");
    printf("5. Exit\n");
}

void generateFortune(int category) {
    const char *loveFortunes[MAX_FORTUNES] = {
        "You will find love in the most unexpected places.",
        "A new romantic interest is heading your way.",
        "Be open to love; it may find you soon.",
        "Heartfelt connections will blossom soon.",
        "Your charm has increased, use it wisely!"
    };

    const char *careerFortunes[MAX_FORTUNES] = {
        "A new opportunity is coming your way at work.",
        "Stay focused and productivity will increase.",
        "You will be recognized for your hard work.",
        "Collaborations will lead to success.",
        "Change is in the air, embrace it!"
    };

    const char *healthFortunes[MAX_FORTUNES] = {
        "Your health will improve if you stay positive.",
        "Regular exercise will benefit you greatly.",
        "Listen to your body; it's trying to tell you something.",
        "Happiness will enhance your overall well-being.",
        "A balanced diet is key to feeling your best."
    };

    const char *generalFortunes[MAX_FORTUNES] = {
        "Adventure awaits; make the most of it!",
        "Unexpected wealth may come your way.",
        "A long-lost friend will soon reach out to you.",
        "You have the strength to overcome any obstacle.",
        "Trust your instincts; they will not lead you astray."
    };

    const char *fortune = NULL;
    srand(time(NULL));
    
    switch (category) {
        case 1:
            fortune = loveFortunes[rand() % MAX_FORTUNES];
            break;
        case 2:
            fortune = careerFortunes[rand() % MAX_FORTUNES];
            break;
        case 3:
            fortune = healthFortunes[rand() % MAX_FORTUNES];
            break;
        case 4:
            fortune = generalFortunes[rand() % MAX_FORTUNES];
            break;
        default:
            printf("Exiting...\n");
            return;
    }

    printf("Here is your fortune: %s\n", fortune);
}

int main() {
    char name[MAX_NAME_LENGTH];
    int choice;

    displayWelcomeMessage();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove the newline character

    printf("Welcome, %s!\n", name);
    
    do {
        displayFortuneOptions();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Only process valid choices
        if (choice < 1 || choice > 5) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        if (choice != 5) {
            generateFortune(choice);
        }
        
    } while (choice != 5);
    
    printf("Thank you for visiting the Fortune Teller! Goodbye, %s!\n", name);
    
    return 0;
}
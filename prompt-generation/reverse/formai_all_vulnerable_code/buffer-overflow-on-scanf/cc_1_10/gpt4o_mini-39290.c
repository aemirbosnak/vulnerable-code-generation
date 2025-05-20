//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

void printFortune(int fortuneNumber);

int main() {
    char name[50];
    int choice = 0;

    // Seed the random number generator
    srand(time(0));

    printf("✨✨✨ Welcome to the Magical Fortune Teller! ✨✨✨\n");
    printf("What is your name, brave soul? ");
    fgets(name, sizeof(name), stdin);

    // Remove newline character from name
    name[strcspn(name, "\n")] = 0;

    printf("\nHello, %s! Let's peer into the cosmos and discover your future...\n", name);
    printf("Are you ready? (Enter 1 for Yes, 0 for No): ");
    scanf("%d", &choice);

    if (choice != 1) {
        printf("Ah, a wise choice! Sometimes, not knowing is the best path ahead. 🌌\n");
        return 0;
    }

    printf("\n🔮🔮🔮 Your journey begins now! 🔮🔮🔮\n");

    // Generate a random fortune
    int fortuneNumber = rand() % NUM_FORTUNES;

    printFortune(fortuneNumber);

    printf("\nThank you for visiting the Magical Fortune Teller! 🌟\n");
    printf("Remember, the future is what you make of it! Goodbye!\n");

    return 0;
}

void printFortune(int fortuneNumber) {
    switch (fortuneNumber) {
        case 0:
            printf("🌟 You will find a great opportunity at work that will change your life! 🌟\n");
            break;
        case 1:
            printf("🌙 A journey long awaited will soon begin. Pack your bags! 🌙\n");
            break;
        case 2:
            printf("🌈 Love is just around the corner, waiting for you to embrace it! 🌈\n");
            break;
        case 3:
            printf("💰 Financial abundance is coming your way – prepare to enjoy the fruits of your labor! 💰\n");
            break;
        case 4:
            printf("🦄 Embrace your inner creativity! A new project will bring you joy! 🦄\n");
            break;
        case 5:
            printf("🌻 A surprise gift from a friend will brighten your day! 🌻\n");
            break;
        case 6:
            printf("✨ It’s time for self-care. Treat yourself to something special this week! ✨\n");
            break;
        case 7:
            printf("⚡ You will encounter a challenge, but with courage, you'll overcome it! ⚡\n");
            break;
        case 8:
            printf("🌊 A period of calm and peace is approaching in your life. Embrace it! 🌊\n");
            break;
        case 9:
            printf("🎉 Celebration is in the air! A reason to rejoice is on the horizon! 🎉\n");
            break;
        default:
            printf("🔮 The stars have not aligned properly. Try again! 🔮\n");
            break;
    }
}
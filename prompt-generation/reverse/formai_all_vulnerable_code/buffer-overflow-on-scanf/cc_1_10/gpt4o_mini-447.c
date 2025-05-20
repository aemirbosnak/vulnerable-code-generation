//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printFortune(int fortuneNumber) {
    switch (fortuneNumber) {
        case 0: 
            printf("✨ You will encounter a hidden talent! Embrace it! ✨\n");
            break;
        case 1: 
            printf("🌟 A great opportunity is on the horizon. Stay vigilant! 🌟\n"); 
            break;
        case 2:
            printf("🍀 Luck is by your side; trust your instincts! 🍀\n");
            break;
        case 3:
            printf("🔥 A new passion will ignite your spirit. Pursue it! 🔥\n");
            break;
        case 4:
            printf("🍂 Change is coming; adapt to thrive! 🍂\n");
            break;
        case 5:
            printf("🌈 A friendly face will bring you unexpected joy! 🌈\n");
            break;
        case 6:
            printf("🌌 The cosmos favors you; be bold in your endeavors! 🌌\n");
            break;
        case 7:
            printf("🌊 A wave of calm will wash over your worries. Relax! 🌊\n");
            break;
        case 8:
            printf("🗝️ A secret will be revealed, enlightening your path! 🗝️\n");
            break;
        case 9:
            printf("🦋 Transformation is at hand; embrace the new you! 🦋\n");
            break;
        default:
            printf("✨ The universe has unique surprises for you; keep your heart open! ✨\n");
            break;
    }
}

void displayMenu() {
    printf("\nWelcome to the Mystical C Fortune Teller!\n");
    printf("What destiny do you seek? Choose wisely:\n");
    printf("1. Seek your fortune\n");
    printf("2. Revel in the unknown\n");
    printf("3. Consult the stars\n");
    printf("4. Experience serendipity\n");
    printf("5. Exit the ethereal realm\n");
    printf("Enter your choice (1-5): ");
}

int main() {
    int choice;
    int fortuneNumber;

    srand(time(0)); // Seed for random number generation
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fortuneNumber = rand() % 10; // Random number between 0 and 9
                printf("🔮 Your fortune is being revealed...\n");
                printFortune(fortuneNumber);
                break;
            case 2:
                printf("🌌 The unknown is a beautiful journey! Take a step ahead... 🌌\n");
                break;
            case 3:
                printf("✨ The stars are shimmering with hopes and dreams! 🎇\n");
                break;
            case 4:
                printf("🍀 Serendipity is the gentle whisper of the universe—cross your path! 🍀\n");
                break;
            case 5:
                printf("🌟 You choose to leave this realm, but possibilities are endless!\n");
                break;
            default:
                printf("🌙 The cosmos urges you to choose a valid option!\n");
                break;
        }

    } while (choice != 5);

    printf("🌈 Thank you for visiting the Mystical C Fortune Teller. Take your dreams with you! 🌈\n");
    return 0;
}
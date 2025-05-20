//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayWelcomeMessage() {
    printf("***************************************\n");
    printf("** Welcome to the Time Travel Simulator! **\n");
    printf("** Experience Romance Through the Ages! **\n");
    printf("***************************************\n");
}

void showDestinations() {
    printf("\nChoose your romantic destination:\n");
    printf("1. Elizabethan Era (16th Century)\n");
    printf("2. The Roaring Twenties (1920s)\n");
    printf("3. Futuristic Space Colony (Year 3023)\n");
    printf("4. Exit\n");
}

void elizabethanRomance() {
    printf("\nYou have traveled to the Elizabethan Era.\n");
    printf("Beneath the moonlit sky, you find yourself in a lush garden.\n");
    printf("You see a beautiful maiden, her eyes sparkling like stars.\n");
    printf("With a soft voice, she whispers sonnets of love, captivating your heart.\n");
    printf("Do you dare to step closer?\n");
}

void roaringTwentiesRomance() {
    printf("\nWelcome to the Roaring Twenties.\n");
    printf("The air is rich with the sound of jazz and laughter.\n");
    printf("You notice a dapper gentleman in a stylish suit, his charm undeniable.\n");
    printf("He invites you to a spectacular dance, where romance flourishes under the glittering lights.\n");
    printf("Will you sweep him off his feet?\n");
}

void futuristicColonyRomance() {
    printf("\nYou've landed in a Futuristic Space Colony.\n");
    printf("Amongst twinkling stars and glowing tech, you meet an alien with a visual of human beauty.\n");
    printf("Their eyes are like distant galaxies, and you share tales of love from Earth.\n");
    printf("Will you blend your souls across the cosmos?\n");
}

int main() {
    int choice;

    displayWelcomeMessage();

    while (1) {
        showDestinations();
        printf("Select your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                elizabethanRomance();
                break;
            case 2:
                roaringTwentiesRomance();
                break;
            case 3:
                futuristicColonyRomance();
                break;
            case 4:
                printf("\nThank you for using the Time Travel Simulator!\n");
                printf("May your heart always be filled with love, wherever you go!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select a valid option.\n");
        }

        printf("\nWould you like to travel again? (1 for Yes, 0 for No): ");
        int travelAgain;
        scanf("%d", &travelAgain);
        if (travelAgain == 0) {
            printf("\nThank you for traveling through time with love!\n");
            break;
        }
    }
    return 0;
}
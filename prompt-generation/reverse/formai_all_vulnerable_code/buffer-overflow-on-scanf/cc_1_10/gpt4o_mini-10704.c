//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void printWelcomeMessage();
void giveRandomAdvice();
void playHideAndSeek();
void performMagicTrick();

int main() {
    printWelcomeMessage(); // Print a welcome message.

    // Seed the random number generator
    srand(time(NULL));

    // The main menu loop
    int choice;
    do {
        printf("\nChoose A Fun Activity:\n");
        printf("1. Receive Random Life Advice\n");
        printf("2. Play Hide and Seek with your imagination\n");
        printf("3. Witness a Magical Trick\n");
        printf("4. Exit the fun zone\n");
        printf("Your Choice: ");
        scanf("%d", &choice);

        // Execute the chosen activity
        switch (choice) {
            case 1:
                giveRandomAdvice(); // Provide some hilarious advice
                break;
            case 2:
                playHideAndSeek(); // Play a game with your imagination
                break;
            case 3:
                performMagicTrick(); // Perform a cool magic trick
                break;
            case 4:
                printf("Exiting the fun zone! Come back soon for more giggles!\n");
                break;
            default:
                printf("Oops! That's not an option. Try again, or consult your imaginary friend!\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to print a welcome message
void printWelcomeMessage() {
    printf("====================================\n");
    printf("   Welcome to the Fun C Program!   \n");
    printf("   Where coding meets hilarity!     \n");
    printf("====================================\n");
}

// Function to give random advice
void giveRandomAdvice() {
    const char *advice[] = {
        "Don't worry if plan A doesn't work, there are 25 more letters in the alphabet!",
        "If you think nobody cares about you, try missing a couple of payments!",
        "Never trust an atom. They make up everything!",
        "Always follow your dreams... except for the one where you're naked in public!",
        "Life is short, smile while you still have teeth!",
        "If you can't convince them, confuse them!"
    };
    int index = rand() % (sizeof(advice) / sizeof(advice[0]));
    printf("Here's your advice: %s\n", advice[index]);
}

// Function to play a hide and seek game
void playHideAndSeek() {
    printf("Playing Hide and Seek with your imagination...\n");
    printf("Who are you hiding from? What would you do if they found you? Let your imagination run wild!\n");
    printf("Hiding in a giant pizza? Sounds deliciously risky!\n");
    printf("Let's count to ten while you hide!\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d...\n", i);
    }
    printf("Ready or not, here I come! I hope you find a better hiding place than behind the couch!\n");
}

// Function to perform a magic trick
void performMagicTrick() {
    printf("Welcome to the Magic Show! Watch closely!\n");
    printf("I will now make a number disappear!\n");

    int number = rand() % 100 + 1; // Random number between 1 and 100
    printf("Your number is: %d\n", number);
    printf("Now, I'm whispering some magic words...\n");
    
    // 'Whispers' for a dramatic effect
    for (int i = 0; i < 3; i++) {
        printf("Hocus Pocus...\n");
        sleep(1); // Dramatic pause
    }

    printf("Abracadabra! Disappearo Numberus!\n");
    printf("Voila! How many fingers am I holding up?\n");
    printf("(Hint: it's not related to any numbers!) 👀\n");
    printf("Wasn't that magical?\n");
}
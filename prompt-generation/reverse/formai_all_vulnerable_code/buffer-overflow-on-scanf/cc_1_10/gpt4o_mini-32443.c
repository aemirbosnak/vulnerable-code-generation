//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

void generateSurpriseMessage(char message[MAX_LINES][MAX_LENGTH], int lines) {
    const char *surprises[] = {
        "You just discovered a hidden treasure!",
        "A wild coding error appeared!",
        "Your code compiled without warnings!",
        "The answer was beneath your keyboard all along!",
        "You've unlocked a secret feature!",
        "This program has successfully passed the surprise test!",
        "What? Your code actually works as intended?",
        "Welcome to the mysterious world of coding!",
        "Congratulations! You've reached the end of the line!",
        "The coding wizards are smiling upon you today!",
        "A bug was squashed by a miracle!",
        "Did you know your program has a secret friend?",
        "Guess what? It's a great day for a new project!",
        "The universe aligns for your successful coding journey!",
        "You've decrypted the code of the ancients!",
        "Time flies when you're having fun with code!",
        "Your brain lightbulb just turned on!",
        "Whoa! A coding achievement unlocked!",
        "The RGB lights are dancing for your success!",
        "Your keyboard just performed a happy dance!",
        "Did you just pour coffee on your inspiration?"
    };

    srand(time(NULL));
    for (int i = 0; i < lines; i++) {
        strcpy(message[i], surprises[rand() % (sizeof(surprises) / sizeof(surprises[0]))]);
    }
}

void printSurpriseMessages(char message[MAX_LINES][MAX_LENGTH], int lines) {
    printf("\n🎉 Surprise Messages 🎉\n");
    for (int i = 0; i < lines; i++) {
        printf("- %s\n", message[i]);
    }
}

void playGame() {
    char message[MAX_LINES][MAX_LENGTH];
    printf("Welcome to the Surprise Game! 🎊\n");
    printf("How many surprise messages would you like to see? (Max %d): ", MAX_LINES);
    
    int lines;
    scanf("%d", &lines);

    if (lines < 1 || lines > MAX_LINES) {
        printf("Oops! Please enter a number between 1 and %d.\n", MAX_LINES);
        return;
    }

    generateSurpriseMessage(message, lines);
    printSurpriseMessages(message, lines);

    printf("\nWould you like to play again? (yes/no): ");
    char choice[4];
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0 || strcmp(choice, "Yes") == 0) {
        playGame();
    } else {
        printf("Thank you for playing! 👋 Goodbye!\n");
    }
}

int main() {
    printf("✨ Surprise Program in C! ✨\n");
    playGame();
    return 0;
}
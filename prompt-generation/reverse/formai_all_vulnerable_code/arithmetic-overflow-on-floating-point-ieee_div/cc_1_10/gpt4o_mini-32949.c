//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 500
#define TIME_LIMIT 30
#define MAX_WORDS 100
#define BUFFER_SIZE 256

// Scavenger struct to hold information about the player
typedef struct {
    char name[50];
    int wordsTyped;
    int elapsedTime;
} Scavenger;

// Function to generate a random passage from the wasteland scripture
void generatePassage(char *passage) {
    const char *texts[MAX_WORDS] = {
        "Survivors roam the desolate lands, seeking refuge.",
        "Whispers of a forgotten civilization echo in the silence.",
        "In the shadow of the ruins, we find fragments of hope.",
        "The winds carry tales of bravery and despair.",
        "Life clings to the edges of a crumbling world.",
        "Every breath is a battle, every moment a treasure.",
        "Amidst the ashes, we kindle the flames of survival.",
        "Scribes of the wasteland record the remnants of history.",
        "Chaos reigns, but unity sparkles like stars in the dark.",
        "We wield our words like weapons against the relentless night."
    };
    
    srand(time(NULL));
    passage[0] = '\0'; // Ensure passage is empty

    for (int i = 0; i < 5; i++) {
        strcat(passage, texts[rand() % (sizeof(texts) / sizeof(texts[0]))]);
        if (i < 4) {
            strcat(passage, " ");
        }
    }
}

// Function to calculate typing speed
float calculateSpeed(int wordsTyped, int elapsedTime) {
    return ((float)wordsTyped / elapsedTime) * 60; // words per minute
}

// Function to start the Typing Speed Test
void startTypingTest(Scavenger *scavenger) {
    char passage[MAX_TEXT_LENGTH];
    char userInput[MAX_TEXT_LENGTH];
    int i;
    time_t startTime, endTime;

    generatePassage(passage);
    printf("Type the following passage as fast as you can:\n\n%s\n\n", passage);
    printf("You have %d seconds. Press Enter when ready...\n", TIME_LIMIT);
    getchar(); // Wait for user to press enter

    time(&startTime);
    printf("Start Typing Now!\n");

    // Get the user input
    fgets(userInput, sizeof(userInput), stdin);
    time(&endTime);

    // Strip the newline character from fgets
    userInput[strcspn(userInput, "\n")] = 0;

    // Calculate actual typing time
    scavenger->elapsedTime = difftime(endTime, startTime);
    
    // Count words typed by user
    scavenger->wordsTyped = 0;
    char *word = strtok(userInput, " ");
    while (word != NULL) {
        scavenger->wordsTyped++;
        word = strtok(NULL, " ");
    }

    // Calculate speed
    float speed = calculateSpeed(scavenger->wordsTyped, scavenger->elapsedTime);
    
    printf("\nYou typed %d words in %.0f seconds.\n", scavenger->wordsTyped, (float)scavenger->elapsedTime);
    printf("Your typing speed: %.2f words per minute.\n", speed);
}

// Main function
int main() {
    Scavenger player;
    printf("Welcome to the Wasteland Typing Test!\n");
    printf("Enter your name, brave survivor: ");
    fgets(player.name, sizeof(player.name), stdin);
    player.name[strcspn(player.name, "\n")] = 0; // Strip newline from name
    
    printf("Greetings, %s! Prepare to test your typing skills...\n", player.name);
    startTypingTest(&player);
    
    printf("Thank you for playing! May your words echo through the wasteland.\n");
    return 0;
}
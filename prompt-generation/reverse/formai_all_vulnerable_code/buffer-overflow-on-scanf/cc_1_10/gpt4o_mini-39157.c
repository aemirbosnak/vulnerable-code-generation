//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clearScreen() {
    printf("\033[H\033[J");
}

void displayInstructions() {
    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Instructions:\n");
    printf("1. You will be presented with a random sentence.\n");
    printf("2. Type it as fast and accurately as you can.\n");
    printf("3. Press Enter when finished.\n");
    printf("4. Your time will be measured in seconds.\n");
    printf("Good luck!\n\n");
    printf("Press Enter to continue...\n");
    getchar();
}

const char* getRandomSentence() {
    const char* sentences[] = {
        "To be or not to be, that is the question.",
        "A journey of a thousand miles begins with a single step.",
        "The only thing we have to fear is fear itself.",
        "I think, therefore I am.",
        "In the middle of difficulty lies opportunity.",
        "The greatest glory in living lies not in never falling,",
        "but in rising every time we fall.",
        "Life is what happens when you're busy making other plans.",
        "Success is not the key to happiness. Happiness is the key to success."
    };
    int index = rand() % (sizeof(sentences) / sizeof(sentences[0]));
    return sentences[index];
}

void startTypingTest() {
    char input[256];
    const char* sentence = getRandomSentence();
    printf("Your sentence to type:\n");
    printf("\"%s\"\n\n", sentence);
    
    clock_t startTime = clock();
    printf("Start typing now: ");
    fgets(input, sizeof(input), stdin);
    clock_t endTime = clock();

    input[strcspn(input, "\n")] = 0; // Remove newline character from input
    double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    if (strcmp(input, sentence) == 0) {
        printf("Congratulations! You typed it correctly.\n");
    } else {
        printf("Oops! You made some mistakes.\n");
        printf("Your input: \"%s\"\n", input);
        printf("Correct sentence: \"%s\"\n", sentence);
    }

    printf("Time taken: %.2f seconds\n\n", timeTaken);
}

int main() {
    srand(time(NULL));
    clearScreen();
    displayInstructions();

    char choice;
    do {
        startTypingTest();
        printf("Do you want to try again? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // to consume the newline character
        clearScreen();
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for participating in the Typing Speed Test!\n");
    return 0;
}
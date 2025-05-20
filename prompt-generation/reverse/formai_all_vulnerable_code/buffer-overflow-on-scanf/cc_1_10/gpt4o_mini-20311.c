//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 5
#define MAX_LENGTH 100
#define ASCII_ART_HEIGHT 7

void printASCII(char *text);
void printWelcomeMessage();
void printInstructions();
void cleanBuffer();

int main() {
    char input[MAX_LENGTH];
    char playerNames[MAX_PLAYERS][20];
    int playerCount = 0;

    printWelcomeMessage();
    printInstructions();

    // Getting the number of players
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    cleanBuffer(); // Clear newline character after number input

    // Ensure player count is within limits
    if (playerCount < 1 || playerCount > MAX_PLAYERS) {
        printf("Invalid player count. Exiting...\n");
        return 1;
    }

    // Get player names
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for Player %d: ", i + 1);
        fgets(playerNames[i], sizeof(playerNames[i]), stdin);
        playerNames[i][strcspn(playerNames[i], "\n")] = 0; // Remove newline character
    }

    printf("\n--- ASCII Art Generator ---\n");

    // Each player enters text for ASCII art
    for (int i = 0; i < playerCount; i++) {
        printf("%s, enter your text to convert to ASCII art: ", playerNames[i]);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character
        printf("\nASCII Art for %s:\n", input);
        printASCII(input);
        printf("\n");
    }

    printf("Thanks for playing!\n");
    return 0;
}

// Function to print ASCII representation of the input text
void printASCII(char *text) {
    char *asciiMap[ASCII_ART_HEIGHT][26] = {
        {"  _  ", "    _  _       _  _   _ ", "  _ _  ", " _  _  ", "  _   _ ", 
         "  _ _  ", " _  _  ", "  _   _ ", " _  _  ", "  _   _ "},
        
        {" | | ", " |  _| |  | |  |  |   ", " |  | | | |", " |  |  | ", " |  |  | ",
         " |_|  |", "| | | |", " | | | | ", " | |   |", " | | | |"},
        
        {" | | ", " |  | |  | | | | |   | ", " |_| |_| ", " |  |  | ", " |  |  | ",
         " |      |", "| | | |", " | | | | ", " | |   |", " |_| |_|"},
        
        {" | | ", " |  | |  | | | |   | ", "    |_|    ", " |  |  | ", " |  |  | ",
         "      | |", "| | | |", " | | | | ", " | |   |", "  _|_| |_"},
        
        {" | | ", " |  | |  | | |_|   | ", " |  |  | ", " |  |  | ", " |  |  | ",
         "      | |", "| | | |", "  _|_|_|  ", " |     |", " |_|  |"},
        
        {" |_| ", " |_|   |_|  | | |    ", " |_| |_| |_|", " |_|_| |_| ", " |_|_| |_ ",
         " |_|_| |_ ", "| | | |", " | | | | ", " |_| |_|", "|_| |_|"},
        
        {"       ", " |_|  |_|    |_|        ", "       ", "       ", "       ",
         "       ", "        ", "       ", "       ", "       "}
    };

    int len = strlen(text);
    for (int row = 0; row < ASCII_ART_HEIGHT; row++) {
        for (int col = 0; col < len; col++) {
            if (isalpha(text[col])) {
                char index = tolower(text[col]) - 'a';
                printf("%s ", asciiMap[row][index]);
            } else {
                printf("      "); // Space for non-alphabetic characters
            }
        }
        printf("\n");
    }
}

// Function to print welcome message
void printWelcomeMessage() {
    printf("================================\n");
    printf("     Welcome to ASCII Art Game\n");
    printf("================================\n");
}

// Function to print game instructions
void printInstructions() {
    printf("Instructions:\n");
    printf("1. Enter the number of players (1 to %d)\n", MAX_PLAYERS);
    printf("2. Each player will enter their name.\n");
    printf("3. Players will then enter text to generate ASCII art.\n");
    printf("4. Enjoy the art generated!\n");
    printf("================================\n");
}

// Function to clean the input buffer
void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
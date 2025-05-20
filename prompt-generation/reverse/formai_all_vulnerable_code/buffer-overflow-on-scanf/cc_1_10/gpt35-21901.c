//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 5
#define BUFFER_SIZE 256

/* Function prototypes */
void printWelcome();
void printMenu();
int getPlayerCount();
void getPlayers(char* playerNames[], int playerCount);
void playGame(char* playerName);
char* getHexInput(char* playerName);
int validateHexInput(char* hexInput);
void convertHex(char* hexInput, char* convertedHex);
void printResult(char* playerName, char* hexInput, char* convertedHex);

/* Main function */
int main() {
    printWelcome();
    printMenu();

    int playerCount = getPlayerCount();
    char* playerNames[playerCount];
    getPlayers(playerNames, playerCount);

    for(int i = 0; i < playerCount; i++) {
        playGame(playerNames[i]);
    }

    return 0;
}

/* Prints welcome message */
void printWelcome() {
    printf("Welcome to the Hexadecimal Converter game for multiple players!\n\n");
}

/* Prints game menu */
void printMenu() {
    printf("Menu:\n");
    printf("1. Start Game\n");
    printf("2. Exit\n\n");
}

/* Gets number of players */
int getPlayerCount() {
    int playerCount;
    do {
        printf("Enter number of players (1-%d): ", MAX_PLAYERS);
        scanf("%d", &playerCount);
        getchar(); // Consume newline character
    } while(playerCount < 1 || playerCount > MAX_PLAYERS);

    printf("\n");

    return playerCount;
}

/* Gets player names */
void getPlayers(char* playerNames[], int playerCount) {
    for(int i = 0; i < playerCount; i++) {
        char playerName[BUFFER_SIZE];
        printf("Enter name of player %d: ", i+1);
        fgets(playerName, BUFFER_SIZE, stdin);
        playerName[strcspn(playerName, "\n")] = 0; // Remove newline character
        playerNames[i] = (char*) malloc(strlen(playerName)+1); // Allocate memory for player name
        strcpy(playerNames[i], playerName);
    }
    printf("\n");
}

/* Starts game for a particular player */
void playGame(char* playerName) {
    printf("%s's turn!\n", playerName);

    char* hexInput = getHexInput(playerName);

    char convertedHex[BUFFER_SIZE];
    convertHex(hexInput, convertedHex);

    printResult(playerName, hexInput, convertedHex);

    free(hexInput);
}

/* Gets hexadecimal input from the player */
char* getHexInput(char* playerName) {
    char* hexInput = (char*) malloc(BUFFER_SIZE);

    do {
        printf("%s, enter a hexadecimal value: ", playerName);
        fgets(hexInput, BUFFER_SIZE, stdin);
        hexInput[strcspn(hexInput, "\n")] = 0; // Remove newline character
    } while(!validateHexInput(hexInput));

    return hexInput;
}

/* Validates hexadecimal input */
int validateHexInput(char* hexInput) {
    int isValid = 1;
    for(int i = 0; i < strlen(hexInput); i++) {
        if(!isxdigit(hexInput[i])) {
            isValid = 0;
            break;
        }
    }

    if(!isValid) {
        printf("Invalid hexadecimal value! Only characters between 0-9 and A-F are allowed.\n\n");
    }

    return isValid;
}

/* Converts hexadecimal input to binary */
void convertHex(char* hexInput, char* convertedHex) {
    int num = (int) strtol(hexInput, NULL, 16);
    sprintf(convertedHex, "%d", num);
}

/* Prints the result of the game */
void printResult(char* playerName, char* hexInput, char* convertedHex) {
    printf("%s entered: %s\n", playerName, hexInput);
    printf("The decimal equivalent is: %s\n\n", convertedHex);
}
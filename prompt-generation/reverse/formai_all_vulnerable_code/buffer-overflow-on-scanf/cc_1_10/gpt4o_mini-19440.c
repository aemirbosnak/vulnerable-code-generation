//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 4
#define MAX_MESSAGE_LENGTH 256

typedef struct {
    char name[50];
    char messages[MAX_PLAYERS][MAX_MESSAGE_LENGTH];
    int messageCount;
} Player;

void initializePlayers(Player players[], int playerCount);
void sendMessage(Player *sender, Player players[], int playerCount);
void translateToCatLanguage(char *message, char *translatedMessage);
void displayMessages(Player players[], int playerCount);

int main() {
    Player players[MAX_PLAYERS];
    int playerCount;

    printf("Welcome to the Multiplayer Cat Language Translator!\n");
    printf("Enter the number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    if (playerCount < 1 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting.\n");
        return 1;
    }

    initializePlayers(players, playerCount);

    while (1) {
        for (int i = 0; i < playerCount; i++) {
            sendMessage(&players[i], players, playerCount);
        }

        printf("\nCurrent Messages in Cat Language:\n");
        displayMessages(players, playerCount);
    }

    return 0;
}

void initializePlayers(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].messageCount = 0;
    }
}

void sendMessage(Player *sender, Player players[], int playerCount) {
    char message[MAX_MESSAGE_LENGTH];
    char translatedMessage[MAX_MESSAGE_LENGTH];

    printf("%s, enter your message (or 'exit' to quit): ", sender->name);
    scanf(" %[^\n]s", message);
    if (strcmp(message, "exit") == 0) {
        printf("%s has exited the game.\n", sender->name);
        exit(0);
    }

    translateToCatLanguage(message, translatedMessage);
    if (sender->messageCount < MAX_PLAYERS) {
        strcpy(sender->messages[sender->messageCount], translatedMessage);
        sender->messageCount++;
    } else {
        printf("%s, you have reached the maximum message limit!\n", sender->name);
    }
}

void translateToCatLanguage(char *message, char *translatedMessage) {
    int j = 0;
    for (int i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) {
            translatedMessage[j++] = message[i];
            translatedMessage[j++] = 'm'; // Adding 'm' for Cat language
            translatedMessage[j++] = 'e'; // Adding 'e' for Cat language
        } else {
            translatedMessage[j++] = message[i]; // Non-alpha characters unchanged
        }
    }
    translatedMessage[j] = '\0'; // Null-terminate the string
}

void displayMessages(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        printf("Messages from %s:\n", players[i].name);
        for (int j = 0; j < players[i].messageCount; j++) {
            printf("  %d: %s\n", j + 1, players[i].messages[j]);
        }
    }
}
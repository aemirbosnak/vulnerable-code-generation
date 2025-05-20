//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 30
#define MAX_MESSAGE_LENGTH 100

// Structure for a player
typedef struct {
    char name[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Player;

// Function prototypes
void createPlayer(Player *player);
void sendMessage(Player *sender, Player *receiver);
void reverseString(char *str);
void convertToUpper(char *str);
void displayPlayerInfo(Player player);

int main() {
    Player players[MAX_PLAYERS];
    int playerCount = 0;
    int choice;

    // Welcome message
    printf("Welcome to the Multiplayer Game! \n");
    
    while (playerCount < MAX_PLAYERS) {
        printf("1. Join Game\n2. Send Message\n3. Player Info\n4. Exit\nChoose an option: ");
        scanf("%d", &choice);
        getchar(); // to clear the newline after scanf

        switch (choice) {
            case 1:
                // Create a new player
                createPlayer(&players[playerCount]);
                playerCount++;
                break;
            case 2:
                // Send a message between players
                if (playerCount < 2) {
                    printf("Need at least 2 players to send a message.\n");
                } else {
                    int senderIndex, receiverIndex;
                    printf("Choose sender (0-%d): ", playerCount - 1);
                    scanf("%d", &senderIndex);
                    printf("Choose receiver (0-%d): ", playerCount - 1);
                    scanf("%d", &receiverIndex);
                    getchar(); // clear newline
                    sendMessage(&players[senderIndex], &players[receiverIndex]);
                }
                break;
            case 3:
                // Display players' information
                for (int i = 0; i < playerCount; i++) {
                    displayPlayerInfo(players[i]);
                }
                break;
            case 4:
                printf("Exiting the game. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    
    printf("Reached maximum player limit. Exiting...\n");
    return 0;
}

void createPlayer(Player *player) {
    printf("Enter your name (max %d characters): ", MAX_NAME_LENGTH - 1);
    fgets(player->name, MAX_NAME_LENGTH, stdin);
    player->name[strcspn(player->name, "\n")] = 0; // remove newline character
    
    printf("Welcome, %s! You have joined the game.\n", player->name);
}

void sendMessage(Player *sender, Player *receiver) {
    printf("%s, enter your message for %s: ", sender->name, receiver->name);
    fgets(sender->message, MAX_MESSAGE_LENGTH, stdin);
    sender->message[strcspn(sender->message, "\n")] = 0; // remove newline character

    // Manipulate the message
    reverseString(sender->message);
    convertToUpper(sender->message);

    // Send the message
    printf("%s (to %s): %s\n", sender->name, receiver->name, sender->message);
}

void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void convertToUpper(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void displayPlayerInfo(Player player) {
    printf("Player: %s\n", player.name);
    printf("Message: %s\n", player.message);
}
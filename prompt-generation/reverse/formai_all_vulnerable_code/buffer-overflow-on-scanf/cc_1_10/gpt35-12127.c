//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_MESSAGE_LENGTH 50
#define ENCRYPTION_KEY 13

// Function to encrypt message using the Caesar Cipher
char* encrypt(char* message) {
    int i, letter;
    char* encrypted = (char*) malloc(MAX_MESSAGE_LENGTH * sizeof(char));

    for(i = 0; i < strlen(message); i++) {
        letter = message[i];

        if(letter >= 'a' && letter <= 'z') {
            letter = (letter + ENCRYPTION_KEY - 'a') % 26 + 'a';
        } else if(letter >= 'A' && letter <= 'Z') {
            letter = (letter + ENCRYPTION_KEY - 'A') % 26 + 'A';
        }

        encrypted[i] = (char) letter;
    }

    encrypted[i] = '\0'; // add null terminator

    return encrypted;
}

int main() {
    int num_players, i, j;
    char message[MAX_MESSAGE_LENGTH];
    char* encrypted;

    srand(time(NULL)); // seed the random number generator

    // get the number of players
    do {
        printf("Enter the number of players (max %d): ", MAX_PLAYERS);
        scanf("%d", &num_players);
    } while(num_players < 2 || num_players > MAX_PLAYERS);

    // get the message to encrypt
    printf("Enter the message to encrypt (max %d chars): ", MAX_MESSAGE_LENGTH);
    scanf(" %[^\n]s", message);

    // encrypt the message
    encrypted = encrypt(message);

    // print out the encrypted message
    printf("Encrypted message: %s\n", encrypted);

    // create an array of random indices to determine the order in which the players will receive the message
    int index_order[num_players];
    for(i = 0; i < num_players; i++) {
        index_order[i] = rand() % num_players;
        for(j = 0; j < i; j++) {
            if(index_order[i] == index_order[j]) {
                i--;
                break;
            }
        }
    }

    // print out the order in which players will receive the message
    printf("Message order: ");
    for(i = 0; i < num_players; i++) {
        printf("%d ", index_order[i]);
    }
    printf("\n");

    // simulate the message passing between the players
    char* received_message = (char*) malloc(MAX_MESSAGE_LENGTH * sizeof(char));
    int receiver_index;
    for(i = 0; i < num_players; i++) {
        receiver_index = index_order[i];

        // player receives message
        if(receiver_index == 0) {
            printf("You received the message: %s\n", encrypted);
            strcpy(received_message, encrypted);
        } else {
            printf("Player %d received the message: %s\n", receiver_index, received_message);
        }

        // player encrypts message with their own key and passes it on
        if(receiver_index == num_players - 1) {
            encrypted = encrypt(received_message);
            printf("You encrypted the message: %s\n", encrypted);
        } else {
            encrypted = encrypt(received_message);
            printf("Player %d encrypted the message: %s\n", receiver_index + 1, encrypted);
        }
    }

    return 0;
}
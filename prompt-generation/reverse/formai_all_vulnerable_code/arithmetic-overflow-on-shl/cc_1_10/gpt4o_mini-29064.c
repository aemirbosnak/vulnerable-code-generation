//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_INPUT_LENGTH 256

typedef struct {
    char name[50];
    char binary[33]; // 32 bits for the binary representation +1 for null terminator
} Player;

void convertToBinary(int number, char *binary) {
    int index = 31; // Start filling from the last index
    binary[index--] = '\0'; // Null-terminate the string
    
    for (int i = 0; i < 32; i++) {
        binary[index--] = (number & (1 << (31 - i))) ? '1' : '0';
    }
}

void displayResults(Player players[], int count) {
    printf("\nResults:\n");
    
    for (int i = 0; i < count; i++) {
        printf("%s converted to binary: %s\n", players[i].name, players[i].binary);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int playerCount = 0;

    printf("Welcome to the Multiplayer Binary Converter!\n");
    printf("Register up to %d players to convert their numbers to binary.\n", MAX_PLAYERS);
    
    while (playerCount < MAX_PLAYERS) {
        printf("\nEnter the name of Player %d (or type 'end' to finish): ", playerCount + 1);
        fgets(players[playerCount].name, sizeof(players[playerCount].name), stdin);
        players[playerCount].name[strcspn(players[playerCount].name, "\n")] = 0; // Remove trailing newline

        if (strcmp(players[playerCount].name, "end") == 0) {
            break;
        }

        printf("Enter a positive integer for %s: ", players[playerCount].name);
        int number;
        scanf("%d", &number);
        while (getchar() != '\n'); // Clear input buffer

        if (number < 0) {
            printf("Please enter a positive integer only.\n");
            continue;
        }

        convertToBinary(number, players[playerCount].binary);
        playerCount++;
    }

    displayResults(players, playerCount);

    return 0;
}
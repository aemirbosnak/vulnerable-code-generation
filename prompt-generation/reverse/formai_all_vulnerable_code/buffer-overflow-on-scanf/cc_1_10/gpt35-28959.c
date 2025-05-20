//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PLAYERS 4

void convertToHex(int num, char* hex) {
    char hexChars[] = "0123456789abcdef";
    hex[0] = hexChars[(num & 0xF000) >> 12];
    hex[1] = hexChars[(num & 0x0F00) >> 8];
    hex[2] = hexChars[(num & 0x00F0) >> 4];
    hex[3] = hexChars[num & 0x000F];
    hex[4] = '\0';
}

void displayMenu() {
    printf("\n");
    printf("Hexadecimal Converter Game\n");
    printf("---------------------------\n");
    printf("Commands:\n");
    printf("  1. convert [number]\n");
    printf("  2. score\n");
    printf("  3. quit\n");
}

void displayScore(int* scores, int numPlayers) {
    printf("\n");
    printf("Scores\n");
    printf("------\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: %d\n", i + 1, scores[i]);
    }
}

int main() {
    // Initialize variables
    int nums[MAX_PLAYERS];
    int scores[MAX_PLAYERS] = {0};
    char input[100];
    char hex[5];

    int numPlayers = 0;
    printf("Enter the number of players (1-4): ");
    scanf("%d", &numPlayers);
    while (numPlayers < 1 || numPlayers > 4) {
        printf("Invalid input. Enter the number of players (1-4): ");
        scanf("%d", &numPlayers);
    }

    // Main game loop
    int currentPlayer = 0;
    while (1) {
        printf("\nPlayer %d's turn\n", currentPlayer + 1);
        displayMenu();

        printf("Enter command: ");
        scanf("%s", input);

        // Convert command
        if (strcmp(input, "convert") == 0) {
            int num;
            scanf("%d", &num);
            convertToHex(num, hex);
            printf("Hexadecimal: %s\n", hex);

            if (num == 255) {
                printf("Congratulations! You win!\n");
                scores[currentPlayer]++;
            }

            currentPlayer = (currentPlayer + 1) % numPlayers;
        }
        // Score command
        else if (strcmp(input, "score") == 0) {
            displayScore(scores, numPlayers);
        }
        // Quit command
        else if (strcmp(input, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        }
        // Invalid command
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
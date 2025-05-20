//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for maximum number of players and maximum file size to scan
#define MAX_PLAYERS 4
#define MAX_FILE_SIZE 1024

// Define function to scan file for virus
int scanFile(char* fileName) {
    // Simulate scanning process
    srand(time(NULL));

    int result = rand() % 2; // Randomly pick 0 or 1 to simulate virus detection
    printf("File %s scanned. Result = %s\n", fileName, result ? "Virus Detected" : "No Virus Detected");

    return result;
}

int main() {
    // Define array to store player names
    char playerNames[MAX_PLAYERS][50];

    int numPlayers;

    // Prompt user to enter number of players
    printf("Enter number of players (1 to 4): ");
    scanf("%d", &numPlayers);

    // Validate input
    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Please enter a number between 1 and 4.\n");
        return 0;
    }

    // Prompt user to enter player names
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i+1);
        scanf("%s", playerNames[i]);
    }

    // Prompt user to enter file name to scan
    char fileName[MAX_FILE_SIZE];
    printf("Enter file name to scan: ");
    scanf("%s", fileName);

    // Scan file for virus
    int result = scanFile(fileName);

    // Print result
    if (result) {
        // Virus detected
        printf("Virus detected in file %s.\n", fileName);

        // Prompt user to select player to clean file
        int selectedPlayer;
        printf("Select player to clean file:\n");
        for (int i = 0; i < numPlayers; i++) {
            printf("%d. %s\n", i+1, playerNames[i]);
        }
        scanf("%d", &selectedPlayer);

        // Validate input
        if (selectedPlayer < 1 || selectedPlayer > numPlayers) {
            printf("Invalid player selection. Please select a valid player.\n");
            return 0;
        }

        // Print cleaning process
        printf("File %s being cleaned by player %s...\n", fileName, playerNames[selectedPlayer-1]);

        // Simulate cleaning process
        srand(time(NULL));
        int cleaningTime = rand() % 5 + 1;
        for (int i = 1; i <= cleaningTime; i++) {
            printf("Cleaning in progress... %d\n", i);
            sleep(1);
        }
        
        printf("File %s cleaned.\n", fileName);
    } else {
        // No virus detected
        printf("No virus detected in file %s.\n", fileName);
    }

    return 0;
}
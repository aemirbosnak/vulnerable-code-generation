//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Server function
int server_game() {
    // Generate a random number between 1 and 3
    int choice = rand() % 3 + 1;
    printf("Server's move: %d\n", choice);
    
    // Check for win/loss based on client's move
    if (choice == 1 && getchar() == 'R') {
        printf("Server wins!\n");
    } else if (choice == 2 && getchar() == 'P') {
        printf("Server wins!\n");
    } else if (choice == 3 && getchar() == 'S') {
        printf("Server wins!\n");
    } else {
        printf("Server loses!\n");
    }
    
    return 0;
}

// Client function
int client_game() {
    printf("Welcome to Rock, Paper, Scissors!\n");
    printf("Choose your move (1 for Rock, 2 for Paper, 3 for Scissors): ");
    int choice = getchar() - '0';
    
    // Send the move to the server
    printf("Sending move to server...\n");
    printf("Choice: %d\n", choice);
    
    // Wait for server's response
    int response = server_game();
    
    // Print the result
    switch (response) {
        case 0:
            printf("Server lost!\n");
            break;
        case 1:
            printf("Server wins!\n");
            break;
        case 2:
            printf("Server wins!\n");
            break;
        default:
            printf("Error: Invalid response from server.\n");
    }
    
    return 0;
}

int main() {
    // Initialize random number generator
    srand(time(NULL));
    
    // Start the game
    printf("Starting game...\n");
    client_game();
    
    return 0;
}
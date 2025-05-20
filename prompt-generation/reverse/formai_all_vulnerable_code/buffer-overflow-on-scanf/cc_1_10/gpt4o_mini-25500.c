//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 100
#define USERNAME_LENGTH 30
#define PASSWORD_LENGTH 30
#define FILENAME "players.dat"

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    int score;
} Player;

Player players[MAX_PLAYERS];
int player_count = 0;

// Function prototypes
void register_player();
void login_player();
void view_scores();
void save_players();
void load_players();

int main() {
    int choice;

    load_players();

    do {
        printf("\nMultiplayer Game Database\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. View Scores\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_player();
                break;
            case 2:
                login_player();
                break;
            case 3:
                view_scores();
                break;
            case 4:
                save_players();
                printf("Exiting the game. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void register_player() {
    if (player_count >= MAX_PLAYERS) {
        printf("Player limit reached. Cannot register more players.\n");
        return;
    }

    Player new_player;
    printf("Enter username: ");
    scanf("%s", new_player.username);
    printf("Enter password: ");
    scanf("%s", new_player.password);
    new_player.score = 0;

    // Check for existing username
    for (int i = 0; i < player_count; i++) {
        if (strcmp(players[i].username, new_player.username) == 0) {
            printf("Username already exists! Try a different one.\n");
            return;
        }
    }

    players[player_count++] = new_player;
    printf("Registration successful!\n");
}

void login_player() {
    char username[USERNAME_LENGTH], password[PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < player_count; i++) {
        if (strcmp(players[i].username, username) == 0 &&
            strcmp(players[i].password, password) == 0) {
                
            printf("Login successful! Welcome, %s.\n", username);
            players[i].score += 10;  // Incrementing score for demonstration
            return;
        }
    }
    printf("Invalid username or password.\n");
}

void view_scores() {
    if (player_count == 0) {
        printf("No players registered yet.\n");
        return;
    }

    printf("\nPlayer Scores:\n");
    for (int i = 0; i < player_count; i++) {
        printf("Username: %s, Score: %d\n", players[i].username, players[i].score);
    }
}

void save_players() {
    FILE *file = fopen(FILENAME, "wb");
    if (!file) {
        printf("Error saving player data!\n");
        return;
    }
    fwrite(players, sizeof(Player), player_count, file);
    fclose(file);
    printf("Player data saved successfully!\n");
}

void load_players() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        printf("No previous player data found. Starting fresh!\n");
        return;
    }
    player_count = fread(players, sizeof(Player), MAX_PLAYERS, file);
    fclose(file);
    printf("Loaded %d players from database.\n", player_count);
}
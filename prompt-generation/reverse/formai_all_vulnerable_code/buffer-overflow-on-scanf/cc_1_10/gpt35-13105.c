//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a password is strong enough
// Returns 1 if strong, 0 otherwise
int is_strong(char* password) {
    int i, length = strlen(password);
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;

    for (i = 0; i < length; i++) {
        char c = password[i];

        if (c >= 'A' && c <= 'Z')
            has_upper = 1;
        else if (c >= 'a' && c <= 'z')
            has_lower = 1;
        else if (c >= '0' && c <= '9')
            has_digit = 1;
        else
            has_special = 1;
    }

    return has_upper && has_lower && has_digit && has_special && length >= 8;
}

// Function to generate a random password of length N
void generate_password(char* password, int N) {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
    int i;

    for (i = 0; i < N; i++)
        password[i] = charset[rand() % (sizeof(charset) - 1)];

    password[N] = '\0';
}

int main() {
    int num_players, i, player_scores[100];
    char password[100];

    // Ask for number of players
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    // Initialize player scores to 0
    for (i = 0; i < num_players; i++)
        player_scores[i] = 0;

    printf("Welcome to Password Strength Checker Multiplayer Game!\n");

    while (1) {
        // Generate a random password
        generate_password(password, rand() % 8 + 8);

        printf("New password generated: %s\n", password);

        // Ask each player if the password is strong enough
        for (i = 0; i < num_players; i++) {
            char answer;

            printf("Player %d, is this password strong enough? (y/n): ", i + 1);
            scanf(" %c", &answer);

            if (answer == 'y')
                player_scores[i]++;
        }

        // Display the scores
        printf("Current Scores:\n");
        for (i = 0; i < num_players; i++)
            printf("Player %d: %d\n", i + 1, player_scores[i]);

        // Ask players if they want to continue playing
        char answer;

        printf("Do you want to continue playing? (y/n): ");
        scanf(" %c", &answer);

        if (answer != 'y')
            break;
    }

    return 0;
}
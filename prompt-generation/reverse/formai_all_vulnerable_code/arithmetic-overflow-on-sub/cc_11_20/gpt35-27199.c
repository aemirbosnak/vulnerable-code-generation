//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_PWD_LEN 8
#define MAX_PWD_LEN 16

typedef struct {
    char name[50];
    int score;
} player;

void check_password_strength(char *password, int *score) {
    int length = strlen(password);
    int lowercase = 0, uppercase = 0, digit = 0, special_char = 0;

    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase++;
        } else if (isupper(password[i])) {
            uppercase++;
        } else if (isdigit(password[i])) {
            digit++;
        } else {
            special_char++;
        }
    }

    *score = 0;
    if (lowercase >= 2) {
        *score += 10;
    }
    if (uppercase >= 2) {
        *score += 10;
    }
    if (digit >= 2) {
        *score += 10;
    }
    if (special_char >= 2) {
        *score += 10;
    }
    if (length >= MIN_PWD_LEN && length <= MAX_PWD_LEN) {
        *score += 10;
    }

    // Password Scoring System
    if (*score >= 30 && *score <= 40) {
        printf("Your password strength is weak.\n");
    } else if (*score >= 50 && *score <= 60) {
        printf("Your password strength is average.\n");
    } else if (*score >= 70 && *score <= 80) {
        printf("Your password strength is strong.\n");
    } else if (*score >= 90) {
        printf("Your password strength is very strong.\n");
    } else {
        printf("Your password is too short or has too few requirements.\n");
    }
}

int main() {
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    getchar(); // Consume the newline character in the input buffer

    player players[num_players];

    // Get player names
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        fgets(players[i].name, 50, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = '\0'; // Remove newline character
    }

    // Get player password and check its strength
    for (int i = 0; i < num_players; i++) {
        char password[MAX_PWD_LEN + 1];
        printf("%s, enter your password (8-16 characters): ", players[i].name);
        fgets(password, MAX_PWD_LEN + 1, stdin);
        password[strcspn(password, "\n")] = '\0'; // Remove newline character
        int score;
        check_password_strength(password, &score);
        printf("Your score is %d.\n", score);
        players[i].score = score;
    }

    // Sort players in descending order of score
    for (int i = 0; i < num_players - 1; i++) {
        for (int j = 0; j < num_players - i - 1; j++) {
            if (players[j].score < players[j + 1].score) {
                player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    // Display sorted list of players with their scores
    printf("\nLeaderboard:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%d. %s - Score: %d\n", i + 1, players[i].name, players[i].score);
    }

    return 0;
}
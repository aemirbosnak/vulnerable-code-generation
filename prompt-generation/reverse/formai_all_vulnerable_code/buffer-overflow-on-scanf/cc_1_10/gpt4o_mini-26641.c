//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1024
#define MAX_PLAYERS 2

typedef struct {
    char name[50];
    char text[MAX_TEXT_LENGTH];
} Player;

void to_uppercase(char *text) {
    for (int i = 0; text[i]; i++) {
        text[i] = toupper(text[i]);
    }
}

void to_lowercase(char *text) {
    for (int i = 0; text[i]; i++) {
        text[i] = tolower(text[i]);
    }
}

int count_words(const char *text) {
    int count = 0;
    int in_word = 0;
    while (*text) {
        if (isspace(*text)) {
            in_word = 0;
        } else {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        }
        text++;
    }
    return count;
}

int count_lines(const char *text) {
    int count = 0;
    while (*text) {
        if (*text == '\n') {
            count++;
        }
        text++;
    }
    return count + 1; // Add 1 for the last line if not empty
}

void process_text(Player *player) {
    int choice;
    printf("\n--- %s's Text Processing Menu ---\n", player->name);
    printf("1. Display text\n");
    printf("2. Count characters\n");
    printf("3. Count words\n");
    printf("4. Count lines\n");
    printf("5. Convert to uppercase\n");
    printf("6. Convert to lowercase\n");
    printf("0. Exit menu\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Text: %s\n", player->text);
            break;
        case 2:
            printf("Character count: %ld\n", strlen(player->text));
            break;
        case 3:
            printf("Word count: %d\n", count_words(player->text));
            break;
        case 4:
            printf("Line count: %d\n", count_lines(player->text));
            break;
        case 5:
            to_uppercase(player->text);
            printf("Converted to uppercase: %s\n", player->text);
            break;
        case 6:
            to_lowercase(player->text);
            printf("Converted to lowercase: %s\n", player->text);
            break;
        case 0:
            printf("Exiting menu for %s.\n", player->name);
            return;
        default:
            printf("Invalid option! Please try again.\n");
            break;
    }
}

int main() {
    Player players[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        printf("Enter text for %s: ", players[i].name);
        getchar(); // To consume the newline character after scanf
        fgets(players[i].text, MAX_TEXT_LENGTH, stdin);
        players[i].text[strcspn(players[i].text, "\n")] = 0; // Remove newline
    }

    int game_on = 1;
    while (game_on) {
        for (int i = 0; i < MAX_PLAYERS; i++) {
            process_text(&players[i]);
        }
        printf("Do you want to continue playing? (1 for Yes, 0 for No): ");
        scanf("%d", &game_on);
    }

    printf("Thanks for playing!\n");
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Text processing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Global variables
int players = 0;
char **names = NULL;

// Function prototypes
void start_game();
void add_player();
void remove_player(int index);
void print_players();
void send_message(int from, char *message);
void receive_message(char *message, int length);

int main() {
    start_game();

    return 0;
}

void start_game() {
    char host[20];
    printf("Enter your name: ");
    scanf("%s", host);

    names = (char **) malloc(sizeof(char *) * 2);
    names[0] = strdup(host);
    players = 1;

    printf("Game started. Press enter to add more players.\n");
    getchar();
}

void add_player() {
    char name[20];
    printf("Enter player name: ");
    scanf("%s", name);

    names = (char **) realloc(names, sizeof(char *) * (players + 1));
    names[players] = strdup(name);
    players++;

    printf("%s joined the game.\n", name);
}

void remove_player(int index) {
    if (index >= 0 && index < players) {
        free(names[index]);
        for (int i = index; i < players - 1; i++) {
            names[i] = names[i + 1];
        }
        names = (char **) realloc(names, sizeof(char *) * (players - 1));
        players--;

        printf("%s left the game.\n", names[index]);
    } else {
        printf("Invalid player index.\n");
    }
}

void print_players() {
    printf("Players:\n");
    for (int i = 0; i < players; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }
}

void send_message(int from, char *message) {
    printf("%s: %s\n", names[from], message);

    for (int i = 0; i < players; i++) {
        if (i!= from) {
            send(i + 1, message, strlen(message), 0);
        }
    }
}

void receive_message(char *message, int length) {
    printf("%s: %s\n", names[length - 1], message);
}
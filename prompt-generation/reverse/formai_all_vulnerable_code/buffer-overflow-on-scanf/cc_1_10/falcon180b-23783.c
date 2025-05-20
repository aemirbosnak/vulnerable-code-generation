//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20
#define MAX_PLAYERS 10
#define MAX_PLAYER_NAME_LEN 20
#define MAX_MESSAGES 100
#define MAX_MESSAGE_LEN 100

typedef struct {
    char name[MAX_PLAYER_NAME_LEN];
    int id;
} Player;

typedef struct {
    int id;
    char message[MAX_MESSAGE_LEN];
} Message;

Player players[MAX_PLAYERS];
int num_players;
int num_messages;
Message messages[MAX_MESSAGES];

int main() {
    printf("Welcome to the Alien Language Translator!\n");
    printf("How many players are there? (1-10): ");
    scanf("%d", &num_players);
    assert(num_players >= 1 && num_players <= MAX_PLAYERS);

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        assert(strlen(players[i].name) <= MAX_PLAYER_NAME_LEN);
    }

    printf("Enter your message in English:\n");
    fgets(messages[0].message, MAX_MESSAGE_LEN, stdin);
    messages[0].id = 0;
    num_messages = 1;

    while (num_messages > 0) {
        for (int i = 0; i < num_players; i++) {
            printf("Player %d's message:\n", i + 1);
            fgets(messages[num_messages].message, MAX_MESSAGE_LEN, stdin);
            messages[num_messages].id = i + 1;
            num_messages++;
        }

        for (int i = 0; i < num_messages; i++) {
            printf("Player %d: %s\n", messages[i].id, messages[i].message);
        }

        printf("Translate messages to Alien Language? (y/n): ");
        char answer;
        scanf("%c", &answer);
        if (answer == 'y' || answer == 'Y') {
            for (int i = 0; i < num_messages; i++) {
                printf("Player %d's translated message:\n", messages[i].id);
                fgets(messages[i].message, MAX_MESSAGE_LEN, stdin);
            }
        } else {
            break;
        }
    }

    return 0;
}
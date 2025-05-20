//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_MESSAGE_LENGTH 100

typedef struct player {
    char name[20];
    int score;
    int id;
} Player;

void send_message(char message[], Player sender, Player recipients[], int num_recipients) {
    printf("%s says: %s\n", sender.name, message);
    for (int i = 0; i < num_recipients; i++) {
        if (sender.id != recipients[i].id) {
            printf("%s hears %s say: %s\n", recipients[i].name, sender.name, message);
        }
    }
}

void translate_message(char message[], char translated_message[]) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        char c = message[i];
        if (c == 'c') {
            translated_message[i] = 'meow';
        } else if (c == 'C') {
            translated_message[i] = 'MEOW';
        } else {
            translated_message[i] = c;
        }
    }
    translated_message[length] = '\0';
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players = 0;

    printf("Welcome to the C Cat Language Translator Chatroom!\n");
    printf("Enter your name: ");
    char name[20];
    scanf("%s", name);

    Player player;
    strcpy(player.name, name);
    player.score = 0;
    player.id = num_players++;
    players[0] = player;

    printf("Type 'exit' at any time to leave the chatroom.\n");

    char message[MAX_MESSAGE_LENGTH];
    char translated_message[MAX_MESSAGE_LENGTH];
    while (1) {
        printf("[%s]: ", player.name);
        scanf("%s", message);
        if (strcmp(message, "exit") == 0) {
            printf("Goodbye %s!\n", player.name);
            break;
        }
        translate_message(message, translated_message);
        send_message(translated_message, player, players, num_players);
    }

    return 0;
}
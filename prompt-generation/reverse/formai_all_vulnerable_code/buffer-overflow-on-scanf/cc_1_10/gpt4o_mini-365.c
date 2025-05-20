//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 5
#define MAX_MESSAGE_LENGTH 256
#define MAX_CHAT_LOG 10

typedef struct {
    char name[30];
    char chat_log[MAX_CHAT_LOG][MAX_MESSAGE_LENGTH];
    int message_count;
} Player;

void initialize_players(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name for Player %d: ", i + 1);
        fgets(players[i].name, 30, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // Remove newline character
        players[i].message_count = 0;
    }
}

void send_message(Player *sender) {
    if (sender->message_count >= MAX_CHAT_LOG) {
        printf("Chat log full! Cannot send more messages.\n");
        return;
    }
    
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter message from %s: ", sender->name);
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character
    strcpy(sender->chat_log[sender->message_count], message);
    sender->message_count++;
}

void display_chat_log(Player *player) {
    printf("Chat log for %s:\n", player->name);
    for (int i = 0; i < player->message_count; i++) {
        printf("[%d] %s\n", i + 1, player->chat_log[i]);
    }
}

void manipulate_message(Player *player) {
    int message_index;
    char new_message[MAX_MESSAGE_LENGTH];
    
    display_chat_log(player);
    printf("Select message number to edit (1-%d): ", player->message_count);
    scanf("%d", &message_index);
    getchar(); // Clear newline character after scanf

    if (message_index > 0 && message_index <= player->message_count) {
        printf("Enter new message: ");
        fgets(new_message, MAX_MESSAGE_LENGTH, stdin);
        new_message[strcspn(new_message, "\n")] = 0; // Remove newline character
        strcpy(player->chat_log[message_index - 1], new_message);
        printf("Message updated!\n");
    } else {
        printf("Invalid message number!\n");
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int player_count;
    
    printf("Welcome to the Multiplayer Chat System!\n");
    printf("Enter number of players (1 - %d): ", MAX_PLAYERS);
    scanf("%d", &player_count);
    getchar(); // Clear newline character after scanf

    if (player_count < 1 || player_count > MAX_PLAYERS) {
        printf("Invalid player count, exiting...\n");
        return 1;
    }
    
    initialize_players(players, player_count);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Send a message\n");
        printf("2. Display chat log\n");
        printf("3. Edit a message\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character after scanf

        if (choice == 1) {
            for (int i = 0; i < player_count; i++) {
                send_message(&players[i]);
            }
        } else if (choice == 2) {
            for (int i = 0; i < player_count; i++) {
                display_chat_log(&players[i]);
            }
        } else if (choice == 3) {
            int player_number;
            printf("Select player number to edit message (1-%d): ", player_count);
            scanf("%d", &player_number);
            getchar(); // Clear newline character after scanf

            if (player_number > 0 && player_number <= player_count) {
                manipulate_message(&players[player_number - 1]);
            } else {
                printf("Invalid player number!\n");
            }
        } else if (choice != 4) {
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    printf("Exiting the chat system. Goodbye!\n");
    return 0;
}
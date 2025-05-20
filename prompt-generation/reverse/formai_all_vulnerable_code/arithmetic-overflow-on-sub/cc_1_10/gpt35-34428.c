//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_INPUT_LENGTH 50
#define MAX_OUTPUT_LENGTH 100

struct Player {
    int id;
    char name[MAX_INPUT_LENGTH];
    char language[MAX_INPUT_LENGTH];
};

struct Message {
    int sender_id;
    char content[MAX_INPUT_LENGTH];
};

struct Translation {
    int sender_id;
    int receiver_id;
    char original_text[MAX_INPUT_LENGTH];
    char translated_text[MAX_OUTPUT_LENGTH];
};

struct Player players[MAX_PLAYERS];
struct Message messages[MAX_PLAYERS];
struct Translation translations[MAX_PLAYERS];

int main() {
    int num_players;
    int num_messages = 0;
    int num_translations = 0;

    // Register players
    printf("Enter number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d name (up to %d characters): ", i+1, MAX_INPUT_LENGTH);
        scanf("%s", &players[i].name);
        printf("Enter player %d language (up to %d characters): ", i+1, MAX_INPUT_LENGTH);
        scanf("%s", &players[i].language);
        players[i].id = i+1;
    }

    // Main message translation loop
    while (1) {
        // Get message and receiver
        int sender_id, receiver_id;
        char message_content[MAX_INPUT_LENGTH];
        printf("Enter sender id (1-%d): ", num_players);
        scanf("%d", &sender_id);
        printf("Enter receiver id (1-%d): ", num_players);
        scanf("%d", &receiver_id);
        printf("Enter message content (up to %d characters): ", MAX_INPUT_LENGTH);
        fflush(stdin);
        fgets(message_content, MAX_INPUT_LENGTH, stdin);
        message_content[strlen(message_content)-1] = '\0'; // Remove newline character

        // Check if sender and receiver use the same language
        if (strcmp(players[sender_id-1].language, players[receiver_id-1].language) == 0) {
            // No need for translation, send message directly
            messages[num_messages].sender_id = sender_id;
            strcpy(messages[num_messages].content, message_content);
            num_messages++;
        } else {
            // Need to translate message
            translations[num_translations].sender_id = sender_id;
            translations[num_translations].receiver_id = receiver_id;
            strcpy(translations[num_translations].original_text, message_content);

            // Search for appropriate translator
            int translator_id = 0;
            for (int i = 0; i < num_players; i++) {
                if (strcmp(players[i].language, "C Cat") == 0) {
                    // Found C Cat speaker, use as translator
                    translator_id = i+1;
                    break;
                }
            }

            // Use translator to translate message
            char translated_text[MAX_OUTPUT_LENGTH];
            sprintf(translated_text, "C Cat translation of message '%s'", message_content);
            strcpy(translations[num_translations].translated_text, translated_text);

            // Send translated message
            messages[num_messages].sender_id = translator_id;
            strcpy(messages[num_messages].content, translated_text);
            num_messages++;
            num_translations++;
        }

        // Check for new messages and display them
        for (int i = 0; i < num_messages; i++) {
            if (messages[i].sender_id == receiver_id) {
                printf("%s: %s\n", players[messages[i].sender_id-1].name, messages[i].content);
            }
        }
    }

    return 0;
}
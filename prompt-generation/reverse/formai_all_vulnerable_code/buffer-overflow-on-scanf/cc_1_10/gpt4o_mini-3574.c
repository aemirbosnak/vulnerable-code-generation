//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PLAYERS 5
#define BUFFER_SIZE 512

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
    char name[50];
    char message[BUFFER_SIZE];
    int id;
} Player;

Player players[MAX_PLAYERS];
int player_count = 0;

void *translate_to_cat_language(void *arg) {
    Player *player = (Player *)arg;
    
    while (1) {
        sleep(1);
        pthread_mutex_lock(&mutex);
        
        printf("%s's message in Cat Language: ", player->name);
        
        char cat_message[BUFFER_SIZE] = "";
        for (int i = 0; player->message[i] != '\0'; i++) {
            char ch = player->message[i];

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                strcat(cat_message, "meow");
            } else if ((ch >= 'b' && ch <= 'z') || (ch >= 'B' && ch <= 'Z')) {
                char temp[3];
                sprintf(temp, "%cpurr", ch);
                strcat(cat_message, temp);
            } else {
                strncat(cat_message, &ch, 1);
            }
        }
        
        printf("%s\n", cat_message);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *player_input(void *arg) {
    Player *player = (Player *)arg;
    
    while (1) {
        printf("%s, enter your message: ", player->name);
        fgets(player->message, BUFFER_SIZE, stdin);
        player->message[strcspn(player->message, "\n")] = 0; // Remove newline
    }
    return NULL;
}

int main() {
    printf("Welcome to the Cat Language Multiplayer Translator!\n");
    
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &player_count);
    getchar(); // consume newline after player_count input

    if (player_count > MAX_PLAYERS || player_count <= 0) {
        printf("Invalid number of players, exiting program.\n");
        return 1;
    }

    pthread_t threads[player_count];

    for (int i = 0; i < player_count; i++) {
        printf("Enter name for player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // Remove newline
        players[i].id = i;

        pthread_create(&threads[i], NULL, player_input, (void*)&players[i]);
        pthread_create(&threads[i], NULL, translate_to_cat_language, (void*)&players[i]);
    }

    for (int i = 0; i < player_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
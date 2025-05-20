//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 32
#define MAX_MAP_SIZE 10
#define MAX_MESSAGE_LENGTH 128

typedef struct {
    char name[MAX_NAME_LENGTH];
    int x;
    int y;
    int health;
} Player;

typedef struct {
    char name[MAX_MAP_SIZE][MAX_MAP_SIZE];
    int width;
    int height;
} Map;

typedef struct {
    char message[MAX_MESSAGE_LENGTH];
    int sender;
} Message;

typedef struct {
    Player players[MAX_PLAYERS];
    Map map;
    Message messages[MAX_PLAYERS];
} GameState;

GameState state;

void init_game() {
    strcpy(state.map.name, "MAP1");
    state.map.width = 10;
    state.map.height = 10;

    for (int i = 0; i < MAX_PLAYERS; i++) {
        sprintf(state.players[i].name, "Player%d", i + 1);
        state.players[i].x = rand() % state.map.width;
        state.players[i].y = rand() % state.map.height;
        state.players[i].health = 100;
    }
}

void print_map() {
    for (int y = 0; y < state.map.height; y++) {
        for (int x = 0; x < state.map.width; x++) {
            printf("%c", state.map.name[y][x]);
        }
        printf("\n");
    }
}

void print_players() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: (%d, %d) Health: %d\n", state.players[i].name, state.players[i].x, state.players[i].y, state.players[i].health);
    }
}

void print_messages() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strlen(state.messages[i].message) > 0) {
            printf("%s: %s\n", state.players[i].name, state.messages[i].message);
        }
    }
}

void handle_input(int player) {
    char input[10];
    scanf("%s", input);

    if (strcmp(input, "w") == 0) {
        state.players[player].y--;
    } else if (strcmp(input, "s") == 0) {
        state.players[player].y++;
    } else if (strcmp(input, "a") == 0) {
        state.players[player].x--;
    } else if (strcmp(input, "d") == 0) {
        state.players[player].x++;
    } else if (strcmp(input, "m") == 0) {
        scanf("%s", state.messages[player].message);
    }
}

void update_game() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        handle_input(i);
    }
}

void draw_game() {
    print_map();
    print_players();
    print_messages();
}

int main() {
    init_game();

    while (1) {
        update_game();
        draw_game();
    }

    return 0;
}
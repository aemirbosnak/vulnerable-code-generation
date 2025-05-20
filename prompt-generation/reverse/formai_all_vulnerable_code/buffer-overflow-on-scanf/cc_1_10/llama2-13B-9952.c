//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_GOLD 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int gold;
} player_t;

player_t player;

void init_player(void) {
    player.name[0] = '\0';
    player.gold = 0;
}

void print_player_info(void) {
    printf("Your name: %s\n", player.name);
    printf("Your gold: %d\n", player.gold);
}

void add_gold(int amount) {
    player.gold += amount;
}

void subtract_gold(int amount) {
    player.gold -= amount;
}

void game_loop(void) {
    int choice;

    print_player_info();

    printf("What would you like to do? (q/Q to quit): ");
    scanf("%c", &choice);

    switch (choice) {
        case 'q':
        case 'Q':
            exit(EXIT_SUCCESS);
        case 'a':
            add_gold(10);
            break;
        case 's':
            subtract_gold(10);
            break;
        case 'e':
            add_gold(50);
            break;
        case 'd':
            subtract_gold(50);
            break;
        default:
            printf("Invalid input. Try again.\n");
            break;
    }
}

int main(void) {
    init_player();

    while (1) {
        game_loop();
    }

    return EXIT_SUCCESS;
}
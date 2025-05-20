//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_FORTUNE_LENGTH 80

typedef struct {
    char name[20];
    int money;
    char fortune[MAX_FORTUNE_LENGTH];
} Player;

void init_player(Player *player, char *name) {
    strcpy(player->name, name);
    player->money = 100;
    player->fortune[0] = '\0';
}

void print_player(Player player) {
    printf("Name: %s\n", player.name);
    printf("Money: %d\n", player.money);
    printf("Fortune: %s\n", player.fortune);
}

void generate_fortune(Player *player) {
    char fortunes[][MAX_FORTUNE_LENGTH] = {
        "You will meet a tall, dark stranger.",
        "A great opportunity awaits you.",
        "Beware of a friend who is not what they seem.",
        "You will come into a large sum of money.",
        "Travel is in your future.",
        "Someone close to you will reveal a secret.",
        "You will experience a change in your love life.",
        "Your hard work will pay off soon.",
        "A new job opportunity will present itself.",
        "You will have good luck in the coming days."
    };

    srand(time(NULL));
    int index = rand() % 10;
    strcpy(player->fortune, fortunes[index]);
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players = 0;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("How many players will be participating? ");
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++) {
        char name[20];
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", name);
        init_player(&players[i], name);
    }

    int money = 0;
    printf("\nTo tell your fortune, please insert $1.\n");
    scanf("%d", &money);

    if (money!= 1) {
        printf("Sorry, the Automated Fortune Teller only accepts $1.\n");
        return 1;
    }

    for (int i = 0; i < num_players; i++) {
        generate_fortune(&players[i]);
        print_player(players[i]);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10

struct player {
    char name[20];
    int score;
    int cards[MAX_CARDS];
};

struct bingo_card {
    int numbers[25];
};

void generate_card(struct bingo_card *card) {
    for (int i = 0; i < 25; i++) {
        card->numbers[i] = rand() % 75 + 1;
    }
}

void print_card(struct bingo_card *card) {
    printf("Bingo Card:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", card->numbers[i*5+j]);
        }
        printf("\n");
    }
}

int check_win(struct bingo_card *card, int num) {
    for (int i = 0; i < 25; i++) {
        if (card->numbers[i] == num) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));

    int num_players;
    printf("Enter number of players: ");
    scanf("%d", &num_players);

    struct player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    struct bingo_card cards[MAX_CARDS];
    for (int i = 0; i < num_players; i++) {
        generate_card(&cards[i]);
        print_card(&cards[i]);
        printf("\n");
    }

    int current_num = 1;
    while (1) {
        for (int i = 0; i < num_players; i++) {
            if (check_win(&cards[i], current_num)) {
                players[i].score++;
                printf("%s got a bingo with number %d!\n", players[i].name, current_num);
            }
        }
        current_num++;
        if (current_num > 75) {
            break;
        }
    }

    for (int i = 0; i < num_players; i++) {
        printf("%s's final score: %d\n", players[i].name, players[i].score);
    }

    return 0;
}
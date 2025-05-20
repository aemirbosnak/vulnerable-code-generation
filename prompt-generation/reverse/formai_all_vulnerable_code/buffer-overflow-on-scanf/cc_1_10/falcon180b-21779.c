//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_FORTUNES 100

struct fortune {
    char text[80];
};

struct player {
    char name[20];
    int score;
};

void rand_seed(void) {
    time_t t;
    time(&t);
    srand(t);
}

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void shuffle_fortunes(struct fortune *fortunes) {
    int i, j, k;
    struct fortune temp;

    for (i = 0; i < MAX_FORTUNES; i++) {
        for (j = i + 1; j < MAX_FORTUNES; j++) {
            if (rand_int(0, 1) == 0) {
                temp = fortunes[i];
                fortunes[i] = fortunes[j];
                fortunes[j] = temp;
            }
        }
    }
}

void print_fortunes(struct fortune *fortunes, int num_fortunes) {
    int i;

    for (i = 0; i < num_fortunes; i++) {
        printf("%s\n", fortunes[i].text);
    }
}

void play_game(struct player *players, struct fortune *fortunes) {
    int i, num_fortunes, choice, score = 0;
    char input[20];

    rand_seed();
    shuffle_fortunes(fortunes);

    num_fortunes = rand_int(1, MAX_FORTUNES);

    for (i = 0; i < num_fortunes; i++) {
        printf("Player %s, choose your fortune:\n", players[0].name);
        print_fortunes(fortunes, MAX_FORTUNES);
        scanf("%s", input);

        choice = rand_int(0, MAX_FORTUNES - 1);

        if (choice == rand_int(0, MAX_FORTUNES - 1)) {
            printf("You've won!\n");
            score++;
        } else {
            printf("Sorry, you lose.\n");
        }
    }

    printf("Your final score is: %d\n", score);
}

int main() {
    struct player players[MAX_PLAYERS];
    struct fortune fortunes[MAX_FORTUNES];
    int num_players, num_fortunes, i;

    rand_seed();

    printf("How many players? (1-10): ");
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("Player %d name: ", i + 1);
        scanf("%s", players[i].name);
    }

    printf("How many fortunes? (1-100): ");
    scanf("%d", &num_fortunes);

    for (i = 0; i < num_fortunes; i++) {
        printf("Fortune %d: ", i + 1);
        scanf("%s", fortunes[i].text);
    }

    play_game(players, fortunes);

    return 0;
}
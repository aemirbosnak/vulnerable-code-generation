//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_FORTUNE_LENGTH 100

typedef struct {
    char name[20];
    int score;
} Player;

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
    int length;
} Fortune;

Player players[MAX_PLAYERS];
Fortune fortunes[MAX_PLAYERS];

void init_player(Player *player, char *name) {
    strcpy(player->name, name);
    player->score = 0;
}

void init_fortune(Fortune *fortune, char *text) {
    strcpy(fortune->text, text);
    fortune->length = strlen(text);
}

int main() {
    int num_players;
    char input[20];
    srand(time(NULL));

    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", input);
        init_player(&players[i], input);
    }

    for (int i = 0; i < num_players; i++) {
        fortunes[i].text[0] = '\0';
        int j;
        for (j = 0; j < 3; j++) {
            int k;
            for (k = 0; k < 5; k++) {
                char word[20];
                sprintf(word, "word%d", rand() % 100);
                strcat(fortunes[i].text, word);
                strcat(fortunes[i].text, " ");
            }
            strcat(fortunes[i].text, ".\n");
        }
        fortunes[i].length = strlen(fortunes[i].text);
    }

    int current_player = 0;
    while (1) {
        printf("\n%s's fortune:\n%s", players[current_player].name, fortunes[current_player].text);
        printf("Press enter to continue...\n");
        getchar();

        if (current_player == num_players - 1) {
            current_player = 0;
        } else {
            current_player++;
        }
    }

    return 0;
}
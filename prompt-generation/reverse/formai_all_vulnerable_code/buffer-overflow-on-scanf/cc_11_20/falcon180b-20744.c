//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_players, i, j, player_won, game_over, bingo[5][5], num;
    char name[100][20];
    printf("Enter number of players: ");
    scanf("%d", &num_players);

    printf("Enter player names:\n");
    for(i = 0; i < num_players; i++) {
        scanf("%s", name[i]);
    }

    srand(time(0));
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            bingo[i][j] = rand() % 15 + 1;
        }
    }

    printf("\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d ", bingo[i][j]);
        }
        printf("\n");
    }

    game_over = 0;
    while(game_over == 0) {
        for(i = 0; i < num_players; i++) {
            player_won = 1;
            for(j = 0; j < 5; j++) {
                if(bingo[j][i]!= name[i][j]) {
                    player_won = 0;
                    break;
                }
            }
            if(player_won == 1) {
                printf("%s won!\n", name[i]);
                game_over = 1;
                break;
            }
        }
        if(game_over == 0) {
            num = rand() % 15 + 1;
            printf("Call: %d\n", num);
            for(i = 0; i < num_players; i++) {
                if(bingo[0][i] == num) {
                    printf("%s got a number!\n", name[i]);
                }
            }
        }
    }

    return 0;
}
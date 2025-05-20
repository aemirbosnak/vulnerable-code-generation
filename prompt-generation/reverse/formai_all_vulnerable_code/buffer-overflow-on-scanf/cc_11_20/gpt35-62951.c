//FormAI DATASET v1.0 Category: QR code generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QR_CODE_SIZE 10
#define PLAYER_COUNT 2

int main() {
    char qr_code[QR_CODE_SIZE][QR_CODE_SIZE];
    int players[PLAYER_COUNT][2];
    int i, j, player_id, winner;

    // initialize QR code with random characters
    srand(time(NULL));
    for (i = 0; i < QR_CODE_SIZE; i++) {
        for (j = 0; j < QR_CODE_SIZE; j++) {
            qr_code[i][j] = rand() % 26 + 'a';
        }
    }

    // initialize player positions
    players[0][0] = 0;
    players[0][1] = 0;
    players[1][0] = 9;
    players[1][1] = 9;

    // game loop
    while (1) {
        // print QR code with player positions
        for (i = 0; i < QR_CODE_SIZE; i++) {
            for (j = 0; j < QR_CODE_SIZE; j++) {
                if (i == players[0][0] && j == players[0][1]) {
                    printf("P1 ");
                } else if (i == players[1][0] && j == players[1][1]) {
                    printf("P2 ");
                } else {
                    printf("%c   ", qr_code[i][j]);
                }
            }
            printf("\n");
        }

        // get player move
        printf("Player %d, choose a direction (1=up, 2=down, 3=left, 4=right): ", player_id+1);
        int direction;
        scanf("%d", &direction);

        // update player position
        switch (direction) {
            case 1: // up
                players[player_id][0]--;
                if (players[player_id][0] < 0) {
                    players[player_id][0] = 0;
                }
                break;
            case 2: // down
                players[player_id][0]++;
                if (players[player_id][0] >= QR_CODE_SIZE) {
                    players[player_id][0] = QR_CODE_SIZE-1;
                }
                break;
            case 3: // left
                players[player_id][1]--;
                if (players[player_id][1] < 0) {
                    players[player_id][1] = 0;
                }
                break;
            case 4: // right
                players[player_id][1]++;
                if (players[player_id][1] >= QR_CODE_SIZE) {
                    players[player_id][1] = QR_CODE_SIZE-1;
                }
                break;
        }

        // check if player has reached finish
        if (players[player_id][0] == 9 && players[player_id][1] == 9) {
            winner = player_id;
            break;
        }

        // switch player turn
        player_id = (player_id + 1) % PLAYER_COUNT;
    }

    // print winner
    printf("Player %d wins!\n", winner+1);

    return 0;
}
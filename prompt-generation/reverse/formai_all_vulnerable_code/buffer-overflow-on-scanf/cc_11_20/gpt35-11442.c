//FormAI DATASET v1.0 Category: Log analysis ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LOGS 1000
#define MAX_PLAYERS 10

struct log {
    char player1[20];
    char player2[20];
    char move[10];
};

struct player_stats {
    char name[20];
    int wins;
    int losses;
    int draws;
};

int main() {
    struct log logs[MAX_LOGS];
    struct player_stats players[MAX_PLAYERS];
    int num_logs = 0, num_players = 0;
    int i,j;

    while(1) {
        printf("Enter command [log/player/stats/quit]: ");
        char command[10];
        scanf("%s", command);
        if(strcmp(command, "log") == 0) {
            if(num_logs < MAX_LOGS) {
                struct log new_log;
                printf("Enter player 1 name: ");
                scanf("%s", new_log.player1);
                printf("Enter player 2 name: ");
                scanf("%s", new_log.player2);
                printf("Enter move: ");
                scanf("%s", new_log.move);
                logs[num_logs] = new_log;
                num_logs++;
            }
            else {
                printf("Max number of logs reached\n");
            }
        }
        else if(strcmp(command, "player") == 0) {
            if(num_players < MAX_PLAYERS) {
                struct player_stats new_player;
                printf("Enter player name: ");
                scanf("%s", new_player.name);
                new_player.wins = 0;
                new_player.losses = 0;
                new_player.draws = 0;
                players[num_players] = new_player;
                num_players++;
            }
            else {
                printf("Max number of players reached\n");
            }
        }
        else if(strcmp(command, "stats") == 0) {
            for(i=0; i<num_players; i++) {
                printf("%s: %d wins, %d losses, %d draws\n", players[i].name, players[i].wins, players[i].losses, players[i].draws);
            }
        }
        else if(strcmp(command, "quit") == 0) {
            break;
        }
        else {
            printf("Invalid command\n");
        }
    }

    //Calculate player stats
    for(i=0; i<num_logs; i++) {
        for(j=0; j<num_players; j++) {
            if(strcmp(logs[i].player1, players[j].name) == 0) {
                if(strcmp(logs[i].move, "win") == 0) {
                    players[j].wins++;
                }
                else if(strcmp(logs[i].move, "loss") == 0) {
                    players[j].losses++;
                }
                else if(strcmp(logs[i].move, "draw") == 0) {
                    players[j].draws++;
                }
            }
            else if(strcmp(logs[i].player2, players[j].name) == 0) {
                if(strcmp(logs[i].move, "win") == 0) {
                    players[j].losses++;
                }
                else if(strcmp(logs[i].move, "loss") == 0) {
                    players[j].wins++;
                }
                else if(strcmp(logs[i].move, "draw") == 0) {
                    players[j].draws++;
                }
            }
        }
    }

    return 0;
}
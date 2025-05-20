//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multiplayer
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_PLAYERS 4
#define MAX_LOGS 100
#define MAX_LOG_LENGTH 200

char logs[MAX_LOGS][MAX_LOG_LENGTH];
int num_logs = 0;

int is_attack(char* log) {
    if(strstr(log, "attack"))
        return 1;
    return 0;
}

void log_attack(char* attacker, char* victim, char* weapon) {
    char log[MAX_LOG_LENGTH];
    sprintf(log, "%s attacked %s with a %s", attacker, victim, weapon);
    strcpy(logs[num_logs], log);
    num_logs++;
}

void log_defense(char* defender, char* weapon) {
    char log[MAX_LOG_LENGTH];
    sprintf(log, "%s defended an attack with a %s", defender, weapon);
    strcpy(logs[num_logs], log);
    num_logs++;
}

void log_move(char* player, int x, int y) {
    char log[MAX_LOG_LENGTH];
    sprintf(log, "%s moved to (%d,%d)", player, x, y);
    strcpy(logs[num_logs], log);
    num_logs++;
}

void print_logs() {
    for(int i=0; i<num_logs; i++) {
        printf("%d. %s\n", i+1, logs[i]);
    }
}

int main() {
    char players[MAX_PLAYERS][20] = {"Player 1", "Player 2", "Player 3", "Player 4"};
    int player_x[MAX_PLAYERS] = {0, 1, 2, 3};
    int player_y[MAX_PLAYERS] = {0, 1, 2, 3};
    char weapons[MAX_PLAYERS][20] = {"sword", "axe", "mace", "dagger"};

    while(1) {
        char input[50];
        printf("Enter command: ");
        scanf("%[^\n]", input);
        getchar();

        char* token = strtok(input, " ");
        if(strcmp(token, "move") == 0) {
            char* player_name = strtok(NULL, " ");
            int x = atoi(strtok(NULL, ","));
            int y = atoi(strtok(NULL, ","));
            for(int i=0; i<MAX_PLAYERS; i++) {
                if(strcmp(players[i], player_name) == 0) {
                    player_x[i] = x;
                    player_y[i] = y;
                    log_move(players[i], x, y);
                    break;
                }
            }
        } else if(strcmp(token, "attack") == 0) {
            char* attacker_name = strtok(NULL, " ");
            char* victim_name = strtok(NULL, " ");
            char* weapon = strtok(NULL, " ");
            for(int i=0; i<MAX_PLAYERS; i++) {
                if(strcmp(players[i], attacker_name) == 0) {
                    log_attack(attacker_name, victim_name, weapon);
                    break;
                }
            }
            for(int i=0; i<MAX_PLAYERS; i++) {
                if(strcmp(players[i], victim_name) == 0) {
                    if(is_attack(logs[num_logs-1]))
                        log_defense(victim_name, weapons[i]);
                    break;
                }
            }
        } else if(strcmp(token, "logs") == 0) {
            print_logs();
        } else if(strcmp(token, "quit") == 0) {
            break;
        }
    }

    return 0;
}
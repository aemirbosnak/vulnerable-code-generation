//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multiplayer
#include<stdio.h>
#include<string.h>

#define MAX_LEN 1000
#define MAX_PLAYERS 4

int num_players = 0;

struct player {
    char name[30];
    int score;
    char summary[MAX_LEN];
} players[MAX_PLAYERS];

int get_num_players() {
    int n;
    printf("How many players? ");
    scanf("%d", &n);
    return n;
}

void initialize_players() {
    int i;
    for (i = 0; i < num_players; i++) {
        printf("Enter name of player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        memset(players[i].summary, 0, MAX_LEN);
    }
}

void print_results() {
    int i;
    printf("\nFinal scores:\n");
    for (i = 0; i < num_players; i++)
        printf("%s: %d\n", players[i].name, players[i].score);
}

int main() {
    num_players = get_num_players();
    initialize_players();

    FILE *fp;
    char filename[30];
    printf("Enter filename of text to be summarized: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file. Exiting.\n");
        return 1;
    }

    char text[MAX_LEN];
    fgets(text, MAX_LEN, fp);
    fclose(fp);

    int summary_len;
    printf("Enter the length of the summary: ");
    scanf("%d", &summary_len);

    char *delim = " .";
    char *token;
    int player_index = 0;
    int len = strlen(text);
 
    int i = 0;
    while (i < len) {
        int summary_index = 0;
        while (summary_index < summary_len && i < len) {
            token = strtok(i == 0 ? text : NULL, delim);
            if (token != NULL) {
                strcat(players[player_index].summary, token);
                strcat(players[player_index].summary, " ");
                summary_index += strlen(token) + 1;
            } else {
                break;
            }
            i += strlen(token) + 1;
        }
        printf("%s, enter score for summary: ", players[player_index].name);
        int score;
        scanf("%d", &score);
        players[player_index].score += score;
        player_index = (player_index + 1) % num_players;
    }

    print_results();
    return 0;
}
//FormAI DATASET v1.0 Category: HTML beautifier ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 10

struct Player {
    char name[20];
    int score;
};

int main() {
    struct Player players[MAX_PLAYERS];
    int num_players, i, j;
    char html_code[500];
    printf("Welcome to the HTML beautifier multiplayer game!\n");
    printf("How many players will be playing today? (Maximum of %d players)\n", MAX_PLAYERS);
    scanf("%d", &num_players);

    while(num_players <= 0 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Please enter a number between 1 and %d: \n", MAX_PLAYERS);
        scanf("%d", &num_players);
    }

    for(i=0; i<num_players; i++) {
        printf("Player %d, please enter your name: ", i+1);
        scanf("%s", &players[i].name);
        players[i].score = 0;
    }

    printf("\nYour HTML code: \n");
    scanf(" %[^\n]", html_code);

    // Beautify HTML code
    char beautified_html[500] = "";
    int indent_level = 0, len = strlen(html_code);
    for(i=0; i<len; i++) {

        if(html_code[i] == '<') {
            if(html_code[i+1] == '/') indent_level--;
            for(j=0; j<indent_level; j++) {
                strcat(beautified_html, "    ");
            }
            if(html_code[i+1] != '/') indent_level++;
        }

        strncat(beautified_html, &html_code[i], 1);

        if(html_code[i] == '>' && html_code[i-1] != '/') {
            strcat(beautified_html, "\n");
        }
    }

    printf("\nBeautified HTML code: \n");
    printf("%s\n", beautified_html);

    // Calculate scores
    int score_per_indent = 10;
    for(i=0; i<num_players; i++) {
        for(j=0; j<strlen(beautified_html); j++) {
            if((beautified_html[j] == ' ' || beautified_html[j] == '\t') && (beautified_html[j+1] != ' ' && beautified_html[j+1] != '\t')) {
                players[i].score += score_per_indent;
            }
        }
    }

    // Display scores
    printf("\nScores:\n");
    for(i=0; i<num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}
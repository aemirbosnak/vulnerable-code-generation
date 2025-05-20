//FormAI DATASET v1.0 Category: Syntax parsing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4

struct Player {
    char name[50];
    int score;
};

struct Syntax {
    char keyword[50];
    char definition[100];
};

struct Syntax syntax_list[] = {
    {"int", "Specifies the data type integer"},
    {"char", "Specifies the data type character"},
    {"float", "Specifies the data type floating point number"},
    {"double", "Specifies the data type double precision floating point number"},
    {"void", "Specifies that the function has no return value"},
    {"if", "Specifies a conditional statement"},
    {"else", "Specifies an alternate statement for if condition"},
    {"for", "Specifies a loop statement"},
    {"while", "Specifies a loop statement"},
    {"do-while", "Specifies a loop statement"},
    {"switch", "Specifies a conditional statement for multiple cases"},
    {"case", "Specifies a case for switch statement"}
};

int num_players;
struct Player players[MAX_PLAYERS];

void welcome_message() {
    printf("Welcome to Syntax Parsing Game!\n");
    printf("Please enter the number of players (maximum %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    for(int i=0; i<num_players; i++) {
        printf("Player %d, please enter your name: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    printf("Great! Let's start the game!\n");
}

void display_scores() {
    for(int i=0; i<num_players; i++) {
        printf("%s's score is %d\n", players[i].name, players[i].score);
    }
}

void play_game() {
    int round_number = 1;

    while(1) {
        printf("Round %d\n", round_number);
        printf("Please enter a C syntax keyword: ");
        char keyword[50];
        scanf("%s", keyword);

        for(int i=0; i<sizeof(syntax_list)/sizeof(struct Syntax); i++) {
            if(strcmp(keyword, syntax_list[i].keyword) == 0) {
                printf("%s is a valid syntax keyword! +1 point for each player\n", syntax_list[i].keyword);
                for(int j=0; j<num_players; j++) {
                    players[j].score += 1;
                }
                display_scores();
                break;
            }
            if(i == sizeof(syntax_list)/sizeof(struct Syntax) - 1) {
                printf("%s is not a valid syntax keyword! No points awarded\n", keyword);
                display_scores();
            }
        }

        printf("Do you want to continue playing? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if(choice == 'n') {
            break;
        }
        round_number++;
    }
}

void announce_winner() {
    struct Player winner = players[0];
    for(int i=1; i<num_players; i++) {
        if(players[i].score > winner.score) {
            winner = players[i];
        }
    }

    printf("%s is the winner with a score of %d!\n", winner.name, winner.score);
}

int main() {
    welcome_message();
    play_game();
    announce_winner();

    return 0;
}
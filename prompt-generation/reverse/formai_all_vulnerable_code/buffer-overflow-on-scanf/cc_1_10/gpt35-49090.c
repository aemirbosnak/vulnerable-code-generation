//FormAI DATASET v1.0 Category: Educational ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10

int roll_dice();
int get_player_choice(int);
void print_score_table(int[][MAX_ROUNDS+1], int);
void print_winner(int[][MAX_ROUNDS+1], int);
void clear_buffer();

int main()
{
    int players, rounds, current_round, current_player, score_table[MAX_PLAYERS][MAX_ROUNDS+1] = {0};

    srand(time(NULL));

    printf("How many players (2 to 4)? ");
    scanf("%d", &players);
    clear_buffer();

    printf("How many rounds would you like to play? ");
    scanf("%d", &rounds);
    clear_buffer();

    printf("You will be playing with %d players for %d rounds.\n\n", players, rounds);

    for(current_round = 0; current_round < rounds; current_round++){
        printf("---ROUND %d ---\n\n", current_round + 1);
        for(current_player = 0; current_player < players; current_player++){
            printf("It's Player %d's turn. Roll the dice? (Y/N) ", current_player + 1);
            if(get_player_choice(current_player)){
                score_table[current_player][current_round] = roll_dice();
                printf("Player %d has scored %d in round %d.\n\n", current_player + 1, score_table[current_player][current_round], current_round + 1);
                print_score_table(score_table, players);
            }
            else{
                printf("Player %d has skipped round %d.\n\n", current_player + 1, current_round + 1);
            }
        }
    }

    print_winner(score_table, players);

    return 0;
}

int roll_dice()
{
    return (rand() % 6) + 1;
}

int get_player_choice(int player_num)
{
    char input;

    do{
        scanf("%c", &input);
        clear_buffer();
        if(input == 'Y' || input == 'y'){
            return 1;
        }
        if(input == 'N' || input == 'n'){
            return 0;
        }
        printf("Invalid input. Please enter Y or N.\n");
    }while(1);
}

void print_score_table(int scores[][MAX_ROUNDS+1], int num_of_players)
{
    int i, j;

    printf("SCORE TABLE:\n\n");
    printf("          ");
    for(i = 1; i <= MAX_ROUNDS; i++){
        printf("| Round %d ", i);
    }
    printf("| Total |\n");
    for(i = 0; i < num_of_players; i++){
        printf("Player %d ", i + 1);
        for(j = 0; j <= MAX_ROUNDS; j++){
            printf("|   %2d   ", scores[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

void print_winner(int scores[][MAX_ROUNDS+1], int num_of_players)
{
    int i, j, max_score = 0, winners[MAX_PLAYERS] = {0}, winner_count = 0;

    printf("FINAL SCORE TABLE:\n\n");
    printf("          ");
    for(i = 1; i <= MAX_ROUNDS; i++){
        printf("| Round %d ", i);
    }
    printf("| Total |\n");
    for(i = 0; i < num_of_players; i++){
        printf("Player %d ", i + 1);
        for(j = 0; j <= MAX_ROUNDS; j++){
            printf("|   %2d   ", scores[i][j]);
            scores[i][MAX_ROUNDS+1] += scores[i][j];
        }
        printf("|\n");
        if(scores[i][MAX_ROUNDS+1] > max_score){
            max_score = scores[i][MAX_ROUNDS+1];
        }
    }
    printf("\n");

    printf("WINNERS:\n\n");
    for(i = 0; i < num_of_players; i++){
        if(scores[i][MAX_ROUNDS+1] == max_score){
            winners[winner_count++] = i + 1;
        }
    }
    printf("Player(s) ");
    for(i = 0; i < winner_count; i++){
        printf("%d", winners[i]);
        if(i == winner_count - 2){
            printf(" and ");
        }
        else if(i != winner_count - 1){
            printf(", ");
        }
    }
    printf(" won with a total score of %d.\n", max_score);
}

void clear_buffer()
{
    while(getchar() != '\n');
}
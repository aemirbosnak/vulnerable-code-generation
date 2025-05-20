//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_RATINGS 5
#define MIN_RATINGS 1
#define MAX_PLAYERS 4

int ratings[MAX_PLAYERS];
int num_players;

void get_ratings() {
    printf("Enter the ratings (1-5) for each player:\n");
    for(int i=0; i<num_players; i++) {
        printf("Player %d: ", i+1);
        scanf("%d", &ratings[i]);
        while(ratings[i]<MIN_RATINGS || ratings[i]>MAX_RATINGS) {
            printf("Invalid rating! Enter a rating between %d and %d: ", MIN_RATINGS, MAX_RATINGS);
            scanf("%d", &ratings[i]);
        }
    }
}

void display_ratings() {
    printf("\nPlayer ratings:\n");
    for(int i=0; i<num_players; i++) {
        printf("Player %d: %d\n", i+1, ratings[i]);
    }
}

void rank_players() {
    int max_rating = 0;
    int max_index = 0;
    printf("\nPlayer ranks:\n");
    for(int i=1; i<=num_players; i++) {
        for(int j=0; j<num_players; j++) {
            if(ratings[j]>max_rating) {
                max_rating = ratings[j];
                max_index = j;
            }
        }
        printf("%d. Player %d with rating %d\n", i, max_index+1, max_rating);
        ratings[max_index] = 0;
        max_rating = 0;
        max_index = 0;
    }
}

int main() {
    printf("Welcome to the C Movie Rating System!\n");
    printf("Enter the number of players (max 4): ");
    scanf("%d", &num_players);

    while(num_players<1 || num_players>MAX_PLAYERS) {
        printf("Invalid number of players! Enter a number between 1 and 4: ");
        scanf("%d", &num_players);
    }

    get_ratings();
    display_ratings();
    rank_players();

    return 0;
}
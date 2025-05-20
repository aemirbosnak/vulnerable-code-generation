//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20
#define MAX_NUMBERS 100

typedef struct player {
    char name[MAX_NAME_LENGTH];
    int score;
    int numbers[MAX_NUMBERS];
    int num_numbers;
} Player;

void init_player(Player *p) {
    strcpy(p->name, "Player");
    p->score = 0;
    p->num_numbers = 0;
}

void add_number(Player *p, int n) {
    if (p->num_numbers >= MAX_NUMBERS) {
        printf("%s's list is full.\n", p->name);
        return;
    }
    p->numbers[p->num_numbers++] = n;
}

int sum_numbers(Player *p) {
    int sum = 0;
    for (int i = 0; i < p->num_numbers; i++) {
        sum += p->numbers[i];
    }
    return sum;
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int num_players = 0;

    while (num_players < MAX_PLAYERS) {
        printf("Enter your name (max %d characters): ", MAX_NAME_LENGTH - 1);
        scanf("%s", players[num_players].name);
        strcat(players[num_players].name, "'s turn");

        while (1) {
            printf("Press enter to roll the dice...\n");
            getchar();
            int dice = rand() % 6 + 1;
            printf("You rolled a %d!\n", dice);

            if (dice == 1) {
                printf("Sorry, you lose your turn.\n");
                break;
            } else if (dice == 6) {
                printf("Congratulations, you get an extra turn!\n");
            } else {
                printf("What would you like to do?\n1. Add to your list\n2. Calculate your score\n");
                scanf("%d", &dice);

                if (dice == 1) {
                    printf("Enter a number to add to your list: ");
                    int n;
                    scanf("%d", &n);
                    add_number(&players[num_players], n);
                } else if (dice == 2) {
                    printf("Your score is %d.\n", sum_numbers(&players[num_players]));
                }
            }
        }

        num_players++;
    }

    return 0;
}
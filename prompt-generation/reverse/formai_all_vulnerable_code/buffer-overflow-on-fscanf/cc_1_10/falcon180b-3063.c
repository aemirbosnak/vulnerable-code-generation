//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 5
#define COLS 5

void print_bingo_card(int card[ROWS][COLS]) {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

void generate_bingo_card(int card[ROWS][COLS]) {
    int i, j;
    srand(time(NULL)); // seed the random number generator with current time
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            card[i][j] = rand() % 15 + 1; // generate a number between 1 and 15
        }
    }
}

int check_win(int card[ROWS][COLS]) {
    int i, j, count=0;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(card[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int bingo_card[ROWS][COLS], i, j, player_count, current_player, called_numbers[15];
    char name[20];
    FILE *fp;

    printf("Enter number of players: ");
    scanf("%d", &player_count);

    printf("Enter names of players:\n");
    for(i=0; i<player_count; i++) {
        printf("Player %d name: ", i+1);
        scanf("%s", name);
        printf("%s\n", name);
    }

    printf("Enter names of players again to confirm:\n");
    for(i=0; i<player_count; i++) {
        printf("Player %d name: ", i+1);
        scanf("%s", name);
        if(strcmp(name, name)!= 0) {
            printf("Error: Names do not match.\n");
            exit(1);
        }
    }

    fp = fopen("bingo_numbers.txt", "r");
    if(fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    for(i=0; i<15; i++) {
        fscanf(fp, "%d", &called_numbers[i]);
    }

    fclose(fp);

    for(i=0; i<player_count; i++) {
        printf("Generating bingo card for %s...\n", name);
        generate_bingo_card(bingo_card[i]);
    }

    printf("\nBingo cards:\n");
    for(i=0; i<player_count; i++) {
        printf("Card for %s:\n", name);
        print_bingo_card(bingo_card[i]);
    }

    int round_count = 0;
    while(1) {
        round_count++;
        printf("\nRound %d:\n", round_count);
        for(i=0; i<15; i++) {
            printf("%d ", called_numbers[i]);
        }
        printf("\n");

        int player_won = 0;
        for(i=0; i<player_count; i++) {
            current_player = i;
            while(current_player >= player_count) {
                current_player -= player_count;
            }

            if(check_win(bingo_card[current_player]) == 0) {
                printf("%s wins!\n", name);
                player_won = 1;
                break;
            }
        }

        if(player_won == 0) {
            printf("No winner this round.\n");
        }

        if(player_won == 1) {
            break;
        }
    }

    return 0;
}
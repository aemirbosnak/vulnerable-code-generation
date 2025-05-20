//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Global Variables
int num_players = 0;
int num_bingos = 0;
char bingo_list[5][5] = {
    "BINGO",
    "BINGO",
    "BINGO",
    "BINGO",
    "BINGO"
};

// Function Prototypes
void print_bingo_list();
void print_player_names();
void print_bingos();
void shuffle_bingo_list();
void call_bingo(int row, int column);

// Main Function
int main(void) {
    printf("Welcome to C Bingo Simulator!\n");
    printf("Number of Players: ");
    scanf("%d", &num_players);
    printf("Number of BINGOs: ");
    scanf("%d", &num_bingos);
    print_bingo_list();
    print_player_names();
    shuffle_bingo_list();
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: ", i + 1);
        for (int j = 0; j < 5; j++) {
            call_bingo(j, 0);
            call_bingo(j, 1);
            call_bingo(j, 2);
            call_bingo(j, 3);
            call_bingo(j, 4);
        }
        printf("\n");
    }
    print_bingos();
    printf("\n");
    return 0;
}

// Print Bingo List Function
void print_bingo_list(void) {
    printf("Bingo List:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c", bingo_list[i][j]);
        }
        printf("\n");
    }
}

// Print Player Names Function
void print_player_names(void) {
    printf("Player Names:\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: ", i + 1);
    }
    printf("\n");
}

// Print BINGOs Function
void print_bingos(void) {
    printf("BINGOs:\n");
    for (int i = 0; i < num_bingos; i++) {
        printf("Bingo %d:\n", i + 1);
        for (int j = 0; j < 5; j++) {
            printf("%c", bingo_list[i % 5][j]);
        }
        printf("\n");
    }
}

// Shuffle Bingo List Function
void shuffle_bingo_list(void) {
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int random_index = rand() % 25;
            char temp = bingo_list[i][j];
            bingo_list[i][j] = bingo_list[random_index][j];
            bingo_list[random_index][j] = temp;
        }
    }
}

// Call Bingo Function
void call_bingo(int row, int column) {
    printf("Call Bingo!\n");
    printf("Row: %d, Column: %d\n", row, column);
    printf("Bingo List:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c", bingo_list[i][j]);
        }
        printf("\n");
    }
    printf("Player Names:\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: ", i + 1);
    }
    printf("\n");
}
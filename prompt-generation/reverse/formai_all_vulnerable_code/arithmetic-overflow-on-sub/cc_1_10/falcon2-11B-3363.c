//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>

typedef struct {
    int game_state;
    int last_num;
    int current_num;
    int nums[20];
    int nums_drawn[20];
    int nums_remaining[20];
    int nums_called[20];
    int nums_left_to_call[20];
    int win_state;
} game_state_t;

game_state_t game_state = {0, 0, 0, {0}, {0}, {0}, {0}, {0}, {0}};

void init_game(void) {
    srand(time(NULL));
    game_state.last_num = rand() % 100;
    game_state.current_num = game_state.last_num;
    game_state.game_state = 0;
    game_state.win_state = 0;
}

void print_game(void) {
    printf("Game state: %d\n", game_state.game_state);
    printf("Last number: %d\n", game_state.last_num);
    printf("Current number: %d\n", game_state.current_num);
    printf("Nums: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", game_state.nums[i]);
    }
    printf("\n");
    printf("Nums drawn: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", game_state.nums_drawn[i]);
    }
    printf("\n");
    printf("Nums remaining: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", game_state.nums_remaining[i]);
    }
    printf("\n");
    printf("Nums called: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", game_state.nums_called[i]);
    }
    printf("\n");
    printf("Nums left to call: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", game_state.nums_left_to_call[i]);
    }
    printf("\n");
}

int get_next_num(void) {
    return game_state.last_num;
}

int check_win(void) {
    int i;
    for (i = 0; i < 20; i++) {
        if (game_state.nums_called[i] == game_state.nums_drawn[i] && game_state.nums_called[i] == game_state.nums_remaining[i]) {
            game_state.win_state = 1;
            return 1;
        }
    }
    return 0;
}

void check_num(int num) {
    if (game_state.game_state == 0) {
        game_state.current_num = num;
        game_state.game_state = 1;
    }
    else if (game_state.game_state == 1) {
        if (game_state.nums_remaining[num - 1]) {
            game_state.nums_called[num - 1] = 1;
            game_state.nums_remaining[num - 1] = 0;
            game_state.game_state = 2;
        }
        else {
            game_state.current_num = get_next_num();
            game_state.game_state = 0;
        }
    }
}

int main(void) {
    game_state.game_state = 0;
    init_game();
    while (game_state.win_state == 0) {
        printf("Enter a number to call (0-19): ");
        scanf("%d", &game_state.current_num);
        check_num(game_state.current_num);
        if (check_win() == 1) {
            printf("You win!\n");
        }
        print_game();
    }
    return 0;
}
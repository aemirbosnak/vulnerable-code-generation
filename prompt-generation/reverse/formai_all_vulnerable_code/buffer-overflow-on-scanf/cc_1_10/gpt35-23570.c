//FormAI DATASET v1.0 Category: Memory Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16

void print_board(char board[BOARD_SIZE]) {
    int i;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == '\0') {
            printf("_");
        } else {
            printf("%c", board[i]);
        }
        printf(" ");
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
}

void fill_board(char board[BOARD_SIZE]) {
    int i;
    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int letter_index = 0;
    srand(time(NULL));
    for (i = 0; i < BOARD_SIZE; i += 2) {
        char letter = letters[letter_index];
        board[i] = letter;
        board[i + 1] = letter;
        letter_index++;
    }
    for (i = 0; i < BOARD_SIZE; i++) {
        int random_index = rand() % BOARD_SIZE;
        char temp = board[i];
        board[i] = board[random_index];
        board[random_index] = temp;
    }
}

void play_game() {
    char board[BOARD_SIZE] = {'\0'};
    int revealed_count = 0;
    int revealed_indices[2] = {-1, -1};
    fill_board(board);
    while (revealed_count < BOARD_SIZE) {
        print_board(board);
        printf("Enter a card index (0-15): ");
        int index;
        scanf("%d", &index);
        if (index < 0 || index >= BOARD_SIZE || board[index] != '\0') {
            printf("Invalid input!\n");
            continue;
        }
        board[index] = board[index] == '\0' ? ' ' : board[index];
        if (revealed_indices[0] == -1) {
            revealed_indices[0] = index;
        } else if (revealed_indices[1] == -1) {
            revealed_indices[1] = index;
            if (board[revealed_indices[0]] == board[revealed_indices[1]]) {
                revealed_count += 2;
            } else {
                board[revealed_indices[0]] = board[revealed_indices[1]] = '\0';
            }
            revealed_indices[0] = revealed_indices[1] = -1;
        }
    }
    printf("Congratulations, you won!\n");
}

int main() {
    play_game();
    return 0;
}
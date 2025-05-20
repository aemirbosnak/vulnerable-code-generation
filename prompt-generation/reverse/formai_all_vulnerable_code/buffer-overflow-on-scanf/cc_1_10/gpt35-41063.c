//FormAI DATASET v1.0 Category: Memory Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4 // Size of memory game board
#define MAX_GUESSES (BOARD_SIZE * BOARD_SIZE) / 2 // Maximum number of guesses allowed
#define MEMORY_DURATION 2 // Memory duration in seconds
#define SLEEP_TIME 1000000 // Sleep time in microseconds

// Struct for holding game board info
struct GameBoard {
    int board[BOARD_SIZE][BOARD_SIZE];
    int guessed[BOARD_SIZE][BOARD_SIZE];
};

/* Function prototypes */
void init_board(struct GameBoard *board);
void print_board(struct GameBoard *board);
int check_match(struct GameBoard *board, int row1, int col1, int row2, int col2);
void wait_for_memory_duration();
void reset_guessed(struct GameBoard *board);
void process_guess(struct GameBoard *board, int row, int col, int *row1, int *col1, int *row2, int *col2);
void play_game(struct GameBoard *board);

/* Function implementations */
void init_board(struct GameBoard *board) {
    int i, j, count = 0;
    int nums[MAX_GUESSES * 2];
    srand(time(NULL));
    
    // Generate random unique numbers for pairs
    for (i = 0; i < MAX_GUESSES * 2; i += 2) {
        nums[i] = count;
        nums[i+1] = count;
        count++;
    }
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            int index = rand() % (MAX_GUESSES * 2 - (i * BOARD_SIZE + j));
            board->board[i][j] = nums[index];
            nums[index] = nums[MAX_GUESSES * 2 - (i * BOARD_SIZE + j) - 1];
            board->guessed[i][j] = 0;
        }
    }
}

void print_board(struct GameBoard *board) {
    int i, j;
    printf("Memory Game Board:\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board->guessed[i][j]) {
                printf("%2d ", board->board[i][j]);
            } else {
                printf("  X");
            }
        }
        printf("\n");
    }
}

int check_match(struct GameBoard *board, int row1, int col1, int row2, int col2) {
    if (board->board[row1][col1] == board->board[row2][col2]) {
        return 1;
    }
    return 0;
}

void wait_for_memory_duration() {
    struct timespec timeToWait;
    timeToWait.tv_sec = MEMORY_DURATION;
    timeToWait.tv_nsec = 0L;
    nanosleep(&timeToWait, NULL);
}

void reset_guessed(struct GameBoard *board) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board->guessed[i][j] = 0;
        }
    }
}

void process_guess(struct GameBoard *board, int row, int col, int *row1, int *col1, int *row2, int *col2) {
    if (*row1 == -1 && *col1 == -1) {
        *row1 = row;
        *col1 = col;
    } else if (*row2 == -1 && *col2 == -1) {
        *row2 = row;
        *col2 = col;
    } else {
        printf("Too many guesses. Please try again.\n");
    }
}

void play_game(struct GameBoard *board) {
    int num_guesses = 0;
    int row1 = -1, col1 = -1, row2 = -1, col2 = -1;
    while (num_guesses < MAX_GUESSES) {
        system("clear"); // Clear terminal
        print_board(board);
        int row, col;
        printf("Enter row and column number to guess: ");
        scanf("%d%d", &row, &col);
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            printf("Invalid guess. Please try again.\n");
            continue;
        }
        if (board->guessed[row][col]) {
            printf("Already guessed. Please try again.\n");
            continue;
        }
        process_guess(board, row, col, &row1, &col1, &row2, &col2);
        if (row2 != -1 && col2 != -1) {
            num_guesses++;
            board->guessed[row1][col1] = 1;
            board->guessed[row2][col2] = 1;
            if (check_match(board, row1, col1, row2, col2)) {
                printf("Matched!\n");
            } else {
                printf("Not a match.\n");
                wait_for_memory_duration();
                reset_guessed(board);
            }
            row1 = -1;
            col1 = -1;
            row2 = -1;
            col2 = -1;
        }
        usleep(SLEEP_TIME);
    }
    printf("Congratulations! You won Memory Game!\n");
}

int main() {
    struct GameBoard board;
    init_board(&board);
    play_game(&board);
    return 0;
}
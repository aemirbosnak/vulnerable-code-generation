//FormAI DATASET v1.0 Category: Memory Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16
#define MAX_GUESSES 8

void print_board(const char *board, int size);
int get_input(void);
void swap(char *a, char *b);
void shuffle(char *board, int size);
int play_game(const char *wordlist[], int list_size);
void clear_input_buffer(void);

int main(void)
{
    const char *wordlist[] = {"apple", "banana", "cherry", "grape", "lemon", 
                              "orange", "peach", "pear", "pineapple", "watermelon"};
    int list_size = sizeof(wordlist) / sizeof(wordlist[0]);
    int score = play_game(wordlist, list_size);
    printf("You scored %d out of %d possible points!\n", score, MAX_GUESSES);
    return 0;
}

void print_board(const char *board, int size)
{
    int i, j;
    for (i = 0; i < size; i++) {
        putchar('|');
        for (j = 0; j < size; j++) {
            printf(" %c |", board[i * size + j]);
        }
        putchar('\n');
    }
}

int get_input(void)
{
    int input;
    while (scanf("%d", &input) != 1 || input < 0 || input >= BOARD_SIZE) {
        printf("Invalid input! Try again: ");
        clear_input_buffer();
    }
    clear_input_buffer();
    return input;
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(char *board, int size)
{
    int i;
    srand((unsigned)time(NULL));
    for (i = 0; i < size * size; i++) {
        int j = i + rand() / (RAND_MAX / (size * size - i) + 1);
        swap(&board[i], &board[j]);
    }
}

int play_game(const char *wordlist[], int list_size)
{
    int score = 0;
    char board[BOARD_SIZE * BOARD_SIZE / 2];
    int i, j;

    printf("Welcome to the Memory Game!\n");
    printf("The board has been shuffled and is now hidden from view.\n");
    printf("You must guess the location of all the matching pairs of letters!\n");

    for (i = 0; i < MAX_GUESSES; i++) {
        printf("\nRound %d:\n\n", i + 1);
        shuffle(board, BOARD_SIZE / 2);

        for (j = 0; j < BOARD_SIZE / 2; j++) {
            board[j] = board[j] < list_size ? wordlist[board[j]][0] : '\0';
        }

        print_board(board, BOARD_SIZE / 2);

        printf("Enter the coordinates of the first letter: ");
        int input1 = get_input();

        printf("Enter the coordinates of the second letter: ");
        int input2 = get_input();

        if (board[input1] == board[input2]) {
            printf("Congratulations! You found a match!\n");
            score++;
        } else {
            printf("Sorry, those letters do not match!\n");
        }
    }

    return score;
}

void clear_input_buffer(void)
{
    for (int c = getchar(); c != '\n' && c != EOF; c = getchar());
}
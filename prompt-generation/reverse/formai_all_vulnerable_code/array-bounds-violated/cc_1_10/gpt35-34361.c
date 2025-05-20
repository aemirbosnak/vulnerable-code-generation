//FormAI DATASET v1.0 Category: Memory Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define CARDS_COUNT (ROWS * COLS / 2)

/* Symbolic constant for hidden card */
#define HIDDEN ' '

/* Structure for each card */
typedef struct
{
    char value;     /* Value of card */
    int visible;    /* Visibility flag */
} Card;

/* Function to print the cards */
void print_cards(Card board[ROWS][COLS])
{
    int i, j;
    printf("\n");
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(board[i][j].visible)
                printf("%c ", board[i][j].value);
            else
                printf("%c ", HIDDEN);
        }
        printf("\n");
    }
}

/* Function to check if the game is over */
int game_over(Card board[ROWS][COLS])
{
    int i, j;
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(!board[i][j].visible)
                return 0;
        }
    }
    return 1;
}

int main()
{
    Card board[ROWS][COLS];
    int i, j, x, y;
    char cards[CARDS_COUNT * 2] = {'A','A','B','B','C','C','D','D','E','E','F','F','G','G','H','H'};

    srand(time(NULL));

    /* Initialize game board */
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            board[i][j].value = HIDDEN;
            board[i][j].visible = 0;
        }
    }

    /* Shuffle cards */
    for(i = 0; i < CARDS_COUNT * 2; i++)
    {
        x = rand() % CARDS_COUNT * 2;
        y = rand() % CARDS_COUNT * 2;
        char temp = cards[x];
        cards[x] = cards[y];
        cards[y] = temp;
    }

    /* Place cards on board randomly */
    int k = 0;
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            board[i][j].value = cards[k++];
        }
    }

    /* Main game loop */
    int count = 0;
    int first_card_row, first_card_col, second_card_row, second_card_col;
    while(!game_over(board))
    {
        print_cards(board);
        printf("\nEnter coordinates of two cards: ");
        scanf("%d %d %d %d", &first_card_row, &first_card_col, &second_card_row, &second_card_col);

        /* Check if cards are a match */
        if(board[first_card_row][first_card_col].value == board[second_card_row][second_card_col].value)
        {
            board[first_card_row][first_card_col].visible = 1;
            board[second_card_row][second_card_col].visible = 1;
            printf("\nMatch!");
        }
        else
        {
            printf("\nNo match. Try again.");
        }

        count++;
    }
    print_cards(board);
    printf("\nCongratulations! You won in %d moves.", count);

    return 0;
}
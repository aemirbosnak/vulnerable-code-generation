//FormAI DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

typedef struct {
    int x;
    int y;
} Coordinates;

void initializeBoard(int board[][BOARD_SIZE]);
void shuffleCards(int cards[], int count);
void printBoard(int board[][BOARD_SIZE], int revealedCards[][BOARD_SIZE]);
int getCard();
Coordinates getCoordinates();
void revealCard(int board[][BOARD_SIZE], int revealedCards[][BOARD_SIZE], Coordinates coor1, Coordinates coor2);
int isGameOver(int revealedCards[][BOARD_SIZE]);


int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int revealedCards[BOARD_SIZE][BOARD_SIZE] = {{0}};
    initializeBoard(board);

    while (!isGameOver(revealedCards)) {
        system("cls");  // Clears the console window
        printBoard(board, revealedCards);

        printf("Enter the coordinates of your first card: ");
        Coordinates coor1 = getCoordinates();
        printf("Enter the coordinates of your second card: ");
        Coordinates coor2 = getCoordinates();

        int card1 = board[coor1.x][coor1.y];
        int card2 = board[coor2.x][coor2.y];

        if (card1 == card2 && !revealedCards[coor1.x][coor1.y] && !revealedCards[coor2.x][coor2.y]) {
            printf("You have successfully matched the cards!\n");
            revealedCards[coor1.x][coor1.y] = 1;
            revealedCards[coor2.x][coor2.y] = 1;
        }
        else {
            printf("The cards do not match.\n");
            revealCard(board, revealedCards, coor1, coor2);
        }
        printf("\nPress any key to continue...\n");
        getchar();
    }

    printf("Congratulations, you have successfully matched all the cards!\n");
    return 0;
}

void initializeBoard(int board[][BOARD_SIZE]) {
    int cards[BOARD_SIZE * BOARD_SIZE / 2];
    int i, j;
    for (i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; i++) {
        cards[i] = i+1;
    }
    shuffleCards(cards, BOARD_SIZE * BOARD_SIZE / 2);

    int k = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = cards[k];
            k++;
        }
    }
}

void shuffleCards(int cards[], int count) {
    srand(time(NULL));
    int i, j, temp;
    for (i = count-1; i > 0; i--) {
        j = rand() % (i+1);
        temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void printBoard(int board[][BOARD_SIZE], int revealedCards[][BOARD_SIZE]) {
    int i, j;
    printf("   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%3d ", i+1);
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i+1);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (revealedCards[i][j]) {
                printf("%3d ", board[i][j]);
            }
            else {
                printf("%3c ", '-');
            }
        }
        printf("\n");
    }
}

int getCard() {
    int card;
    printf("Enter card value (1-8): ");
    scanf("%d", &card);
    while (card < 1 || card > 8) {
        printf("Invalid card value. Please enter a value between 1 and 8\n");
        printf("Enter card value (1-8): ");
        scanf("%d", &card);
    }
    return card;
}

Coordinates getCoordinates() {
    int x, y;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);
    while (x < 1 || x > BOARD_SIZE || y < 1 || y > BOARD_SIZE) {
        printf("Invalid coordinates. Please enter values between 1 and %d\n", BOARD_SIZE);
        printf("Enter x: ");
        scanf("%d", &x);
        printf("Enter y: ");
        scanf("%d", &y);
    }
    Coordinates coor;
    coor.x = x-1;
    coor.y = y-1;
    return coor;
}

void revealCard(int board[][BOARD_SIZE], int revealedCards[][BOARD_SIZE], Coordinates coor1, Coordinates coor2) {
    revealedCards[coor1.x][coor1.y] = 1;
    revealedCards[coor2.x][coor2.y] = 1;
    printBoard(board, revealedCards);
    revealedCards[coor1.x][coor1.y] = 0;
    revealedCards[coor2.x][coor2.y] = 0;
}

int isGameOver(int revealedCards[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (!revealedCards[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}
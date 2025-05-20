//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

typedef struct {
    int x, y;
} coord;

char board[N][N];
int open[N][N];

void init() {
    int i, j, k, l;
    char c[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    srand(time(NULL));
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            board[i][j] = c[rand() % 8];
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            open[i][j] = 0;
}

void display() {
    int i, j;
    printf("  ");
    for (i = 0; i < N; i++)
        printf("%c ", 'A' + i);
    printf("\n");
    for (i = 0; i < N; i++) {
        printf("%c ", 'A' + i);
        for (j = 0; j < N; j++)
            printf("%c ", open[i][j] ? board[i][j] : '#');
        printf("\n");
    }
}

int play(coord c1, coord c2) {
    if (board[c1.x][c1.y] == board[c2.x][c2.y]) {
        open[c1.x][c1.y] = open[c2.x][c2.y] = 1;
        return 1;
    }
    return 0;
}

int main() {
    init();
    coord c1, c2;
    int score = 0;
    while (1) {
        display();
        printf("Enter two coordinates (e.g. A1 B2): ");
        scanf(" %c%d %c%d", &c1.x, &c1.y, &c2.x, &c2.y);
        c1.x -= 'A';
        c2.x -= 'A';
        c1.y--;
        c2.y--;
        if (c1.x < 0 || c1.x >= N || c1.y < 0 || c1.y >= N ||
            c2.x < 0 || c2.x >= N || c2.y < 0 || c2.y >= N) {
            printf("Invalid coordinates!\n");
            continue;
        }
        if (play(c1, c2))
            score++;
        if (score == N * N / 2) {
            printf("Congratulations! You won!\n");
            break;
        }
    }
    return 0;
}
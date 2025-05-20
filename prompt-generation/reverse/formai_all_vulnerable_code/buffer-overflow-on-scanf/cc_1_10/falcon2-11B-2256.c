//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_bingo_cards(int n, int size, char **cards, char **bingo_matrix) {
    srand(time(0));
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < size; j++) {
            int rand_num = rand() % 25;
            bingo_matrix[i][j] = rand_num;
            if (rand_num == 0) {
                cards[i][j] = 'B';
            } else {
                cards[i][j] = 'O';
            }
        }
    }
}

int main() {
    int n, size;
    char **cards, **bingo_matrix;

    printf("Enter the number of players (n): ");
    scanf("%d", &n);
    printf("Enter the size of the bingo card (size): ");
    scanf("%d", &size);

    cards = (char **)malloc(n * sizeof(char *));
    bingo_matrix = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        cards[i] = (char *)malloc(size * sizeof(char));
        bingo_matrix[i] = (char *)malloc(size * sizeof(char));
    }

    generate_bingo_cards(n, size, cards, bingo_matrix);

    printf("Bingo Cards:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", cards[i][j]);
        }
        printf("\n");
    }

    free(cards);
    free(bingo_matrix);

    return 0;
}
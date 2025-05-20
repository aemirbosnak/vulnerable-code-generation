//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MIN_NUM 1
#define MAX_NUM 10

typedef struct {
    int rows;
    int cols;
    int** table;
} GameTable;

void init_table(GameTable* table) {
    table->rows = MAX_ROWS;
    table->cols = MAX_COLS;
    table->table = malloc(sizeof(int*) * MAX_ROWS);
    for (int i = 0; i < MAX_ROWS; i++) {
        table->table[i] = malloc(sizeof(int) * MAX_COLS);
        for (int j = 0; j < MAX_COLS; j++) {
            table->table[i][j] = MIN_NUM;
        }
    }
}

void print_table(GameTable* table) {
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            printf("%d ", table->table[i][j]);
        }
        printf("\n");
    }
}

void randomize_table(GameTable* table) {
    srand(time(NULL));
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            table->table[i][j] = MIN_NUM + rand() % (MAX_NUM - MIN_NUM + 1);
        }
    }
}

int get_num_of_ones(GameTable* table) {
    int count = 0;
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            if (table->table[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

void update_table(GameTable* table, int row, int col) {
    int value = table->table[row][col];
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            if (table->table[i][j] == value) {
                table->table[i][j] = 0;
            }
        }
    }
}

void play_game(GameTable* table) {
    int ones = get_num_of_ones(table);
    while (ones > 0) {
        printf("Enter row and column: ");
        int row, col;
        scanf("%d %d", &row, &col);
        if (row < 0 || row >= table->rows || col < 0 || col >= table->cols) {
            printf("Invalid input.\n");
            continue;
        }
        update_table(table, row, col);
        ones = get_num_of_ones(table);
    }
    printf("You win!\n");
}

int main() {
    GameTable table;
    init_table(&table);
    randomize_table(&table);
    print_table(&table);
    play_game(&table);
    return 0;
}
//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 6
#define PATTERNS 10

typedef struct {
    int row;
    int col;
    char pattern[SIZE][SIZE];
} Pattern;

Pattern patterns[PATTERNS] = {
    {
        .row = SIZE,
        .col = SIZE,
        .pattern = {
            {'*', '*', '*', '*', '*', '*'},
            {'*', ' ', '*', ' ', '*', '*'},
            {'*', ' ', '*', ' ', '*', '*'},
            {'*', ' ', '*', ' ', '*', '*'},
            {'*', ' ', '*', ' ', '*', '*'},
            {'*', '*', '*', '*', '*', '*'}
        }
    },
    {
        .row = SIZE,
        .col = SIZE,
        .pattern = {
            {' ', ' ', ' ', ' ', ' ', ' '},
            {'*', '*', '*', '*', '*', '*'},
            {' ', ' ', ' ', ' ', ' ', ' '},
            {'*', '*', '*', '*', '*', '*'},
            {' ', ' ', ' ', ' ', ' ', ' '},
            {'*', '*', '*', '*', '*', '*'}
        }
    },
    // Add more patterns here
};

void print_pattern(Pattern p) {
    for (int i = 0; i < p.row; i++) {
        for (int j = 0; j < p.col; j++) {
            printf("%c", p.pattern[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    printf("Select a pattern number from 1 to %d:\n", PATTERNS);
    scanf("%d", &choice);

    if (choice > 0 && choice <= PATTERNS) {
        print_pattern(patterns[choice - 1]);
    } else {
        printf("Invalid pattern number.\n");
    }

    return 0;
}
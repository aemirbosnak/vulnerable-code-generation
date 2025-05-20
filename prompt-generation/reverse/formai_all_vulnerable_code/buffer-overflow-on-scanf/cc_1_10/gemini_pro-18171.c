//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_CASES 100
#define MAX_SUSPECTS 1000
#define MAX_CLUES 10000

typedef struct {
    int id;
    int num_clues;
    int *clues;
} suspect_t;

typedef struct {
    int id;
    int num_clues;
    int *clues;
} clue_t;

suspect_t suspects[MAX_SUSPECTS];
clue_t clues[MAX_CLUES];
int num_cases;
int num_suspects;
int num_clues;

void read_input() {
    int i, j;

    scanf("%d", &num_cases);

    for (i = 0; i < num_cases; i++) {
        scanf("%d", &num_suspects);
        scanf("%d", &num_clues);

        for (j = 0; j < num_suspects; j++) {
            suspects[j].id = j + 1;
            suspects[j].num_clues = 0;
            suspects[j].clues = malloc(sizeof(int) * MAX_CLUES);
        }

        for (j = 0; j < num_clues; j++) {
            clues[j].id = j + 1;
            clues[j].num_clues = 0;
            clues[j].clues = malloc(sizeof(int) * MAX_SUSPECTS);
        }

        for (j = 0; j < num_clues; j++) {
            int suspect_id, clue_id;
            scanf("%d %d", &suspect_id, &clue_id);

            suspects[suspect_id - 1].clues[suspects[suspect_id - 1].num_clues++] = clue_id;
            clues[clue_id - 1].clues[clues[clue_id - 1].num_clues++] = suspect_id;
        }
    }
}

void solve_cases() {
    int i, j, k;

    for (i = 0; i < num_cases; i++) {
        int max_clues = 0;
        int max_clues_suspect_id = -1;

        for (j = 0; j < num_suspects; j++) {
            if (suspects[j].num_clues > max_clues) {
                max_clues = suspects[j].num_clues;
                max_clues_suspect_id = suspects[j].id;
            }
        }

        printf("Case #%d: %d\n", i + 1, max_clues_suspect_id);
    }
}

int main() {
    read_input();
    solve_cases();

    return 0;
}
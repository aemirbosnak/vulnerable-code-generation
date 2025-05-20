//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_STATES 4
#define ALPHABET_SIZE 4
#define MAX_GENome_LENGTH 100

typedef struct {
    int next[ALPHABET_SIZE];
    int output;
} FSM_t;

void init_fsm(FSM_t* fsm) {
    memset(fsm, 0, sizeof(FSM_t));
    fsm->next['A'] = 1;
    fsm->next['C'] = 2;
    fsm->next['G'] = 3;
    fsm->next['T'] = 0;
    fsm->output = 1;
}

void print_genome(char* genome) {
    int i;
    for (i = 0; genome[i] != '\0'; i++) {
        putchar(genome[i]);
    }
    putchar('\n');
}

void print_state(int state) {
    switch (state) {
        case 0: printf("State 0: Start\n"); break;
        case 1: printf("State 1: A\n"); break;
        case 2: printf("State 2: C\n"); break;
        case 3: printf("State 3: G\n"); break;
    }
}

void simulate_sequencing(FSM_t* fsm, char* genome) {
    int state = 0, i, symbol;
    for (i = 0; i < strlen(genome) && i < MAX_GENome_LENGTH; i++) {
        symbol = genome[i];
        print_state(state);
        state = fsm->next[symbol];
    }
}

int main() {
    FSM_t fsm;
    char genome[MAX_GENome_LENGTH];

    init_fsm(&fsm);
    printf("Input the genome to sequence:\n");
    scanf("%s", genome);

    printf("Sequencing result:\n");
    simulate_sequencing(&fsm, genome);

    return 0;
}
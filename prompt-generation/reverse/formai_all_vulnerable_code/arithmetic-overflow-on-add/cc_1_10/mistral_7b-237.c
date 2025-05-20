//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BASES 4
#define LENGTH 100000
#define SEED 123456

typedef struct base {
    char symbol;
    int probability;
} base_t;

base_t bases[BASES] = {
    {'A', 35}, {'C', 17}, {'G', 18}, {'T', 30}
};

typedef struct read {
    int id;
    char *sequence;
    struct read *next;
} read_t;

read_t *reads = NULL;

void simulate_base_call(void) {
    srand(time(NULL) + SEED);
    int index = rand() % BASES;
    printf("%c", bases[index].symbol);
}

void simulate_read(int id) {
    read_t *read = malloc(sizeof(read_t));
    read->id = id;
    read->sequence = malloc(sizeof(char) * (LENGTH + 1));

    for (int i = 0; i < LENGTH; i++) {
        simulate_base_call();
        read->sequence[i] = bases[rand() % BASES].symbol;
    }

    read->sequence[LENGTH] = '\0';
    read->next = reads;
    reads = read;
}

void print_reads(void) {
    read_t *current = reads;

    printf("\nSEQUENCES:\n");
    while (current != NULL) {
        printf("ID: %d, SEQUENCE: %s\n", current->id, current->sequence);
        current = current->next;
    }
}

int main() {
    srand(SEED);

    for (int i = 1; i <= 5; i++) {
        simulate_read(i);
    }

    print_reads();

    return 0;
}
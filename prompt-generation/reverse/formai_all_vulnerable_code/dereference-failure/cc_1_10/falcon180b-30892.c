//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char base;
    int position;
} Nucleotide;

typedef struct {
    char* sequence;
    int length;
} Genome;

Genome* generateRandomGenome(int length) {
    Genome* genome = malloc(sizeof(Genome));
    genome->length = length;
    genome->sequence = malloc(length * sizeof(char));

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int randomInt = rand() % 4;
        switch (randomInt) {
            case 0:
                genome->sequence[i] = 'A';
                break;
            case 1:
                genome->sequence[i] = 'C';
                break;
            case 2:
                genome->sequence[i] = 'G';
                break;
            case 3:
                genome->sequence[i] = 'T';
                break;
        }
    }

    return genome;
}

void printGenome(Genome* genome) {
    for (int i = 0; i < genome->length; i++) {
        printf("%c", genome->sequence[i]);
    }
    printf("\n");
}

int main() {
    Genome* genome = generateRandomGenome(100);
    printGenome(genome);

    free(genome->sequence);
    free(genome);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_ERRORS 10

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int length;
    int position;
} Read;

int main(int argc, char *argv[]) {
    srand(time(NULL));

    Sequence genome = {0};
    Read reads[100] = {0};

    int i, j;
    for (i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        char base = rand() % 4;
        switch (base) {
            case 0:
                genome.sequence[i] = 'A';
                break;
            case 1:
                genome.sequence[i] = 'C';
                break;
            case 2:
                genome.sequence[i] = 'G';
                break;
            case 3:
                genome.sequence[i] = 'T';
                break;
        }
    }
    genome.length = MAX_SEQUENCE_LENGTH;

    for (i = 0; i < 100; i++) {
        reads[i].sequence = malloc(MAX_READ_LENGTH * sizeof(char));
        reads[i].length = rand() % MAX_READ_LENGTH + 1;

        for (j = 0; j < reads[i].length; j++) {
            char base = rand() % 4;
            switch (base) {
                case 0:
                    reads[i].sequence[j] = 'A';
                    break;
                case 1:
                    reads[i].sequence[j] = 'C';
                    break;
                case 2:
                    reads[i].sequence[j] = 'G';
                    break;
                case 3:
                    reads[i].sequence[j] = 'T';
                    break;
            }
        }
        reads[i].position = rand() % genome.length;
    }

    int errors = 0;
    for (i = 0; i < 100; i++) {
        int k = 0;
        while (k < reads[i].length && reads[i].position + k < genome.length) {
            if (reads[i].sequence[k]!= genome.sequence[reads[i].position + k]) {
                errors++;
                if (errors > MAX_ERRORS) {
                    break;
                }
            }
            k++;
        }
    }

    printf("Errors: %d\n", errors);

    return 0;
}
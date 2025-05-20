//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define NUM_READS 100
#define READ_LENGTH 50

typedef struct {
    char *sequence;
    int length;
} Read;

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[length] = '\0';
}

int main() {
    srand(time(NULL));

    Read *reads = (Read *) malloc(NUM_READS * sizeof(Read));

    for (int i = 0; i < NUM_READS; i++) {
        reads[i].sequence = (char *) malloc(READ_LENGTH * sizeof(char));
        reads[i].length = READ_LENGTH;
        generate_random_sequence(reads[i].sequence, READ_LENGTH);
    }

    FILE *output_file = fopen("genome_sequence.txt", "w");

    fprintf(output_file, "Genome Sequence:\n");

    for (int i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        for (int j = 0; j < NUM_READS; j++) {
            if (i >= reads[j].length) {
                fprintf(output_file, "N");
            } else {
                fprintf(output_file, "%c", reads[j].sequence[i]);
            }
        }
        fprintf(output_file, "\n");
    }

    fclose(output_file);

    return 0;
}
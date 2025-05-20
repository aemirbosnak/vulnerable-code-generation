//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MIN_SEQUENCE_LENGTH 1000
#define NUM_READS 100

typedef struct {
    char *sequence;
    int length;
} Read;

int main() {
    srand(time(NULL));
    Read *reads = (Read *)malloc(sizeof(Read) * NUM_READS);
    int i;

    for (i = 0; i < NUM_READS; i++) {
        reads[i].length = rand() % (MAX_SEQUENCE_LENGTH - MIN_SEQUENCE_LENGTH + 1) + MIN_SEQUENCE_LENGTH;
        reads[i].sequence = (char *)malloc(sizeof(char) * reads[i].length);
        int j;
        for (j = 0; j < reads[i].length; j++) {
            reads[i].sequence[j] = 'A' + rand() % 4;
        }
        reads[i].sequence[reads[i].length - 1] = '\0';
    }

    int total_length = 0;
    for (i = 0; i < NUM_READS; i++) {
        total_length += reads[i].length;
    }

    char *genome_sequence = (char *)malloc(sizeof(char) * total_length);
    int current_position = 0;

    for (i = 0; i < NUM_READS; i++) {
        int overlap = 0;
        int j;
        for (j = 0; j < i; j++) {
            int k;
            for (k = 0; k < reads[j].length && k < reads[i].length; k++) {
                if (reads[j].sequence[k]!= reads[i].sequence[k]) {
                    break;
                }
            }
            if (k == reads[j].length) {
                overlap = reads[j].length;
                break;
            }
        }
        if (overlap > 0) {
            current_position -= overlap;
        }
        strncpy(genome_sequence + current_position, reads[i].sequence, reads[i].length);
        current_position += reads[i].length;
    }

    printf("Genome sequence:\n%s\n", genome_sequence);

    for (i = 0; i < NUM_READS; i++) {
        free(reads[i].sequence);
    }
    free(reads);
    free(genome_sequence);

    return 0;
}
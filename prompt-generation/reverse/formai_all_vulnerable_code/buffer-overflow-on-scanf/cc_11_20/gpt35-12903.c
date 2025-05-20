//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main() {
    int genome_length = 0; // the length of the genome to be sequenced
    int match_probability = 0; // the probability of a base pair matching
    int mismatch_probability = 0; // the probability of a base pair mismatching
    char *genome; // the genome to be sequenced
    char *sequence; // the sequenced genome
    int i, j; // loop variables
    int match_count = 0; // the number of base pairs that matched
    int mismatch_count = 0; // the number of base pairs that mismatched

    // prompt the user for input
    printf("Enter the length of the genome to be sequenced: ");
    scanf("%d", &genome_length);

    printf("Enter the probability of a base pair matching (0-100): ");
    scanf("%d", &match_probability);

    printf("Enter the probability of a base pair mismatching (0-100): ");
    scanf("%d", &mismatch_probability);

    // allocate memory for genome and sequence
    genome = (char *) malloc(genome_length * sizeof(char));
    sequence = (char *) malloc(genome_length * sizeof(char));

    // seed the random number generator
    srand(time(NULL));

    // populate the genome with random base pairs
    for(i = 0; i < genome_length; i++) {
        int base_pair = rand() % 4;
        switch(base_pair) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'C';
                break;
            case 2:
                genome[i] = 'G';
                break;
            case 3:
                genome[i] = 'T';
                break;
        }
    }

    // print the genome
    printf("The genome to be sequenced:\n%s\n\n", genome);

    // simulate sequencing by comparing each base pair to the genome
    for(i = 0; i < genome_length; i++) {
        int match = rand() % 100;
        if(match < match_probability) {
            sequence[i] = genome[i]; // base pair matches
            match_count++;
        } else {
            int mismatch = rand() % 100;
            if(mismatch < mismatch_probability) {
                // base pair mismatches
                int base_pair = rand() % 4;
                switch(base_pair) {
                    case 0:
                        sequence[i] = 'A';
                        break;
                    case 1:
                        sequence[i] = 'C';
                        break;
                    case 2:
                        sequence[i] = 'G';
                        break;
                    case 3:
                        sequence[i] = 'T';
                        break;
                }
            } else {
                sequence[i] = '-'; // base pair is not sequenced
            }
            mismatch_count++;
        }
    }

    // print the sequenced genome
    printf("The sequenced genome:\n%s\n\n", sequence);

    // print matching and mismatching statistics
    printf("Matching base pairs: %d out of %d\n", match_count, genome_length);
    printf("Mismatching base pairs: %d out of %d\n", mismatch_count, genome_length);

    // free memory
    free(genome);
    free(sequence);

    return 0;
}
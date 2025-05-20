//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 1000 // maximum length of genome
#define MAX_MUTATIONS 200 // maximum number of mutations allowed
#define MUTATION_PROB 0.1 // probability of each base mutating

int main(int argc, char *argv[]) {
    int len = MAX_LEN; // default genome length
    int num_mutations = 0; // default number of mutations
    double mutation_prob = MUTATION_PROB; // default mutation probability

    // parse command line arguments
    if (argc > 1) {
        len = atoi(argv[1]);
        if (len > MAX_LEN) {
            printf("Error: genome length cannot exceed %d!\n", MAX_LEN);
            return 1;
        }
    }
    if (argc > 2) {
        num_mutations = atoi(argv[2]);
        if (num_mutations > MAX_MUTATIONS) {
            printf("Error: maximum number of mutations is %d!\n", MAX_MUTATIONS);
            return 1;
        }
    }
    if (argc > 3) {
        mutation_prob = atof(argv[3]);
        if (mutation_prob < 0 || mutation_prob > 1) {
            printf("Error: mutation probability must be between 0 and 1!\n");
            return 1;
        }
    }

    // initialize random seed
    srand(time(NULL));

    // initialize genome as random sequence of A, C, G, T bases
    char genome[MAX_LEN];
    for (int i = 0; i < len; i++) {
        int rand_num = rand() % 4;
        switch (rand_num) {
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

    // perform mutations
    for (int i = 0; i < num_mutations; i++) {
        int rand_index = rand() % len;
        if (rand() < mutation_prob * RAND_MAX) {
            int rand_num = rand() % 3;
            switch (rand_num) {
                case 0:
                    genome[rand_index] = 'A';
                    break;
                case 1:
                    genome[rand_index] = 'C';
                    break;
                case 2:
                    genome[rand_index] = 'G';
                    break;
                case 3:
                    genome[rand_index] = 'T';
                    break;
            }
        }
    }

    // print out genome sequence
    for (int i = 0; i < len; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");

    return 0;
}
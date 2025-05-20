//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 1000 // maximum amount of nucleotides in genome
#define A 0 // adenine
#define C 1 // cytosine
#define G 2 // guanine
#define T 3 // thymine

int main() {
    srand(time(NULL));

    int genome[MAX_N];

    int n; // length of genome
    printf("Enter length of genome: ");
    scanf("%d", &n);

    if (n > MAX_N) {
        printf("Error: genome length too large\n");
        return -1;
    }

    printf("Generating genome...\n");

    for (int i = 0; i < n; i++) {
        genome[i] = rand() % 4; // randomly choose a nucleotide A, C, G, or T
    }

    printf("Generated genome: ");
    for (int i = 0; i < n; i++) {
        if (genome[i] == A) printf("A");
        else if (genome[i] == C) printf("C");
        else if (genome[i] == G) printf("G");
        else printf("T");
    }
    printf("\n");

    printf("Simulating sequencing...\n");

    const double BASE_QUALITY = 30.0; // probability of correct read given correct base
    const double ERROR_RATE = 0.01; // probability of incorrect read given incorrect base
    const double INSERTION_RATE = 0.01; // probability of insertion
    const double DELETION_RATE = 0.01; // probability of deletion

    char seq[MAX_N];
    int pos = 0;

    for (int i = 0; i < n; i++) {
        double r = (double) rand() / RAND_MAX;

        if (r < INSERTION_RATE) { // insert a random nucleotide
            int new_nucleotide = rand() % 4;
            seq[pos] = new_nucleotide;
            pos++;
        }

        if (r < DELETION_RATE) { // delete current nucleotide
            continue;
        }

        // simulate sequencing error
        r = (double) rand() / RAND_MAX;
        if (r < ERROR_RATE) {
            int error_type = rand() % 3; // choose between substitution, insertion, and deletion
            if (error_type == 0) { // substitution
                int new_nucleotide = rand() % 4;
                while (new_nucleotide == genome[i]) { // choose a different nucleotide
                    new_nucleotide = rand() % 4;
                }
                seq[pos] = new_nucleotide;
                pos++;
            } else if (error_type == 1) { // insertion
                int new_nucleotide = rand() % 4;
                seq[pos] = new_nucleotide;
                pos++;
                seq[pos] = genome[i];
                pos++;
            } else { // deletion
                continue;
            }
        } else { // no error
            seq[pos] = genome[i];
            pos++;
        }
    }

    printf("Sequenced genome: ");
    for (int i = 0; i < pos; i++) {
        if (seq[i] == A) printf("A");
        else if (seq[i] == C) printf("C");
        else if (seq[i] == G) printf("G");
        else printf("T");
    }
    printf("\n");

    return 0;
}
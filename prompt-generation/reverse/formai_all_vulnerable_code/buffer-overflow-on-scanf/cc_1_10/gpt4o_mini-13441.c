//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define SUBSEQ_LENGTH 10

void generate_random_dna(char *dna, int length);
void print_dna(const char *dna, int length);
int search_subsequence(const char *dna, int length, const char *subseq);
void mutate_dna(char *dna, int length, int mutation_rate);

int main() {
    char dna[MAX_GENOME_LENGTH + 1];
    char subseq[SUBSEQ_LENGTH + 1];
    int length, mutation_rate;

    // Seed random number generator
    srand(time(NULL));

    // Prompt user for length of DNA
    printf("Enter the length of the DNA sequence (1-%d): ", MAX_GENOME_LENGTH);
    scanf("%d", &length);

    // Validate length input
    if (length < 1 || length > MAX_GENOME_LENGTH) {
        printf("Invalid length. Please enter a value between 1 and %d.\n", MAX_GENOME_LENGTH);
        return EXIT_FAILURE;
    }

    // Generate random DNA sequence
    generate_random_dna(dna, length);
    printf("Generated DNA Sequence:\n");
    print_dna(dna, length);

    // Input a subsequence to search
    printf("Enter a subsequence to search (max length %d): ", SUBSEQ_LENGTH);
    scanf("%s", subseq);
    
    // Search for subsequence
    int position = search_subsequence(dna, length, subseq);
    if (position != -1) {
        printf("Subsequence '%s' found at position %d.\n", subseq, position);
    } else {
        printf("Subsequence '%s' not found in the DNA sequence.\n", subseq);
    }

    // Input mutation rate
    printf("Enter mutation rate (1-100): ");
    scanf("%d", &mutation_rate);
    
    // Validate mutation rate input
    if (mutation_rate < 1 || mutation_rate > 100) {
        printf("Invalid mutation rate. Please enter a value between 1 and 100.\n");
        return EXIT_FAILURE;
    }

    // Mutate the DNA sequence
    mutate_dna(dna, length, mutation_rate);
    printf("Mutated DNA Sequence:\n");
    print_dna(dna, length);
    
    return EXIT_SUCCESS;
}

void generate_random_dna(char *dna, int length) {
    const char nucleotides[] = "ACGT";
    for (int i = 0; i < length; i++) {
        dna[i] = nucleotides[rand() % 4];
    }
    dna[length] = '\0';  // Null-terminate the string
}

void print_dna(const char *dna, int length) {
    for (int i = 0; i < length; i++) {
        putchar(dna[i]);
    }
    putchar('\n');
}

int search_subsequence(const char *dna, int length, const char *subseq) {
    int subseq_length = strlen(subseq);
    for (int i = 0; i <= length - subseq_length; i++) {
        if (strncmp(&dna[i], subseq, subseq_length) == 0) {
            return i;  // return starting index of subsequence
        }
    }
    return -1;  // not found
}

void mutate_dna(char *dna, int length, int mutation_rate) {
    for (int i = 0; i < length; i++) {
        if (rand() % 100 < mutation_rate) {
            // Mutate the nucleotide
            const char nucleotides[] = "ACGT";
            char current_nucleotide = dna[i];
            char new_nucleotide;
            do {
                new_nucleotide = nucleotides[rand() % 4];
            } while (new_nucleotide == current_nucleotide);  // Ensure it's a different nucleotide
            dna[i] = new_nucleotide;
        }
    }
}
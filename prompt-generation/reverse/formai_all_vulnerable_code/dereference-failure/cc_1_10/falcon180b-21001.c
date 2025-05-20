//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DNA_SEQ_LENGTH 1000000 // maximum length of DNA sequence

// function prototypes
void generate_random_dna_sequence(char* dna_seq, int seq_length);
void print_dna_sequence(char* dna_seq, int seq_length);
void save_dna_sequence_to_file(char* dna_seq, int seq_length, char* filename);

int main() {
    srand(time(NULL)); // seed random number generator with current time

    int seq_length;
    printf("Enter the length of the DNA sequence: ");
    scanf("%d", &seq_length);

    if (seq_length > MAX_DNA_SEQ_LENGTH) {
        printf("Error: DNA sequence length must be less than or equal to %d.\n", MAX_DNA_SEQ_LENGTH);
        return 1;
    }

    char dna_seq[MAX_DNA_SEQ_LENGTH];
    generate_random_dna_sequence(dna_seq, seq_length);

    printf("Random DNA sequence:\n");
    print_dna_sequence(dna_seq, seq_length);

    char filename[100];
    printf("Enter the filename to save the DNA sequence: ");
    scanf("%s", filename);

    save_dna_sequence_to_file(dna_seq, seq_length, filename);

    printf("DNA sequence saved to file: %s\n", filename);

    return 0;
}

// generates a random DNA sequence of given length
void generate_random_dna_sequence(char* dna_seq, int seq_length) {
    const char bases[] = "ACGT";
    for (int i = 0; i < seq_length; i++) {
        dna_seq[i] = bases[rand() % 4];
    }
    dna_seq[seq_length] = '\0'; // add null terminator
}

// prints a DNA sequence
void print_dna_sequence(char* dna_seq, int seq_length) {
    for (int i = 0; i < seq_length; i++) {
        printf("%c", dna_seq[i]);
    }
    printf("\n");
}

// saves a DNA sequence to a file
void save_dna_sequence_to_file(char* dna_seq, int seq_length, char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open file %s for writing.\n", filename);
        return;
    }

    fprintf(file, "%s", dna_seq);
    fclose(file);
}
//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQ_LENGTH 100
#define MAX_SEQUENCES 10

typedef struct {
    char sequence[MAX_SEQ_LENGTH];
    int length;
} DNASequence;

void generate_random_dna_sequence(DNASequence *dna_seq) {
    char *nucleotides = "ACGT";
    int seq_length = rand() % (MAX_SEQ_LENGTH - 1) + 1; // Random length between 1 and MAX_SEQ_LENGTH

    for (int i = 0; i < seq_length; i++) {
        dna_seq->sequence[i] = nucleotides[rand() % 4];
    }
    dna_seq->sequence[seq_length] = '\0'; // Null-terminate the string
    dna_seq->length = seq_length;
}

void print_dna_sequences(DNASequence sequences[], int count) {
    printf("Generated DNA Sequences:\n");
    for (int i = 0; i < count; i++) {
        printf("Sequence %d: %s (Length: %d)\n", i + 1, sequences[i].sequence, sequences[i].length);
    }
}

void print_summary(DNASequence sequences[], int count) {
    int total_length = 0;
    for (int i = 0; i < count; i++) {
        total_length += sequences[i].length;
    }
    printf("Total number of sequences: %d\n", count);
    printf("Total length of all sequences: %d\n", total_length);
    printf("Average length of sequences: %.2f\n", (float)total_length / count);
}

void display_menu() {
    printf("\nGenome Sequencing Simulator Menu:\n");
    printf("1. Generate DNA Sequences\n");
    printf("2. View Generated Sequences\n");
    printf("3. View Summary\n");
    printf("4. Exit\n");
}

int main() {
    srand(time(NULL));
    DNASequence sequences[MAX_SEQUENCES];
    int seq_count = 0;
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (seq_count < MAX_SEQUENCES) {
                    generate_random_dna_sequence(&sequences[seq_count]);
                    seq_count++;
                    printf("DNA sequence generated successfully!\n");
                } else {
                    printf("Maximum number of sequences generated.\n");
                }
                break;

            case 2:
                print_dna_sequences(sequences, seq_count);
                break;

            case 3:
                print_summary(sequences, seq_count);
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
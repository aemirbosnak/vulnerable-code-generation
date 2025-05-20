//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENES 1000
#define MAX_LENGTH 100
#define SEQUENCE_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    char sequence[SEQUENCE_LENGTH];
} Gene;

Gene genes[MAX_GENES];
int gene_count = 0;

void generate_random_sequence(char *seq) {
    const char *nucleotides = "ACGT";
    for (int i = 0; i < SEQUENCE_LENGTH - 1; i++) {
        seq[i] = nucleotides[rand() % 4];
    }
    seq[SEQUENCE_LENGTH - 1] = '\0'; // Null-terminate the string
}

void add_gene(const char *name) {
    if (gene_count >= MAX_GENES) {
        printf("Maximum number of genes reached. Cannot add more.\n");
        return;
    }
    strncpy(genes[gene_count].name, name, MAX_LENGTH);
    generate_random_sequence(genes[gene_count].sequence);
    gene_count++;
}

void print_genes() {
    printf("Genes in the system:\n");
    for (int i = 0; i < gene_count; i++) {
        printf("Gene Name: %s, Sequence: %s\n", genes[i].name, genes[i].sequence);
    }
}

void mutate_sequence(char *seq) {
    int pos = rand() % (SEQUENCE_LENGTH - 1); // Random position in sequence
    const char *nucleotides = "ACGT";
    char original = seq[pos];
    char mutated;

    do {
        mutated = nucleotides[rand() % 4];
    } while (mutated == original); // Ensure mutation changes the nucleotide

    seq[pos] = mutated;
}

void simulate_mutations() {
    int mutations = rand() % 5 + 1; // Random mutations between 1 and 5
    printf("Simulating %d mutations...\n", mutations);

    for (int i = 0; i < mutations; i++) {
        int gene_index = rand() % gene_count;
        mutate_sequence(genes[gene_index].sequence);
        printf("Mutated %s to %s\n", genes[gene_index].name, genes[gene_index].sequence);
    }
}

void save_genes_to_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Unable to open file %s for writing.\n", filename);
        return;
    }

    for (int i = 0; i < gene_count; i++) {
        fprintf(file, "%s\t%s\n", genes[i].name, genes[i].sequence);
    }
    fclose(file);
    printf("Genes saved to %s\n", filename);
}

void load_genes_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open file %s for reading.\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) && gene_count < MAX_GENES) {
        char name[MAX_LENGTH], sequence[SEQUENCE_LENGTH];
        sscanf(line, "%s\t%s", name, sequence);
        strncpy(genes[gene_count].name, name, MAX_LENGTH);
        strncpy(genes[gene_count].sequence, sequence, SEQUENCE_LENGTH);
        gene_count++;
    }
    fclose(file);
    printf("Loaded genes from %s\n", filename);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Mind-Bending Genome Sequencing Simulator!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a gene\n");
        printf("2. Print all genes\n");
        printf("3. Simulate mutations\n");
        printf("4. Save genes to file\n");
        printf("5. Load genes from file\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);

        char name[MAX_LENGTH];
        char filename[MAX_LENGTH];

        switch (choice) {
            case 1:
                printf("Enter gene name: ");
                scanf("%s", name);
                add_gene(name);
                break;
            case 2:
                print_genes();
                break;
            case 3:
                simulate_mutations();
                break;
            case 4:
                printf("Enter filename to save: ");
                scanf("%s", filename);
                save_genes_to_file(filename);
                break;
            case 5:
                printf("Enter filename to load: ");
                scanf("%s", filename);
                load_genes_from_file(filename);
                break;
            case 6:
                printf("Exiting the simulator. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}
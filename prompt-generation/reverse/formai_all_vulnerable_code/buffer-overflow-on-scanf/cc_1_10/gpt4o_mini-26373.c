//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOMES 10
#define MAX_LENGTH 1000
#define BASES "ACGT"
#define MAX_MUTATIONS 5

typedef struct {
    char name[50];
    char sequence[MAX_LENGTH];
} Genome;

void generate_sequence(Genome* genome) {
    int length = rand() % (MAX_LENGTH - 100) + 100; // Length between 100 to MAX_LENGTH
    for (int i = 0; i < length; i++) {
        genome->sequence[i] = BASES[rand() % 4];
    }
    genome->sequence[length] = '\0'; // Null-terminate the string
}

void mutate_sequence(char* sequence, int mutations) {
    int length = strlen(sequence);
    for (int i = 0; i < mutations; i++) {
        // Choose a random position for mutation
        int pos = rand() % length;
        // Mutate the base at that position
        char new_base = BASES[rand() % 4];
        sequence[pos] = new_base;
    }
}

void display_genome(Genome* genome) {
    printf("Genome: %s\n", genome->name);
    printf("Sequence: %s\n", genome->sequence);
}

void save_genome(Genome* genome, const char* filename) {
    FILE* file = fopen(filename, "a");
    if (file) {
        fprintf(file, "Genome: %s\n", genome->name);
        fprintf(file, "Sequence: %s\n\n", genome->sequence);
        fclose(file);
    } else {
        perror("Failed to open file for saving genome");
    }
}

void load_and_display_genomes(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        char line[512];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        perror("Failed to open file for loading genomes");
    }
}

int main() {
    srand(time(0)); // Seed random number generator

    Genome genomes[MAX_GENOMES];
    int genome_count = 0;

    printf("Welcome to the Post-Apocalyptic Genome Sequencing Simulator!\n");
    
    while (1) {
        printf("\nChoose an action:\n");
        printf("1. Create a new genome\n");
        printf("2. Mutate an existing genome\n");
        printf("3. Save a genome to file\n");
        printf("4. Load and display genomes from file\n");
        printf("5. Exit\n");
        printf("-> ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (genome_count < MAX_GENOMES) {
                    printf("Enter the name for the new genome: ");
                    scanf("%s", genomes[genome_count].name);
                    generate_sequence(&genomes[genome_count]);
                    display_genome(&genomes[genome_count]);
                    genome_count++;
                } else {
                    printf("Maximum genome limit reached!\n");
                }
                break;
            case 2:
                if (genome_count > 0) {
                    printf("Select a genome to mutate (0 to %d): ", genome_count - 1);
                    int index;
                    scanf("%d", &index);
                    if (index >= 0 && index < genome_count) {
                        int mutations = rand() % MAX_MUTATIONS + 1; // Random mutations
                        mutate_sequence(genomes[index].sequence, mutations);
                        printf("Mutated Genome:\n");
                        display_genome(&genomes[index]);
                    } else {
                        printf("Invalid genome index!\n");
                    }
                } else {
                    printf("No genomes available to mutate.\n");
                }
                break;
            case 3:
                if (genome_count > 0) {
                    char filename[100];
                    printf("Enter filename to save genomes: ");
                    scanf("%s", filename);
                    for (int i = 0; i < genome_count; i++) {
                        save_genome(&genomes[i], filename);
                    }
                    printf("Genomes saved to %s\n", filename);
                } else {
                    printf("No genomes available to save.\n");
                }
                break;
            case 4:
                {
                    char filename[100];
                    printf("Enter filename to load genomes: ");
                    scanf("%s", filename);
                    load_and_display_genomes(filename);
                }
                break;
            case 5:
                printf("Farewell, brave survivor!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}